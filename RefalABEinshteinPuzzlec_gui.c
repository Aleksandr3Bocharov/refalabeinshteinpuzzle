// Copyright 2025 Aleksandr Bocharov
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt
// 2025-03-05
// https://github.com/Aleksandr3Bocharov/RefalABBrainfuck

//====================================================================
// Модуль "RefalABEinshteinPuzzlec" (GUI версия)
//====================================================================

#include <stdint.h>
#include <stdbool.h>
#include "refal.def"
#include "gui.h"

static int steps = 0;
static int stepsBack = 0;
static char answer[21] = {'\0'};
static int rule = 0;
static int position = 0;
static char ruleText[150] = {'\0'};
static char table[6][150] = { "Home Color  Nationality Cigarettes Pet   Drink",
                              {'\0'}, {'\0'}, {'\0'}, {'\0'}, {'\0'} };

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

// <Info> == 'Y' | 'N'
static void info_(void)
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
    if (!guiInfo())
        p->info.infoc = 'N';
    return;
}
char info_0[] = {Z4 'I', 'N', 'F', 'O', '\004'};
G_L_B uint8_t info = '\122';
void (*info_1)(void) = info_;

// <VAnswer S(N)S S(N)B E(O)A> ==
static void vanswer_(void)
{
    const T_LINKCB *p = refal.preva->next;
    do
    {
        if (p->tag != TAGN)
            break;
        steps = gcoden(p);
        p = p->next;
        if (p->tag != TAGN)
            break;
        stepsBack = gcoden(p);
        p = p->next;
        bool neot = false;
        size_t i;
        for (i = 0; p != refal.nexta; i++)
        {
            if (p->tag != TAGO || i == 20)
            {
                neot = true;
                break;
            }
            answer[i] = p->info.infoc;
            p = p->next;
        }
        if (neot)
            break;
        answer[i] = '\0';
        return;
    } while (false);
    refal.upshot = 2;
    return;
}
char vanswer_0[] = {Z7 'V', 'A', 'N', 'S', 'W', 'E', 'R', '\007'};
G_L_B uint8_t vanswer = '\122';
void (*vanswer_1)(void) = vanswer_;

// <VRule S(N)P S(N)R E(O)T> ==
static void vrule_(void)
{
    const T_LINKCB *p = refal.preva->next;
    do
    {
        if (p->tag != TAGN)
            break;
        position = gcoden(p);
        if (position > 2)
            break;
        p = p->next;
        if (p->tag != TAGN)
            break;
        rule = gcoden(p);
        if (rule > 16)
            break;
        p = p->next;
        bool neot = false;
        size_t i;
        for (i = 0; p != refal.nexta; i++)
        {
            if (p->tag != TAGO || i == 149)
            {
                neot = true;
                break;
            }
            ruleText[i] = p->info.infoc;
            p = p->next;
        }
        if (neot)
            break;
        ruleText[i] = '\0';
        return;
    } while (false);
    refal.upshot = 2;
    return;
}
char vrule_0[] = {Z5 'V', 'R', 'U', 'L', 'E', '\005'};
G_L_B uint8_t vrule = '\122';
void (*vrule_1)(void) = vrule_;

// <VTable S(N)R E(O)T> ==
static void vtable_(void)
{
    const T_LINKCB *p = refal.preva->next;
    do
    {
        if (p->tag != TAGN)
            break;
        const int row = gcoden(p);
        if (row < 1 || row > 5)
            break;
        p = p->next;
        bool neot = false;
        size_t i;
        for (i = 0; p != refal.nexta; i++)
        {
            if (p->tag != TAGO || i == 149)
            {
                neot = true;
                break;
            }
            table[row][i] = p->info.infoc;
            p = p->next;
        }
        if (neot)
            break;
        table[row][i] = '\0';
        return;
    } while (false);
    refal.upshot = 2;
    return;
}
char vtable_0[] = {Z6 'V', 'T', 'A', 'B', 'L', 'E', '\006'};
G_L_B uint8_t vtable = '\122';
void (*vtable_1)(void) = vtable_;

// <View> == 'Y' | 'N'
static void view_(void)
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
    guiView(answer, steps, stepsBack, rule, ruleText, table, position);
    return;
}
char view_0[] = {Z4 'V', 'I', 'E', 'W', '\004'};
G_L_B uint8_t view = '\122';
void (*view_1)(void) = view_;

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
