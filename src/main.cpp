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
#include "tetris.hpp"


auto main() -> int
{
    gfx::init();
    
    add_shape(0, 10);
    add_shape(0, 20);

    gfx::mv_add_str(1, 0, "Type any character to see it in bold\n");
    auto ch = gfx::get_kb();

    if(ch == KEY_F(1))		/* Without keypad enabled this will */
        gfx::print("F1 Key pressed");/*  not get to us either	*/
    /* Without noecho() some ugly escape
     * charachters might have been printed
     * on screen			*/
    else
    {	
        //printw("The pressed key is ");
        gfx::print("The pressed key is: ");
        gfx::attribute_on(A_BOLD);
        gfx::printc(ch);
        gfx::attribute_off(A_BOLD);
    }

    gfx::update();
    gfx::get_ch();
    gfx::close();

    return 0;
}
