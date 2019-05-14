//
// Created by liu on 18-12-13.
//

#ifndef CHESS_AI_H
#define CHESS_AI_H


struct point algorithm(int counter, int who, int row, int column);
//算法，在主程序中被调用
/*
 *
 * @param row 行数
 * @param column 列数
 * @param who 谁下
 * @return 赢了没有
 */
int whoWin(int row, int column, int who);


#endif //CHESS_AI_H
