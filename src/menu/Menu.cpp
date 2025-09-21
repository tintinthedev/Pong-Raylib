#include "Menu.h"
#include <raylib.h>

void Menu::DrawScore(int score, int fontSize, int x, int y)
{
    DrawText(TextFormat("%i", score), x, y, fontSize, WHITE);
}