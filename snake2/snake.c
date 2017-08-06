#include <stdio.h>
#include <stdlib.h>
#include "resource.h"
#include <windows.h>
#include <conio.h>
#include <MMSystem.h>//PlaySound库
#include <windows.h>
#include "header.h"
#include <time.h >
#include "string.h"

#pragma comment(lib,"winmm.lib")//PlaySound库

	//显示首页
void firstpage();

void MyPlaySound();// 播放音乐

void testSpace();//检测空格
	
void MyStopMusic();//停止音乐

void showChar();//以字符串显示边框

void showNum();//以数字显示边框

void setSnakeRandPos();//生成随机位置

void DrawSnake();//画蛇

void SnakeMove();//蛇动

int main()
{
	//显示首页
	//test();
	
	int i=0;
	int j=0;
	
	//firstpage();//显示提示

	//MyPlaySound();// 播放音乐

	//testSpace();//检测空格
	
	//MyStopMusic();//停止音乐

	
	setSnakeRandPos();//产生随机数
	while(1)
	{
		system("cls");
		SnakeMove();
		showChar();//花背景
		
		Sleep(500);
	}

	system("pause");
	return 0;
}
void firstpage()
{
	printf("\t\t《欢迎进入贪吃蛇的世界》\n");
	printf("\t\tW S D A 控制方向\n");
	printf("\t\t按空格提示游戏\n");
}
void MyPlaySound()
{
	//https://msdn.microsoft.com/en-us/library/dd743680(VS.85).aspx
	//PlaySound("07.wav",NULL,SND_FILENAME | SND_ASYNC);
	PlaySound(MAKEINTRESOURCE(IDR_WAVE1),NULL ,SND_RESOURCE | SND_ASYNC);
}
//检测空格
void testSpace()
{
	char chInput;
	while(1)//检测空格
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
	PlaySound(NULL,0,0);//停止音乐
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
					 printf("▇");
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
	//产生随机数
	srand((unsigned int)time(NULL));//随机种子
	nX = rand()%19+1;
	nY = rand()%18+1;
	//初始化蛇的三个节点
	g_ArrSnake[0][0] = nY; //行
	g_ArrSnake[0][1] = nX*2; //列
	g_ArrSnake[0][2] = to_west; //行

	g_ArrSnake[1][0] = nY; //行
	g_ArrSnake[1][1] = nX*2+2; //列
	g_ArrSnake[1][2] = to_west; //行

	g_ArrSnake[2][0] = nY; //行
	g_ArrSnake[2][1] = nX*2+4; //列
	g_ArrSnake[2][2] = to_west; //行
	DrawSnake();
}
void DrawSnake()
{
	int i = 0;
	for(i=0;g_ArrSnake[i][0]!=0;i++)
	{

		strncpy(&g_charBackGround[g_ArrSnake[i][0]][g_ArrSnake[i][1]],"▇",2);
	}
}
void SnakeMove()
{
	int i = DEF_SNAKE_LONG -1;
	for(i;i>=1;i--)
	{
		//纵坐标任意一个为0，即为不合法
		if(0==g_ArrSnake[i][0])//g_ArrSnake[i][1],g_ArrSnake[i][2]任意一个即可
		{
			continue;//
		}
		g_ArrSnake[i][0] = g_ArrSnake[i-1][0];
		g_ArrSnake[i][1] = g_ArrSnake[i-1][1];
		g_ArrSnake[i][2] = g_ArrSnake[i-1][2];
	}
	//处理蛇头
	if(to_west == g_ArrSnake[0][2] || to_east == g_ArrSnake[0][2])
	{
		g_ArrSnake[0][1] +=g_ArrSnake[0][2];
	}
	else
	{
		g_ArrSnake[0][0] +=g_ArrSnake[0][2];
	}

	//画蛇
	DrawSnake();
	
}