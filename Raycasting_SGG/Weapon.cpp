#include "Weapon.h"
#include "Bullet.h"
#include "Game.h"

Weapon::Weapon(float xPos, float yPos, float damage)
	:
	position(xPos, yPos),
    body(position, 0.25),
    damage(damage)
{

}

Weapon* Weapon::Make_Pistol(const Vector2& pos)
{
	return new Weapon(pos.x, pos.y, 20);
}

void Weapon::Onpickup(GameObject& in_user)
{
	isOnGround = false;
	user = &in_user;
}

void Weapon::OnUse()
{
    Game* game = reinterpret_cast<Game*>(graphics::getUserData());
    Level& level = game->GetLevel();

    Vector2 pos = user->Position();
    Vector2 vel = user->Direction() * 20;

    level.AddGameObject(new Bullet(pos.x, pos.y, vel.x, vel.y, damage));

    graphics::playSound("assets\\Audio\\Pistol.wav", 1.0f);
}

GameObject::State Weapon::getState() const
{
    return state;
}

GameObject::COLLIDERTYPE Weapon::getColliderType() const
{
    return type;
}

Vector2 Weapon::Position() const
{
    if (user != nullptr) return user->Position();
    return position;
}

graphics::Brush Weapon::GetBrush() const
{
    graphics::Brush br;

    br.texture = "assets//Weapons//pistol_0.png";
    br.outline_opacity = 0.0f;

    return br;
}

Circle Weapon::GetBody() const
{
    return body;
}

Circle& Weapon::GetBodyRef()
{
    return body;
}

void Weapon::Hit(GameObject& other)
{

}

void Weapon::Update()
{
}

Vector2 Weapon::Direction() const
{
    if (user != nullptr) return user->Direction();

    return Vector2(0.0f, 0.0f);
}
