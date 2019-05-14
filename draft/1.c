#include <stdio.h>

int map[15][15];
//initialize the board
void ini() {

    for (int i = 0; i < 15; ++i) {
        for (int j = 0; j < 15; ++j) {
            map[i][j] = 0;
        }
    }
}

void prin() {
    //there was a// system("cls")
    for (int i = 0; i < 15; ++i) {
        printf("\t\n");
        for (int j = 0; j < 15; ++j) {
            if (map[i][j] == 0)
                printf("┼");
            else {
                if ((map[i][j] == 1) || (map[i][j]) == 4) {
                    printf("●");
                }
                if ((map[i][j] == 2) || (map[i][j]) == 5) {
                    printf("○");
                }
                if (map[i][j] == 3) {
                    printf("Ⅹ");
                }
            }
        }
    }
    printf("\n");
}

int main() {
    ini();
    prin();
    return 0;
}