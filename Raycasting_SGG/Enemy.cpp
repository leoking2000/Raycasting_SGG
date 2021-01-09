#include "Enemy.h"
#include "Game.h"
#include "Weapon.h"

Enemy::Enemy(float xPos, float yPos, float health, float speed,const std::string& texture)
	:
	body({ xPos, yPos }, 0.5f),
	speed(speed),
	health(health),
	texture(texture)
{
}

Enemy* Enemy::Make_Ghost(float xPos, float yPos)
{
	return new Enemy(xPos, yPos, 500.0f, 1.0f, std::string("assets\\Enemies\\Ghosts_Red0.png"));
}

GameObject::State Enemy::getState() const
{
	return state;
}

GameObject::COLLIDERTYPE Enemy::getColliderType() const
{
	return type;
}

Vector2 Enemy::Position() const
{
	return body.GetCenter();
}

graphics::Brush Enemy::GetBrush() const
{
	graphics::Brush br;

	br.texture = texture;
	br.outline_opacity = 0.0f;

	return br;
}

Circle Enemy::GetBody() const
{
	return body;
}

Circle& Enemy::GetBodyRef()
{
	return body;
}

void Enemy::Hit(GameObject& other)
{
	Game* game = reinterpret_cast<Game*>(graphics::getUserData());
	const Level& pLevel = game->GetLevel();

	if (&other == pLevel.GetPlayer())// is other the player?
	{
		reinterpret_cast<IHasHealth*>(&other)->Damage(10);
	}
}

Vector2 Enemy::Direction() const
{
	return Vector2(0.0f,0.0f);
}

void Enemy::Update()
{
	Game* game = reinterpret_cast<Game*>(graphics::getUserData());
	const GameObject* target = game->GetLevel().GetPlayer();

	Vector2 newPosotion = body.GetCenter() + (target->Position() - body.GetCenter()).Normalize() * speed * graphics::getDeltaTime() / 1000;
	body.SetCenter(newPosotion);
}

void Enemy::Damage(float amount)
{
	health -= amount;
	if (health <= 0)
	{
		state = GameObject::State::DEAD;
	}
}
