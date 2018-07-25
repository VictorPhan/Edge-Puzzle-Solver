#include "algorithm.h"

void Algorithm::solve_board(Board b, vector<Piece> pieces) {
    // b.print_constraints();
    // cout << b.update_moves(pieces);
    // b.print_moves();
    // cout << pieces.size() << '\n';
    if(pieces.size() == 1) {
        b.print_constraints();
        b.print_bitmask();
        pieces[0].printEdges();
    }
    if(pieces.size() == 0) {
        b.print_constraints();
        b.print_bitmask();
    }
    if(b.update_moves(pieces)) {
        // b.print_constraints();
        vector<int> tmp;
        // cout << "Row: " << b.row_move << '\n';
        // cout << "Col: " << b.col_move << '\n';
        for(size_t it=0; it<pieces.size(); it++) {
            tmp = Board::compare(pieces[it], 
                b.constraints[b.row_move][b.col_move]);
            if(tmp.size() > 0) {
                for(size_t at=0; at<tmp.size(); at++) {
                    vector<Piece> pieces_cpy = pieces;
                    Board next = Algorithm::step(b, pieces[it], tmp[at]);
                    next.bitmask[b.row_move][b.col_move] = 1;
                    pieces_cpy.erase(pieces_cpy.begin() + it);
                    solve_board(next, pieces_cpy);
                }
            }
        }
    }
}

Board Algorithm::step(Board b, Piece p, int cyc) {
    for(int i=0; i<4; i++) {
        b.constraints[b.row_move][b.col_move][i] = p.edges[(i+cyc)%4];
    }

    // Handle rows
    if(b.row_move == 0) {
        b.constraints[b.row_move+1][b.col_move][0] = -b.constraints[b.row_move][b.col_move][2];
    }
    else if(b.row_move == rows-1) {
        b.constraints[b.row_move-1][b.col_move][2] = -b.constraints[b.row_move][b.col_move][0];
    }
    else {
        b.constraints[b.row_move+1][b.col_move][0] = -b.constraints[b.row_move][b.col_move][2];
        b.constraints[b.row_move-1][b.col_move][2] = -b.constraints[b.row_move][b.col_move][0];
    }

    // Then columns
    if(b.col_move == 0) {
        b.constraints[b.row_move][b.col_move+1][3] = -b.constraints[b.row_move][b.col_move][1];
    }
    else if(b.col_move == cols-1) {
        b.constraints[b.row_move][b.col_move-1][1] = -b.constraints[b.row_move][b.col_move][3];
    }
    else {
        b.constraints[b.row_move][b.col_move+1][3] = -b.constraints[b.row_move][b.col_move][1];
        b.constraints[b.row_move][b.col_move-1][1] = -b.constraints[b.row_move][b.col_move][3];
    }

    return b;
}