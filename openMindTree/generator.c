//
// Created by liu on 18-12-30.
//

#include "value.h"
#include "part12.h"
#include "AI.h"
#include "whowin.h"
#include <stdio.h>
#include <ctype.h>




int main() {
    cleaRecord();
    int counter = 0;
    int row, column;
    int ww = 0;
    while (++counter && ww == 0) {
        int wind = algorithm();
        row = (wind + SIZE - 1) / SIZE;
        column = wind % SIZE;
        for (; valid(row, column) == 0; wind = algorithm()) {
            row = (wind + SIZE - 1) / SIZE;
            column = wind % SIZE;
        }
        int who = counter % 2;
        printf("%d%5d\n",who, wind);
        ww = whoWin(who, row, column);
        if (ww == 1) {
            printf("finish, 1 win");
            return 0;
        } else if (ww == 2) {
            printf("finish, 2 win");
            return 0;
        }
    }

    FILE *fpt;
    fpt = fopen("wendangming.txt","w");//打开文档，写入
    fprintf(fpt,"Hello world");
    fclose(fpt);

}