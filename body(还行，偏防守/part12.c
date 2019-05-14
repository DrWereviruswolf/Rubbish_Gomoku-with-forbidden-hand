
/* Created by liu on 18-11-25.
this ducument is part 1 & 2 including anything except algorithm
*/

#include "value.h"
#include "part12.h"
#include <stdio.h>
#include <stdlib.h>

//record array to display array
void recordToDisplayArray(void){
    for (int i = 0; i < SIZE; ++i)
        for (int j = 0; j < SIZE * CHARSIZE + 1; ++j)
            aDisplayBoardArray[i][j] = aInitDisplayBoardArray[i][j];
    for (int i = 0; i < SIZE; ++i)
        for (int j = 0; j < SIZE; ++j) {
            if (aRecordBoard[i][j] == PLAY1) {
                aDisplayBoardArray[i][2 * j] = play1Pic[0];
                aDisplayBoardArray[i][2 * j + 1] = play1Pic[1];
            } else if (aRecordBoard[i][j] == PLAY2) {
                aDisplayBoardArray[i][2 * j] = play2Pic[0];
                aDisplayBoardArray[i][2 * j + 1] = play2Pic[1];
            } else if (aRecordBoard[i][j] == PLAY1CURREENT) {
                aDisplayBoardArray[i][2 * j] = play1CurrentPic[0];
                aDisplayBoardArray[i][2 * j + 1] = play1CurrentPic[1];
            } else if (aRecordBoard[i][j] == PLAY2CURREENT) {
                aDisplayBoardArray[i][2 * j] = play2CurrentPic[0];
                aDisplayBoardArray[i][2 * j + 1] = play2CurrentPic[1];
            }
        }
}

//put display array to screen
void displayBoard(void){
    system("clear");
    for (int i = 0; i < SIZE; ++i)
        printf("%2d %s\n", 15 - i, aDisplayBoardArray[i]);
    printf("   ");
    for (int i = 0; i < SIZE; ++i)
        printf(" %c", 'A' + i);
    printf("\n");
}

//if (row,column) has been filled
int valid(int row, int column){
    if (aRecordBoard[row][column] == PLAY1CURREENT || aRecordBoard[row][column] == PLAY2CURREENT ||
        aRecordBoard[row][column] == PLAY1 ||
        aRecordBoard[row][column] == PLAY2)
        return 0;
    //invalid
    if (row < 0 || row > SIZE - 1 || column < 0 || column > SIZE - 1)
        return 0;
    return 1;
    //valid
}

//record board become PLAY1 AND PLAY2 to be regularized
void regulaRecord(void) {
    for (int i = 0; i < SIZE; ++i)
        for (int j = 0; j < SIZE; ++j) {
            if (aRecordBoard[i][j] == PLAY1CURREENT)
                aRecordBoard[i][j] = PLAY1;
            if (aRecordBoard[i][j] == PLAY2CURREENT)
                aRecordBoard[i][j] = PLAY2;
        }
}

void cleaRecord(void){
    for (int i = 0; i < SIZE; ++i)
        for (int j = 0; j < SIZE; ++j)
            aRecordBoard[i][j] = 0;
}

void otherOperation(void){
    recordToDisplayArray();
    displayBoard();
    regulaRecord();
}
