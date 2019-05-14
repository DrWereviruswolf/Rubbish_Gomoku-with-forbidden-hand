//
// Created by liu on 18-12-7.
//

#ifndef CHESS_PART1_2_H
#define CHESS_PART1_2_H


#define SIZE 15
#define CHARSIZE 2

#define PLAY1CURREENT 3
#define PLAY2CURREENT 4
#define PLAY1 1
#define PLAY2 2

void recordToDisplayArray(void);
void displayBoard(void);
int valid(int row, int column);

void regulaRecord(void);
void cleaRecord(void);
/*
 * int whoWin(int recordboard[SIZE][SIZE]);
 */

#endif //CHESS_PART1_2_H
