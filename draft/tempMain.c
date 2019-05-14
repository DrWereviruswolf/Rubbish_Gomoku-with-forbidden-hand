//people to people without restriction
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "part12.h"
#include "value.h"
#include "whowin.h"

/*
  definition
 */

int main(){
    cleaRecord();
    int row, column;
    while (++counter) {
        printf("Please input in the format \"12h\": ");
        scanf("%s", input);
        if (input[0] == 'q' && input[2] == '\0') {
            printf("Bye.\n");
            return 0;
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
        printf("            drop at %s\n",input);
        regulaRecord();

        if (whoWin(who,row,column) == PLAY1) {
            printf("Congratulations! PLAY1!\n");
            break;
        } else if (whoWin(counter,row,column) == PLAY2) {
            printf("Congratulations! PLAY2!\n");
            break;
        }
    }

    return 0;
}
/*simplify main function
 argc argv to choose different modes to play chess*/

