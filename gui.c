// Copyright 2025 Aleksandr Bocharov
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt
// 2025-03-05
// https://github.com/Aleksandr3Bocharov/RefalABBrainfuck

//====================================================================
// Модуль "gui" (GUI raygui raylib версия)
//====================================================================

#include <string.h>
#include <stdbool.h>

#include "raylib.h"

#define RAYGUI_IMPLEMENTATION
#include "raygui/raygui.h"
#undef RAYGUI_IMPLEMENTATION

#include "gui.h"

static const int screenWidth = 1300;
static const int screenHeight = 820;

static Font cyrillicFont;
static float sizeCyrillicFont = 0.0f;

void guiInit(void)
{
    InitWindow(screenWidth, screenHeight, "RefalABEinshteinPuzzle (GUI версия)");
    SetExitKey(0);
    cyrillicFont = LoadFont("fonts/dejavu.fnt");
    SetTargetFPS(60);
    GuiSetFont(cyrillicFont);
    sizeCyrillicFont = (float)cyrillicFont.baseSize + 1.0f;
    GuiSetStyle(DEFAULT, TEXT_SIZE, 20);
}

void guiClose(void)
{
    CloseWindow();
}

bool guiInfo(void)
{
    bool ok = false;
    bool exitWindow = false;
    while (!exitWindow)
    {
        exitWindow = WindowShouldClose();
        const bool enter = IsKeyPressed(KEY_ENTER);
        BeginDrawing();
        ClearBackground(GetColor(GuiGetStyle(DEFAULT, BACKGROUND_COLOR)));
        DrawTextEx(cyrillicFont, "Задача Эйнштейна.", (Vector2){10.0f, 20.0f}, sizeCyrillicFont, 1.0f, DARKGRAY);
        DrawTextEx(cyrillicFont, "Условия:", (Vector2){10.0f, 50.0f}, sizeCyrillicFont, 1.0f, DARKGRAY);
        DrawTextEx(cyrillicFont, "1. Есть 5 домов разных цветов.", (Vector2){10.0f, 80.0f}, sizeCyrillicFont, 1.0f, DARKGRAY);
        DrawTextEx(cyrillicFont, "2. В каждом доме живет по одному человеку, отличающегося от другого по национальности.", (Vector2){10.0f, 110.0f}, sizeCyrillicFont, 1.0f, DARKGRAY);
        DrawTextEx(cyrillicFont, "3. Каждый обитатель пьет только один определенный напиток, курит определенную марку сигарет и держит животное.", (Vector2){10.0f, 140.0f}, sizeCyrillicFont, 1.0f, DARKGRAY);
        DrawTextEx(cyrillicFont, "4. Никто из пяти людей не пьет одинакового напитка, не курит одинаковые сигареты и не держит одинаковых животных.", (Vector2){10.0f, 170.0f}, sizeCyrillicFont, 1.0f, DARKGRAY);
        DrawTextEx(cyrillicFont, "Вопрос: Чья рыба?", (Vector2){10.0f, 230.0f}, sizeCyrillicFont, 1.0f, DARKGRAY);
        DrawTextEx(cyrillicFont, "Подсказки:", (Vector2){10.0f, 290.0f}, sizeCyrillicFont, 1.0f, DARKGRAY);
        DrawTextEx(cyrillicFont, "1. Англичанин живет в красном доме.", (Vector2){10.0f, 320.0f}, sizeCyrillicFont, 1.0f, DARKGRAY);
        DrawTextEx(cyrillicFont, "2. У шведа есть собака.", (Vector2){10.0f, 350.0f}, sizeCyrillicFont, 1.0f, DARKGRAY);
        DrawTextEx(cyrillicFont, "3. Датчанин пьет чай.", (Vector2){10.0f, 380.0f}, sizeCyrillicFont, 1.0f, DARKGRAY);
        DrawTextEx(cyrillicFont, "4. Зеленый дом стоит слева от белого.", (Vector2){10.0f, 410.0f}, sizeCyrillicFont, 1.0f, DARKGRAY);
        DrawTextEx(cyrillicFont, "5. Обитатель зеленого дома пьет кофе.", (Vector2){10.0f, 440.0f}, sizeCyrillicFont, 1.0f, DARKGRAY);
        DrawTextEx(cyrillicFont, "6. Человек, который курит Pall Mall, держит птицу.", (Vector2){10.0f, 470.0f}, sizeCyrillicFont, 1.0f, DARKGRAY);
        DrawTextEx(cyrillicFont, "7.  Обитатель среднего дома пьет молоко.", (Vector2){10.0f, 500.0f}, sizeCyrillicFont, 1.0f, DARKGRAY);
        DrawTextEx(cyrillicFont, "8.  Обитатель желтого дома курит Dunhill.", (Vector2){10.0f, 530.0f}, sizeCyrillicFont, 1.0f, DARKGRAY);
        DrawTextEx(cyrillicFont, "9.  Норвежец живет в первом доме.", (Vector2){10.0f, 560.0f}, sizeCyrillicFont, 1.0f, DARKGRAY);
        DrawTextEx(cyrillicFont, "10. Курильщик Marlboro живет возле того, у кого есть кошка.", (Vector2){10.0f, 590.0f}, sizeCyrillicFont, 1.0f, DARKGRAY);
        DrawTextEx(cyrillicFont, "11. Человек, у которого есть конь, живет возле того, кто курит Dunhill.", (Vector2){10.0f, 620.0f}, sizeCyrillicFont, 1.0f, DARKGRAY);
        DrawTextEx(cyrillicFont, "12. Курильщик Winfield пьет пиво.", (Vector2){10.0f, 650.0f}, sizeCyrillicFont, 1.0f, DARKGRAY);
        DrawTextEx(cyrillicFont, "13. Норвежец живет возле голубого дома.", (Vector2){10.0f, 680.0f}, sizeCyrillicFont, 1.0f, DARKGRAY);
        DrawTextEx(cyrillicFont, "14. Немец курит Rothmans.", (Vector2){10.0f, 710.0f}, sizeCyrillicFont, 1.0f, DARKGRAY);
        DrawTextEx(cyrillicFont, "15. Курильщик Marlboro живет по соседству с человеком, который пьет воду.", (Vector2){10.0f, 740.0f}, sizeCyrillicFont, 1.0f, DARKGRAY);
        if (GuiButton((Rectangle){screenWidth / 2 - 80, 770, 160, 30}, "Решить задачу") || enter)
        {
            ok = true;
            exitWindow = true;
        }
        EndDrawing();
    }
    return ok;
}

int guiView(const char *answer, int steps, int stepsBack, int rule, const char *ruleText, char table[6][150], int position)
{
    int result = 0;
    bool exitWindow = false;
    while (!exitWindow)
    {
        exitWindow = WindowShouldClose();
        BeginDrawing();
        ClearBackground(GetColor(GuiGetStyle(DEFAULT, BACKGROUND_COLOR)));
        DrawTextEx(cyrillicFont, "Вопрос: Чья рыба?", (Vector2){10.0f, 20.0f}, sizeCyrillicFont, 1.0f, DARKGRAY);
        DrawTextEx(cyrillicFont, TextFormat("Ответ: %s имеет рыбу.", answer), (Vector2){10.0f, 60.0f}, sizeCyrillicFont, 1.0f, DARKGRAY);
        DrawTextEx(cyrillicFont, TextFormat("Правило %d: %s", rule, ruleText), (Vector2){10.0f, 140.0f}, sizeCyrillicFont, 1.0f, DARKGRAY);
        for (size_t i = 0; i < 6; i++)
            DrawTextEx(cyrillicFont, table[i], (Vector2){10.0f, 180.0f + 40.0f * (float)i}, sizeCyrillicFont, 1.0f, DARKGRAY);
        GuiButton((Rectangle){10, 420, 50, 30}, GuiIconText(ICON_PLAYER_PREVIOUS, NULL));
        GuiButton((Rectangle){60, 420, 50, 30}, GuiIconText(ICON_PLAYER_PLAY_BACK, NULL));
        GuiButton((Rectangle){110, 420, 50, 30}, GuiIconText(ICON_PLAYER_PLAY, NULL));
        GuiButton((Rectangle){160, 420, 50, 30}, GuiIconText(ICON_PLAYER_NEXT, NULL));
        DrawTextEx(cyrillicFont, TextFormat("Количество шагов без возвращения: %d.", steps), (Vector2){10.0f, 470.0f}, sizeCyrillicFont, 1.0f, DARKGRAY);
        DrawTextEx(cyrillicFont, TextFormat("Количество шагов с возвращением: %d.", stepsBack), (Vector2){10.0f, 510.0f}, sizeCyrillicFont, 1.0f, DARKGRAY);
        EndDrawing();
    }
    return result;
}

bool guiIsExit(void)
{
    bool isExit = true;
    bool exitWindow = false;
    while (!exitWindow)
    {
        exitWindow = WindowShouldClose();
        const bool enter = IsKeyPressed(KEY_ENTER);
        const bool escape = IsKeyPressed(KEY_ESCAPE);
        BeginDrawing();
        ClearBackground(GetColor(GuiGetStyle(DEFAULT, BACKGROUND_COLOR)));
        DrawRectangle(0, 0, screenWidth, screenHeight, Fade(RAYWHITE, 0.8f));
        int result = GuiMessageBox((Rectangle){screenWidth / 2 - 180, screenHeight / 2 - 50, 360, 100}, GuiIconText(ICON_EXIT, "Выход"), "Вы действительно хотите выйти?", "Да;Нет");
        if (result == 0 || result == 1 || result == 2 || enter || escape)
        {
            exitWindow = true;
            if (result == 0 || result == 2 || escape)
                isExit = false;
        }
        EndDrawing();
    }
    return isExit;
}
