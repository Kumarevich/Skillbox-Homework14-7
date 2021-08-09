#include <iostream>

bool checking(bool matrix[12][12]) {
    int result = 0;
    for (int i = 0; i < 12; ++i) {
        for (int j = 0; j < 12; ++j) {
            if (matrix[i][j]) {
                std::cout << "o ";
                ++result;
            } else {
                std::cout << "x ";
            }
        }
        std::cout << std::endl;
    }
    if (result == 0) {
        return true;
    } else {
        return false;
    }
}

bool check_input(int x1, int y1, int x2, int y2) {
    if (x1 < 1 || x1 > 12 || y1 < 1 || y1 > 12 || x2 < 1 || x2 > 12 || y2 < 1 || y2 > 12 || x1 > x2 || y1 > y2) {
        return false;
    }
    return true;
}

void bursting_bubble(bool matrix[12][12], int x1, int y1, int x2, int y2) {
    for (int i = x1 - 1; i < x2; ++i) {
        for (int j = y1 - 1; j < y2; ++j) {
             matrix[i][j] = false;
        }
    }
}

int main() {
    bool bubbleWrap[12][12];
    for (int i = 0; i < 12; ++i) {
        for (int j = 0; j < 12; ++j) {
            bubbleWrap[i][j] = true;
        }
    }

    int x1, x2, y1, y2;

    while (!checking(bubbleWrap)) {
        std::cout << "Input first and last points (x1, y1, x2, y2): ";
        std::cin >> x1 >> y1 >> x2 >> y2;
        while (!check_input(x1, y1, x2, y2)) {
            std::cout << "Wrong input. Try again in [1..12] range: ";
            std::cin >> x1 >> y1 >> x2 >> y2;
        }
        bursting_bubble(bubbleWrap, x1, y1, x2, y2);
    }

    return 0;
}
