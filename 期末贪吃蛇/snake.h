#ifndef _SNAKE_H
#define _SNAKE_H

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
#include<mmsystem.h>
#pragma comment (lib,"winmm.lib")


//	�߽ṹ��
typedef struct Snake
{
	int x;  //x����
	int y;  //y����
	struct Snake *pre;  //ǰָ��
	struct Snake *next; //��ָ��
}S;
//  ʳ��ṹ��
typedef struct Food
{
	int x;  //x����
	int y;  //y����
}F;

void initSnake(S *s);   //��ʼ����ͷ
int gameover(S * head);  //��Ϸ����
int isSnakeEatMeetFood(S *snake, F *food);  //�߳Ե�ʳ��
Snake *snakeGrow(S *head);  //������һ��
void creatFood(F *food);   //����ʳ��
void drawPicture(S *h, F *f, F *bigf, char *s);  //����ͼ�ο��Լ�ÿһʱ�̵��ߺ�ʳ��
int changedir(int c);  //�ı��ߵ��ƶ�����
void snakeMove(S *h, S *r, int c);  //�ߵ��ƶ�
int isOverlapSnake(F *f, S *h);  //�ж�ʳ���Ƿ��������غ�
void controlV1(int score, char c);  //ѡ����Ѷ�
void controlV2(int score, char c);  //ѡ���е��Ѷ�
void controlV3(int score, char c);  //ѡ�������Ѷ�
void gameStart();  //��ӭ����
void gameStart1();  //��Ϸģ��
void gameStart2();  //��Ϸ�Ѷ�ѡ��
void endInterface();  //��������
void gameDescription();  //��Ϸ˵��
void save(int score);  //�������
void mostScore();  //��ʷ��߷�
void pauseGame();  //��ͣ��Ϸ
void SNAKE();  //��Ϸ�Ľ���
void creatBigFood(F *f);  //������ʳ��
int isSnakeEatMeetBigFood(S *h, F *f);  //�߳Ե���ʳ��
int isBigOverlapSnake(F *f, S *h);  //�жϴ�ʳ���Ƿ��������غ�
int isBigfOverlapf(F *bigf, F *f);  //�жϴ�ʳ���Ƿ���Сʳ���غ�
#endif
