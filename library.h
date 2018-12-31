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
	char login[20];             //登录号
	char bookname[50];          //书名
	char authorname[50];        //作者名
	char classify[50];          //分类
	char publisher[50];         //出版单位
	char time[50];              //出版时间
	struct library *next;
};