// Copyright 2025 Aleksandr Bocharov
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt
// 2025-03-05
// https://github.com/Aleksandr3Bocharov/RefalABBrainfuck

//====================================================================
// Модуль "gui" (GUI raygui raylib версия)
//====================================================================

#ifndef GUI_H
#define GUI_H

#include <stdbool.h>

extern void guiClose(void);
extern bool guiInfo(void);
extern void guiInit(void);
extern bool guiIsExit(void);
extern int guiView(const char *answer, int steps, int stepsBack, int rule, const char *ruleText, char table[6][6][32], int position);

#endif
