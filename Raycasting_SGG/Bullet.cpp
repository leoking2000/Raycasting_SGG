#include "Bullet.h"
#include "Decoration.h"
#include "Game.h"

Bullet::Bullet(float xPos, float yPos, float xVel, float yVel, float damage)
    :
    body({ xPos, yPos }, 0.2f),
    velocity(xVel, yVel),
    amountOfDamage(damage)
{
}

GameObject::State Bullet::getState() const
{
    return state;
}

GameObject::COLLIDERTYPE Bullet::getColliderType() const
{
    return type;
}

Vector2 Bullet::Position() const
{
    return body.GetCenter();
}

graphics::Brush Bullet::GetBrush() const
{
    graphics::Brush br;
    br.texture = "assets//Entities//Bullet.png";
    br.outline_opacity = 0.0f;

    return br;
}

Circle Bullet::GetBody() const
{
    return body;
}

Circle& Bullet::GetBodyRef()
{
    return body;
}

Vector2 Bullet::Direction() const
{
    return velocity;
}

void Bullet::Hit(GameObject& other)
{
    IHasHealth* target = dynamic_cast<IHasHealth*>(&other);


    if (target != nullptr )
    {
        target->Damage(amountOfDamage);
        state = GameObject::State::DEAD;
    }

}

void Bullet::Update()
{
    Vector2 position = body.GetCenter() + velocity * graphics::getDeltaTime() / 1000;
    Game* game = reinterpret_cast<Game*>(graphics::getUserData());
    const Level& level = game->GetLevel();

    if (position.x < 0 && position.x > level.GetWidth() && position.y < 0 && position.y > level.GetHeight() || level.Get(int(position.x), int(position.y)) != ' ')
    {
       state = GameObject::State::DEAD;
    }
    else
    {
        body.SetCenter(position);
    }

}
