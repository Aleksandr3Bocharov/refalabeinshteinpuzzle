// Copyright 2025 Aleksandr Bocharov
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt
// 2025-03-03
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

static const int screenWidth = 1024;
static const int screenHeight = 360;

static Font cyrillicFont;

static void setStyle(void)
{
    GuiSetFont(cyrillicFont);
    GuiSetStyle(DEFAULT, TEXT_SIZE, 20);
}

void guiInit(void)
{
    InitWindow(screenWidth, screenHeight, "RefalABEinshteinPuzzle (GUI версия)");
    SetExitKey(0);
    cyrillicFont = LoadFont("fonts/dejavu.fnt");
    SetTargetFPS(60);
    setStyle();
}

void guiClose(void)
{
    CloseWindow();
}

bool guiInfo(void)
{
    bool ok = true;
    bool exitWindow = false;
    while (!exitWindow)
    {
        exitWindow = WindowShouldClose();
        const bool enter = IsKeyPressed(KEY_ENTER);
        BeginDrawing();
        
        EndDrawing();
    }
    return ok;
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
