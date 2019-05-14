//
// Created by liu on 18-12-13.
/**
 * 主要是评估函数算法
 * 一共有十二个函数
 * 包括：
 * 分数限定
 * 四方向连子统计
 * 先手分值累加函数
 * 后手分值累加函数
 * 算法函数
 */
//
#include <stdlib.h>
#include <time.h>
#include "AI.h"
#include "value.h"
#include "forbiddenHand.h"


int value[3][10];
int myBoardScore[SIZE][SIZE];

//对棋的评价分数
//前者 is oppNum;后者 is linkNumber
void valuation(void) {
    value[2][1] = 0;
    value[2][2] = 0;
    value[2][3] = 0;
    value[2][4] = 0;
    value[2][5] = 10023;

    value[1][1] = 0;
    value[1][2] = 1;
    value[1][3] = 9;
    value[1][4] = 100;
    value[1][5] = 10023;

    value[0][1] = 1;
    value[0][2] = 9;
    value[0][3] = 97;
    value[0][4] = 1008;
    value[0][5] = 10023;
    for (int i = 0; i < 3; ++i) {
        for (int j = 6; j < 10; ++j) {
            value[i][j] = 10023;
        }
    }

}

//对对手棋的评分
//要比我方棋分略低，使得我方呈进攻状态，
//将一种算杀的思想蕴藏于此
int valueRival[3][10];

void valuationRival(void) {
    valueRival[2][1] = 0;
    valueRival[2][2] = 0;
    valueRival[2][3] = 0;
    valueRival[2][4] = 0;
    valueRival[2][5] = 10022;

    valueRival[1][1] = 0;
    valueRival[1][2] = 0;
    valueRival[1][3] = 8;
    valueRival[1][4] = 97;
    valueRival[1][5] = 10022;

    valueRival[0][1] = 0;
    valueRival[0][2] = 8;
    valueRival[0][3] = 95;
    valueRival[0][4] = 983;
    valueRival[0][5] = 10022;
    for (int i = 0; i < 3; ++i) {
        for (int j = 6; j < 10; ++j) {
            valueRival[i][j] = 10022;
        }
    }

}

//水平方向上的度量
//返回限制数，和连子数
struct singleInfo horizInfo(int row, int column, int who) {
    struct singleInfo temp;
    int i, j;
    for (i = 1; i < 5 && column + i < SIZE && aRecordBoard[row][column + i] == who; i++);
    for (j = 1; j < 5 && column - j >= 0 && aRecordBoard[row][column - j] == who; ++j);
    temp.linkNum = i + j - 1;
    temp.oppNum = 0;
    if (column + i == SIZE) {
        temp.oppNum = 1;
    } else {
        if (aRecordBoard[row][column + i] != 0)
            temp.oppNum = 1;
    }
    if (column - j == -1) {
        temp.oppNum++;
    } else {
        if (aRecordBoard[row][column - j] != 0)
            temp.oppNum++;
    }
    return temp;
}

//垂直方向的度量
struct singleInfo vertInfo(int row, int column, int who) {
    struct singleInfo temp;
    int i, j;
    for (i = 1; i < 5 && row + i < SIZE && aRecordBoard[row + i][column] == who; ++i);
    for (j = 1; j < 5 && row - j >= 0 && aRecordBoard[row - j][column] == who; ++j);
    temp.linkNum = i + j - 1;
    temp.oppNum = 0;
    if (row + i == SIZE) {
        temp.oppNum = 1;
    } else {
        if (aRecordBoard[row + i][column] != 0)
            temp.oppNum = 1;
    }
    if (row - j == -1) {
        temp.oppNum++;
    } else {
        if (aRecordBoard[row - j][column] != 0)
            temp.oppNum++;
    }
    return temp;
}

//左上方到右下方的度量
struct singleInfo upLeftInfo(int row, int column, int who) {
    struct singleInfo temp;
    int i, j;
    for (i = 1; i < 5 && aRecordBoard[row + i][column + i] == who && row + i < SIZE && column + i < SIZE; ++i);
    for (j = 1; j < 5 && aRecordBoard[row - j][column - j] == who && row - j >= 0 && column - j >= 0; ++j);
    temp.linkNum = i + j - 1;
    temp.oppNum = 0;
    if (column + i == SIZE || row + i == SIZE) {
        temp.oppNum = 1;
    } else {
        if (aRecordBoard[row + i][column + i] != 0)
            temp.oppNum = 1;
    }
    if (column - j == -1 || row - j == -1) {
        temp.oppNum++;
    } else {
        if (aRecordBoard[row - j][column - j] != 0)
            temp.oppNum++;
    }
    return temp;
}

//右上方到左下方的度量
struct singleInfo upRightInfo(int row, int column, int who) {
    struct singleInfo temp;
    int i, j;
    for (i = 1; i < 5 && aRecordBoard[row + i][column - i] == who && row + i < SIZE && column - i >= 0; ++i);
    for (j = 1; j < 5 && aRecordBoard[row - j][column + j] == who && row - j >= 0 && column + j < SIZE; ++j);
    temp.linkNum = i + j - 1;
    temp.oppNum = 0;
    if (row + i == SIZE || column - i == -1) {
        temp.oppNum = 1;
    } else {
        if (aRecordBoard[row + i][column - i] != 0)
            temp.oppNum = 1;
    }
    if (row - j == -1 || column + j == SIZE) {
        temp.oppNum++;
    } else {
        if (aRecordBoard[row - j][column + j] != 0)
            temp.oppNum++;
    }
    return temp;
}

//为自己估分
struct singleScore calculator(int row, int column, int who) {
//算分函数
    struct singleScore temp;
    (temp.info)[0] = horizInfo(row, column, who);
    (temp.info)[1] = vertInfo(row, column, who);
    (temp.info)[2] = upLeftInfo(row, column, who);
    (temp.info)[3] = upRightInfo(row, column, who);
//将上述信息记录至数组中
    temp.score = 0;
    //遍历后，选择最高分
    for (int i = 0; i < 4; ++i) {
        temp.score += value[temp.info[i].oppNum][temp.info[i].linkNum];
    }
    //这是在forbiddenHand中的数值微调
    int addScore;
    if (who == 1) {
        addScore = forbidden(row, column, who);
        //如果引发禁手
        //分数降低
        if (addScore == 1)
            if (temp.score < 10000)
                temp.score -= 100000;
            //如果冲四活三，则分数升高
        if (addScore == 2)
            temp.score += 6000;
    } else {
        addScore = wellDone(row, column, who);
        //同上，对后手分值有双活三，三和四，双四，等
        switch (addScore) {
        case 0:
            break;
        case 1:
            temp.score += 802;
        case 2:
            temp.score += 802;
            break;
        case 3:
            temp.score += 5000;
            break;
        default:
            temp.score += 6000;
            break;
        }
    }
    return temp;
}

//为对手估分
struct singleScore calculatRival(int row, int column, int rival) {
//算分函数
    struct singleScore temp;
    (temp.info)[0] = horizInfo(row, column, rival);
    (temp.info)[1] = vertInfo(row, column, rival);
    (temp.info)[2] = upLeftInfo(row, column, rival);
    (temp.info)[3] = upRightInfo(row, column, rival);

    temp.score = 0;
    for (int i = 0; i < 4; ++i) {
        temp.score += valueRival[temp.info[i].oppNum][temp.info[i].linkNum];
    }
    int addScore;
    if (rival == 1) {
        addScore = forbidden(row, column, rival);
        if (addScore == 1)
            if (temp.score < 10000)
                temp.score -= 10000;
        if (addScore == 2)
            temp.score += 6000;
    } else {
        addScore = wellDone(row, column, rival);
        switch (addScore) {
        case 0:
            break;
        case 1:
            temp.score += 802;
        case 2:
            temp.score += 802;
            break;
        case 3:
            temp.score += 5000;
            break;
        default:
            temp.score += 6000;
            break;
        }
    }
    return temp;
}

//谁赢的判断函数
int whoWin(int row, int column, int who) {
    if (horizInfo(row, column, who).linkNum >= 5 || vertInfo(row, column, who).linkNum >= 5 ||
        upLeftInfo(row, column, who).linkNum >= 5 || upRightInfo(row, column, who).linkNum >= 5)
        return who;
    return 0;
    //>5触犯长连禁手
    //长连禁手实际上极其罕见，几乎触犯不到
}

struct point algorithm1(int who) {
    struct point temp = {7, 8, -2000000};
    //针对先手
//对对手得分取负数，算出最大值，也就是对手的最小值，注意这里只考虑我下之前的
    int i, j, k;
    int rival = (who == 1) ? 2 : 1;
    for (i = 0; i < SIZE; ++i) {
        for (j = 0; j < SIZE; ++j) {
            if (aRecordBoard[i][j] != 0)
                //别人已经下过的位置去除
                myBoardScore[i][j] = -2000000;
            else {
                //选取对我们两者分数都高的位置
                myBoardScore[i][j] = calculator(i, j, who).score + calculatRival(i, j, rival).score;
            }
            if (myBoardScore[i][j] > temp.score) {
                temp.score = myBoardScore[i][j];
                temp.row = i;
                temp.column = j;
            } else if (myBoardScore[i][j] == temp.score) {
                //为了防止在比赛中多场相同，
                //设置了随机数来使分值相同的能够随便下
                srand(time(NULL));
                if (rand() % 2) {
                    temp.score = myBoardScore[i][j];
                    temp.row = i;
                    temp.column = j;
                };
            }
        }
    }
    return temp;
}

/**
 *
 * @param who 当前谁在下
 * @param row
 * @param column
 * @return 棋的位置
 * 默认算法在前面轮次中做出限定
 * 默认算法其实几乎是随便下，
 * 只是限定开局范围大概不会偏离中心很远
 */
struct point defaultAlgor(int who, int row, int column) {
    int rival = (who == 1) ? 2 : 1;
    struct point temp = {row, column, 600};
    int i, j;
    for (i = row - 1; i < row + 2; ++i) {
        for (j = column - 1; j < column + 2; ++j) {
            if (-1 < i && i < SIZE && -1 < j &&
                j < SIZE && aRecordBoard[i][j] == 0) {
                aRecordBoard[i][j] = who;
                if (algorithm1(rival).score < temp.score) {
                    temp.score = algorithm1(rival).score;
                    temp.row = i;
                    temp.column = j;
                } else if (algorithm1(rival).score == temp.score) {
                    //随机数的存在是为了让开局落子多样化
                    srand(time(NULL));
                    if (rand() % 2) {
                        temp.score = algorithm1(rival).score;
                        temp.row = i;
                        temp.column = j;
                    };
                }
                aRecordBoard[i][j] = 0;
            }
        }
    }
    return temp;
}


/**
 *
 * @param counter 轮数
 * @param who
 * @param row
 * @param column
 * @return 对所有算法进行统筹
 */
struct point algorithm(int counter, int who, int row, int column) {
    valuation();
    valuationRival();
    struct point temp;
    if (counter < 3) {
        temp = defaultAlgor(who, row, column);
    } else {
        temp = algorithm1(who);
    }
    return temp;
}


