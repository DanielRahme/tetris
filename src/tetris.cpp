/**
 * @file tetris.cpp
 * @author Daniel Rahme
 * @date 2020-05-12
 * @brief The tetris related game mechanics and functions.
 */

// TODO: 
// Add all shapes
// Random shape generator
// Move shapes
// Add collision
// Score board

#include "tetris.hpp"
#include <array>
#include "gfx.hpp"

//#include "gfx.hpp"
//#include <array>

void add_shape(int x=0, int y=0)
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
