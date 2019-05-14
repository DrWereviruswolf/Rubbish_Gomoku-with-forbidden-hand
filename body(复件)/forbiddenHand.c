//
// Created by liu on 19-1-7.
//
#include <stdio.h>
#include "value.h"
#include "forbiddenHand.h"
#include "AI.h"

struct singleSpeciInfo you(int row, int column, int who) {
    int rival = (who == 1) ? 2 : 1;
    struct singleSpeciInfo temp = {0, 0, 0};
    int i = 1, j = 1, jump = 0;
    int validNumber = 1;
    int *p;
    while (i <= 5) {
        p = &aRecordBoard[row][column + i];
        if (column + i == SIZE) {
            validNumber--;
            break;
        } else {
            if (*p == rival) {
                validNumber--;
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
        p = &aRecordBoard[row][column - j];
        if (column - j == -1) {
            validNumber--;
            break;
        } else {
            if (*p == rival) {
                validNumber--;
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
    temp.oneWayPattern = validNumber;
    temp.skipNum = jump;
    temp.pointer = i + j;
    return temp;
}

struct singleSpeciInfo zuo(int row, int column, int who) {
    int rival = (who == 1) ? 2 : 1;
    struct singleSpeciInfo temp = {0, 0, 0};
    int i = 1, j = 1, jump = 0;
    int validNumber = 1;
    int *p;
    while (j <= 5) {
        p = &aRecordBoard[row][column - j];
        if (column - j == -1) {
            validNumber--;
            break;
        } else {
            if (*p == rival) {
                validNumber--;
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
            break;
        } else {
            if (*p == rival) {
                validNumber--;
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
    temp.oneWayPattern = validNumber;
    temp.skipNum = jump;
    temp.pointer = i + j;
    return temp;
}

struct singleSpeciInfo xia(int row, int column, int who) {
    int rival = (who == 1) ? 2 : 1;
    struct singleSpeciInfo temp = {0, 0, 0};
    int i = 1, j = 1, jump = 0;
    int validNumber = 1;
    int *p;
    while (i <= 5) {
        p = &aRecordBoard[row + i][column];
        if (row + i == SIZE) {
            validNumber--;
            break;
        } else {
            if (*p == rival) {
                validNumber--;
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
            break;
        } else {
            if (*p == rival) {
                validNumber--;
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
    temp.oneWayPattern = validNumber;
    temp.skipNum = jump;
    temp.pointer = i + j;
    return temp;
}

struct singleSpeciInfo shang(int row, int column, int who) {
    int rival = (who == 1) ? 2 : 1;
    struct singleSpeciInfo temp = {0, 0, 0};
    int i = 1, j = 1, jump = 0;
    int validNumber = 1;
    int *p;
    while (j <= 5) {
        p = &aRecordBoard[row - j][column];
        if (row - j == -1) {
            validNumber--;
            break;
        } else {
            if (*p == rival) {
                validNumber--;
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
            break;
        } else {
            if (*p == rival) {
                validNumber--;
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
    temp.oneWayPattern = validNumber;
    temp.skipNum = jump;
    temp.pointer = i + j;
    return temp;
}

struct singleSpeciInfo zuoshang(int row, int column, int who) {
    int rival = (who == 1) ? 2 : 1;
    struct singleSpeciInfo temp = {0, 0, 0};
    int i = 1, j = 1, jump = 0;
    int validNumber = 1;
    int *p;
    while (j <= 5) {
        p = &aRecordBoard[row - j][column - j];
        if (row - j == -1 || column - j == -1) {
            validNumber--;
            break;
        } else {
            if (*p == rival) {
                validNumber--;
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
            break;
        } else {
            if (*p == rival) {
                validNumber--;
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
    temp.oneWayPattern = validNumber;
    temp.skipNum = jump;
    temp.pointer = i + j;
    return temp;
}

struct singleSpeciInfo youshang(int row, int column, int who) {
    int rival = (who == 1) ? 2 : 1;
    struct singleSpeciInfo temp = {0, 0, 0};
    int i = 1, j = 1, jump = 0;
    int validNumber = 1;
    int *p;
    while (j <= 5) {
        p = &aRecordBoard[row - j][column + j];
        if (row - j == -1 || column + j == SIZE) {
            validNumber--;
            break;
        } else {
            if (*p == rival) {
                validNumber--;
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
            break;
        } else {
            if (*p == rival) {
                validNumber--;
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
    temp.oneWayPattern = validNumber;
    temp.skipNum = jump;
    temp.pointer = i + j;
    return temp;
}

struct singleSpeciInfo zuoxia(int row, int column, int who) {
    int rival = (who == 1) ? 2 : 1;
    struct singleSpeciInfo temp = {0, 0, 0};
    int i = 1, j = 1, jump = 0;
    int validNumber = 1;
    int *p;
    while (i <= 5) {
        p = &aRecordBoard[row + i][column - i];
        if (row + i == SIZE || column - i == -1) {
            validNumber--;
            break;
        } else {
            if (*p == rival) {
                validNumber--;
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
            break;
        } else {
            if (*p == rival) {
                validNumber--;
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
    temp.oneWayPattern = validNumber;
    temp.skipNum = jump;
    temp.pointer = i + j;
    return temp;
}

struct singleSpeciInfo youxia(int row, int column, int who) {
    int rival = (who == 1) ? 2 : 1;
    struct singleSpeciInfo temp = {0, 0, 0};
    int i = 1, j = 1, jump = 0;
    int validNumber = 1;
    int *p;
    while (i <= 5) {
        p = &aRecordBoard[row + i][column + i];
        if (row + i == SIZE || column + i == SIZE) {
            validNumber--;
            break;
        } else {
            if (*p == rival) {
                validNumber--;
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
            break;
        } else {
            if (*p == rival) {
                validNumber--;
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
    temp.oneWayPattern = validNumber;
    temp.skipNum = jump;
    temp.pointer = i + j;
    return temp;
}

int forbidHoriz(int row, int column, int who) {
    struct singleSpeciInfo temp1 = zuo(row, column, who);
    struct singleSpeciInfo temp2 = you(row, column, who);
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

int simulation(int row, int column, int who) {
    return shang(row, column, who).oneWayPattern;
}

int simulation2(int row, int column, int who) {
    return xia(row, column, who).oneWayPattern;
}

//1禁手，0不禁手
int forbidden(int row, int column, int who) {
    int count7, count4, count3;
    count7 = count4 = count3 = 0;
    int temp[4] = {forbidVert(row, column, who), forbidHoriz(row, column, who),
                   forbidUpAndLeft(row, column, who), forbidUpAndRight(row, column, who)};
    for (int i = 0; i < 4; ++i) {
        switch (temp[i]) {
        case 1:
            return 1;             //同行上已经被禁
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
    if (count3 > 1 || count4 > 1)
        return 1;
    if (count7 > 0 && (count3 == 1 || count4 == 1))
        return 1;
    return 0;
}