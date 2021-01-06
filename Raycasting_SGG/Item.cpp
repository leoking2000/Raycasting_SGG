#include "Item.h"
#include "Item.h"

GameObject::State Item::getState() const
{
    return state;
}

GameObject::COLLIDERTYPE Item::getColliderType() const
{
    return type;
}

void Item::Hit(GameObject& other)
{

}

void Item::Update()
{
}

Vector2 Item::Direction() const
{
    return Vector2(0.0f,0.0f);
}
