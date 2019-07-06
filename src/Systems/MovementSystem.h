#ifndef MOVEMENT_SYSTEM_H
#define MOVEMENT_SYSTEM_H
#include "../System.h"
#include "../Components/PositionComponent.h"
#include "../Components/VelocityComponent.h"

class MovementSystem: public System<PositionComponent, VelocityComponent>
{
	using BaseType = System<PositionComponent, VelocityComponent>;
public:
	MovementSystem(EntityManager* entityManager): BaseType(entityManager){}

	void init() override{}
	virtual void update(double deltaTime) override;
};
#endif // MOVEMENT_SYSTEM_H
