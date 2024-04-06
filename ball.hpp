#include "raylib.h"

class Ball
{
public:

    Ball(int width, int height, int radius, int speed_x, int speed_y) : x(width / 2), y(height / 2), radius(radius), speed_x(speed_x), speed_y(speed_y) {};
    void draw();
    void update_coords();
    void reset_ball();

    float get_y() { return this-> y; }
    float get_x() { return this-> x; }
    int get_radius() { return this-> radius; }
    int get_speed() { return this->speed_x; }
    int get_player_score() { return this->player_score; }
    int get_pc_score() { return this->pc_score; }
    void set_speed(int speed) { this->speed_x = speed; }


private:

    float x, y;
    int speed_x, speed_y;
    int radius;
    int player_score = 0;
    int pc_score = 0;

};