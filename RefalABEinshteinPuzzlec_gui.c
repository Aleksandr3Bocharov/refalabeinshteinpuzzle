// Copyright 2025 Aleksandr Bocharov
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt
// 2025-03-03
// https://github.com/Aleksandr3Bocharov/RefalABBrainfuck

//====================================================================
// Модуль "RefalABEinshteinPuzzlec" (GUI версия)
//====================================================================

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>
#include "refal.def"
#include "gui.h"

// <Init> ==
static void init_(void)
{
    if (refal.preva->next != refal.nexta)
    {
        refal.upshot = 2;
        return;
    }
    guiInit();
    return;
}
char init_0[] = {Z4 'I', 'N', 'I', 'T', '\004'};
G_L_B uint8_t init = '\122';
void (*init_1)(void) = init_;

// <Close> ==
static void close_(void)
{
    if (refal.preva->next != refal.nexta)
    {
        refal.upshot = 2;
        return;
    }
    guiClose();
    return;
}
char close_0[] = {Z5 'C', 'L', 'O', 'S', 'E', '\005'};
G_L_B uint8_t close = '\122';
void (*close_1)(void) = close_;

// <IsExit> == 'Y' | 'N'
static void isexit_(void)
{
    if (refal.preva->next != refal.nexta)
    {
        refal.upshot = 2;
        return;
    }
    T_LINKCB *p = refal.prevr;
    if (!slins(p, 1))
        return;
    p = p->next;
    p->tag = TAGO;
    p->info.codep = NULL;
    p->info.infoc = 'Y';
    if (!guiIsExit())
        p->info.infoc = 'N';
    return;
}
char isexit_0[] = {Z6 'I', 'S', 'E', 'X', 'I', 'T', '\006'};
G_L_B uint8_t isexit = '\122';
void (*isexit_1)(void) = isexit_;
