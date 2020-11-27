#include "Player.h"

Player::Player(const Vector2& pos)
    :
    position(pos)
{
}

Vector2 Player::Position() const
{
    return position;
}

Vector2 Player::Direction() const
{
    return direction;
}

void Player::GoForward(float v)
{
	position += direction * v;
}

void Player::RotateBy(float rad)
{
	direction.Rotate(rad);
	direction.Normalize();
}

