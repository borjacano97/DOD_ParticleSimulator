#ifndef POSITION_COMPONENT_H
#define POSITION_COMPONENT_H
#include "../Component.h"
#include "../utils/Vector2.h"

class PositionComponent : public Component
{
public:
	HAS_ID(PositionComponent);
	bool init(void* data) override { return true; }
	Vector2 value;
};
#endif // POSITION_COMPONENT_H
