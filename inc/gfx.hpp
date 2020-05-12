/**
 * @file gfx.hpp
 * @author Daniel Rahme
 * @date 2020-04-26
 * @brief Graphics library using curses.
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



    template<typename T>
    void loading_bar(T percent)
    {
        for (auto i = 0; i < 100; i++) {
            char symbol = (i < percent) ? 'X' : '-';
            addch(symbol);

            napms(100);
            refresh();
        }
    }


} // end namespace gfx

#endif

