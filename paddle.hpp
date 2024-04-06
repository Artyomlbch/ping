#include "raylib.h"

class Paddle
{
public:

    Paddle(float x, float y, float width, float height, int speed): x(x), y(y), width(width), height(height), speed(speed) {};
    void draw();
    void update_coords();
    float get_x() { return this->x; }
    float get_y() { return this->y; }
    float get_width() { return this->width; }
    float get_height() { return this->height; }

protected:

    float x, y;
    float width, height;
    int speed;

};

class PCPaddle: public Paddle
{
public:

    PCPaddle(float x, float y, float width, float height, int speed): Paddle(x, y, width, height, speed) {};
    void update_coords(int ball_y);

};