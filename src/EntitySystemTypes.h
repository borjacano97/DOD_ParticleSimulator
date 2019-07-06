#ifndef ENTITY_SYSTEM_TYPES_H
#define ENTITY_SYSTEM_TYPES_H

typedef const void* ID;

using EntityID = ID;
constexpr EntityID INVALID_ENTITY_ID = nullptr;

typedef ID ComponentID;
constexpr ComponentID INVALID_COMPONENT_ID = nullptr;

namespace
{
	template<typename T>
	struct type_id_ptr { static const T* const id; };
	
	template<typename T>
	const T* const type_id_ptr<T>::id = nullptr;

}
template<typename T>
constexpr ID getTypeID() noexcept { return &type_id_ptr<T>::id; }

#endif // ENTITY_SYSTEM_TYPES_H
