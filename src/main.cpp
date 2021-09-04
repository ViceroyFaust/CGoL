#include <algorithm>
#include <stdio.h>

int main(/*int argc, char* argv[]*/) {
    // Row-Major order. Formula is [col + num_columns * row]
    int y = 256;
    int x = 256;
    int generations = 4;
    bool* curGrid = new bool[y * x]();
    bool* newGrid = new bool[y * x]();
    // Constructing a 5x5 square with no corners
    curGrid[5 + x * 3];
    curGrid[6 + x * 3];
    curGrid[7 + x * 3];
    curGrid[4 + x * 4];
    curGrid[8 + x * 4];
    curGrid[4 + x * 5];
    curGrid[8 + x * 5];
    curGrid[4 + x * 6];
    curGrid[8 + x * 6];
    curGrid[5 + x * 7];
    curGrid[6 + x * 7];
    curGrid[7 + x * 7];
    // Num of gen repetitions
    for (int i = 0; i < generations; ++i) {
        // Generation loop
        for (int row = 1; row < y - 1; ++row) {
            for (int col = 1; col < x - 1; ++col) {
                int neighbours = 0;
                for (int nRow = row - 1; nRow < row + 1; ++nRow) {
                    for (int nCol = col - 1; nCol < col + 1; ++nCol) {
                        if (nRow == row && nCol == col)
                            continue;
                        if (curGrid[nCol + x * nRow])
                            ++neighbours;
                    }
                }
                if ((neighbours == 3) || (neighbours == 2 && curGrid[col + x * row]))
                    newGrid[col + x * row] = true;
                else
                    newGrid[col + x * row] = false;
            }
        }
        std::swap(curGrid, newGrid);
    }
    // print loop for all of the final live cell points
    for (int row = 1; row < y - 1; ++row)
        for (int col = 1; col < x - 1; ++col)
            if (curGrid[col + x * row])
                std::printf("(row: %d, col: %d\n", row, col);
}