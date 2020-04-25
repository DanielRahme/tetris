/**
 * @file hello.cpp
 * @author Daniel Rahme
 * @date 2019-04-29
 * @brief A hello world program.
 */

#include <iostream>
#include "functions.hpp"
#include <ncurses.h>


static void wait(const unsigned long long delay)
{
    for (volatile unsigned long long i = 0; i < delay; i++);
}


int main()
{
    func::print_hello("World");

    constexpr auto f = []{ std::cout << "Just a lambda\n"; }; 
    f();

    std::cout << "Square of 3 == " << func::square(3) << '\n';


    int ch;

    initscr();			/* Start curses mode 		*/
    raw();				/* Line buffering disabled	*/
    keypad(stdscr, TRUE);		/* We get F1, F2 etc..		*/
    noecho();			/* Don't echo() while we do getch */

    for (auto i = 0; i < 80; i++) {
        addch('X');
        wait(100000000);
        refresh();			/* Print it on to the real screen */
    }





    mvaddstr(1, 0, "Type any character to see it in bold\n");
    ch = getch();			/* If raw() hadn't been called
                                         * we have to press enter before it
                                         * gets to the program 		*/
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
