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

#endif //CHESS_VALUE_H
