#ifndef	SYSTEM_H
#define SYSTEM_H
#include "BaseSystem.h"

#include <tuple>
#include <vector>
#include <unordered_map>

#include "EntitySystemTypes.h"
#include "Entity.h"

class Component;

template<class...Comps>
class System : public BaseSystem
{

	using EntityIDToIndexMap = std::unordered_map<EntityID, size_t, std::hash<EntityID>>;
	EntityIDToIndexMap entityIDToIndexMap;

protected:
	using ComponentTuple = std::tuple<std::add_pointer_t<Comps>...>;
	std::vector<ComponentTuple> components;
public:
	explicit System(EntityManager* entityManager) : BaseSystem(entityManager){}

	virtual ~System() = default;

	void onEntityCreated(const Entity& entity) override final;
	void onEntityDestroyed(EntityID id) override final;

	virtual void init() = 0;

private:
	// Recursively looks through  component types
	template<size_t INDEX, class CompType, class... CompArgs>
	bool processComponent(ComponentID id, Component* component, ComponentTuple& tupleToFill);


	// This is the termination specialization of the recursion, which happens when we no longer have a ComponentType
	// that's passed in.
	template<size_t INDEX>
	bool processComponent(ComponentID id, Component* component, ComponentTuple& tupleToFill);


};

template <class ... Comps>
void System<Comps...>::onEntityCreated(const Entity& entity)
{
	ComponentTuple component_tuple;
	size_t matchingComps = 0;
	for(auto& compPair : entity.getComponents())
	{
		if(processComponent<0, Comps...>(compPair.first, compPair.second, component_tuple))
		{
			matchingComps++;
			if(matchingComps == sizeof...(Comps))
			{
				components.emplace_back(std::move(component_tuple));
				entityIDToIndexMap.emplace(entity.getID(), components.size() - 1);
				break;
			}
		}
	}
}

template <class ... Comps>
void System<Comps...>::onEntityDestroyed(EntityID id)
{
	const auto it = entityIDToIndexMap.find(id);
	if(it != entityIDToIndexMap.end())
	{
		//move the back element to overwrite this one 
		components[it->second] = std::move(components.back());
		components.pop_back();

		const auto* movedComponent = std::get<0>(components[it->second]);

		auto movedTupleIt = entityIDToIndexMap.find(movedComponent->getEntityID());
		assert(movedTupleIt != entityIDToIndexMap.end()); //this should be impossible
		movedTupleIt->second = it->second;

	}
}

template <class ... Comps>
template <size_t INDEX, class CompType, class ... CompArgs>
bool System<Comps...>::processComponent(ComponentID id, Component* component, ComponentTuple& tupleToFill)
{
	if(CompType::ID == id)
	{
		std::get<INDEX>(tupleToFill) = static_cast<CompType*>(component);
		return true;
	}

	return processComponent<INDEX + 1, CompArgs...>(id, component, tupleToFill);
}

template <class ... Comps>
template <size_t INDEX>
bool System<Comps...>::processComponent(ComponentID id, Component* component, ComponentTuple& tupleToFill)
{
	return false;
}
#endif // SYSTEM_H
