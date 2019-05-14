/**
 * ��׿��
 * 2017K8009929033
 * �ڳ����к���������.h�ļ���
 * .c�ļ��л���û�к���������
 * �������ۺϵĺ��������·�
 * һ��5������ļ�
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
 * ���ļ�Ϊ�������ļ���������ģʽ��ѡ�񣬶��㷨��ѡ��
 * һ�������������ֱ�Ϊ���˶�ս���˻���ս����main����
  definition
 */

void p2p() {
    cleaRecord();//������Ļ
    int row, column;
    int counter = 0;                                             //counter��ʾ����
    while (++counter) {
        printf("Please input in the format \"12h\": ");
        scanf("%s", input);
        //�˳�
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
            printf("Error: input format wrong. Please try again.\n");                 //����������淶������
            counter--;
            continue;
        }
        //¼������
        //����Ƿ���Ч
        if (valid(row, column) == 0) {                                                //valid��ʾ�����ڿյĵط�
            printf("Error: you cannot drop here. Please try again.\n");
            counter--;
            continue;
        }
        //PLAY1 first
        aRecordBoard[row][column] = (counter % 2) ? PLAY1CURREENT : PLAY2CURREENT;
        int who = (counter % 2) ? PLAY1 : PLAY2;                                  //who��˭
        //��Ĳ���
        otherOperation();
        printf("            drop at %d%c\n", 15 - row, 'A' + column);
        //�ж��Ƿ��ʤ
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
 * @param machNum �������ֻ��Ǻ���
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
            //�����㷨���о���
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
        //����������£����ý����ж�
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
    //ѡ���˻���ս
    printf("\nWork of ��׿��\n");
    printf("\nperson to person is p; person to machine is m. Choose the mode:");
    int mode = getchar();
    if (mode == 'p') {
        p2p();
    }
    if (mode == 'm'){
        //���˭����
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
