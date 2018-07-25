#include <iostream>
#include <string.h>
#include "board.h"

Board::Board(int r, int c) {
    rows = r;
    cols = c;

    constraints = new int**[rows];
    bitmask = new bool*[rows];
    moves = new int*[rows];
    for (int i = 0; i < rows; i++) {
        constraints[i] = new int*[cols];
        bitmask[i] = new bool[cols];
        moves[i] = new int[cols];

        for (int j = 0; j < 4; j++) {
            constraints[i][j] = new int[4];
        }
    }
    for(int i=0; i<rows; i++) {
        for (int j=0; j<cols; j++) {
            for (int k=0; k<4; k++) {
                constraints[i][j][k] = 0;
            }
        }
    }
    // memset(constraints, 0, sizeof(int) * rows * cols * 4);
    // memset(bitmask, 0, sizeof(bool) * rows * cols);
    // memset(moves, 0, sizeof(int) * rows * cols);
    // cout << constraints[0][0][0] << '\n';
}

void Board::set_border(int *border) {
    int it = 0;
    for(int i=0; i<cols; i++) {
        cout << it;
        cout << constraints[0][i][0];
        cout << " ";
        cout << border[it];
        constraints[0][i][0] = border[it];
        cout << it;
        constraints[cols-1][i][2] = border[it+cols];
        it++;
    }
    for(int j=0; j<rows; j++) {
        cout << it;
        constraints[j][0][3] = border[it+rows];
        constraints[j][rows-1][1] = border[it];
        it++;
    }
}

void Board::print_constraints() {
    cout << "Printing constraints\n";
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            for(int k=0; k<4; k++) {
                cout << constraints[i][j][k] << ",";
            }
            cout << "\t\t\t";
        }
        cout << '\n';
    }
}

void Board::free_board() {
    // cout << "1";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            // cout << "2";
            delete [] constraints[i][j];
            // cout << "3";
        }
        // cout << "4";
        delete [] constraints[i];
        delete [] bitmask[i];
        delete [] moves[i];
    }
    // cout << "5";
    delete [] constraints;
    delete [] bitmask;
    delete [] moves;
    // cout << "6";
    cout << "Successfully freed\n";
}