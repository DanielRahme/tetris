/**
 * @file hello.cpp
 * @author Daniel Rahme
 * @date 2020-04-26
 * @brief A tetris game using NCurses.
 */

#include <iostream>
#include <array>
#include <ncurses.h>

#include "functions.hpp"
#include "gfx.hpp"


auto add_shape(int x=0, int y=0)
{
    using shape_t = std::array<bool, 8>;


    shape_t shape = {1,1,0,0,
                     1,1,0,0};

    const char sym = 'x';

    for (auto i = 0; i < 2; i++) {
        gfx::move_cursor(x, ++y);
        for (auto j = 0; j < 4; j++) {
            if (shape[i*4 + j]) 
                gfx::add_char(sym);
            else
                gfx::add_char('k');
        }
    }

}



auto main() -> int
{
    gfx::init();
    
    add_shape(0, 10);
    add_shape(0, 20);

    mvaddstr(1, 0, "Type any character to see it in bold\n");
    auto ch = gfx::get_kb();

    if(ch == KEY_F(1))		/* Without keypad enabled this will */
        printw("F1 Key pressed");/*  not get to us either	*/
    /* Without noecho() some ugly escape
     * charachters might have been printed
     * on screen			*/
    else
    {	printw("The pressed key is ");
        attron(A_BOLD);
        printw("%c", ch);
        attroff(A_BOLD);
    }
    refresh();			/* Print it on to the real screen */
    getch();			/* Wait for user input */
    endwin();			/* End curses mode		  */

    return 0;
}
