// Copyright 2025 Aleksandr Bocharov
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt
// 2025-03-25
// https://github.com/Aleksandr3Bocharov/RefalABBrainfuck

//====================================================================
// Модуль "RefalABEinshteinPuzzlec" (GUI версия)
//====================================================================

#include <stdint.h>
#include <stdbool.h>
#include "refalab.h"
#include "gui.h"

extern uint8_t refalab_true, refalab_false;

static uint32_t steps = 0;
static uint32_t steps_Back = 0;
static char answer[21] = {'\0'};
static uint32_t rule = 0;
static uint32_t position = 0;
static char rule_Text[150] = {'\0'};
static char table[6][6][32] = {{{"Дом"}, {"Цвет"}, {"Национальность"}, {"Сигареты"}, {"Животное"}, {"Напиток"}},
                               {{'\0'}, {'\0'}, {'\0'}, {'\0'}, {'\0'}, {'\0'}},
                               {{'\0'}, {'\0'}, {'\0'}, {'\0'}, {'\0'}, {'\0'}},
                               {{'\0'}, {'\0'}, {'\0'}, {'\0'}, {'\0'}, {'\0'}},
                               {{'\0'}, {'\0'}, {'\0'}, {'\0'}, {'\0'}, {'\0'}},
                               {{'\0'}, {'\0'}, {'\0'}, {'\0'}, {'\0'}, {'\0'}}};

// <GUI_Init> ==
static void gui_init_(void)
{
    if (refal.preva->next != refal.nexta)
    {
        refal.upshot = 2;
        return;
    }
    gui_Init();
    return;
}
char gui_init_0[] = {Z0 'G', 'U', 'I', '_', 'I', 'N', 'I', 'T', (char)8};
G_L_B uint8_t refalab_gui_init = '\122';
void (*gui_init_1)(void) = gui_init_;

// <GUI_Close> ==
static void gui_close_(void)
{
    if (refal.preva->next != refal.nexta)
    {
        refal.upshot = 2;
        return;
    }
    gui_Close();
    return;
}
char gui_close_0[] = {Z1 'G', 'U', 'I', '_', 'C', 'L', 'O', 'S', 'E', (char)9};
G_L_B uint8_t refalab_gui_close = '\122';
void (*gui_close_1)(void) = gui_close_;

// <Dialog_Info> == /True/ | /False/
static void dialog_info_(void)
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
    p->tag = TAGF;
    p->info.codep = NULL;
    p->info.codef = &refalab_true;
    if (!dialog_Info())
        p->info.codef = &refalab_false;
    return;
}
char dialog_info_0[] = {Z3 'D', 'I', 'A', 'L', 'O', 'G', '_', 'I', 'N', 'F', 'O', (char)11};
G_L_B uint8_t refalab_dialog_info = '\122';
void (*dialog_info_1)(void) = dialog_info_;

// <View_Answer S(N).Steps S(N).Back E(O).Answer> ==
static void view_answer_(void)
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
        steps_Back = gcoden(p);
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
char view_answer_0[] = {Z3 'V', 'I', 'E', 'W', '_', 'A', 'N', 'S', 'W', 'E', 'R', (char)11};
G_L_B uint8_t refalab_view_answer = '\122';
void (*view_answer_1)(void) = view_answer_;

// <View_Rule S(N).Position S(N).Rule E(O).Text> ==
static void view_rule_(void)
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
            rule_Text[i] = p->info.infoc;
            p = p->next;
        }
        if (neot)
            break;
        rule_Text[i] = '\0';
        return;
    } while (false);
    refal.upshot = 2;
    return;
}
char view_rule_0[] = {Z1 'V', 'I', 'E', 'W', '_', 'R', 'U', 'L', 'E', (char)9};
G_L_B uint8_t refalab_view_rule = '\122';
void (*view_rule_1)(void) = view_rule_;

// <View_Table S(N).Row S(N).Column E(O).Text> ==
static void view_table_(void)
{
    const T_LINKCB *p = refal.preva->next;
    do
    {
        if (p->tag != TAGN)
            break;
        const uint32_t row = gcoden(p);
        if (row < 1 || row > 5)
            break;
        p = p->next;
        if (p->tag != TAGN)
            break;
        const uint32_t col = gcoden(p);
        if (col > 5)
            break;
        p = p->next;
        bool neot = false;
        size_t i;
        for (i = 0; p != refal.nexta; i++)
        {
            if (p->tag != TAGO || i == 31)
            {
                neot = true;
                break;
            }
            table[row][col][i] = p->info.infoc;
            p = p->next;
        }
        if (neot)
            break;
        table[row][col][i] = '\0';
        return;
    } while (false);
    refal.upshot = 2;
    return;
}
char view_table_0[] = {Z2 'V', 'I', 'E', 'W', '_', 'T', 'A', 'B', 'L', 'E', (char)10};
G_L_B uint8_t refalab_view_table = '\122';
void (*view_table_1)(void) = view_table_;

// <View_Show> == 'Q' | 'B' | 'P' | 'N' | 'E'
static void view_show_(void)
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
    p->info.infoc = 'Q';
    const int result = view_Show(answer, steps, steps_Back, rule, rule_Text, table, position);
    if (result == 1)
        p->info.infoc = 'B';
    else if (result == 2)
        p->info.infoc = 'P';
    else if (result == 3)
        p->info.infoc = 'N';
    else if (result == 4)
        p->info.infoc = 'E';
    return;
}
char view_show_0[] = {Z1 'V', 'I', 'E', 'W', '_', 'S', 'H', 'O', 'W', (char)9};
G_L_B uint8_t refalab_view_show = '\122';
void (*view_show_1)(void) = view_show_;

// <Dialog_Is_Exit> == /True/ | /False/
static void dialog_is_exit_(void)
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
    p->tag = TAGF;
    p->info.codep = NULL;
    p->info.codef = &refalab_true;
    if (!dialog_Is_Exit())
        p->info.codef = &refalab_false;
    return;
}
char dialog_is_exit_0[] = {Z6 'D', 'I', 'A', 'L', 'O', 'G', '_', 'I', 'S', '_', 'E', 'X', 'I', 'T', (char)14};
G_L_B uint8_t refalab_dialog_is_exit = '\122';
void (*dialog_is_exit_1)(void) = dialog_is_exit_;
