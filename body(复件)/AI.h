//
// Created by liu on 18-12-13.
//

#ifndef CHESS_AI_H
#define CHESS_AI_H

struct singleInfo horizInfo(int row, int column, int who);

struct point algorithm(int counter, int who, int row, int column);

int whoWin(int row, int column, int who);

struct singleScore calculator(int row, int column, int who);

int calcul(int row, int column, int who);

#endif //CHESS_AI_H
