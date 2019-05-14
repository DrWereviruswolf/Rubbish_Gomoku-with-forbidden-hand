#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "part12.h"
#include "value.h"
#include "AI.h"
#include "forbiddenHand.h"

/*
 * 此文件为主函数文件，包括对模式的选择，对算法的选择
 * 一共三个函数，分别为人人对战，人机对战，和main函数
  definition
 */

void p2p() {
    cleaRecord();//清理屏幕
    int row, column;
    int counter = 0;                                             //counter表示轮数
    while (++counter) {
        printf("Please input in the format \"12h\": ");
        scanf("%s", input);
        if (input[0] == 'q' && input[1] == '\0') {
            printf("Bye.\n");
            break;
        }
        if (isdigit(input[0]) && isdigit(input[1]) && isalpha(input[2]) && input[4] == '\0') {
            row = 15 - (input[0] - '0') * 10 - (input[1] - '0');
            column = input[2] - 'a';
        } else if (isdigit(input[0]) && isalpha(input[1]) && input[3] == '\0') {
            row = 15 - (input[0] - '0');
            column = input[1] - 'a';
        } else {
            printf("Error: input format wrong. Please try again.\n");                 //不符合输入规范，报错
            counter--;
            continue;
        }
        if (valid(row, column) == 0) {                                                //valid表示落子在空的地方
            printf("Error: you cannot drop here. Please try again.\n");
            counter--;
            continue;
        }

        aRecordBoard[row][column] = (counter % 2) ? PLAY1CURREENT : PLAY2CURREENT;//PLAY1 first
        int who = (counter % 2) ? PLAY1 : PLAY2;                                  //who是谁


        otherOperation();                                                     //别的操作
        printf("            drop at %d%c\n", 15 - row, 'A' + column);
        printf("上 = %d\n", simulation(row, column, who));
        printf("下 = %d\n", simulation2(row, column, who));
        printf("forbidden?  %d\n", forbidden(row, column, who));
        printf("calculator = %d\n", calculator(row, column, who).score);
        if (whoWin(row, column, who) == who) {
            printf("Congratulations! PLAYER%d!\n", who);
            break;
        }
    }
}

/*simplify main function
 argc argv to choose different modes to play chess*/


void p2m(int machNum) {
    cleaRecord();
    int row = 9, column = 9;
    int counter = 0;
    while (++counter) {
        int who = (counter % 2) ? PLAY1 : PLAY2;
        if (who != machNum) {
            printf("Please input in the format \"12h\": ");
            scanf("%s", input);
            if (input[0] == 'q' && input[1] == '\0') {
                printf("Bye.\n");
                break;
            }
            if (isdigit(input[0]) && isdigit(input[1]) && isalpha(input[2]) && input[4] == '\0') {
                row = 15 - (input[0] - '0') * 10 - (input[1] - '0');
                column = input[2] - 'a';
            } else if (isdigit(input[0]) && isalpha(input[1]) && input[3] == '\0') {
                row = 15 - (input[0] - '0');
                column = input[1] - 'a';
            } else {
                printf("Error: input format wrong. Please try again.\n");
                counter--;
                continue;
            }
            if (valid(row, column) == 0) {
                printf("Error: you cannot drop here. Please try again.\n");
                counter--;
                continue;
            }
        } else {
            struct point temp = algorithm(counter, who, row, column);
            row = temp.row;
            column = temp.column;
        }
        aRecordBoard[row][column] = (counter % 2) ? PLAY1CURREENT : PLAY2CURREENT;//PLAY1 first
        otherOperation();
        printf("            drop at %d%c\n", 15 - row, 'A' + column);
        printf("forbidden?  %d\n", forbidden(row, column, who));
        printf("calculator = %d\n", calculator(row, column, who).score);
        if (whoWin(row, column, who) == who) {
            printf("Congratulations! PLAYER%d!\n", who);
            break;
        }
        if (calculator(row,column,who).score==-10000){
            printf("ForbiddenHand, sorry, Player%d!\n",who);
            break;
        }
    }
}



int main() {
    otherOperation();
    printf("\nWork of 刘卓轩"
           "\nperson to person is p; person to machine is m. Choose the mode:");
    int mode = getchar();
    if (mode == 'p')
        p2p();
    if (mode == 'm') {
        printf("\nThis AI should play 1(st) or 2(nd):");
        int machNum;
        scanf("%d", &machNum);
        if (machNum == 1)
            p2m(1);
        if (machNum == 2)
            p2m(2);
    }
    return 0;
}
