//
// Created by liu on 18-12-7.
/**
 * ���ļ����һЩͨ�õ�ȫ�ֱ������ж��������
 * ������ʾ
 * ������.h�еĽṹ��
 */
//

#include "value.h"

const char aInitDisplayBoardArray[SIZE][SIZE * CHARSIZE + 1] =
        {
                "���өөөөөөөөөөөөө�",
                "�ĩ��������������",
                "�ĩ��������������",
                "�ĩ��������������",
                "�ĩ��������������",
                "�ĩ��������������",
                "�ĩ��������������",
                "�ĩ��������������",
                "�ĩ��������������",
                "�ĩ��������������",
                "�ĩ��������������",
                "�ĩ��������������",
                "�ĩ��������������",
                "�ĩ��������������",
                "���۩۩۩۩۩۩۩۩۩۩۩۩۩�"
        };
const char play1Pic[] = "��";
const char play1CurrentPic[] = "��";
const char play2Pic[] = "��";
const char play2CurrentPic[] = "��";
int aRecordBoard[SIZE][SIZE];
char aDisplayBoardArray[SIZE][SIZE * CHARSIZE + 1];
char input[MAX] = {0};

