//
// Created by liu on 19-1-10

#include "../body/value.h"
#include "maxminAlgo.h"
#include "../body/AI.h"
#include "../body/forbiddenHand.h"

inline int max(int a, int b) {
    return a > b ? a : b;
}

struct point layer1[15];

void *max(int *p) {

}

struct boardValue {
    int ***point;
    int value;
};



int value[10];
void valuation(void){
    value[1]=1;
    value[2]=3;
    value[3]=10;
    value[4]=33;
    value[5]=103;
    for (int i = 6; i < 10; ++i) {
        value[i]=102;
    }
}

/*int valueBoard(int **p[], int who) {   //p是指向落子的数组,**p[1]~**P[i]表示落子的地址
    int valueTemp = 0;
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE;) {
        }
    }
}*/


struct point maxminalg(int counter, int who, int row, int column) {
    struct point temp = {7, 8, -2000000};
    calcul(row, column, who);
    return temp;
}

int AlphaBeta(int depth, int alpha, int beta)
{
    if (depth == 0)
    {
        return Evaluate();
    }
    GenerateLegalMoves();
    while (MovesLeft())
    {
        MakeNextMove();
        val = -AlphaBeta(depth - 1, -beta, -alpha);
        UnmakeMove();
        if (val >= beta)
        {
            return beta;
        }
        if (val > alpha)
        {
            alpha = val;
        }
    }
    return alpha;
}