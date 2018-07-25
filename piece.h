#ifndef __PIECE_H_INCLUDED__
#define __PIECE_H_INCLUDED__

class Piece {
    public:
        Piece(int,int,int,int);
        void printEdges();
        int edges[4];  // Edge values of a piece
};

#endif