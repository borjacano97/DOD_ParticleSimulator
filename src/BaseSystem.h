#ifndef BASE_SYSTEM_H
#define BASE_SYSTEM_H
#include "EntitySystemTypes.h"

class Entity;
class EntityManager;

class BaseSystem
{
protected:
	EntityManager* entityManager_;
public:
	explicit BaseSystem(EntityManager* entityManager): entityManager_(entityManager) {  }
	virtual ~BaseSystem() = default;

	virtual void onEntityCreated(const Entity& entity) = 0;
	virtual void onEntityDestroyed(EntityID id) = 0;
	virtual void update(double deltaTime) = 0;
};
#endif // BASE_SYSTEM_H
