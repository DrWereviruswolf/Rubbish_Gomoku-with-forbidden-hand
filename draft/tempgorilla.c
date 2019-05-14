#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "part12.h"
#include "value.h"
#include "whowin.h"
#include "AI.h"

/*
  definition
 */

void p2p() {
    cleaRecord();
    int row, column;
    int counter = 0;
    while (++counter) {
        printf("Please input in the format \"12h\": ");
        scanf("%s", input);
        if (input[0] == 'q' && input[2] == '\0') {
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

        aRecordBoard[row][column] = (counter % 2) ? PLAY1CURREENT : PLAY2CURREENT;//PLAY1 first
        int who = (counter % 2) ? PLAY1 : PLAY2;
        recordToDisplayArray();
        displayBoard();
        printf("            drop at %s\n", input);
        regulaRecord();

        if (whoWin(who, row, column) == who) {
            printf("Congratulations! PLAY%d!\n", who);
            break;
        }
    }
}

/*simplify main function
 argc argv to choose different modes to play chess*/


void p2m(int machNum) {
    cleaRecord();
    int row, column;
    int counter = 0;
    while (++counter) {
        int who = (counter % 2) ? PLAY1 : PLAY2;
        if (who != machNum) {
            printf("Please input in the format \"12h\": ");
            scanf("%s", input);
            if (input[0] == 'q' && input[2] == '\0') {
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
        } else if (who == machNum) {

            int wind = algorithm();
            row = (wind + SIZE - 1) / SIZE;
            column = wind % SIZE;
            for (; valid(row, column) == 0; wind = algorithm()) {
                row = (wind + SIZE - 1) / SIZE;
                column = wind % SIZE;
            }
            // to be continued
        }

        aRecordBoard[row][column] = (counter % 2) ? PLAY1CURREENT : PLAY2CURREENT;//PLAY1 first

        recordToDisplayArray();
        displayBoard();
        printf("            drop at %s\n", input);
        regulaRecord();

        if (whoWin(who, row, column) == who) {
            printf("Congratulations! PLAY%d!\n", who);
            break;
        }
//        whoWin(who,row,column)==PLAY2?printf("Congratulations! PLAY2!\n"):printf("Congratulations! PLAY1!\n");
    }
}

int main() {
    printf("\nWelcome to Liu Zhuoxuan's gomoku"
           "\np2p is p; p2m is m. Choose the mode:");
    int mode = getchar();
    if (mode == 'p')
        p2p();
    if (mode == 'm') {
        printf("\nI want to play 1(st) or 2(nd):");
        int machNum;
        scanf("%d", &machNum);
        if (machNum == 1)
            p2m(1);
        if (machNum == 2)
            p2m(2);
    }
    return 0;
}
