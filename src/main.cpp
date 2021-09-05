#include <algorithm>
#include <stdio.h>

int main(/*int argc, char* argv[]*/) {
    // Row-Major order. Formula is [col + num_columns * row]
    int num_rows = 11;
    int num_columns = 11;
    int generations = 4;
    bool* curGrid = new bool[num_rows * num_columns]();
    bool* newGrid = new bool[num_rows * num_columns]();
    // Constructing a 5x5 square with no corners
    curGrid[4 + num_columns * 3] = true;
    curGrid[5 + num_columns * 3] = true;
    curGrid[6 + num_columns * 3] = true;
    curGrid[3 + num_columns * 4] = true;
    curGrid[7 + num_columns * 4] = true;
    curGrid[3 + num_columns * 5] = true;
    curGrid[7 + num_columns * 5] = true;
    curGrid[3 + num_columns * 6] = true;
    curGrid[7 + num_columns * 6] = true;
    curGrid[4 + num_columns * 7] = true;
    curGrid[5 + num_columns * 7] = true;
    curGrid[6 + num_columns * 7] = true;
    // Num of gen repetitions
    for (int i = 0; i < generations; ++i) {
        // Generation loop
        for (int row = 1; row < num_rows - 1; ++row) {
            for (int col = 1; col < num_columns - 1; ++col) {
                int neighbours = 0;
                for (int nRow = row - 1; nRow <= row + 1; ++nRow) {
                    for (int nCol = col - 1; nCol <= col + 1; ++nCol) {
                        if (nRow == row && nCol == col)
                            continue;
                        if (curGrid[nCol + num_columns * nRow])
                            ++neighbours;
                    }
                }
                if ((neighbours == 3) || (neighbours == 2 && curGrid[col + num_columns * row]))
                    newGrid[col + num_columns * row] = true;
                else
                    newGrid[col + num_columns * row] = false;
            }
        }
        std::swap(curGrid, newGrid);
    }
    // print loop for all of the final live cell points
    for (int row = 0; row < num_rows; ++row) {
        for (int col = 0; col < num_columns; ++col) {
            if (curGrid[col + num_columns * row])
                printf("X ");
            else
                printf(". ");
        }
        printf("\n");
    }
}