#include <stdio.h>
#include <stdlib.h>
#include<time.h>

///����ԭ���Լ�����
int count;///������Ŀ����
int max;///�����������
int ffloat;///ѡ���Ƿ���С��
int file;///ѡ���Ƿ����Ϊ�ļ�
int getChoice();
void Menu();
int integer(int);
int decimal(int);
FILE *fp;///�����ļ�

		 /*
		 �û�ѡ����
		 �����û��Ĺ���ѡ��
		 choice=1��ʾ�ӷ���2��ʾ������3��ʾ�˷���4��ʾ������0��ʾ�˳�
		 */
int getChoice()
{
	int choice;
	scanf("%d", &choice);
	return choice;
}

/*
��ʾ���ܲ˵�
*/
void Menu()
{
	printf("===================================\n");
	printf("\n��ӭʹ��Сѧ������������ϰ���\n");
	printf("\nѡ������:\n");
	printf("\t1���ӷ���ϰ\t2��������ϰ\n");
	printf("\t3���˷���ϰ\t4��������ϰ\n");
	printf("\t5���ۺ���ϰ\n");
	printf("\n===================================\n");
}

/*
��������
*/
int integer(int n)
{
	int i, j, m;
	int ranswer1[count];
	int t = 0;                ///��ʱ����
	char operation;            ///�������
	int num1[count];               ///������1
	int num2[count];               ///������2
	srand(time(NULL)); ///��ʼ�����������
	for (j = 1;j <= 2 * count; j++)
	{
		num1[j] = rand() % max + 1;           ///ȡ0��max֮��������
		num2[j] = rand() % max + 1;
	}
	if (n == 5)      ///��������ܣ����ѡ��5���������1-4�������ÿһ�����㷽ʽ
	{
		n = rand() % 4 + 1;
	}

	switch (n)
	{
	case 1:
		operation = '+';
		break;

	case 2:
		operation = '-';
		break;

	case 3:
		operation = '*';
		break;

	case 4:
		operation = '/';
		break;
	}

	///����������������ʱ�򣬽�������������
	for (i = 1;i <= count;i++)
	{
		if ((operation == '-') && (num1[i]<num2[i]))
		{
			t = num1[i];
			num1[i] = num2[i];
			num2[i] = t;
		}

		///���������еĳ�������num2Ϊ0ʱ�ͽ�num2ǿ����Ϊ1
		///��num1��ֵ��ֵ��num1*num2����ֹ��������
		if (operation == '/')
		{
			if (num2[i] == 0)
			{
				num2[i] = 1;
			}
			num1[i] = num1[i] * num2[i];        ///��ֹnum1���ܱ�num2���������
		}
		printf("%d%c%d= \n", num1[i], operation, num2[i]);
		fprintf(fp, "%d%c%d= \n", num1[i], operation, num2[i]);
	}
	///���㲢������ȷ��
	printf("��ȷ��Ϊ�� \n");
	fprintf(fp, "��ȷ��Ϊ�� \n");
	for (i = 1;i <= count;i++)
	{
		switch (operation)
		{
		case '+':
			ranswer1[i] = num1[i] + num2[i];
			break;

		case '-':
			ranswer1[i] = num1[i] + num2[i];
			break;

		case '*':
			ranswer1[i] = num1[i] + num2[i];
			break;

		case '/':
			ranswer1[i] = num1[i] + num2[i];
			break;
		}
		printf("%d  \n", ranswer1[i]);
		fprintf(fp, "%d  \n", ranswer1[i]);
	}
	printf("�����밴1�������밴0\n");///ѡ���Ƿ��������
	scanf("%d", &m);
	if (m == 1)
		return 1;
	else
		return 0;
}

/*
С������
*/
int decimal(int n)
{
	int i, j, m;
	float ranswer2[count];
	float t;                ///��ʱ����
	char operation;            ///�������
	float num3[count];               ///������1
	float num4[count];               ///������2
	srand(time(NULL)); ///��ʼ�����������
	for (j = 1;j <2 * count;j++)
	{
		num3[j] = rand() / (double)(RAND_MAX / max) + 1;///�������С��
		num4[j] = rand() / (double)(RAND_MAX / max) + 1;
	}
	if (n == 5)
	{
		n = rand() % 4 + 1;
	}

	switch (n)
	{
	case 1:
		operation = '+';
		break;

	case 2:
		operation = '-';
		break;

	case 3:
		operation = '*';
		break;

	case 4:
		operation = '/';
		break;
	}
	for (i = 1;i <= count;i++)
	{
		if ((operation == '-') && (num3[i]<num4[i]))
		{
			t = num3[i];
			num3[i] = num4[i];
			num4[i] = t;
		}
		if (operation == '/')
		{
			if (num4[i] == 0)
			{
				num4[i] = 1;
			}
			num3[i] = num3[i] * num4[i];
		}

		printf("%.2f%c%.2f= \n", num3[i], operation, num4[i]);
		fprintf(fp, "%.2f%c%.2f= \n", num3[i], operation, num4[i]);
	}
	printf("��ȷ��Ϊ�� \n");
	fprintf(fp, "��ȷ��Ϊ�� \n");
	for (i = 1;i <= count;i++)
	{
		switch (operation)
		{
		case '+':
			ranswer2[i] = num3[i] + num4[i];
			break;

		case '-':
			ranswer2[i] = num3[i] - num4[i];
			break;

		case '*':
			ranswer2[i] = num3[i] * num4[i];
			break;

		case '/':
			ranswer2[i] = num3[i] / num4[i];
			break;
		}
		printf("%.2f  \n", ranswer2[i]);
		fprintf(fp, "%.2f  \n", ranswer2[i]);
	}
	printf("�����밴1�������밴0\n");
	scanf("%d", &m);
	if (m == 1)
		return 1;
	else
		return 0;
}

///������
int main(void)
{
	int a = 1, choice;        ///�����û���ѡ��
	do      ///ѭ����ʼ����
	{
		Menu();                  ///��ʾ�˵�
		printf("��������Ҫ��ӡ��Ŀ������\n");
		scanf("%d", &count);
		printf("��������Ŀ�е�������֣�\n");
		scanf("%d", &max);
		printf("��ѡ���Ƿ���ҪС��(��Ϊ1����Ϊ0)��\n");
		scanf("%d", &ffloat);
		printf("��ѡ���Ƿ�������ļ�(��Ϊ1����Ϊ0)��\n");
		scanf("%d", &file);
		printf("���������ѡ��0--5����\n");
		if (file == 1)
			fp = fopen("��������.txt", "w");
		choice = getChoice();
		if (choice != 0)
		{
			///����choice�ķ�Χ
			if (choice<0 || choice>5)
				choice = 1;
			if (ffloat == 0)
			{
				a = integer(choice);
			}
			if (ffloat == 1)
			{
				a = decimal(choice);
			}
		}
		if (choice == 0)
		{
			a = 0;
			if (file == 1)
				fclose(fp);
			break;                ///�û�ѡ��0���˳�ѭ�����˳�ϵͳ��
		}
	} while (a == 1);
	printf("��лʹ�ñ����\n");
	return 0;
}
