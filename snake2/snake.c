#include <stdio.h>
#include <stdlib.h>
#include "resource.h"
#include <windows.h>
#include <conio.h>
#include <MMSystem.h>//PlaySound��
#include <windows.h>
#include "header.h"
#include <time.h >
#include "string.h"

#pragma comment(lib,"winmm.lib")//PlaySound��

	//��ʾ��ҳ
void firstpage();

void MyPlaySound();// ��������

void testSpace();//���ո�
	
void MyStopMusic();//ֹͣ����

void showChar();//���ַ�����ʾ�߿�

void showNum();//��������ʾ�߿�

void setSnakeRandPos();//�������λ��

void DrawSnake();//����

void SnakeMove();//�߶�

int main()
{
	//��ʾ��ҳ
	//test();
	
	int i=0;
	int j=0;
	
	//firstpage();//��ʾ��ʾ

	//MyPlaySound();// ��������

	//testSpace();//���ո�
	
	//MyStopMusic();//ֹͣ����

	
	setSnakeRandPos();//���������
	while(1)
	{
		system("cls");
		SnakeMove();
		showChar();//������
		
		Sleep(500);
	}

	system("pause");
	return 0;
}
void firstpage()
{
	printf("\t\t����ӭ����̰���ߵ����硷\n");
	printf("\t\tW S D A ���Ʒ���\n");
	printf("\t\t���ո���ʾ��Ϸ\n");
}
void MyPlaySound()
{
	//https://msdn.microsoft.com/en-us/library/dd743680(VS.85).aspx
	//PlaySound("07.wav",NULL,SND_FILENAME | SND_ASYNC);
	PlaySound(MAKEINTRESOURCE(IDR_WAVE1),NULL ,SND_RESOURCE | SND_ASYNC);
}
//���ո�
void testSpace()
{
	char chInput;
	while(1)//���ո�
	{
		chInput = _getch();
		if(' '==chInput)
		{
			break;
		}
	};
}
void MyStopMusic()
{
	PlaySound(NULL,0,0);//ֹͣ����
}

void showNum()
{
		int i=0;
		int j=0;
	while(1)
	{
		system("cls");
		for(i=0;i<20;i++)
		{
			for(j=0;j<23;j++)
			{
				if(1 == g_arrBackGround[i][j])
				{
					 printf("�~");
				}
				else
				{
					printf("  ");
				}
			}
			printf("\n");
		}
		Sleep(1000);

	}
}
void showChar()
{
	int i =0;
	for(i=0;i<20;i++)
	{
		printf(g_charBackGround[i]);
	}
}
void setSnakeRandPos()
{
	int nX = -1;
	int nY = -1;
	//���������
	srand((unsigned int)time(NULL));//�������
	nX = rand()%19+1;
	nY = rand()%18+1;
	//��ʼ���ߵ������ڵ�
	g_ArrSnake[0][0] = nY; //��
	g_ArrSnake[0][1] = nX*2; //��
	g_ArrSnake[0][2] = to_west; //��

	g_ArrSnake[1][0] = nY; //��
	g_ArrSnake[1][1] = nX*2+2; //��
	g_ArrSnake[1][2] = to_west; //��

	g_ArrSnake[2][0] = nY; //��
	g_ArrSnake[2][1] = nX*2+4; //��
	g_ArrSnake[2][2] = to_west; //��
	DrawSnake();
}
void DrawSnake()
{
	int i = 0;
	for(i=0;g_ArrSnake[i][0]!=0;i++)
	{

		strncpy(&g_charBackGround[g_ArrSnake[i][0]][g_ArrSnake[i][1]],"�~",2);
	}
}
void SnakeMove()
{
	int i = DEF_SNAKE_LONG -1;
	for(i;i>=1;i--)
	{
		//����������һ��Ϊ0����Ϊ���Ϸ�
		if(0==g_ArrSnake[i][0])//g_ArrSnake[i][1],g_ArrSnake[i][2]����һ������
		{
			continue;//
		}
		g_ArrSnake[i][0] = g_ArrSnake[i-1][0];
		g_ArrSnake[i][1] = g_ArrSnake[i-1][1];
		g_ArrSnake[i][2] = g_ArrSnake[i-1][2];
	}
	//������ͷ
	if(to_west == g_ArrSnake[0][2] || to_east == g_ArrSnake[0][2])
	{
		g_ArrSnake[0][1] +=g_ArrSnake[0][2];
	}
	else
	{
		g_ArrSnake[0][0] +=g_ArrSnake[0][2];
	}

	//����
	DrawSnake();
	
}