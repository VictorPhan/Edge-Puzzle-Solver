#include <iostream>
#include "piece.h"

Piece::Piece(int a, int b, int c, int d) {
    edges[0] = a;
    edges[1] = b;
    edges[2] = c;
    edges[3] = d;
}

void Piece::printEdges() {
    for (int i=0; i<3; i++) {
        std::cout << edges[i] << ' ';
    }
    std::cout << edges[3] << '\n';
}