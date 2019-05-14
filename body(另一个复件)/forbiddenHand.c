//
// Created by liu on 19-1-7.
/**
 * 对禁手做出判断
 * 并附带判断双三双四等棋型
 * 使得估值算法得到一定程度的优化
 */
//
#include <stdio.h>
#include "value.h"
#include "forbiddenHand.h"
#include "AI.h"
/**
 *
 * @param row 行数
 * @param column 列数
 * @param who 谁下
 * @return 往右数形状
 */
struct singleSpeciInfo you(int row, int column, int who) {
    int rival = (who == 1) ? 2 : 1;
    //对敌人描述
    struct singleSpeciInfo temp = {0, 0, 0};
    //初始化
    int i = 1, j = 1, jump = 0, clash = 0;
    //i，j是两个指针，jump代表遇到空白往前跳一次，clash代表遇到棋盘壁或被堵住
    int validNumber = 1;
    //等价作用是活三还是活四
    int *p;
    //指针指向记录棋盘中的值，以减少时间
    while (i <= 5) {
        p = &aRecordBoard[row][column + i];
        if (column + i == SIZE) {
            clash++;
            validNumber--;
            break;
        } else {
            if (*p == rival) {
                validNumber--;
                clash++;
                break;
            } else if (*p == who) {
                validNumber++;
                i++;
            } else if (*p == 0) {
                if (jump == 0) {
                    jump = 1;
                    i++;
                } else
                    break;
            }
        }
    }
    //向相反方向检测
    while (j <= 6 - i) {
        p = &aRecordBoard[row][column - j];
        if (column - j == -1) {
            clash++;
            validNumber--;
            break;
        } else {
            if (*p == rival) {
                validNumber--;
                clash++;
                break;
            } else if (*p == who) {
                validNumber++;
                j++;
            } else if (*p == 0) {
                if (jump == 0) {
                    jump = 1;
                    j++;
                } else
                    break;
            }
        }
    }
    validNumber += (clash > 0 && validNumber == 3) ? 1 : 0;
    temp.oneWayPattern = validNumber;
    temp.skipNum = jump;
    temp.pointer = i + j;
    return temp;
}

/**
 *
 * @param row
 * @param column
 * @param who
 * @return 向左数的情况，原因是可能向左和向右分别有欠三和欠四
 * 别的代码与you类似
 */
struct singleSpeciInfo zuo(int row, int column, int who) {
    int rival = (who == 1) ? 2 : 1;
    struct singleSpeciInfo temp = {0, 0, 0};
    int i = 1, j = 1, jump = 0, clash = 0;
    int validNumber = 1;
    int *p;
    while (j <= 5) {
        p = &aRecordBoard[row][column - j];
        if (column - j == -1) {
            validNumber--;
            clash++;
            break;
        } else {
            if (*p == rival) {
                validNumber--;
                clash++;
                break;
            } else if (*p == who) {
                validNumber++;
                j++;
            } else if (*p == 0) {
                if (jump == 0) {
                    jump = 1;
                    j++;
                } else
                    break;
            }
        }
    }
    while (i <= 6 - i) {
        p = &aRecordBoard[row][column + i];
        if (column + i == SIZE) {
            validNumber--;
            clash++;
            break;
        } else {
            if (*p == rival) {
                validNumber--;
                clash++;
                break;
            } else if (*p == who) {
                validNumber++;
                i++;
            } else if (*p == 0) {
                if (jump == 0) {
                    jump = 1;
                    i++;
                } else
                    break;
            }
        }
    }

    //if (i+j>6)
    validNumber += (clash > 0 && validNumber == 3) ? 1 : 0;
    temp.oneWayPattern = validNumber;
    temp.skipNum = jump;
    temp.pointer = i + j;
    return temp;
}

//search down
struct singleSpeciInfo xia(int row, int column, int who) {
    int rival = (who == 1) ? 2 : 1;
    struct singleSpeciInfo temp = {0, 0, 0};
    int i = 1, j = 1, jump = 0, clash = 0;
    int validNumber = 1;
    int *p;
    while (i <= 5) {
        p = &aRecordBoard[row + i][column];
        if (row + i == SIZE) {
            validNumber--;
            clash++;
            break;
        } else {
            if (*p == rival) {
                validNumber--;
                clash++;
                break;
            } else if (*p == who) {
                validNumber++;
                i++;
            } else if (*p == 0) {
                if (jump == 0) {
                    jump = 1;
                    i++;
                } else
                    break;
            }
        }
    }
    while (j <= 6 - i) {
        p = &aRecordBoard[row - j][column];
        if (row - j == -1) {
            validNumber--;
            clash++;
            break;
        } else {
            if (*p == rival) {
                validNumber--;
                clash++;
                break;
            } else if (*p == who) {
                validNumber++;
                j++;
            } else if (*p == 0) {
                if (jump == 0) {
                    jump = 1;
                    j++;
                } else
                    break;
            }
        }
    }
    //if (i+j>6)
    validNumber += (clash > 0 && validNumber == 3) ? 1 : 0;
    temp.oneWayPattern = validNumber;
    temp.skipNum = jump;
    temp.pointer = i + j;
    return temp;
}

//search up
struct singleSpeciInfo shang(int row, int column, int who) {
    int rival = (who == 1) ? 2 : 1;
    struct singleSpeciInfo temp = {0, 0, 0};
    int i = 1, j = 1, jump = 0, clash = 0;
    int validNumber = 1;
    int *p;
    while (j <= 5) {
        p = &aRecordBoard[row - j][column];
        if (row - j == -1) {
            validNumber--;
            clash++;
            break;
        } else {
            if (*p == rival) {
                validNumber--;
                clash++;
                break;
            } else if (*p == who) {
                validNumber++;
                j++;
            } else if (*p == 0) {
                if (jump == 0) {
                    jump = 1;
                    j++;
                } else
                    break;
            }
        }
    }
    while (i <= 6 - i) {
        p = &aRecordBoard[row + i][column];
        if (row + i == SIZE) {
            validNumber--;
            clash++;
            break;
        } else {
            if (*p == rival) {
                validNumber--;
                clash++;
                break;
            } else if (*p == who) {
                validNumber++;
                i++;
            } else if (*p == 0) {
                if (jump == 0) {
                    jump = 1;
                    i++;
                } else
                    break;
            }
        }
    }
    validNumber += (clash > 0 && validNumber == 3) ? 1 : 0;
    temp.oneWayPattern = validNumber;
    temp.skipNum = jump;
    temp.pointer = i + j;
    return temp;
}

//查左上方
struct singleSpeciInfo zuoshang(int row, int column, int who) {
    int rival = (who == 1) ? 2 : 1;
    struct singleSpeciInfo temp = {0, 0, 0};
    int i = 1, j = 1, jump = 0, clash = 0;
    int validNumber = 1;
    int *p;
    while (j <= 5) {
        p = &aRecordBoard[row - j][column - j];
        if (row - j == -1 || column - j == -1) {
            validNumber--;
            clash++;
            break;
        } else {
            if (*p == rival) {
                validNumber--;
                clash++;
                break;
            } else if (*p == who) {
                validNumber++;
                j++;
            } else if (*p == 0) {
                if (jump == 0) {
                    jump = 1;
                    j++;
                } else
                    break;
            }
        }
    }
    while (i <= 6 - i) {
        p = &aRecordBoard[row + i][column + i];
        if (row + i == SIZE || column + i == SIZE) {
            validNumber--;
            clash++;
            break;
        } else {
            if (*p == rival) {
                validNumber--;
                clash++;
                break;
            } else if (*p == who) {
                validNumber++;
                i++;
            } else if (*p == 0) {
                if (jump == 0) {
                    jump = 1;
                    i++;
                } else
                    break;
            }
        }
    }
    validNumber += (clash > 0 && validNumber == 3) ? 1 : 0;
    temp.oneWayPattern = validNumber;
    temp.skipNum = jump;
    temp.pointer = i + j;
    return temp;
}

//查右上方
struct singleSpeciInfo youshang(int row, int column, int who) {
    int rival = (who == 1) ? 2 : 1;
    struct singleSpeciInfo temp = {0, 0, 0};
    int i = 1, j = 1, jump = 0, clash = 0;
    int validNumber = 1;
    int *p;
    while (j <= 5) {
        p = &aRecordBoard[row - j][column + j];
        if (row - j == -1 || column + j == SIZE) {
            validNumber--;
            clash++;
            break;
        } else {
            if (*p == rival) {
                validNumber--;
                clash++;
                break;
            } else if (*p == who) {
                validNumber++;
                j++;
            } else if (*p == 0) {
                if (jump == 0) {
                    jump = 1;
                    j++;
                } else
                    break;
            }
        }
    }
    while (i <= 6 - i) {
        p = &aRecordBoard[row + i][column - i];
        if (row + i == SIZE || column - i == -1) {
            validNumber--;
            clash++;
            break;
        } else {
            if (*p == rival) {
                validNumber--;
                clash++;
                break;
            } else if (*p == who) {
                validNumber++;
                i++;
            } else if (*p == 0) {
                if (jump == 0) {
                    jump = 1;
                    i++;
                } else
                    break;
            }
        }
    }
    validNumber += (clash > 0 && validNumber == 3) ? 1 : 0;
    temp.oneWayPattern = validNumber;
    temp.skipNum = jump;
    temp.pointer = i + j;
    return temp;
}

//查左下方
struct singleSpeciInfo zuoxia(int row, int column, int who) {
    int rival = (who == 1) ? 2 : 1;
    struct singleSpeciInfo temp = {0, 0, 0};
    int i = 1, j = 1, jump = 0, clash = 0;
    int validNumber = 1;
    int *p;
    while (i <= 5) {
        p = &aRecordBoard[row + i][column - i];
        if (row + i == SIZE || column - i == -1) {
            validNumber--;
            clash++;
            break;
        } else {
            if (*p == rival) {
                validNumber--;
                clash++;
                break;
            } else if (*p == who) {
                validNumber++;
                i++;
            } else if (*p == 0) {
                if (jump == 0) {
                    jump = 1;
                    i++;
                } else
                    break;
            }
        }
    }
    while (j <= 6 - i) {
        p = &aRecordBoard[row - j][column + j];
        if (row - j == -1 || column + j == SIZE) {
            validNumber--;
            clash++;
            break;
        } else {
            if (*p == rival) {
                validNumber--;
                clash++;
                break;
            } else if (*p == who) {
                validNumber++;
                j++;
            } else if (*p == 0) {
                if (jump == 0) {
                    jump = 1;
                    j++;
                } else
                    break;
            }
        }
    }
    validNumber += (clash > 0 && validNumber == 3) ? 1 : 0;
    temp.oneWayPattern = validNumber;
    temp.skipNum = jump;
    temp.pointer = i + j;
    return temp;
}

//查右下方
struct singleSpeciInfo youxia(int row, int column, int who) {
    int rival = (who == 1) ? 2 : 1;
    struct singleSpeciInfo temp = {0, 0, 0};
    int i = 1, j = 1, jump = 0, clash = 0;
    int validNumber = 1;
    int *p;
    while (i <= 5) {
        p = &aRecordBoard[row + i][column + i];
        if (row + i == SIZE || column + i == SIZE) {
            validNumber--;
            clash++;
            break;
        } else {
            if (*p == rival) {
                validNumber--;
                clash++;
                break;
            } else if (*p == who) {
                validNumber++;
                i++;
            } else if (*p == 0) {
                if (jump == 0) {
                    jump = 1;
                    i++;
                } else
                    break;
            }
        }
    }
    while (j <= 6 - i) {
        p = &aRecordBoard[row - j][column - j];
        if (row - j == -1 || column - j == -1) {
            validNumber--;
            clash++;
            break;
        } else {
            if (*p == rival) {
                validNumber--;
                clash++;
                break;
            } else if (*p == who) {
                validNumber++;
                j++;
            } else if (*p == 0) {
                if (jump == 0) {
                    jump = 1;
                    j++;
                } else
                    break;
            }
        }
    }
    validNumber += (clash > 0 && validNumber == 3) ? 1 : 0;
    temp.oneWayPattern = validNumber;
    temp.skipNum = jump;
    temp.pointer = i + j;
    return temp;
}

//水平情况综合左和右
int forbidHoriz(int row, int column, int who) {
    struct singleSpeciInfo temp1 = zuo(row, column, who);
    struct singleSpeciInfo temp2 = you(row, column, who);
    //小于三的情况无用，还会影响算法，清零
    if (temp1.oneWayPattern < 3)
        temp1.oneWayPattern = 0;
    if (temp2.oneWayPattern < 3)
        temp2.oneWayPattern = 0;
    //指针如果相同，表示两者扫描过的是同一个三或四
    //双三
    if (temp1.pointer != temp2.pointer && temp1.oneWayPattern == 3 && temp2.oneWayPattern == 3)
        return 1;
    //双四
    if (temp1.pointer != temp2.pointer && temp1.oneWayPattern == 4 && temp2.oneWayPattern == 4)
        return 1;
    if (temp1.pointer == temp2.pointer) {
        temp1.oneWayPattern = 0;
    }
    //别的一些连子情况
    return temp1.oneWayPattern + temp2.oneWayPattern;
}
/**
 * 在下面是对四个方向类似的做出判断
 */
int forbidVert(int row, int column, int who) {
    struct singleSpeciInfo temp1 = shang(row, column, who);
    struct singleSpeciInfo temp2 = xia(row, column, who);
    if (temp1.oneWayPattern < 3)
        temp1.oneWayPattern = 0;
    if (temp2.oneWayPattern < 3)
        temp2.oneWayPattern = 0;

    if (temp1.pointer != temp2.pointer && temp1.oneWayPattern == 3 && temp2.oneWayPattern == 3)
        return 1;
    if (temp1.pointer != temp2.pointer && temp1.oneWayPattern == 4 && temp2.oneWayPattern == 4)
        return 1;
    if (temp1.pointer == temp2.pointer) {
        temp1.oneWayPattern = 0;
    }
    return temp1.oneWayPattern + temp2.oneWayPattern;// be forbidden
    /*
       if (temp1)
               if (temp1.oneWayPattern == 3 && temp2.oneWayPattern == 3)
            return 6;
        if (temp1.oneWayPattern == 4 && temp2.oneWayPattern == 4)
            return 8;
      */
}

int forbidUpAndRight(int row, int column, int who) {
    struct singleSpeciInfo temp1 = zuoxia(row, column, who);
    struct singleSpeciInfo temp2 = youshang(row, column, who);
    if (temp1.oneWayPattern < 3)
        temp1.oneWayPattern = 0;
    if (temp2.oneWayPattern < 3)
        temp2.oneWayPattern = 0;

    if (temp1.pointer != temp2.pointer && temp1.oneWayPattern == 3 && temp2.oneWayPattern == 3)
        return 1;
    if (temp1.pointer != temp2.pointer && temp1.oneWayPattern == 4 && temp2.oneWayPattern == 4)
        return 1;
    if (temp1.pointer == temp2.pointer) {
        temp1.oneWayPattern = 0;
    }
    return temp1.oneWayPattern + temp2.oneWayPattern;
}

int forbidUpAndLeft(int row, int column, int who) {
    struct singleSpeciInfo temp1 = zuoshang(row, column, who);
    struct singleSpeciInfo temp2 = youxia(row, column, who);
    if (temp1.oneWayPattern < 3)
        temp1.oneWayPattern = 0;
    if (temp2.oneWayPattern < 3)
        temp2.oneWayPattern = 0;

    if (temp1.pointer != temp2.pointer && temp1.oneWayPattern == 3 && temp2.oneWayPattern == 3)
        return 1;
    if (temp1.pointer != temp2.pointer && temp1.oneWayPattern == 4 && temp2.oneWayPattern == 4)
        return 1;
    if (temp1.pointer == temp2.pointer) {
        temp1.oneWayPattern = 0;
    }
    return temp1.oneWayPattern + temp2.oneWayPattern;
}

/**
 *
 * @param row 行数
 * @param column 列数
 * @param who 谁下
 * @return 双活三返回2，同时三,四返回3，更多的棋子形状返回4，别的返回0
 * 这个函数是针对后手的，如果有类似双三双四等特殊情况，会标识出，然后增加分数
 */
int wellDone(int row, int column, int who) {
    //计算3,4以及同行上都有3,4的情况
    int count7, count4, count3;
    //7表示同行上既有三又有四
    count7 = count4 = count3 = 0;
    int temp[4] = {forbidVert(row, column, who), forbidHoriz(row, column, who),
                   forbidUpAndLeft(row, column, who), forbidUpAndRight(row, column, who)};
    for (int i = 0; i < 4; ++i) {
        switch (temp[i]) {
        case 1:
            return 1;
        case 3:                   //有3型子
            count3++;
            break;
        case 4:
            count4++;
            break;
        case 7:
            count7++;
            break;
        default:
            break;
        }
    }
    count7 *= 2;
    if (count3 > 1 && count4 == 0 && count7 == 0)                   //对一些杀棋的判断
        return 2;
    if ((count3 == 1 && count4 == 1 && count7 == 0) || (count7 == 1 && count3 + count4 == 0))
        return 3;
    if (count3 + count4 + count7 > 1)
        return 2 + count3 + count4 + count7;
    return 0;
}

//1禁手，0不禁手
/**
 * 类似上方函数
 * @param row
 * @param column
 * @param who
 * @return 针对先手的一些信息，包括禁手即多种连子情况
 */
int forbidden(int row, int column, int who) {
    int count7, count4, count3;
    count7 = count4 = count3 = 0;
    //7表示同行上既有三又有四
    int temp[4] = {forbidVert(row, column, who), forbidHoriz(row, column, who),
                   forbidUpAndLeft(row, column, who), forbidUpAndRight(row, column, who)};
    for (int i = 0; i < 4; ++i) {
        switch (temp[i]) {
        case 1:
            return 1;
            //同行上已经被禁,即双三或双四
        case 3:
            //有3型子
            count3++;
            break;
        case 4:
            //有4型子
            count4++;
            break;
        case 7:
            //同一行上有3型子和4型子
            count7++;
            break;
        default:
            break;
        }
    }
    /**
     * 如果存在双三或双四则触犯禁手，
     * 长连在whowin中被排除
     */
    if (count3 > 1 || count4 > 1)
        return 1;
    if (count7 > 0 && (count3 == 1 || count4 == 1))
        return 1;
    //如果出现3和4说明是不触犯禁手的好棋
    if ((count3 == 1 && count4 == 1) || count7 == 1)
        return 2;
    return 0;
}