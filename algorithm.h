#ifndef __ALGORITHM_H_INCLUDED__
#define __ALGORITHM_H_INCLUDED__

#include <vector>
#include "board.h"
#include "piece.h"

class Algorithm {
    public:
        static void solve_board(Board b, vector<Piece> ps);
        static Board step(Board b, Piece p, int cyc);
    private:
        Algorithm() {}
};

#endif