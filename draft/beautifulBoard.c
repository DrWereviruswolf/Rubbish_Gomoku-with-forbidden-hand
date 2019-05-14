#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define SIZE 15
#define CHARSIZE 2
#define MAX 1000

#define BLACKCURREENT 3
#define WHITECURREENT 4
#define BLACK 1
#define WHITE 2
char aInitDisplayBoardArray[SIZE][SIZE * CHARSIZE + 1] =
        {
                "©³©Ó©Ó©Ó©Ó©Ó©Ó©Ó©Ó©Ó©Ó©Ó©Ó©Ó©·",
                "©Ä©à©à©à©à©à©à©à©à©à©à©à©à©à©Ì",
                "©Ä©à©à©à©à©à©à©à©à©à©à©à©à©à©Ì",
                "©Ä©à©à©à©à©à©à©à©à©à©à©à©à©à©Ì",
                "©Ä©à©à©à©à©à©à©à©à©à©à©à©à©à©Ì",
                "©Ä©à©à©à©à©à©à©à©à©à©à©à©à©à©Ì",
                "©Ä©à©à©à©à©à©à©à©à©à©à©à©à©à©Ì",
                "©Ä©à©à©à©à©à©à©à©à©à©à©à©à©à©Ì",
                "©Ä©à©à©à©à©à©à©à©à©à©à©à©à©à©Ì",
                "©Ä©à©à©à©à©à©à©à©à©à©à©à©à©à©Ì",
                "©Ä©à©à©à©à©à©à©à©à©à©à©à©à©à©Ì",
                "©Ä©à©à©à©à©à©à©à©à©à©à©à©à©à©Ì",
                "©Ä©à©à©à©à©à©à©à©à©à©à©à©à©à©Ì",
                "©Ä©à©à©à©à©à©à©à©à©à©à©à©à©à©Ì",
                "©»©Û©Û©Û©Û©Û©Û©Û©Û©Û©Û©Û©Û©Û©¿"
        };
char play1Pic[] = "¡ñ";
char play1CurrentPic[] = "¡ø";
char play2Pic[] = "¡ò";
char play2CurrentPic[] = "¡÷";
int aRecordBoard[SIZE][SIZE];
char aDisplayBoardArray[SIZE][SIZE * CHARSIZE + 1];
char input[MAX] = {0};

/*int mygetline(char s[], int lim) {
    //get a line from the terminal,
    //once one line is finished, exit the function
    //input: a string(to contain the input, large enough), an int to limit the input size
    //output: the length of the input
    int c, i = 0;
    while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
        s[i++] = c;
    if (c == '\n')
        s[i++] = c;
    s[i] = '\0';
    return i;
}
*/


void recordtoDisplayArray(void) {
    for (int i = 0; i < SIZE; ++i)
        for (int j = 0; j < SIZE * CHARSIZE + 1; ++j)
            aDisplayBoardArray[i][j] = aInitDisplayBoardArray[i][j];
    for (int i = 0; i < SIZE; ++i)
        for (int j = 0; j < SIZE; ++j) {
            if (aRecordBoard[i][j] == BLACK) {
                aDisplayBoardArray[i][2 * j] = play1Pic[0];
                aDisplayBoardArray[i][2 * j + 1] = play1Pic[1];
            } else if (aRecordBoard[i][j] == WHITE) {
                aDisplayBoardArray[i][2 * j] = play2Pic[0];
                aDisplayBoardArray[i][2 * j + 1] = play2Pic[1];
            } else if (aRecordBoard[i][j] == BLACKCURREENT) {
                aDisplayBoardArray[i][2 * j] = play1CurrentPic[0];
                aDisplayBoardArray[i][2 * j + 1] = play1CurrentPic[1];
            } else if (aRecordBoard[i][j] == WHITECURREENT) {
                aDisplayBoardArray[i][2 * j] = play2CurrentPic[0];
                aDisplayBoardArray[i][2 * j + 1] = play2CurrentPic[1];
            }
        }
}

void displayBoard(void) {
    system("clear");
    for (int i = 0; i < SIZE; ++i)
        printf("%2d %s\n", 15 - i, aDisplayBoardArray[i]);
    printf("   ");
    for (int i = 0; i < SIZE; ++i)
        printf(" %c", 'A' + i);
    printf("\n");
}

int valid(int row, int column) {
    if (aRecordBoard[row][column] == BLACKCURREENT || aRecordBoard[row][column] == WHITECURREENT || aRecordBoard[row][column] == BLACK ||
        aRecordBoard[row][column] == WHITE)
        return 0;
    if (row < 0 || row > SIZE-1 || column < 0 || column > SIZE-1)
        return 0;
    return 1;
}

int main() {
    int counter = 1;
    for (int i = 0; i < SIZE; ++i)
        for (int j = 0; j < SIZE; ++j)
            aRecordBoard[i][j] = 0;
    int row, column;
    while (counter++) {
        printf("Please input in the format \"12h\": ");
        //mygetline(input, MAX);
        scanf("%s",input);
        if (input[0] == 'q' && input[1] == '\n' && input[2] == '\0')
        //&&input[1]=='u'&&input[2]=='i'&&input[3]=='t'&&input[4]=='\n'&&input[5]=='\0')
        {
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
            continue;
        }

        if (valid(row, column) == 0) {
            printf("Error: you cannot drop here. Please try again.\n");
            continue;
        }

        aRecordBoard[row][column] = (counter % 2) ? BLACKCURREENT : WHITECURREENT;//black first
        recordtoDisplayArray();
        displayBoard();
        for (int i = 0; i < SIZE; ++i)
            for (int j = 0; j < SIZE; ++j) {
                if (aRecordBoard[i][j] == BLACKCURREENT)
                    aRecordBoard[i][j] = BLACK;
                if (aRecordBoard[i][j] == WHITECURREENT)
                    aRecordBoard[i][j] = WHITE;
            }

    }
    return 0;
}

