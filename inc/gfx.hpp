/**
 * @file gfx.hpp
 * @author Daniel Rahme
 * @date 2020-04-26
 * @brief Wrappers for curses functions.
 */

#ifndef GFX_H
#define GFX_H

#include <ncurses.h>

namespace gfx 
{
    auto init = []() -> void
    {
        initscr();              // Start curses mode
        raw();                  // Line buffering disabled
        keypad(stdscr, TRUE);   // We get F1, F2 etc..
        noecho();               // Don't echo() while we do getch
    };


    auto get_kb = []() -> char
    {
        return getch();
    };


    auto add_char = [](char chr) -> void
    {
        addch(chr);
    };


    auto move_cursor = [](int x, int y) -> void
    {
        move(y, x);
    };


    auto mv_add_char = [](int x, int y, char chr) -> void
    {
        mvaddch(y, x, chr);
    };

    auto mv_add_str = [](int x, int y, auto str) -> void
    {
        mvaddstr(y, x, str);
    };

    auto update = []() -> void
    {
        refresh();
    };
    
    auto get_ch = []() -> void
    {
        getch();
    };


    auto close = []() -> void
    {
        endwin();
    };
    

    auto print = [](auto msg) -> void
    {
        printw(msg);
    };

    auto printc = [](char chr) -> void
    {
        printw("%c", chr);
    };


    auto attribute_on = [](auto attr) -> void
    {
        attron(attr);
    };

    auto attribute_off = [](auto attr) -> void
    {
        attroff(attr);
    };
} // end namespace gfx

#endif

