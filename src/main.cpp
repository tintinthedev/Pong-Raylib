#include <raylib.h>
#include "globals/globals.h"
#include "entities/Ball.h"
#include "entities/Paddle.h"
#include "entities/Enemy.h"
#include "menu/Menu.h"

int main()
{
  InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE);
  SetTargetFPS(60);

  Paddle* player = new Paddle(20, WINDOW_HEIGHT / 2 - 50, 20, 100);
  Enemy* enemy = new Enemy(WINDOW_WIDTH - 20 * 2, (WINDOW_HEIGHT - 100) / 2, 20, 100);

  std::vector<Paddle*> colliders = {player, enemy};
  Ball* ball = new Ball(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2, 7, 7, 20, colliders);

  int playerScore = 0;
  int aiScore = 0;

  do
  {
    BeginDrawing();
    ClearBackground(DarkGreen);

    DrawRectangle(0, 0, GetScreenWidth() / 2, GetScreenHeight(), Green);

    DrawCircle(GetScreenWidth() / 2, GetScreenHeight() / 2, 130, LightGreen);

    ball->Draw();
    ball->Update();

    player->Draw();
    player->Update();

    enemy->Draw();
    enemy->Update(*ball);

    if(ball->x >= GetScreenWidth())
    {
      playerScore++;
      ball->reset();
    }

    if(ball->x <= 0)
    {
      aiScore++;
      ball->reset();
    }

    Menu().DrawScore(playerScore, 50, GetScreenWidth() / 4, 50);
    Menu().DrawScore(aiScore, 50, GetScreenWidth() / 2 + GetScreenWidth() / 4, 50);

    EndDrawing();
  } while(!WindowShouldClose());

  CloseWindow();
  return 0;
}