/**
 * @file hello.cpp
 * @author Daniel Rahme
 * @date 2020-04-26
 * @brief A tetris game using NCurses.
 */

#include <iostream>
#include <ncurses.h>

#include "functions.hpp"
#include "gfx.hpp"



auto main() -> int
{
    func::print_hello("World");

    constexpr auto f = []{ std::cout << "Just a lambda\n"; }; 
    f();

    std::cout << "Square of 3 == " << func::square(3) << '\n';

    gfx::init();
    gfx::loading_bar(50);

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
