bool* grid{};

void init(int x, int y) {
grid = new bool[x * y]{};
}

void clean() {
    delete[] grid;
}

int main (/*int argc, char* argv[]*/) {
    init(256, 256);
    clean();
}