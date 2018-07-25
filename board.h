#ifndef __BOARD_H_INCLUDED__
#define __BOARD_H_INCLUDED__

#include <vector>
#include <iostream>
#include <string.h>
#include <tuple>
#include "piece.h"
#include <time.h>

using namespace std;

const int rows = 5;
const int cols = 5;

class Board {
    public:
        Board();
        void set_border(int*);
        void print_constraints();
        void print_moves();
        void print_bitmask();
        bool update_moves(vector<Piece>);
        static vector<int> compare(Piece p, int * c);

        int constraints[rows][cols][4] = {{{0}}};
        bool bitmask[rows][cols] = {{0}};
        int moves[rows][cols] = {{0}};
        int row_move;
        int col_move;
};

#endif