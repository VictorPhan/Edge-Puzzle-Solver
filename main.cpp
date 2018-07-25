#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <deque>
#include <algorithm>
#include <iterator>

#include "piece.h"
#include "board.h"
#include "algorithm.h"

using namespace std;

Piece piece_from_line(string line);
void get_pieces(vector<Piece> *pieces, string file);
void get_border(int *border, string file);

int main(int argc, char *argv[]) {
    if (argc != 3) {
        cout << "Usage: ./main piecesFile bordersFile\n";
        return 0;
    }
    vector<Piece> pieces;
    int border [100];
    Board init_board = Board();
    
    get_pieces(&pieces, argv[1]);
    get_border(border, argv[2]);
    init_board.set_border(border);
    Algorithm::solve_board(init_board, pieces);
    
    return 0;
}

//Retrieve border from borders file and store in border vector
void get_border(int *border, string file) {
    int i=0;
    string line;
    ifstream border_file (file);
    if (border_file.is_open()) {
        while (getline(border_file, line)) {
            if (line[0] != '/') {
                stringstream stream(line);
                int num;
                while(stream >> num) {
                    border[i] = num;
                    i++;
                }
            }
        }
        border_file.close();
    }
    else {
        cout << "Unable to open border file";
    }
    // for(int j=0; j<i; j++) {
    //     cout << border[j] << " ";
    // }
    // cout << '\n';
}

// Retrieve pieces from pieces file and store in pieces vector
void get_pieces(vector<Piece> *pieces, string file) {
    string line;
    ifstream piece_file (file);
    if (piece_file.is_open()) {
        while (getline(piece_file, line)) {
            if (line[0] != '/') {
                (*pieces).push_back(piece_from_line(line));
            }
        }
        piece_file.close();
    }
    else {
        cout << "Unable to open pieces file";
    }
}

Piece piece_from_line(string line) {
    stringstream stream(line);
    int val [4];
    for(int i=0; i<4; i++) {
        stream >> val[i];
        if(!stream)
            break;
    }
    return Piece(val[0],val[1],val[2],val[3]);
}