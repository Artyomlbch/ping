#include "ball.hpp"

void Ball::draw()
{
    DrawCircle(x, y, radius, WHITE);
}

void Ball::update_coords()
{
    this->x += this->speed_x;
    this->y += this->speed_y;

    if (this->y + this->radius >= GetScreenHeight() || y - radius <= 0)
    {
        this->speed_y *= -1;
    }

    if (this->x + this->radius >= GetScreenWidth())
    {
        this->player_score++;
        reset_ball();
    }

    if (this->x - this->radius <= 0)
    {
        this->pc_score++;
        reset_ball();
    }
}

void Ball::reset_ball()
{
    this->y = GetScreenHeight() / 2;
    this->x = GetScreenWidth() / 2;

    this->speed_x = 7;
    this->speed_y = 7;

    int speeds[2] = {-1, 1};
    this->speed_x *= speeds[GetRandomValue(0, 1)];
    this->speed_y *= speeds[GetRandomValue(0, 1)];
}
