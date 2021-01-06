#include "Decoration.h"

GameObject::State Decoration::getState() const
{
    return state;
}

GameObject::COLLIDERTYPE Decoration::getColliderType() const
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

Circle& Decoration::GetBodyRef()
{
    return body;
}

void Decoration::Hit(GameObject& other)
{
	switch (other.getColliderType())
	{
    case GameObject::COLLIDERTYPE::DYNAMIC:
		if(type == GameObject::COLLIDERTYPE::DYNAMIC)
        {
            other.GetBodyRef().ResolveCollisionDynamic(body);
        }
        else
        {
            other.GetBodyRef().ResolveCollisionStatic(body);
        }
		break;
	}

}

Vector2 Decoration::Direction() const
{
    return Vector2(0.0f,0.0f);
}

void Decoration::Update()
{
    if (health <= 0) {
        state = GameObject::State::DEAD;
        return;
    }
}

void Decoration::Damage(float amount)
{
    health -= amount;
}
