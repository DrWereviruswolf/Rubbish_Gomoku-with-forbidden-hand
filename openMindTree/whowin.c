//
// Created by liu on 18-12-8.
//
#include "value.h"
#include "whowin.h"
#include <stdio.h>


int whoWin(int who, int row, int column) {
    int leftNum = 0, rightNum = 0;  //horizontal
    for (int j = 0; column + j < SIZE && j < 5 && aRecordBoard[row][column + j] == who; ++j)
        rightNum++;
    for (int j = 1; j < 5 && column - j > 0 && aRecordBoard[row][column - j] == who; ++j)
        leftNum++;
    if (leftNum + rightNum >= 5)
        return who;

    leftNum = 0, rightNum = 0;  //(0,0)-(14,14)
    int j = 0;
    int i = 0;
    for (;column + j < SIZE && row + i < SIZE && i < 5 && j < 5 && aRecordBoard[row + i][column + j] == who;
    ++j,++i)
        rightNum++;
    for (j = 1, i = 1; j < 5 && i < 5 && row - i > 0 && column - j > 0 && aRecordBoard[row - i][column - j] == who; ++j,++i)
        leftNum++;
    if (leftNum + rightNum >= 5)
        return who;

    leftNum = 0, rightNum = 0;  //vertical
    for (i = 0; row + i < SIZE && i < 5 && aRecordBoard[row + i][column] == who; ++i)
        rightNum++;
    for (i = 1; i < 5 && row-i > 0 && aRecordBoard[row-i][column] == who; ++i)
        leftNum++;
    if (leftNum + rightNum >= 5)
        return who;

    leftNum = 0, rightNum = 0;  //(0,14)-(14,0)
    for (i=0,j = 0; row - i > 0 && column + j < SIZE && i < 5 && j < 5 && aRecordBoard[row - i][column + j] == who; ++j,++i)
        rightNum++;
    for (i=1,j = 1; j < 5 && i < 5 && column - j > 0 && row + i < SIZE && aRecordBoard[row+i][column - j] == who; ++j)
        leftNum++;
    if (leftNum + rightNum >= 5)
        return who;

    return 0;

}

//restrict palyer1(jin shou)
//int restrictPlay1(int counter, int row, int column){}