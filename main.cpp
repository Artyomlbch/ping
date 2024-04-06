#include <iostream>
#include "raylib.h"
#include "ball.hpp"
#include "paddle.hpp"

int main()
{
    const int SCREEN_WIDTH = 1280;
    const int SCREEN_HEIGHT = 800;
    int FPS = 60;
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Ping-Pong");
    SetTargetFPS(FPS);

    Ball ball(SCREEN_WIDTH, SCREEN_HEIGHT, 20, 10, 7);
    Paddle paddle_player(10, (SCREEN_HEIGHT / 2) - 60, 25, 120, 6);
    PCPaddle paddle_pc(SCREEN_WIDTH - 35, (SCREEN_HEIGHT / 2 ) - 60, 25, 120, 7);

    Color light_blue{66, 218, 218};
    Color blue_darker{54, 188, 188};

    while (!WindowShouldClose())
    {
        BeginDrawing();

        ball.update_coords();
        paddle_player.update_coords();
        paddle_pc.update_coords(ball.get_y());

        if (CheckCollisionCircleRec(Vector2{ball.get_x(), ball.get_y()}, ball.get_radius(), Rectangle{paddle_player.get_x(), paddle_player.get_y(), paddle_player.get_width(), paddle_player.get_height()}))
        {
            ball.set_speed(ball.get_speed() * (-1));
            if (ball.get_speed() < 0)
            {
                ball.set_speed(ball.get_speed() - 1);
            }
            else
            {
                    ball.set_speed(ball.get_speed() + 1);
            }
        }

        if (CheckCollisionCircleRec(Vector2{ball.get_x(), ball.get_y()}, ball.get_radius(), Rectangle{paddle_pc.get_x(), paddle_pc.get_y(), paddle_pc.get_width(), paddle_pc.get_height()}))
        {
            ball.set_speed(ball.get_speed() * (-1));
            if (ball.get_speed() < 0)
            {
                ball.set_speed(ball.get_speed() - 1);
            }
            else
            {
                    ball.set_speed(ball.get_speed() + 1);
            }
        }

        ClearBackground(blue_darker);
        DrawLine(SCREEN_WIDTH / 2, 0, SCREEN_WIDTH / 2, SCREEN_HEIGHT, WHITE);
        ball.draw();
        paddle_player.draw();
        paddle_pc.draw();
        DrawText(TextFormat("%d", ball.get_player_score()), (SCREEN_WIDTH / 2) - 100, 20, 80, WHITE);
        DrawText(TextFormat("%d", ball.get_pc_score()), (SCREEN_WIDTH / 2) + 60, 20, 80, WHITE);        

        EndDrawing();
    }

    CloseWindow();
    return 0;
}