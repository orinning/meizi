#pragma once
#define _CRT_NONSTDC_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNINGS


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<Windows.h>
#include<stddef.h>
#include<math.h>




//查询记录



struct w_word {
	char word_[100];
	char trans_[200];
	char setence[200];
	int at;
}*tr,*wd;


//管理员信息
struct user_pw {
	char name[101];
	char pw[101];
	int at=0;
} *regin, *regip;


//用户名信息
struct user_pwC {
	char name[101];
	char pw[101];
	int at=0;
}*regi_n, *regi_p;

struct userna_pw {
	char name1[101];
	char  passd1[101];
	char passd2[101];
}uni1;

struct userna_pw regi;




