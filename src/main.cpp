#include <stdio.h>
#include <algorithm>
#include <utility>
#include <vector>

int xMax = 100;
int yMax = 100;

int neighbours(const std::vector<std::pair<int, int>>& curGen, std::pair<int, int> cell) {
    std::vector<std::pair<int, int>>::const_iterator directions[8] {
    // (0,0) starts in the upper left corner
    std::find(begin(curGen), end(curGen), std::pair(cell.first - 1, cell.second - 1)),
    std::find(begin(curGen), end(curGen), std::pair(cell.first, cell.second - 1)),
    std::find(begin(curGen), end(curGen), std::pair(cell.first + 1, cell.second - 1)),
    std::find(begin(curGen), end(curGen), std::pair(cell.first + 1, cell.second)),
    std::find(begin(curGen), end(curGen), std::pair(cell.first + 1, cell.second + 1)),
    std::find(begin(curGen), end(curGen), std::pair(cell.first, cell.second + 1)),
    std::find(begin(curGen), end(curGen), std::pair(cell.first - 1, cell.second + 1)),
    std::find(begin(curGen), end(curGen), std::pair(cell.first - 1, cell.second))
    };
    int counter{0};
    for (int i{0}; i < sizeof(directions)/sizeof(directions[0]); ++i) {
        if (directions[i] != end(curGen))
            counter++;
    }
    return counter;
}

std::vector<std::pair<int, int>> nextGen(const std::vector<std::pair<int, int>>& curGen) {

}

int main (/*int argc, char* argv[]*/) {
    printf("Hello World!");
}