/**
 * @file gfx.hpp
 * @author Daniel Rahme
 * @date 2020-04-26
 * @brief Graphics library using curses.
 */

#ifndef GFX_H
#define GFX_H

namespace gfx 
{
    auto init = []() -> void
    {
        initscr();              // Start curses mode
        raw();                  // Line buffering disabled
        keypad(stdscr, TRUE);   // We get F1, F2 etc..
        noecho();               // Don't echo() while we do getch
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

