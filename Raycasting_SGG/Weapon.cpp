#include "Weapon.h"
#include "Bullet.h"
#include "Game.h"

Weapon::Weapon(float xPos, float yPos, float damage, TextureAnimator animator_idle, TextureAnimator animator_fire)
	:
    body({xPos, yPos}, 0.25),
    damage(damage),
    animator_idle(animator_idle),
    animator_fire(animator_fire)
{
}

Weapon* Weapon::Make_Pistol(const Vector2& pos)
{
    std::vector<std::string> idle;
    idle.emplace_back("assets//Weapons//pistol_0.png");
    idle.emplace_back("assets//Weapons//pistol_1.png");
    idle.emplace_back("assets//Weapons//pistol_2.png");

    std::vector<std::string> fire;
    fire.emplace_back("assets//Weapons//pistol_3.png");

	return new Weapon(pos.x, pos.y, 20, TextureAnimator(idle,300.0f,true), TextureAnimator(fire, 300.0f,false));
}

void Weapon::Onpickup(GameObject& in_user)
{
	user = &in_user;
    type = GameObject::COLLIDERTYPE::INACTIVE;
    graphics::playSound("assets\\Audio\\Pickup.wav", 1.0f);
}

void Weapon::OnUse()
{
    Game* game = reinterpret_cast<Game*>(graphics::getUserData());
    Level& level = game->GetLevel();

    Vector2 pos = user->Position() + user->Direction();
    Vector2 vel = user->Direction() * 20;

    level.AddGameObject(new Bullet(pos.x, pos.y, vel.x, vel.y, damage));

    graphics::playSound("assets\\Audio\\Pistol.wav", 1.0f);
    use = true;
    animator_fire.reset();
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
    return body.GetCenter();
}

graphics::Brush Weapon::GetBrush() const
{
    graphics::Brush br;
    br.outline_opacity = 0.0f;

    if (user == nullptr)
    {
        br.texture = "assets//Weapons//pistol_g.png";
    }
    else
    {
        br.texture = use ? animator_fire.GetTexture() : animator_idle.GetTexture();
    }


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
    if (user != nullptr) body.SetCenter(user->Position());

    if (use == false)
    {
        animator_idle.Tick();
    }
    else
    {
        animator_fire.Tick();
        use = !animator_fire.IsOver();
    }
 
}

Vector2 Weapon::Direction() const
{
    if (user != nullptr) return user->Direction();

    return Vector2(0.0f, 0.0f);
}
