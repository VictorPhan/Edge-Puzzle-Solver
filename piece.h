class Piece {
    public:
        Piece(int,int,int,int);
        int* getEdges();
        void printEdges();
    private:
        int edges[4];  // Edge values of a piece
};