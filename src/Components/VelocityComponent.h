#ifndef VELOCITY_COMPONENT_H
#define VELOCITY_COMPONENT_H
#include "../Component.h"
#include "../utils/Vector2.h"

class VelocityComponent: public Component
{
public:

	HAS_ID(VelocityComponent);

	Vector2 value;

	~VelocityComponent() = default;
	bool init(void* data) override final { return true; };
};
#endif // VELOCITY_COMPONENT_H
