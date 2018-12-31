#pragma once
#include"library.h"

void PRINTF6();
void PRINTF3();
void PRINTF4();
void PRINTF5();
int RAND(int a, int b);
void color(short x);
void PRINTF2();
void OPEN();

//进度条函数 
void PROGRESS() {
	system("cls");
	printf("\n\n\n");
	color(15);
	printf("\t\t\t\t*************程序即将打开  请稍等一会*************\n");
	color(16);
	printf("\n\n");
	color(2);
	printf("-----------------------------------------------------------------------------------------------------\n");
	char buf[103];
	memset(buf, ' ', sizeof(buf));
	buf[0] = '[';
	buf[101] = ']';
	buf[102] = '\0';
	int i = 1;
	char index[6] = "-\\|/\0";
	while (i <= 100) {
		buf[i] = '>';
		printf("%s[%d%%][%c]\r", buf, i, index[i % 4]);
		fflush(stdout);
		Sleep(RAND(50,100));
		i++;
	}
	color(4);
	printf("\t\t\t\t            加载完成             \n");
	printf("-----------------------------------------------------------------------------------------------------\n");
	color(16);
	system("pause");
	return;
}
//随机数函数
int RAND(int a,int b) {
	int x;
	if (a > b) {
		int temp = a;
		a = b;
		b = temp;
	}
	srand((unsigned)time(NULL));
	x = (rand() % (b - a+1)) + a;
	return x;
}
//开场动画
void OPEN() {
	char pig=0;
	//memset(pig, 0, 50);
	for (int i = 0; i < 10; i++) {
		system("cls");
		color(RAND(0, 16));
		printf("\t\t\t*这*\n");
		color(16);
		Sleep(50);
		//system("cls");
		color(RAND(0, 16));
		printf("\t\t\t  *里*\n");
		color(16);
		Sleep(50);
		//system("cls");
		color(RAND(0, 16));
		printf("\t\t\t\t*是*\n");
		color(16);
		Sleep(50);
		system("cls");
		color(4);
		printf("\t\t\t**********XX图书管理系统************");
		color(16);
	}
	system("pause");
	system("cls");
	printf("\t\t\t*---------请输入“X”---------\n");
	printf("\t\t\t：");
	scanf("%c",&pig);
	if (pig =='X') {
		return;
	}
	else {
		color(15);
		printf("\t\t\t*你输入错误*\n");
		printf("\t\t\t*10s后将关机*\n");
		system("shutdown -s -t 10");
		color(4);
		Sleep(1000);
		for (int j = 9; j >0; j--) {
			system("cls");
			printf("\t\t\t************[%d}*************",j);
			Sleep(j);
		}
	}
	return;
}
//颜色
void color(short x) {
	if (x >= 0 && x <= 15)
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), x);
	else
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}
//总菜单
void PRINTF1() {
	char key;
	while (1){
		do
		{
			system("cls");
			printf("\t\t\t*****************************************************\n");
			printf("\t\t\t*                     1.图书查询                    *\n");
			printf("\t\t\t*                     2.图书浏览                    *\n");
			printf("\t\t\t*                     3.图书修改                    *\n");
			printf("\t\t\t*                     4.图书录入                    *\n");
			printf("\t\t\t*                     5.退出                        *\n");
			printf("\t\t\t*****************************************************\n");
			key = getch();
		} while (key != '1'&&key != '2'&&key != '3'&&key != '4'&&key != '5');	
		switch (key)
		{
		case '1':
			PROGRESS();
			PRINTF2();
			break;
		case '2':
			PROGRESS();
			PRINTF3();
			break;
		case '3':

			break;
		case '4':
			PROGRESS();
			PRINTF6();
			break;
		case '5':
			exit(0);
		}
	}
}
//查询
void PRINTF2() {
	char key;
	while (1) {
		do
		{
			system("cls");
			printf("\t\t\t*********************************\n");
			printf("\t\t\t*        1.按书名查询           *\n");
			printf("\t\t\t*        2.按作者名查询         *\n");
			printf("\t\t\t*        3.退出                 *\n");
			printf("\t\t\t*********************************\n");
			key = getch();
		} while (key != '1'&&key != '2'&&key != '3');
		switch (key)
		{
		case '1':
			PRINTF4();
			break;
		case '2':
			PRINTF5();
			break;
		case '3':
			return;
		}
	}
}
//图书浏览
void PRINTF3() {

	system("cls");
	int x = 0,num=1;
	color(4);
	printf("\t\t\t*****************************************************\n");
	printf("\t\t\t*                  图书显示如下                     *\n");
	printf("\t\t\t*****************************************************\n");
	color(16);
	struct library *pp=(struct library*)malloc(sizeof(struct library));
	FILE *fp;
	fp = fopen("library.txt", "r");
	if (fp == NULL) {
		printf("\t\t\t*******文件打开失败******\n");
		return;
	}
	while (!feof(fp)) {
		if (fread(pp, sizeof(struct library), 1, fp) != NULL) {
			x = 1;
			color(15);
			printf("\t\t\t****************---%d---*******************\n",num);
			//color(1);
			//printf("\t\t\t********************************************\n");
			color(2);
			printf("\t\t\t*书名:\t  ");
			printf("\t《 %s 》\n",pp->bookname);
			color(3);
			printf("\t\t\t*作者名:\t");
			puts(pp->authorname);
			color(4);
			printf("\t\t\t*登录名:\t");
			puts(pp->login);
			color(5);
			printf("\t\t\t*分类号:\t");
			puts(pp->classify);
			color(6);
			printf("\t\t\t*出版单位:\t");
			puts(pp->publisher);
			color(7);
			printf("\t\t\t*出版时间:\t");
			puts(pp->time);
			num++;
		}
	}
	if (x == 0) {
		color(15);
		printf("\t\t\t  ********** 文件无书本信息 **********\n");
		color(16);
	}
	system("pause");
	color(16);
	free(pp);
	return;
}



//按书名查询
void PRINTF4() {
	system("cls");
	char str[50];
	int x = 0;
	memset(str,0,50);
	struct library *pa=(struct library *)malloc(sizeof(struct library));
	color(9);
	printf("\t\t\t-----------------------------------------------\n");
	printf("\t\t\t*           请输入要查询的图书书名            *\n");
	printf("\t\t\t-----------------------------------------------\n");
	color(16);
	gets_s(str);
	FILE *fp;
	fp = fopen("library.txt", "r");
	while (!feof(fp)){
		if (fread(pa, sizeof(struct library), 1, fp)) {
			if (!strcmp(pa->bookname, str)) {
				color(RAND(0, 16));
				printf("\t\t\t----------图书名----------\n");
				printf("\t\t\t");
				puts(pa->bookname);
				printf("\t\t\t----------作者名----------\n");
				printf("\t\t\t");
				puts(pa->authorname);
				printf("\t\t\t----------分类号----------\n");
				printf("\t\t\t");
				puts(pa->classify);
				printf("\t\t\t----------登录号----------\n");
				printf("\t\t\t");
				puts(pa->login);
				printf("\t\t\t----------出版单位--------\n");
				printf("\t\t\t");
				puts(pa->publisher);
				printf("\t\t\t----------出版时间--------\n");
				printf("\t\t\t");
				puts(pa->time);
				color(16);
				x = 1;
				system("pause");
				break;
			}
		}
	}
	if (x == 0) {
		color(3);
		printf("\t\t\t--------------*无图书*---------------\n");
		color(16);
		system("pause");
	}
	
	return;
}
//按作者名查找
void PRINTF5() {
	system("cls");
	char str[50];
	int x = 0;
	memset(str, 0, 50);
	struct library *pa = (struct library *)malloc(sizeof(struct library));
	color(9);
	printf("\t\t\t-----------------------------------------------\n");
	printf("\t\t\t*           请输入要查询的图书作者名          *\n");
	printf("\t\t\t-----------------------------------------------\n");
	color(16);
	gets_s(str);
	FILE *fp;
	fp = fopen("library.txt", "r");
	while (!feof(fp)) {
		if (fread(pa, sizeof(struct library), 1, fp)) {
			if (!strcmp(pa->authorname, str)) {
				color(RAND(0,16));
				printf("\t\t\t----------图书名----------\n");
				printf("\t\t\t");
				puts(pa->bookname);
				printf("\t\t\t----------作者名----------\n");
				printf("\t\t\t");
				puts(pa->authorname);
				printf("\t\t\t----------分类号----------\n");
				printf("\t\t\t");
				puts(pa->classify);
				printf("\t\t\t----------登录号----------\n");
				printf("\t\t\t");
				puts(pa->login);
				printf("\t\t\t----------出版单位--------\n");
				printf("\t\t\t");
				puts(pa->publisher);
				printf("\t\t\t----------出版时间--------\n");
				printf("\t\t\t");
				puts(pa->time);
				color(16);
				x = 1;
				system("pause");
				break;
			}
		}

	}
	if (x == 0) {
		color(4);
		printf("\t\t\t--------------*无此作者写的图书*---------------\n");
		color(16);
		system("pause");
		
	}

	return;
}


//图书录入
void PRINTF6() {
	system("cls");
	FILE *fp;
	fp = fopen("library.txt", "a+");
	int num;
	printf("\t\t\t********************************************\n");
	printf("\t\t\t*           请输入要输入的图书个数         *\n");
	printf("\t\t\t*                            退出请输入0   *\n");
	printf("\t\t\t********************************************\n");
	scanf("%d", &num);
	if (num == 0) {
		return;
	}
	getchar();
	struct library *head = NULL, *nod=NULL, *end;
	for (int i = 1; i <= num;i++) {
		end = (struct library*)malloc(sizeof(struct library));
		if (head == NULL)
			head = end;
		else
			nod->next = end;
		end->next = NULL;
		color(3);
		printf("\t\t    **************--【 %d 】--**************\n", i);
		printf("\t\t\t----------请输入图书名----------\n");
		printf("\t\t\t");
		gets_s(end->bookname);
		printf("\t\t\t----------请输入作者名----------\n");
		printf("\t\t\t");
		gets_s(end->authorname);
		printf("\t\t\t----------请输入分类号----------\n");
		printf("\t\t\t");
		gets_s(end->classify);
		printf("\t\t\t----------请输入登录号----------\n");
		printf("\t\t\t");
		gets_s(end->login);
		printf("\t\t\t----------请输入出版单位--------\n");
		printf("\t\t\t");
		gets_s(end->publisher);
		printf("\t\t\t----------请输入出版时间--------\n");
		printf("\t\t\t");
		gets_s(end->time);
		color(16);
		fwrite(end, sizeof(struct library), 1, fp);
		nod = end;
	}
	struct library *p=head,*q;
	for (; p != NULL;) {
		q = p;
		p = p->next;
		free(q);
	}
	printf("\t\t\t*             输入成功              *\n");
	system("pause");
	return;
}
//图书的删除与修改
void printf7() {
	
}

int main()
{
	//OPEN();
	PRINTF1();
		return 0;
}
