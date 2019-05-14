//
// Created by liu on 18-11-25.
//

int whoWin1(int recordboard[SIZE][SIZE]) {
    int row = 0, column = 0;
    for (row = 0; row < SIZE - 4; ++row) {
        for (column = 0; column < SIZE - 4; ++column) {
            if ((recordboard[row][column] == PLAY1 && recordboard[row][column + 1] == PLAY1 &&
                 recordboard[row][column + 2] == PLAY1 && recordboard[row][column + 3] == PLAY1 &&
                 recordboard[row][column + 4] == PLAY1) ||
                (recordboard[row][column] == PLAY1 && recordboard[row + 1][column] == PLAY1 &&
                 recordboard[row + 2][column] == PLAY1 && recordboard[row + 3][column] == PLAY1
                 && recordboard[row + 4][column] == PLAY1) ||
                (recordboard[row][column] == PLAY1 && recordboard[row + 1][column + 1] == PLAY1 &&
                 recordboard[row + 2][column + 2] == PLAY1 && recordboard[row + 3][column + 3] == PLAY1 &&
                 recordboard[row + 4][column + 4] == PLAY1))
                return PLAY1;
            if ((recordboard[row][column] == PLAY2 && recordboard[row][column + 1] == PLAY2 &&
                 recordboard[row][column + 2] == PLAY2 && recordboard[row][column + 3] == PLAY2 &&
                 recordboard[row][column + 4] == PLAY2) ||
                (recordboard[row][column] == PLAY2 && recordboard[row + 1][column] == PLAY2 &&
                 recordboard[row + 2][column] == PLAY2 && recordboard[row + 3][column] == PLAY2
                 && recordboard[row + 4][column] == PLAY2) ||
                (recordboard[row][column] == PLAY2 && recordboard[row + 1][column + 1] == PLAY2 &&
                 recordboard[row + 2][column + 2] == PLAY2 && recordboard[row + 3][column + 3] == PLAY2 &&
                 recordboard[row + 4][column + 4] == PLAY2))
                return PLAY2;
        }
    }
    for (row = 0; row < SIZE - 4; ++row) {
        for (column = 4; column < SIZE; ++column) {
            if ((recordboard[row][column] == PLAY1 && recordboard[row + 1][column - 1] == PLAY1 &&
                 recordboard[row + 2][column - 2] == PLAY1 && recordboard[row + 3][column - 3] == PLAY1 &&
                 recordboard[row + 4][column - 4] == PLAY1))
                return PLAY1;
            else if ((recordboard[row][column] == PLAY2 && recordboard[row + 1][column - 1] == PLAY2 &&
                      recordboard[row + 2][column - 2] == PLAY2 && recordboard[row + 3][column - 3] == PLAY2 &&
                      recordboard[row + 4][column - 4] == PLAY2))
                return PLAY1;
        }
    }
}

int whoWin()
