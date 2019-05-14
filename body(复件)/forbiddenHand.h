//
// Created by liu on 19-1-7.
//

#ifndef CHESS_FORBIDDENHAND_H
#define CHESS_FORBIDDENHAND_H


int simulation(int row, int column, int who);

int simulation2(int row, int column, int who);

int forbidden(int row, int column, int who);

struct singleSpeciInfo search(int row, int column, int dir[2], int who);

struct singleSpeciInfo you(int row, int column, int who);

struct singleSpeciInfo zuo(int row, int column, int who);

struct singleSpeciInfo shang(int row, int column, int who);

struct singleSpeciInfo xia(int row, int column, int who);

struct singleSpeciInfo zuoxia(int row, int column, int who);

struct singleSpeciInfo youxia(int row, int column, int who);

struct singleSpeciInfo zuoshang(int row, int column, int who);

struct singleSpeciInfo youshang(int row, int column, int who);

#endif //CHESS_FORBIDDENHAND_H
