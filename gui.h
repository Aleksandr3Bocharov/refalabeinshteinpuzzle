// Copyright 2025 Aleksandr Bocharov
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt
// 2025-03-25
// https://github.com/Aleksandr3Bocharov/RefalABBrainfuck

//====================================================================
// Модуль "gui" (GUI raygui raylib версия)
//====================================================================

#ifndef GUI_H
#define GUI_H

#include <stdint.h>
#include <stdbool.h>

extern bool dialog_Info(void);
extern bool dialog_Is_Exit(void);
extern void gui_Close(void);
extern void gui_Init(void);
extern int view_Show(const char *answer, uint32_t steps, uint32_t steps_Back, uint32_t rule, const char *rule_Text, char table[6][6][32], uint32_t position);

#endif
