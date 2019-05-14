//
// Created by liu on 18-12-7.
/**
 * 本文件针对一些通用的全局变量进行定义或声明
 * 包括显示
 * 定义在.h中的结构体
 */
//

#include "value.h"

const char aInitDisplayBoardArray[SIZE][SIZE * CHARSIZE + 1] =
        {
                "┏┯┯┯┯┯┯┯┯┯┯┯┯┯┓",
                "┠┼┼┼┼┼┼┼┼┼┼┼┼┼┨",
                "┠┼┼┼┼┼┼┼┼┼┼┼┼┼┨",
                "┠┼┼┼┼┼┼┼┼┼┼┼┼┼┨",
                "┠┼┼┼┼┼┼┼┼┼┼┼┼┼┨",
                "┠┼┼┼┼┼┼┼┼┼┼┼┼┼┨",
                "┠┼┼┼┼┼┼┼┼┼┼┼┼┼┨",
                "┠┼┼┼┼┼┼┼┼┼┼┼┼┼┨",
                "┠┼┼┼┼┼┼┼┼┼┼┼┼┼┨",
                "┠┼┼┼┼┼┼┼┼┼┼┼┼┼┨",
                "┠┼┼┼┼┼┼┼┼┼┼┼┼┼┨",
                "┠┼┼┼┼┼┼┼┼┼┼┼┼┼┨",
                "┠┼┼┼┼┼┼┼┼┼┼┼┼┼┨",
                "┠┼┼┼┼┼┼┼┼┼┼┼┼┼┨",
                "┗┷┷┷┷┷┷┷┷┷┷┷┷┷┛"
        };
const char play1Pic[] = "●";
const char play1CurrentPic[] = "▲";
const char play2Pic[] = "◎";
const char play2CurrentPic[] = "△";
int aRecordBoard[SIZE][SIZE];
char aDisplayBoardArray[SIZE][SIZE * CHARSIZE + 1];
char input[MAX] = {0};

