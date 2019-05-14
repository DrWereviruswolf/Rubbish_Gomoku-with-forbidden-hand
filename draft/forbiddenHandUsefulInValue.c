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
    temp.oneWayPattern = validNumber;
    temp.skipNum = jump;
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

    //if (i+j>6)
    temp.oneWayPattern = validNumber;
    temp.skipNum = jump;
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
    //if (i+j>6)
    temp.oneWayPattern = validNumber;
    temp.skipNum = jump;
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
    temp.oneWayPattern = validNumber;
    temp.skipNum = jump;
    return temp;
}

int simulation(int row, int column, int who) {
    return shang(row, column, who).oneWayPattern;
}
int simulation2(int row, int column, int who) {
    return xia(row, column, who).oneWayPattern;
}