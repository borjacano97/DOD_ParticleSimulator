#ifndef ENTITYMANAGER_H
#define ENTITYMANAGER_H

#include <vector>
#include <unordered_map>


#include "System.h"
#include "Entity.h"

class EntityManager
{
private:
	using Entities = std::unordered_map<EntityID, Entity>;
	using Components = std::vector<std::vector<Component*>>;
	using Systems = std::vector<BaseSystem*>;

	Entities entities_;
	Components components_;
	Systems systems_;
public:
	EntityManager();

	EntityManager(const EntityManager&) = delete;
	EntityManager& operator= (const EntityManager&) = delete;
	
	EntityManager(EntityManager&&) = delete;
	EntityManager& operator=(EntityManager&&) = delete;

	~EntityManager();

	void createSystems();
	void update(double deltaTime);

	EntityID createEntity();
	void destroyEntity(EntityID entityID);

	
};


#endif // ENTITYMANAGER_H
