# Edge Puzzle Solver

## The puzzle specification
The tiling puzzle requires the assembly of oddly shaped interlocking pieces onto a grid.
The boundary of the grid itself also has oddly shaped edges.


## How to use the program
The pieces is specified in a text file with integers representing edges
(positive and negative integers of the same magnitude indicate edges that can interlock with one another,
e.g. 1 can interlock with -1, 2 with -2, and so on).
The edges of the piece are separated by whitespace and the pieces are separated by rows.

The border is specified by the edge type that will fit into the border in a clockwise order around the board,
edges separated by whitespace and the sides of the border separated by rows.

To call the program, pass in the piecesFile and bordersFile into `main` like so after building with `make`:
`./main piecesFile bordersFile`

## File Structure
* `Makefile`: compile and build the main program and its dependencies.
* `algorithm.cpp`: the program's solution search mechanism.
* `board.cpp`: board representation and board manipulation operations.
* `piece.cpp`: piece representation and print operations.
