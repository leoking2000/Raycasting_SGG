#include "Camera.h"

Camera::Camera(const Scene* pScene)
	:
	pScene(pScene)
{
}

void Camera::setScene(const Scene* pScene_in)
{
	pScene = pScene_in;
}

void Camera::RenderSceneAt(int x, int y, int width, int height) const
{
	const Vector2 player_pos = pScene->player.Position();
	const Vector2 player_dir = pScene->player.Direction();

	const Vector2 plane = { -player_dir.y, player_dir.x };

    graphics::Brush br;
    br.outline_opacity = 1.0f;

    graphics::Brush sky;
    sky.outline_color[0] = 0.28f;
    sky.outline_color[1] = 0.5f;
    sky.outline_color[2] = 1.75f;
    sky.outline_opacity = 1.0f;

    graphics::Brush floor;
    floor.outline_color[0] = 0.2f;
    floor.outline_color[1] = 0.2f;
    floor.outline_color[2] = 0.2f;
    floor.outline_opacity = 1.0f;


	for (int column = 0; column < width; column++)
	{

        float cameraX = 2 * column / float(width) - 1; //x-coordinate in camera space
        Vector2 ray_dir(player_dir + (plane * cameraX));

        //length of ray from current position to next x or y-side
        Vector2 sideDist;

        //length of ray from one x or y-side to next x or y-side
        Vector2 deltaDist = { std::abs(1 / ray_dir.x), std::abs(1 / ray_dir.y) };
        float perpWallDist;

        //what direction to step in x or y-direction (either +1 or -1)
        int stepX;
        int stepY;

        bool hit = false; //was there a wall hit?
        int side; //was a NS or a EW wall hit?

        //calculate step and initial sideDist
        if (ray_dir.x < 0)
        {
            stepX = -1;
            sideDist.x = (player_pos.x - (int)player_pos.x) * deltaDist.x;
        }
        else
        {
            stepX = 1;
            sideDist.x = ((int)player_pos.x + 1.0f - player_pos.x) * deltaDist.x;
        }
        if (ray_dir.y < 0)
        {
            stepY = -1;
            sideDist.y = (player_pos.y - (int)player_pos.y) * deltaDist.y;
        }
        else
        {
            stepY = 1;
            sideDist.y = ((int)player_pos.y + 1.0f - player_pos.y) * deltaDist.y;
        }

        Vector2 hitPos((int)player_pos.x, (int)player_pos.y);

        //perform DDA
        while (!hit)
        {
            //jump to next map square, OR in x-direction, OR in y-direction
            if (sideDist.x < sideDist.y)
            {
                sideDist.x += deltaDist.x;
                hitPos.x += stepX;
                side = 0;
            }
            else
            {
                sideDist.y += deltaDist.y;
                hitPos.y += stepY;
                side = 1;
            }
            //Check if ray has hit a wall
            if (pScene->level.Get(hitPos.x, hitPos.y) != '.') hit = true;
        }

        if (side == 0)
        {
            perpWallDist = (hitPos.x - player_pos.x + (1 - stepX) / 2) / ray_dir.x;
        }
        else
        {
            perpWallDist = (hitPos.y - player_pos.y + (1 - stepY) / 2) / ray_dir.y;
        }

        //Calculate height of line to draw on screen
        int lineHeight = (int)(width / perpWallDist);

        //calculate lowest and highest pixel to fill in current stripe
        int drawStart = -lineHeight / 2 + width / 3;
        if (drawStart < 0) drawStart = 0;
        int drawEnd = lineHeight / 2 + width / 3;
        if (drawEnd >= width) drawEnd = width - 1;

        switch (pScene->level.Get(hitPos.x, hitPos.y))
        {
        case '#':  
            br.outline_color[0] = 1.0f;
            br.outline_color[1] = 1.0f;
            br.outline_color[2] = 1.0f;
            br.texture = "assets//wall.png";
            break;

        case 'R':  br.outline_color[0] = 1.0f; br.outline_color[1] = 0.0f; br.outline_color[2] = 0.0f; break;
                      
        case 'G':  br.outline_color[0] = 0.0f; br.outline_color[1] = 1.0f; br.outline_color[2] = 0.0f; break;
                      
        case 'B':  br.outline_color[0] = 0.0f; br.outline_color[1] = 0.0f; br.outline_color[2] = 1.0f; break;
                                     
        default:   br.outline_color[0] = 0.5f; br.outline_color[1] = 1.0f; br.outline_color[2] = 0.5f; break;

        }

        if (side == 1)
        {
            br.outline_color[0] = br.outline_color[0] / 2;
            br.outline_color[1] = br.outline_color[1] / 2;
            br.outline_color[2] = br.outline_color[2] / 2;
        }

        float startY = float(drawStart + y);
        float endY = float(drawEnd + y);
        if (endY > height) endY = height;

        //graphics::drawLine(column + x, y, column + x, startY, sky);
        graphics::drawLine(column + x, startY, column + x, endY, br);
        //graphics::drawLine(column + x, endY, column + x, height + y, floor);
	}

}
