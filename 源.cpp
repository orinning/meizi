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

//���������� 
void PROGRESS() {
	system("cls");
	printf("\n\n\n");
	color(15);
	printf("\t\t\t\t*************���򼴽���  ���Ե�һ��*************\n");
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
	printf("\t\t\t\t            �������             \n");
	printf("-----------------------------------------------------------------------------------------------------\n");
	color(16);
	system("pause");
	return;
}
//���������
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
//��������
void OPEN() {
	char pig=0;
	//memset(pig, 0, 50);
	for (int i = 0; i < 10; i++) {
		system("cls");
		color(RAND(0, 16));
		printf("\t\t\t*��*\n");
		color(16);
		Sleep(50);
		//system("cls");
		color(RAND(0, 16));
		printf("\t\t\t  *��*\n");
		color(16);
		Sleep(50);
		//system("cls");
		color(RAND(0, 16));
		printf("\t\t\t\t*��*\n");
		color(16);
		Sleep(50);
		system("cls");
		color(4);
		printf("\t\t\t**********XXͼ�����ϵͳ************");
		color(16);
	}
	system("pause");
	system("cls");
	printf("\t\t\t*---------�����롰X��---------\n");
	printf("\t\t\t��");
	scanf("%c",&pig);
	if (pig =='X') {
		return;
	}
	else {
		color(15);
		printf("\t\t\t*���������*\n");
		printf("\t\t\t*10s�󽫹ػ�*\n");
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
//��ɫ
void color(short x) {
	if (x >= 0 && x <= 15)
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), x);
	else
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}
//�ܲ˵�
void PRINTF1() {
	char key;
	while (1){
		do
		{
			system("cls");
			printf("\t\t\t*****************************************************\n");
			printf("\t\t\t*                     1.ͼ���ѯ                    *\n");
			printf("\t\t\t*                     2.ͼ�����                    *\n");
			printf("\t\t\t*                     3.ͼ���޸�                    *\n");
			printf("\t\t\t*                     4.ͼ��¼��                    *\n");
			printf("\t\t\t*                     5.�˳�                        *\n");
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
//��ѯ
void PRINTF2() {
	char key;
	while (1) {
		do
		{
			system("cls");
			printf("\t\t\t*********************************\n");
			printf("\t\t\t*        1.��������ѯ           *\n");
			printf("\t\t\t*        2.����������ѯ         *\n");
			printf("\t\t\t*        3.�˳�                 *\n");
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
//ͼ�����
void PRINTF3() {

	system("cls");
	int x = 0,num=1;
	color(4);
	printf("\t\t\t*****************************************************\n");
	printf("\t\t\t*                  ͼ����ʾ����                     *\n");
	printf("\t\t\t*****************************************************\n");
	color(16);
	struct library *pp=(struct library*)malloc(sizeof(struct library));
	FILE *fp;
	fp = fopen("library.txt", "r");
	if (fp == NULL) {
		printf("\t\t\t*******�ļ���ʧ��******\n");
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
			printf("\t\t\t*����:\t  ");
			printf("\t�� %s ��\n",pp->bookname);
			color(3);
			printf("\t\t\t*������:\t");
			puts(pp->authorname);
			color(4);
			printf("\t\t\t*��¼��:\t");
			puts(pp->login);
			color(5);
			printf("\t\t\t*�����:\t");
			puts(pp->classify);
			color(6);
			printf("\t\t\t*���浥λ:\t");
			puts(pp->publisher);
			color(7);
			printf("\t\t\t*����ʱ��:\t");
			puts(pp->time);
			num++;
		}
	}
	if (x == 0) {
		color(15);
		printf("\t\t\t  ********** �ļ����鱾��Ϣ **********\n");
		color(16);
	}
	system("pause");
	color(16);
	free(pp);
	return;
}



//��������ѯ
void PRINTF4() {
	system("cls");
	char str[50];
	int x = 0;
	memset(str,0,50);
	struct library *pa=(struct library *)malloc(sizeof(struct library));
	color(9);
	printf("\t\t\t-----------------------------------------------\n");
	printf("\t\t\t*           ������Ҫ��ѯ��ͼ������            *\n");
	printf("\t\t\t-----------------------------------------------\n");
	color(16);
	gets_s(str);
	FILE *fp;
	fp = fopen("library.txt", "r");
	while (!feof(fp)){
		if (fread(pa, sizeof(struct library), 1, fp)) {
			if (!strcmp(pa->bookname, str)) {
				color(RAND(0, 16));
				printf("\t\t\t----------ͼ����----------\n");
				printf("\t\t\t");
				puts(pa->bookname);
				printf("\t\t\t----------������----------\n");
				printf("\t\t\t");
				puts(pa->authorname);
				printf("\t\t\t----------�����----------\n");
				printf("\t\t\t");
				puts(pa->classify);
				printf("\t\t\t----------��¼��----------\n");
				printf("\t\t\t");
				puts(pa->login);
				printf("\t\t\t----------���浥λ--------\n");
				printf("\t\t\t");
				puts(pa->publisher);
				printf("\t\t\t----------����ʱ��--------\n");
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
		printf("\t\t\t--------------*��ͼ��*---------------\n");
		color(16);
		system("pause");
	}
	
	return;
}
//������������
void PRINTF5() {
	system("cls");
	char str[50];
	int x = 0;
	memset(str, 0, 50);
	struct library *pa = (struct library *)malloc(sizeof(struct library));
	color(9);
	printf("\t\t\t-----------------------------------------------\n");
	printf("\t\t\t*           ������Ҫ��ѯ��ͼ��������          *\n");
	printf("\t\t\t-----------------------------------------------\n");
	color(16);
	gets_s(str);
	FILE *fp;
	fp = fopen("library.txt", "r");
	while (!feof(fp)) {
		if (fread(pa, sizeof(struct library), 1, fp)) {
			if (!strcmp(pa->authorname, str)) {
				color(RAND(0,16));
				printf("\t\t\t----------ͼ����----------\n");
				printf("\t\t\t");
				puts(pa->bookname);
				printf("\t\t\t----------������----------\n");
				printf("\t\t\t");
				puts(pa->authorname);
				printf("\t\t\t----------�����----------\n");
				printf("\t\t\t");
				puts(pa->classify);
				printf("\t\t\t----------��¼��----------\n");
				printf("\t\t\t");
				puts(pa->login);
				printf("\t\t\t----------���浥λ--------\n");
				printf("\t\t\t");
				puts(pa->publisher);
				printf("\t\t\t----------����ʱ��--------\n");
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
		printf("\t\t\t--------------*�޴�����д��ͼ��*---------------\n");
		color(16);
		system("pause");
		
	}

	return;
}


//ͼ��¼��
void PRINTF6() {
	system("cls");
	FILE *fp;
	fp = fopen("library.txt", "a+");
	int num;
	printf("\t\t\t********************************************\n");
	printf("\t\t\t*           ������Ҫ�����ͼ�����         *\n");
	printf("\t\t\t*                            �˳�������0   *\n");
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
		printf("\t\t    **************--�� %d ��--**************\n", i);
		printf("\t\t\t----------������ͼ����----------\n");
		printf("\t\t\t");
		gets_s(end->bookname);
		printf("\t\t\t----------������������----------\n");
		printf("\t\t\t");
		gets_s(end->authorname);
		printf("\t\t\t----------����������----------\n");
		printf("\t\t\t");
		gets_s(end->classify);
		printf("\t\t\t----------�������¼��----------\n");
		printf("\t\t\t");
		gets_s(end->login);
		printf("\t\t\t----------��������浥λ--------\n");
		printf("\t\t\t");
		gets_s(end->publisher);
		printf("\t\t\t----------���������ʱ��--------\n");
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
	printf("\t\t\t*             ����ɹ�              *\n");
	system("pause");
	return;
}
//ͼ���ɾ�����޸�
void printf7() {
	
}

int main()
{
	//OPEN();
	PRINTF1();
		return 0;
}
