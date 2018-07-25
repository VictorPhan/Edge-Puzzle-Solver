#include "board.h"

Board::Board() {}

void wait ( int seconds )
{
	clock_t endwait;
	endwait = clock () + seconds * CLOCKS_PER_SEC ;
	while (clock() < endwait) {}
}

bool Board::update_moves(vector<Piece> ps) {
    // wait(1);
    size_t min_move = 0;
    vector<int> count;
    vector<int> tmp;
    bool aswitch = false;
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            if(bitmask[i][j] == 0) {
                aswitch = true;
                for(size_t it=0; it<ps.size(); it++) {
                    tmp = compare(ps[it], constraints[i][j]);
                    count.insert(count.end(), tmp.begin(), tmp.end());
                }
                if (count.size() != 0) {
                    if (count.size() < min_move || min_move == 0) {
                        min_move = count.size();
                        row_move = i;
                        col_move = j;
                    }
                    moves[i][j] = count.size();
                }
                else {
                    return false;
                }
                count.clear();
            }
        }
    }
    if(aswitch == false) {
        // print_constraints();
        // print_bitmask();
    }
    // print_constraints();
    // print_moves();
    // print_bitmask();

    return true;
}

vector<int> Board::compare(Piece p, int *c) {
    vector<int> pos;
    bool cand = true;
    for(int cyc=0; cyc<4; cyc++) {
        for(int i=0; i<4; i++) {
            if(c[i] != 0) {
                // cout << (p.edges[(i+cyc)%4]==c[i]);
                if(!(p.edges[(i+cyc)%4]==c[i])) {
                    cand = false;
                }
            }
        }
        if (cand == true) {
            pos.push_back(cyc);
        }
        else {
            cand = true;
        }
        // cout << "\t";
    }
    // cout << '\n';
    return pos;
}

void Board::set_border(int *border) {
    int it = 0;
    for(int i=0; i<cols; i++) {
        constraints[0][i][0]                = -border[it];
        constraints[cols-1][rows-i-1][2]    = -border[it+rows+cols];
        it++;
    }
    for(int j=0; j<rows; j++) {
        constraints[cols-j-1][0][3]         = -border[it+rows+cols];
        constraints[j][rows-1][1]           = -border[it];
        it++;
    }
}

void Board::print_constraints() {
    cout << "Printing constraints:\n";
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            for(int k=0; k<4; k++) {
                cout << constraints[i][j][k] << ",";
            }
            cout << "\t";
        }
        cout << '\n';
    }
}

void Board::print_moves() {
    cout << "Printing moves:\n";
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            cout << moves[i][j] << ",";
            cout << "\t";
        }
        cout << '\n';
    }
}

void Board::print_bitmask() {
    cout << "Printing bitmask:\n";
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            cout << bitmask[i][j] << ",";
            cout << "\t";
        }
        cout << '\n';
    }
}