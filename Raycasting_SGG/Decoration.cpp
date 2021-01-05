#include "Decoration.h"

GameObject::State Decoration::getState() const
{
    return state;
}

GameObject::Type Decoration::getType() const
{
    return type;
}

Vector2 Decoration::Position() const
{
    return body.GetCenter();
}

graphics::Brush Decoration::GetBrush() const
{
    graphics::Brush br;

    br.texture = texture;
    br.outline_opacity = 0.0f;

    return br;
}

Circle Decoration::GetBody() const
{
    return body;
}

void Decoration::Hit(const GameObject& other)
{
    switch (other.getType())
    {
    case GameObject::Type::ENTITY:
        
        break;
    }
}

Vector2 Decoration::Direction() const
{
    return Vector2(0.0f,0.0f);
}

void Decoration::Update()
{
}
