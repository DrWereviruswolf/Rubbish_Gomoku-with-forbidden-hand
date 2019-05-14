//
// Created by liu on 18-12-13.
//
#include <stdlib.h>
#include "AI.h"
#include "value.h"
#include "forbiddenHand.h"


int value[3][10];
int myBoardScore[SIZE][SIZE];

void valuation(void) {
    value[2][1] = 0;
    value[2][2] = 0;
    value[2][3] = 0;
    value[2][4] = 0;
    value[2][5] = 10023;

    value[1][1] = 0;
    value[1][2] = 1;
    value[1][3] = 10;
    value[1][4] = 100;
    value[1][5] = 10023;

    value[0][1] = 1;
    value[0][2] = 10;
    value[0][3] = 99;
    value[0][4] = 1000;
    value[0][5] = 10023;
    for (int i = 0; i < 3; ++i) {
        for (int j = 6; j < 10; ++j) {
            value[i][j] = 10023;
        }
    }

}
//3 is oppNum;6 is linkNumber


#include <stdio.h>

struct singleInfo horizInfo(int row, int column, int who) {
    struct singleInfo temp;
    int i, j;
    for (i = 1; i < 5 && column + i < SIZE && aRecordBoard[row][column + i] == who; i++);
    for (j = 1; j < 5 && column - j >= 0 && aRecordBoard[row][column - j] == who; ++j);
    temp.linkNum = i + j - 1;
    temp.oppNum = 0;
    if (column + i == SIZE) {
        temp.oppNum = 1;
    } else {
        if (aRecordBoard[row][column + i] != 0)
            temp.oppNum = 1;
    }
    if (column - j == -1) {
        temp.oppNum++;
    } else {
        if (aRecordBoard[row][column - j] != 0)
            temp.oppNum++;
    }
    return temp;
}

struct singleInfo vertInfo(int row, int column, int who) {
    struct singleInfo temp;
    int i, j;
    for (i = 1; i < 5 && row + i < SIZE && aRecordBoard[row + i][column] == who; ++i);
    for (j = 1; j < 5 && row - j >= 0 && aRecordBoard[row - j][column] == who; ++j);
    temp.linkNum = i + j - 1;
    temp.oppNum = 0;
    if (row + i == SIZE) {
        temp.oppNum = 1;
    } else {
        if (aRecordBoard[row + i][column] != 0)
            temp.oppNum = 1;
    }
    if (row - j == -1) {
        temp.oppNum++;
    } else {
        if (aRecordBoard[row - j][column] != 0)
            temp.oppNum++;
    }
    return temp;
}

struct singleInfo upLeftInfo(int row, int column, int who) {
    struct singleInfo temp;
    int i, j;
    for (i = 1; i < 5 && aRecordBoard[row + i][column + i] == who && row + i < SIZE && column + i < SIZE; ++i);
    for (j = 1; j < 5 && aRecordBoard[row - j][column - j] == who && row - j >= 0 && column - j >= 0; ++j);
    temp.linkNum = i + j - 1;
    temp.oppNum = 0;
    if (column + i == SIZE || row + i == SIZE) {
        temp.oppNum = 1;
    } else {
        if (aRecordBoard[row + i][column + i] != 0)
            temp.oppNum = 1;
    }
    if (column - j == -1 || row - j == -1) {
        temp.oppNum++;
    } else {
        if (aRecordBoard[row - j][column - j] != 0)
            temp.oppNum++;
    }
    return temp;
}

struct singleInfo upRightInfo(int row, int column, int who) {
    struct singleInfo temp;
    int i, j;
    for (i = 1; i < 5 && aRecordBoard[row + i][column - i] == who && row + i < SIZE && column - i >= 0; ++i);
    for (j = 1; j < 5 && aRecordBoard[row - j][column + j] == who && row - j >= 0 && column + j < SIZE; ++j);
    temp.linkNum = i + j - 1;
    temp.oppNum = 0;
    if (row + i == SIZE || column - i == -1) {
        temp.oppNum = 1;
    } else {
        if (aRecordBoard[row + i][column - i] != 0)
            temp.oppNum = 1;
    }
    if (row - j == -1 || column + j == SIZE) {
        temp.oppNum++;
    } else {
        if (aRecordBoard[row - j][column + j] != 0)
            temp.oppNum++;
    }
    return temp;
}

struct singleScore calculator(int row, int column, int who) {
    int rival = (who == 1) ? 2 : 1;
    struct singleScore temp;
    (temp.info)[0] = horizInfo(row, column, who);
    (temp.info)[1] = vertInfo(row, column, who);
    (temp.info)[2] = upLeftInfo(row, column, who);
    (temp.info)[3] = upRightInfo(row, column, who);

    temp.score = 0;
    for (int i = 0; i < 4; ++i) {
        temp.score += value[temp.info[i].oppNum][temp.info[i].linkNum];
    }
    int addScore;
    if (who == 1) {
        addScore = forbidden(row, column, who);
        if (addScore == 1)
            temp.score -= 100000;
        if (addScore == 2)
            temp.score += 6000;
    } else {
        addScore = wellDone(row, column, who);
        switch (addScore){
        case 0:
            break;
        case 2:
            temp.score+=802;
            break;
        case 3:
            temp.score+=5000;
            break;
        default:
            temp.score+=6000;
            break;
        }
    }
    return temp;
}

int calcul(int row, int column, int who) {
    return calculator(row, column, who).score;
}//debug delete it

int whoWin(int row, int column, int who) {
    if (horizInfo(row, column, who).linkNum == 5 || vertInfo(row, column, who).linkNum == 5 ||
        upLeftInfo(row, column, who).linkNum == 5 || upRightInfo(row, column, who).linkNum == 5)
        return who;
    return 0;
}

struct point algorithm1(int who) {
    struct point temp = {7, 8, -2000000};
    //针对先手
//对对手得分取负数，算出最大值，也就是对手的最小值，注意这里只考虑我下之前的
    int i, j;
    int rival = (who == 1) ? 2 : 1;
    for (i = 0; i < SIZE; ++i) {
        for (j = 0; j < SIZE; ++j) {
            if (aRecordBoard[i][j] != 0)
                myBoardScore[i][j] = -2000000;
            else {
                myBoardScore[i][j] = calculator(i, j, who).score + calculator(i, j, rival).score;//
            }
            if (myBoardScore[i][j] > temp.score) {
                temp.score = myBoardScore[i][j];
                temp.row = i;
                temp.column = j;
            }
        }
    }
    return temp;
}

struct point defaultAlgor(int who, int row, int column) {
    int rival = (who == 1) ? 2 : 1;
    struct point temp = {row, column, 600};
    int i, j;
    for (i = row - 1; i < row + 2; ++i) {
        for (j = column - 1; j < column + 2; ++j) {
            if (-1 < i && i < SIZE && -1 < j &&
                j < SIZE && aRecordBoard[i][j] == 0) {
                aRecordBoard[i][j] = who;
                if (algorithm1(rival).score < temp.score) {
                    temp.score = algorithm1(rival).score;
                    temp.row = i;
                    temp.column = j;
                }
                aRecordBoard[i][j] = 0;
            }
        }
    }
    return temp;
}


//after counter>15 use algorithm2 to search layers
struct point algorithm2(int who) {
    struct point temp = {7, 8, -2000000};
//针对后手的优化算法
    int i, j;
    int rival = (who == 1) ? 2 : 1;
    for (i = 0; i < SIZE; ++i) {
        for (j = 0; j < SIZE; ++j) {
            if (aRecordBoard[i][j] != 0)
                myBoardScore[i][j] = -2000000;
            else {
                myBoardScore[i][j] = calculator(i, j, who).score + calculator(i, j, rival).score;//
            }
            if (myBoardScore[i][j] > temp.score) {
                temp.score = myBoardScore[i][j];
                temp.row = i;
                temp.column = j;
            }
        }
    }
    return temp;
}


struct point algorithm(int counter, int who, int row, int column) {
    valuation();
    struct point temp;
    if (counter < 3) {
        temp = defaultAlgor(who, row, column);
    } else {
        temp = algorithm1(who);
        printf("%d\n", temp.score);
    }
    return temp;
}




/*void valuation(void) {
    value[2][1] = 0;
    value[2][2] = 0;
    value[2][3] = 0;
    value[2][4] = 0;
    value[2][5] = 1023;

    value[1][1] = 1;
    value[1][2] = 2;
    value[1][3] = 7;
    value[1][4] = 25;
    value[1][5] = 1023;

    value[0][1] = 1;
    value[0][2] = 6;
    value[0][3] = 19;
    value[0][4] = 400;
    value[0][5] = 1023;
    for (int i = 0; i < 3; ++i) {
        for (int j = 6; j < 10; ++j) {
            value[i][j] = 1023;
        }
    }

}*/