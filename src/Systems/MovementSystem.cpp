#include "MovementSystem.h"
#include "../Components/PositionComponent.h"
#include "../Components/VelocityComponent.h"
#include <iostream>


void MovementSystem::update(double deltaTime)
{ 
	int i = 1;
	for(auto& component_tuple : components)
	{
		PositionComponent* position = std::get<PositionComponent*>(component_tuple);
		VelocityComponent* velocity = std::get<VelocityComponent*>(component_tuple);

		std::cout << "Particle " << i++ << " was in " << position->value.toString();
		position->value += velocity->value * deltaTime;
		std::cout << " now is in " << position->value.toString() << '\n';
	}
}
