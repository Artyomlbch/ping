#include "paddle.hpp"

void Paddle::draw()
{
    DrawRectangleRounded(Rectangle{x, y, width, height}, 0.8, 0, WHITE);
}

void Paddle::update_coords()
{
    if (IsKeyDown(KEY_DOWN))
    {
        this->y += speed;
        if (this->y + this->height >= GetScreenHeight())
        {
            this->y = GetScreenHeight() - this->height;
        }
    }
    else if (IsKeyDown(KEY_UP))
    {
        this->y -= speed;
        if (this->y <= 0)
        {
            this->y = 0;
        }
    }
}

void PCPaddle::update_coords(int ball_y)
{
    if (this->y + (this->height / 2) >= ball_y)
    {
        this->y -= this->speed;
        if (this->y <= 0)
        {
            this->y = 0;
        }
    }
    if (this->y + (this->height / 2) < ball_y)
    {
        this->y += this->speed;
        if (this->y + this->height >= GetScreenHeight())
        {
            this->y = GetScreenHeight() - this->height;
        }
    }
}

