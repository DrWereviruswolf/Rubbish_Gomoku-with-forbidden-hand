/**
 * 刘卓轩
 * 2017K8009929033
 * 在程序中函数声明在.h文件中
 * .c文件中基本没有函数声明，
 * 所以最综合的函数在最下方
 * 一共5个设计文件
 */

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
        //退出
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
        //录入数据
        //检查是否有效
        if (valid(row, column) == 0) {                                                //valid表示落子在空的地方
            printf("Error: you cannot drop here. Please try again.\n");
            counter--;
            continue;
        }
        //PLAY1 first
        aRecordBoard[row][column] = (counter % 2) ? PLAY1CURREENT : PLAY2CURREENT;
        int who = (counter % 2) ? PLAY1 : PLAY2;                                  //who是谁
        //别的操作
        otherOperation();
        printf("            drop at %d%c\n", 15 - row, 'A' + column);
        //判断是否获胜
        if (whoWin(row, column, who) == who) {
            printf("Congratulations! PLAYER%d!\n", who);
            break;
        }
    }
}

/*simplify main function
 argc argv to choose different modes to play chess*/

/**
 *
 * @param machNum 机器先手还是后手
 */
void p2m(int machNum) {
    //cleaRecord();
    int row = 8, column = 8;
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
            //调用算法进行抉择
            struct point temp = algorithm(counter, who, row, column);
            row = temp.row;
            column = temp.column;
        }

        aRecordBoard[row][column] = (counter % 2) ? PLAY1CURREENT : PLAY2CURREENT;//PLAY1 first
        otherOperation();
        printf("            drop at %d%c\n", 15 - row, 'A' + column);

       // printf("forbidden?  %d\n", forbidden(row, column, who));
       // printf("calculator = %d\n", calculator(row, column, who).score);
        if (whoWin(row, column, who) == who) {
            printf("Congratulations! PLAYER%d!\n", who);
            break;
        }
        //在先手情况下，调用禁手判断
        if (who == 1 && forbidden(row, column, who) == 1) {
            printf("ForbiddenHand, sorry, Player%d!\n", who);
            scanf("%s", input);
            if (input[0] == 'b' && input[1] == '\0') {
                printf("Bye.\n");
                break;
            }
        }
    }
}


int main() {
    otherOperation();
    //选择人机对战
    printf("\nWork of 刘卓轩\n");
    printf("\nperson to person is p; person to machine is m. Choose the mode:");
    int mode = getchar();
    if (mode == 'p') {
        p2p();
    }
    if (mode == 'm'){
        //针对谁先下
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
