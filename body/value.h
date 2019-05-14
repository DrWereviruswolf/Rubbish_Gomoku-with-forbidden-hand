//
// Created by liu on 18-12-7.
//
/*
 * 结构体定义
 */
#ifndef CHESS_VALUE_H
#define CHESS_VALUE_H

#define SIZE 15
#define MAX 1000
#define CHARSIZE 2
#define PLAY1CURREENT 3
#define PLAY2CURREENT 4
#define PLAY1 1
#define PLAY2 2

/*
 * 全局变量声明
 * 定义见.c
 */
extern const char aInitDisplayBoardArray[SIZE][SIZE * CHARSIZE + 1];
extern const char play1Pic[];
extern const char play1CurrentPic[];
extern const char play2Pic[];
extern const char play2CurrentPic[];
extern int aRecordBoard[SIZE][SIZE];
extern char aDisplayBoardArray[SIZE][SIZE * CHARSIZE + 1];
//玩家的输入
extern char input[MAX];
//点的信息
struct point {
    int row;
    int column;
    int score;
};
struct singleInfo {
    int linkNum;
    //my pattern
    int oppNum;
    //rival's besiege
};
//多方向上点的信息
struct singleScore {
    struct singleInfo info[4];
    int score;
};
//详细的多方向连子信息
struct singleSpeciInfo {
    int skipNum;
    // 如果是空一格类型的三和四就为1，否则为0
    int oneWayPattern;
    // 3 还是 4
    int pointer;
    //指针记录最后指向的位置
};
#endif
//CHESS_VALUE_H
// copyright Liu Zhuoxuan
// UCAS 2019.1.12
