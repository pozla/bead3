#include "rules.hpp"

bool Rules::horizontalCheck(int gameData[20][20]) {
    for (int i=0; i<20; i++) {
        for (int j=0; j<16; j++) {
            if ((gameData[i][j] == 1) && (gameData[i][j+1] == 1) && (gameData[i][j+2] == 1) && (gameData[i][j+3] == 1) && (gameData[i][j+4] == 1) ||
                (gameData[i][j] == 2) && (gameData[i][j+1] == 2) && (gameData[i][j+2] == 2) && (gameData[i][j+3] == 2) && (gameData[i][j+4] == 2)) return true;
        }
    }
    return false;
}

bool Rules::verticalCheck(int gameData[20][20]) {
    for (int i=0; i<16; i++) {
        for (int j=0; j<20; j++) {
            if ((gameData[i][j] == 1) && (gameData[i+1][j] == 1) && (gameData[i+2][j] == 1) && (gameData[i+3][j] == 1) && (gameData[i+4][j] == 1) ||
                (gameData[i][j] == 2) && (gameData[i+1][j] == 2) && (gameData[i+2][j] == 2) && (gameData[i+3][j] == 2) && (gameData[i+4][j] == 2)) return true;
        }
    }
    return false;
}

bool Rules::diagonalCheck1(int gameData[20][20]) {
    for (int i=0; i<16; i++) {
        for (int j=0; j<16; j++) {
            if ((gameData[i][j] == 1) && (gameData[i+1][j+1] == 1) && (gameData[i+2][j+2] == 1) && (gameData[i+3][j+3] == 1) && (gameData[i+4][j+4] == 1) ||
                (gameData[i][j] == 2) && (gameData[i+1][j+1] == 2) && (gameData[i+2][j+2] == 2) && (gameData[i+3][j+3] == 2) && (gameData[i+4][j+4] == 2)) return true;
        }
    }
    return false;
}

bool Rules::diagonalCheck2(int gameData[20][20]) {
    for (int i=0; i<16; i++) {
        for (int j=4; j<20; j++) {
            if ((gameData[i][j] == 1) && (gameData[i+1][j-1] == 1) && (gameData[i+2][j-2] == 1) && (gameData[i+3][j-3] == 1) && (gameData[i+4][j-4] == 1) ||
                (gameData[i][j] == 2) && (gameData[i+1][j-1] == 2) && (gameData[i+2][j-2] == 2) && (gameData[i+3][j-3] == 2) && (gameData[i+4][j-4] == 2)) return true;
        }
    }
    return false;
}

bool Rules::fullCheck(int gameData[20][20]) {
    for (int i=0; i<20; i++) {
        for (int j=4; j<20; j++) {
            if (gameData[i][j] == 0) return false;
        }
    }
    return true;
}
