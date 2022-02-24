#ifndef _SNAKE_H
#define _SNAKE_H

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
#include<mmsystem.h>
#pragma comment (lib,"winmm.lib")


//	蛇结构体
typedef struct Snake
{
	int x;  //x坐标
	int y;  //y坐标
	struct Snake *pre;  //前指针
	struct Snake *next; //后指针
}S;
//  食物结构体
typedef struct Food
{
	int x;  //x坐标
	int y;  //y坐标
}F;

void initSnake(S *s);   //初始化蛇头
int gameover(S * head);  //游戏结束
int isSnakeEatMeetFood(S *snake, F *food);  //蛇吃到食物
Snake *snakeGrow(S *head);  //蛇增长一节
void creatFood(F *food);   //创建食物
void drawPicture(S *h, F *f, F *bigf, char *s);  //绘制图形框以及每一时刻的蛇和食物
int changedir(int c);  //改变蛇的移动方向
void snakeMove(S *h, S *r, int c);  //蛇的移动
int isOverlapSnake(F *f, S *h);  //判断食物是否于蛇身重合
void controlV1(int score, char c);  //选择简单难度
void controlV2(int score, char c);  //选择中等难度
void controlV3(int score, char c);  //选择困难难度
void gameStart();  //欢迎界面
void gameStart1();  //游戏模块
void gameStart2();  //游戏难度选择
void endInterface();  //结束界面
void gameDescription();  //游戏说明
void save(int score);  //保存分数
void mostScore();  //历史最高分
void pauseGame();  //暂停游戏
void SNAKE();  //游戏的进行
void creatBigFood(F *f);  //创建大食物
int isSnakeEatMeetBigFood(S *h, F *f);  //蛇吃到大食物
int isBigOverlapSnake(F *f, S *h);  //判断大食物是否与蛇身重合
int isBigfOverlapf(F *bigf, F *f);  //判断大食物是否与小食物重合
#endif
