#pragma once
#define _CRT_NONSTDC_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<windows.h>
#include<conio.h>
#include<stddef.h>
#include<time.h>

struct library{
	char login[20];             //��¼��
	char bookname[50];          //����
	char authorname[50];        //������
	char classify[50];          //����
	char publisher[50];         //���浥λ
	char time[50];              //����ʱ��
	struct library *next;
};