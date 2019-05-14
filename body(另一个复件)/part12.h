//
// Created by liu on 18-12-7.
//

#ifndef CHESS_PART1_2_H
#define CHESS_PART1_2_H


#define SIZE 15
//棋盘大小
#define CHARSIZE 2
//符合所占字节数
//当前标示
#define PLAY1CURREENT 3
#define PLAY2CURREENT 4
#define PLAY1 1
#define PLAY2 2

int valid(int row, int column);

void cleaRecord(void);
void otherOperation(void);

#endif //CHESS_PART1_2_H
