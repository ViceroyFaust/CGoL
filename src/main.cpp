#include <algorithm>

int main(/*int argc, char* argv[]*/) {
    // Row-Major order. Formula is [col + num_columns * row]
    int y = 256;
    int x = 256;
    int generations = 8;
    bool* curGrid = new bool[y * x]();
    bool* newGrid = new bool[y * x]();
    for (int i = 0; i < generations; ++i) {
        int neighbours = 0;
        // Generation loop
        for (int row = 1; row < y - 1; ++row) {
            for (int col = 1; col < x - 1; ++col) {
                for (int nRow = row - 1; nRow < row + 1; ++nRow) {
                    for (int nCol = col - 1; nCol < col + 1; ++nCol) {
                        if (nRow == row && nCol == col)
                            continue;
                        if (curGrid[nCol + x * nRow])
                            ++neighbours;
                    }
                }
                if (curGrid[col + x * row])
                    if (neighbours == 2 || neighbours == 3)
                        newGrid[col + x * row] = true;
                    else if (neighbours == 3)
                        newGrid[col + x * row] = true;
                neighbours = 0;
            }
        }
        std::swap(curGrid, newGrid);
        std::fill(newGrid, newGrid + y * x, false);
    }
}