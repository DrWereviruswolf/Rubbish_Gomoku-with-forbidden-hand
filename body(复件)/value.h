//
// Created by liu on 18-12-7.
//

#ifndef CHESS_VALUE_H
#define CHESS_VALUE_H

#define SIZE 15
#define MAX 1000
#define CHARSIZE 2
#define PLAY1CURREENT 3 // no zero
#define PLAY2CURREENT 4
#define PLAY1 1
#define PLAY2 2

extern const char aInitDisplayBoardArray[SIZE][SIZE * CHARSIZE + 1];
extern const char play1Pic[];
extern const char play1CurrentPic[];
extern const char play2Pic[];
extern const char play2CurrentPic[];
extern int aRecordBoard[SIZE][SIZE];
extern char aDisplayBoardArray[SIZE][SIZE * CHARSIZE + 1];
extern char input[MAX];
struct point {
    int row;
    int column;
    int score;
};
struct singleInfo {
    int linkNum;//my pattern
    int oppNum;//rival's besiege
};
struct singleScore {
    struct singleInfo info[4];
    int score;
};
struct singleSpeciInfo {
    int skipNum; // 如果是空一格类型的三和四就为1，否则为0
    int oneWayPattern;// 3 还是 4
    int pointer;//指针记录最后指向的位置
};
struct boardValue {
    int value;
    struct point point_value;
    struct boardValue *next;
};
#endif //CHESS_VALUE_H

//0是2空，1是1空1边界，2是2边界，3是1空1堵
// ，4是1堵1边界，6是2堵