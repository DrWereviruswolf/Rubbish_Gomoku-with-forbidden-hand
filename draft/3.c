#include <stdio.h>

#define N 15

int map[N][N];

//initialize the board (i,j)
void ini() {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            map[i][j] = 0;
        }
    }
}

void prin() {
    //there was a// system("cls")
    printf("#  ");
    int signal[N];
    for (int k = 0; k < N; ++k) {
        signal[k] = k;
    }
    for (int k = 0; k < N; ++k) {
        if (k < 9)printf("%d ", signal[k] + 1);
        else printf("%d",signal[k]+1);
    }
   //give index in the front
    for (int i = 0; i < N; ++i) {

        if ( i < 9)
            printf("#\n# %d", signal[i] + 1);
        else
            printf("#\n#%d", signal[i] + 1);
        //give side index
        for (int j = 0; j < N; ++j) {
            if (map[i][j] == 0)
                printf("┼");     // you can change the icon
            else {
                if ((map[i][j] == 1) || (map[i][j]) == 4) {
                    printf("●");
                } else if ((map[i][j] == 2) || (map[i][j]) == 5) {
                    printf("○");
                } else if (map[i][j] == 3) {
                    printf("Ⅹ");
                }
            }
        }
    }
    printf("#");
}

int main() {
    printf("------------------------Welcome to my AIv1 chess------------------------\n\n");
    ini();
    prin();
    return 0;
}