#pragma once
#include"trans.h"


#define LEN 50


struct user_pwC *na0, *pw0;
//struct userna_pw *na1, *pw1;

void loginAD();
void ADMIN();
void COMMON();
void PRINTF1_1();
void PRINTF2_1();
void PRINTF3_1();
void IMPORT();
void VIEW();
void LOANDMA();
void WORD_CO(struct w_word *inpu);
void FWORD_CO();
void QUE(struct w_word *input);
void FQUE();

void REGISTCOM() {                                                  //�û�ע��
	system("cls");
	struct userna_pw *regi1=(struct userna_pw*)malloc(sizeof(struct userna_pw));
	FILE *fp;
	fp = fopen("username_pwCOM.txt", "a+");  //******************* //���û����ýṹ��������ļ�
	//memset(regi1->name1, 0, 101 * sizeof(char));
	//memset(regi1->passd1, 0, 101 * sizeof(char));
	//memset(regi1->passd2, 0, 101 * sizeof(char));
	printf("\t*************************\n");
	printf("\t*  ����������û���     *\n");
	gets_s(regi1->name1);	                 
	//na0 = &uni0;
	//pw0 = na0;
	while (1) {
		printf("\t*  �������������       *\n");
		gets_s(regi1->passd1);                                   //����������ͬ�ṹ��������ļ�
		printf("\t*  ����һ������ĵ�����: *\n");
		gets_s(regi1->passd2);

		if (strcmp(regi1->passd1, regi1->passd2)) {
			printf("\t*���Ķ������벻����*\n");
			printf("\t*  ����������      *\n");
		}
		else {
			//strcpy(regi_n->name, regi1.name1);
			//strcpy(regi_p->pw, regi1.passd1);

			fwrite(regi1,sizeof(struct userna_pw),1 ,fp);
			//fputs("\n", fp);
			//fputs(regi1.passd1, fp);
			//fputs("\n", fp);
			printf("*ע��ɹ�*\n");
			system("pause");
			fclose(fp);
			break;
		}
	}                //���һ��������бȶ�
	return ;
}             
void loginCOM()                                          //�û�����
{
	system("cls");
	struct userna_pw *log1 = (struct userna_pw*)malloc(sizeof(struct userna_pw));
	struct userna_pw *t=(struct userna_pw*)malloc(sizeof(struct userna_pw));
	//memset(log1->name1, 0, 101 * sizeof(char));
	//memset(log1->passd1, 0, 101 * sizeof(char));
	//memset(log1->passd2, 0, 101 * sizeof(char));
	printf("\t**********************\n");
	printf("\t*    �������û�����  *\n");
	gets_s(log1->name1);
	printf("\t*    ����������      *\n");
	gets_s(log1->passd2);                                          //�ļ�¼������ �ļ��ṹ�ȶ� 
	//strcat(log1->passd2, "\n");
	//strcat(log1->name1, "\n");
	FILE *fp1;
	fp1 = fopen("username_pwCOM.txt", "r");
	if (fp1 == NULL) {
		printf("�޴��ļ���\n");
		return;
	}
	int ok = 0;
	while (!feof(fp1)) {
		//fread(t.name1, sizeof(struct userna_pw), 1, fp1);
		//fread(t.passd1, sizeof(struct userna_pw), 1, fp1);
		while (fread(t, sizeof(struct userna_pw), 1, fp1) != NULL) {
			//fgets(t.passd1, sizeof(t.passd1), fp1);
			if (!strcmp(t->name1, log1->name1) && !strcmp(t->passd1, log1->passd2)) {
				ok = 1;
			}
		}
	}
	if (ok == 1) {
		printf("����ɹ�");
		printf("\t*     �س�������һ��        *\n");
		system("pause");
		COMMON();
	}
	else {
	printf("����ʧ��");
	system("pause");
	fclose(fp1);
}
	return;
}

void REGISTAD() {                                                  //����Աע��
	system("cls");
	
	memset(regi.name1, 0, 101 * sizeof(char));
	memset(regi.passd1, 0, 101 * sizeof(char));
	memset(regi.passd2, 0, 101 * sizeof(char));
	FILE *fp;
		fp = fopen("username_pwAD.txt", "a+");  //*******************
	printf("\t*************************\n");
	printf("\t*  ����������û���     *\n");
	gets_s(regi.name1);
	//na1 = &uni1;
	//pw1 = na1;
	while (1) {
		printf("\t*  �������������       *\n");
		gets_s(regi.passd1);                                   //����������ͬ�ṹ��������ļ�
		printf("\t*  ����һ������ĵ�����: *\n");
		gets_s(regi.passd2);


		if (strcmp(regi.passd1, regi.passd2)) {
			printf("\t*���Ķ������벻����*\n");
			printf("\t*  ����������      *\n");
		}
		else {

			//strcpy(regin->name, regi.name1);
			//strcpy(regin->pw, regi.passd1);

			fputs(regi.name1, fp);
			fputs("\n", fp);
			fputs(regi.passd1, fp);
			fputs("\n", fp);
			printf("*ע��ɹ�*\n");
			system("pause");
			fclose(fp);
			loginAD();
			break;
		}
	}                //���һ��������бȶ�
	return;
}
void loginAD()                                          //����Ա����
{
	system("cls");
	struct userna_pw log,t1;
	memset(log.name1, 0, 101 * sizeof(char));
	memset(log.passd1, 0, 101 * sizeof(char));
	memset(log.passd2, 0, 101 * sizeof(char));
	printf("\t**********************\n");
	printf("\t*    �������û�����  *\n");
	printf("\t**********************\n");
	gets_s(log.name1);                      //�ļ������û�
	printf("\t*    ����������      *\n");
	gets_s(log.passd2);                                          //�ļ�¼������ �ļ��ṹ�ȶ� 
	strcat(log.passd2, "\n");
	strcat(log.name1, "\n");
	FILE *fp1;
	fp1 = fopen("username_pwAD.txt", "r");
	 if (fp1 == NULL) {
		 printf("�޴��ļ���\n");
		 return ;
	}
	 int ok=0;
	 while (!feof(fp1)) {
		 fgets(t1.name1, sizeof(t1.name1), fp1);
		 fgets(t1.passd1, sizeof(t1.passd1), fp1);
		 if (!strcmp(t1.name1, log.name1) && !strcmp(t1.passd1, log.passd2)) {
			  ok = 1;
		 }
	
	 }
	 if (ok == 1) {
		 printf("����ɹ�\n\n\n");
		 printf("\t*     �س�������һ��        *\n");
		 system("pause");
			 ADMIN();

	 }
	 else {
		 printf("����ʧ��");
		 printf("\t*     �س�������һ��        *\n");
		 system("pause");
		 fclose(fp1);
	 }
		 return;
	 
}


char PRINTF1() {
	char key = 'a';
	while(1){
		do
		{
			system("cls");
			printf("\t*****************************\n");
			printf("\t*   1.�οͽ���              *\n");
			printf("\t*                           *\n");
			printf("\t*   2.��ͨ�û������ע��    *\n");
			printf("\t*                           *\n");
			printf("\t*   3.����Ա�����ע��      *\n");
			printf("\t*                 4.�˳�    *\n");
			printf("\t*****************************\n");
			printf("��������Ҫ���еĴ�������֣�\n");
			key = getch();
		} while (key != '1' && key != '2' &&key != '3'&&key !='4');
		switch (key)
		{
		case '1':
			PRINTF1_1(); break;
		case '2':
			PRINTF2_1(); break;
		case '3':
			PRINTF3_1(); break;
		case '4':
			exit(0);
		default:
			printf("����");
			break;
		}
	}
}
//��ѯ����
void PRINTF1_1()
{
	
	int x = 0;
	FILE *fp;
	fp = fopen("wordd.txt", "r");
	char tempor[100];
	struct w_word *check = (struct w_word *)malloc(sizeof(struct w_word));
	struct w_word *chec = (struct w_word *)malloc(sizeof(struct w_word));
	memset(tempor, 0, 100 * sizeof(char));
	system("cls");
	printf("\t*****************************************\n");
	printf("\t*      1.��������Ҫ��ѯ�ĵ���           *\n");
	printf("\t*****************************************\n");
	int i = 0;
	scanf("%s", tempor);
	while (fread(chec, sizeof(struct w_word), 1, fp) != NULL) {
		if (strstr(chec->word_, tempor) !=NULL) {
			printf("\n");
			printf("%s", chec->word_);
			//fread(strstr(((struct w_word *)check)->trans_, tempor), sizeof(struct w_word), 20, fp);
			//puts(check->trans_);
			//printf("\n");
			//printf("����.\t");
			//fwrite(((struct w_word *)check)->setence, sizeof(struct w_word),20, fp);
			//puts(check->setence);
			printf("\n");
			//x = 1;
			//break;
			//system("pause");
		}
	}
	rewind(fp);
	//fclose(fp);
	//printf("\t*        �س���������һ��        \n");
	//system("pause");
	//FILE *fpp;
	//fpp = fopen("wordd.txt", "r");
		while (fread(check, sizeof(struct w_word),1, fp) != NULL) {
			if (strstr(check->word_, tempor) == (char *)(check->word_)) {
				printf("\n");
				printf("%s: ",check->word_);
				//fread(strstr(((struct w_word *)check)->trans_, tempor), sizeof(struct w_word), 20, fp);
				puts(check->trans_);
				//printf("\n");
				printf("����.\t");
				//fwrite(((struct w_word *)check)->setence, sizeof(struct w_word),20, fp);
				puts(check->setence);
				printf("\n");
				x = 1;
				break;
				//system("pause");
			}
		}
		//system("pause");
		//printf("\t*        �س���������һ��        \n");
		system("pause");
	
	if(x==0) {
		printf("\t*    �Ҳ����˵��ʷ���     *\n");
		system("pause");

		return ;
	}
	else {

		QUE(check);
		char key;
		do {
			printf("\t*****************************************\n");
			printf("\t*      �Ƿ�Ҫ���˵��ʼ�¼�����ʼ�¼��   *\n");
			printf("\t*              1.��                     *\n");
			printf("\t*              2.��                     *\n");
			printf("\t*****************************************\n");
			key = getch();
		} while (key == '1'&&key == '2');
		if (key == '1') {
			WORD_CO(check);          //�浥���ղر�
			printf("\t*          �Ѵ���         *\n");
			system("pause");
		}
	}	fclose(fp);
		return ;
}


//��¼��ע�����
void PRINTF2_1() {
	
	char key2_1=0;
	do
	{
		system("cls");
		printf("\t***********************************\n");
		printf("\t*          ��ͨ�û�               *\n");
		printf("\t*           1.����                *\n");
		printf("\t*           2.ע��                *\n");
		printf("\t*                           3.�˳�*\n");
		printf("\t***********************************\n");
		key2_1 = getch();
	} while (key2_1 != '1' && key2_1 != '2'&& key2_1 != '3');
	if (key2_1 == '1') {
		loginCOM();
		return;
	}
	else if (key2_1 == '2') {
		REGISTCOM();
		printf("*          �밴�س�������         *\n");
		system("pause");
		loginCOM();
		return;
	}
	else
		return;
		

}
void PRINTF3_1() {
	
	char key3_1=0;
	do
	{
		system("cls");
		printf("\t*****************************\n");
		printf("\t*           ����Ա          *\n");
		printf("\t*          1.����           *\n");
		printf("\t*          2.ע��           *\n");
		printf("\t*                     3.�˳�*\n");
		printf("\t*****************************\n");
		key3_1 = getch();
	} while (key3_1 != '1'&&key3_1 != '2'&&key3_1 != '3');
	if (key3_1 == '1') {
		loginAD();
		return;
	}
	else if (key3_1 == '2') {
		REGISTAD();
		printf("\t *       ����       *\n");
		system("pause");
		loginAD();
		return;
	}
	else
		return;
}

//����Ա����
void ADMIN() {
	char keyA=0;
	while (1) {
		
		do
		{
			system("cls");
			printf("\t*****************************************\n");
			printf("\t*          1.��ѯ����                   *\n");
			printf("\t*          2.���뵥��                   *\n");
			printf("\t*          3.�鿴������Ϣ               *\n");
			printf("\t*          4.�鿴�͹����û�             *\n");
			printf("\t*                             5.�˳�    *\n");
			printf("\t*****************************************\n");
			keyA = getch();
		} while (keyA != '1'&&keyA != '2'&&keyA != '3'&&keyA != '4'&&keyA != '5');
		switch (keyA)
		{
		case '1':
			PRINTF1_1();
			break;
		case '2':
			IMPORT();
			break;
		case '3':
			VIEW();
			break;
		case '4':
			LOANDMA();
			break;
		case '5':
			return;
		default:
			printf("\t\t����");
			break;
		}
	}
}
//��ͨ�û�����
void COMMON() {
	char keyC=0;
	while(1){
		do
		{
			system("cls");
			printf("\t*****************************\n");
			printf("\t*     1.��ѯ����            *\n");
			printf("\t*     2.�����ղر�          *\n");
			printf("\t*     3.��ѯ��¼            *\n");
			printf("\t*                   4.�˳�  *\n");
			printf("\t*****************************\n");
			keyC = getch();
		} while (keyC != '1'&&keyC != '2'&&keyC != '3'&&keyC != '4');
		switch (keyC)
		{
		case '1':
			PRINTF1_1();
		
		break;
		case '2':
			FILE *fp0;
			fp0 = fopen("wordd_coll.txt", "a");
			char bbb[5];
			if (fgets(bbb,1,fp0) == NULL) {
				printf("\t*      ��û�д��뵥��  �ղر�Ϊ��      *\n");
				system("pause");
			}
			else {
				fclose(fp0);
				FWORD_CO();
			}
			break;
		case '3':
			FILE *fp_;
			fp_ = fopen("query log.txt", "a");
				char ccc[5];
			if ((fgets(ccc, 1, fp_) == NULL)){

				printf("\t*      ��û�в�ѯ����  ��¼Ϊ��      *\n");
				system("pause");
			}
			else {
				fclose(fp_);
				FQUE();
			}
			
			break;
		case '4':
			return;
		default:
			printf("\t\t����");
			break;
		}
	}
}

//���뵥��
void IMPORT() {                    //���뵥��
	system("cls");

	FILE *fp2;
	fp2 = fopen("wordd.txt", "a+");
	int n,x=0;
	printf("\t*****************************************\n");
	printf("\t*      ��Ҫ������ٸ�����               *\n");
	printf("\t*****************************************\n");
	scanf("%d",&n);
	tr = (struct w_word*)malloc( n * sizeof(struct w_word));
	wd = (struct w_word*)malloc(n * sizeof(struct w_word));
	for (int i = 0; i < n; i++) {
		printf("********      %d    *********\n",i+1);
		printf("\n");
		printf("\t*         �����뵥��              *\n");
		scanf("%s",&(tr + i)->word_);
		//(tr + i)->word_[strlen((tr + i)->word_) ]='\0';
		//fputs((wd+i)->word_, fp2);
		//fputs("     ", fp2);
		printf("\t*         ������ǰ�浥�ʵķ���    *\n");
		scanf("%s", &(tr + i)->trans_);
		getchar();
		//fputs((tr + i)->trans_, fp2);
		//fputs("\n", fp2);
		printf("\n");
		printf("\t*         ������ǰ�浥�ʵ�����    *\n");
		gets_s((tr+ i)->setence);
		//fputs((wd + i)->setence, fp2);
		//fputs("\n", fp2);
		rewind(fp2);
		while (feof(fp2) != EOF) {
			while (fread(wd, sizeof(struct w_word), 1, fp2) != NULL) {
				if ((tr + i)->word_ == wd->word_) {
					printf("\t*     �˵����Ѿ�������  �벻Ҫ�ظ�����     \t");
					system("pause");
					x = 1;
				}
			}
			break;
		}
		if (x == 0)
			fseek(fp2, 0L, SEEK_END);
			fwrite((tr+i),sizeof(struct w_word),1,fp2);
		printf("\n");
	}
	//rewind(fp2);
	
	fclose(fp2);
	return;
}                           
//�鿴���е��ʱ�
void VIEW() {              //�鿴���е�����Ϣ
	struct w_word *exi=(struct w_word *)malloc(sizeof(struct w_word));
	FILE *fp4;
	fp4 = fopen("wordd.txt", "r");
	if (fp4 == NULL) {
		printf("\t**      �ļ�δ¼�뵥��     **\n ");
		return;
	}
	else {
		while (feof(fp4) != EOF) {
			while (fread(exi, sizeof(struct w_word), 1, fp4) !=NULL){
				printf("%s��  ", exi->word_);
				puts(exi->trans_);
				puts("\n");
			}
			break;
		}
	}
	fclose(fp4);
	system("pause");
	return;
}
//�鿴�͹����û�
void LOANDMA() {
	int x = 0;
	struct userna_pw *usp=(struct userna_pw*)malloc(sizeof(struct userna_pw));
	char number[100];
	//char n[20];
	FILE *fp5;
	fp5 = fopen("username_pwCOM.txt", "r");
	if (fp5== NULL) {
		printf("\t**      ���û�     **\n ");
		while (getchar() != '\n')
			continue;
		return;
	}
	else {
		while (feof(fp5) != EOF) {
			while (fread(usp,sizeof(struct userna_pw),1,fp5) != NULL) {
				printf("****�û�����");
				puts(usp->name1);
				printf("****���룺");
				puts(usp->passd1);
			}
			break;
		}
		
	}
	//fflush(fp5);
	fclose(fp5);
	system("pause");
	printf("\t*     �Ƿ�ѡ��ɾ���û�       *\n");
	printf("\t*   1.��           2.��      *\n");
	char keyy = getch();
	if (keyy == '1') {
		FILE *fpp;
		fpp = fopen("username_pwCOM.txt","r");
		rewind(fpp);
		//struct userna_pw asd;
		struct userna_pw  us[105];
		int i=0,m1=(-1),qu=0;
			while (1) {
				printf("\t*      �������û����û���      *\n");
				scanf("%s", number);
				if (number[0] == '\0') {
					printf("    ���󣡣�    ����������       ");
					continue;
				}
				else
					break;
			}
				while (!feof(fpp)) {
					if (fread(&us[i], sizeof(struct userna_pw), 1, fpp) != NULL) {
						i++;
					}
				}
				fclose(fpp);
				if (i == 0) {
					printf("*    ���û�    *");
					system("pause");
					return;
				}
				for (int m = 0; m < i; m++) {
					if (strcmp(us[m].name1, number) == 0) {
						m1 = m;
						break;
					}
				}
				if(m1==-1){
						printf("*    �û�������    *");
						qu = 1;
					
				}
				else {
					for (int s = m1; s < i; s++) {
						us[s] = us[s + 1];
					}
					i--;
					if ((fpp = fopen("username_pwCOM.txt", "w")) == NULL) {
						return;
					}
					for (int k = 0; k < i; k++) {
						if (fwrite(&us[k], sizeof(struct userna_pw), 1, fpp) != 1) {
							printf("*      ɾ��ʧ��      *");
							system("pause");
							x = 1;
						}
					}
					//printf("*      ɾ���ɹ�      *");
				}
				if (x == 0) {
					printf("\t*      ɾ���ɹ�        *\n");
					printf("\t*       �س�������һ��  *\n");
					system("pause");
				}

		return;
	}
	else {
		return;
	}

}
//�浥�ʼ�¼��
void WORD_CO(struct w_word *inpu) {
	FILE *fp6;
	fp6 = fopen("word_coll.txt", "a");
	fwrite(inpu,sizeof(struct w_word),1, fp6);
	fclose(fp6);
	return;

}
//��ʾ���ʼ�¼��
void FWORD_CO() {
	system("cls");
	printf("\t*****************************************\n");
	printf("\t*       ���ʼ�¼��                      *\n");
	printf("\t*****************************************\n");
	struct w_word *fword=(struct w_word *)malloc(sizeof(struct w_word));
	//struct word_coll {
	//	char word1[100];
	//	char trans1[200];
	//	struct word_coll *next;
	//	int a;
	//};
	//struct word_coll *head = NULL;
	//struct word_coll *prev=NULL, *current;
	char input[50];
	FILE *fp7;
	fp7 = fopen("word_coll.txt", "r");
	if (fp7 == NULL) {
		printf("\t*        ������¼���޵���      *\n");
		system("pause");
		return;
	}
	while (feof(fp7) != EOF) {
		while (fread(fword, sizeof(struct w_word), 1, fp7) != NULL && input[0] != '\0') {
			//current = (struct word_coll*)malloc(sizeof(struct word_coll));
			//if (head == NULL)
			//	head = current;
			//else
				//prev->next = current;
			//current->next = NULL;
			puts(fword->word_);
			puts(fword->trans_);
			//prev = current;
			//memset(input, 0, sizeof(char) * 50);
		}
	}
	printf("\t**************�س�������*****************\n");
	system("pause");
	return;
}
//���ѯ��¼
void QUE(struct w_word *input) {
	FILE *fps;
	fps = fopen("query log.txt", "a");
	fwrite(input,sizeof(struct w_word),1,fps);
	fclose(fps);
	return;
}
//��ʾ��ѯ��¼
void FQUE() {
	system("cls");
	printf("\t*****************************************\n");
	printf("\t*              ��ѯ��¼               *\n");
	printf("\t*****************************************\n");
	struct w_word *fque = (struct w_word *)malloc(sizeof(struct w_word));
	//struct query_l {
	//	char word2[100];
	//	char trans2[200];
	//	struct query_l *next;
	//	int a;
	//};
	//struct query_l *head = NULL;
	//struct query_l *prev=NULL , *current;
	//char inputt[50];
	FILE *fp7;
	fp7 = fopen("query log.txt", "r");
	while (feof(fp7) != EOF) {
		while (fread(fque, sizeof(struct w_word), 1,fp7) != NULL) {
			//current = (struct query_l*)malloc(sizeof(struct query_l));
			//if (head == NULL)
			//	head = current;
			//else
			//	prev->next = current;
			//current->next = NULL;
			puts(fque->word_);
			puts(fque->trans_);
			//prev = current;
			//memset(inputt, 0, sizeof(char) * 50);
		}
	}
	printf("\t**************�س�������*****************\n");
	while (getchar() != '\n')
		continue;
	return;
}
//������ʾ���ʱ�
void SORT() {
	char *ptsw[10000], *ptst[10000];
	int a=5;
	//a = sizeof(wd) / sizeof(struct w_word);

	for (int i = 0; i < a; ++i) {
	//	ptsw[i] = (wd -i)->word_;
		ptst[i] = (tr - i)->trans_;
	}
	char*temp,*temp1;
	int top, seek;
	for (top = 0; top < a - 1; top++) {
		for (seek = top + 1; seek < a; seek++) {
			if (strcmp(ptsw[top], ptsw[seek]) > 0) {
				temp = ptsw[top];
				ptsw[top] = ptsw[seek];
				ptsw[seek] = temp;

				temp1 = ptst[top];
				ptst[top] = ptst[seek];
				ptst[seek] = temp1;
			}
		}
	}
	for (int k = 0; k < a; k++) {
		puts(ptsw[k]);
		printf("\t");
		puts(ptsw[k]);
		printf("\n");
	}
	return;
}


int main() {
 PRINTF1();             //������
		return 0;
}
