#ifndef COMPONENT_H
#define COMPONENT_H
#include "EntitySystemTypes.h"
#include <limits>

#define HAS_ID(ComponentName) static constexpr ComponentID ID = getTypeID<ComponentName>()

class Component
{
	EntityID entityID;

	static constexpr size_t INVALID_POOL_INDEX = std::numeric_limits<size_t>::max();
	size_t poolIndex;

public:
	Component() : entityID(INVALID_ENTITY_ID), poolIndex(INVALID_POOL_INDEX){}
	virtual ~Component() = default;
	virtual bool init(void* data) = 0;

	inline void setEntityID(const EntityID id) { entityID = id; }
	inline EntityID getEntityID() const { return entityID; }

	inline void setPoolIndex(const size_t index) { poolIndex = index; }
	inline size_t getPoolIndex() const { return poolIndex; }
};
#endif // COMPONENT_H
