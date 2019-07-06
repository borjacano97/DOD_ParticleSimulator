#ifndef ENTITY_H
#define ENTITY_H

#include "EntitySystemTypes.h"
#include <unordered_map>
#include <assert.h>

class Component;

class Entity
{
	EntityID id;

	using ComponentMap = std::unordered_map<ComponentID, Component*, std::hash<ComponentID>, std::equal_to<ComponentID>>;

	ComponentMap components{};
public:
	explicit Entity(const EntityID id): id(id){}
	Entity(const Entity&) = delete;
	Entity(Entity&&) = default;

	Entity& operator=(const Entity&) = delete;
	Entity& operator=(Entity&&) = default;



	EntityID getID() const { return id; }

	inline void addComponent(ComponentID id, Component*component)
	{
		//We do not allow duplicated components
		assert(components.find(id) == components.end());

		components.emplace(id, component);
	}

	const ComponentMap& getComponents() const { return components; }

	template<class ComponentType>
	ComponentType* getComponent()const
	{
		auto it = components.find(ComponentType::ID);
		if (it != components.end())
			return it->second;
		return nullptr;
	}
};

#endif // ENTITY_H
