#include<graphics.h>
#include<time.h>
#include"snake.h"

#define R 242
#define G 208
#define B 162
int Dif = -1;  //游戏难度值
char s[6];  //等分数值转换为字符串
int score ;  //得分
int  c = 77;  //移动方向


int main()
{
	gameStart();
	gameStart1();
}

void initSnake(S *s)
{
	s->x = 100;
	s->y = 100;
	s->next = NULL;
	s->pre = NULL;
}

void snakeMove(S *h,S *r,int c)
{
	S *p = r;
	while (p != h)  //当蛇移动时，每移动一次，后一个蛇身坐标等于前一个蛇身坐标
	{
		p->x = p->pre->x;
		p->y = p->pre->y;
		p = p->pre;
	}

	if (c == 68||c == 100)  //方位键为d或者D向右移动
	{
		h->x += 20;
		h->y = h->y;
	}
	else if ( c == 65 || c == 97)  //方位键为a或者A向左移动
	{
		h->x -= 20;
		h->y = h->y;
	}
	else if ( c == 83 || c == 115)  //方位键为s或者S向下移动
	{
		h->y += 20;
		h->x = h->x;
	}
	else if ( c == 87 || c == 119)  //方位键为w或者D向上移动
	{
		h->y -= 20;
		h->x = h->x;
	}
}

int isSnakeEatMeetFood(S *h, F *f)
{
	//遍历蛇链表,当蛇的坐标与食物左边相同时，蛇与食物重合
	if (h->x == (f->x-10)&&h->y == (f->y-10))  //蛇的形状为正方形，食物形状为圆形，
		return 1;
	else
		return 0;
}

S *snakeGrow(S *h)
{
	S *p = (S*)malloc(sizeof(S));  //申请动态空间
	p->next = NULL;
	S *q = h;
	while (q ->next!= NULL)
		q = q->next;
	q->next = p;
	p->pre = q;
	return p;
}

void creatFood(F *f)
{
	f->x = (rand() % 42) * 20 +10;
	f->y = (rand() % 35) * 20 +10;
}

int isOverlapSnake(F *f, S *h)
{
	S *q = h;
	while (q != NULL)
	{
		if (q->x == (f->x-10)&&q->y == (f->y-10))  //食物为圆形，坐标为圆心
			return 1;
		q = q->next;
	}
	return 0;
}

int gameover(S *h)
{
	S *p = h;
	if (p->x <= -1 || p->y <= -1 || p->x>=840 || p->y>=700)  //当蛇碰到墙壁
		return 1;
	p = p->next;
	while (p!= NULL)  //当蛇碰到自身
	{
		if (h->x == p->x&&h->y == p->y)
			return 1;
		p = p->next;
	}
	return 0;
}

void controlV1(int score, char c)  
{
	if (score < 10)
	{
		if (c == 'j') //移动加速
		{
			Sleep(60);
			return;
		}
		Sleep(180);
	}
	else if (score < 20)
	{
		if (c == 'j')
		{
			Sleep(60);
			return;
		}
		Sleep(140);
	}
	else
	{
		if (c == 'j')
		{
			Sleep(60);
			return;
		}
		Sleep(120);
	}
}

void controlV2(int score,char c)
{
	if (score < 10)
	{
		if (c == 'j')  //移动加速
		{
			Sleep(60);
			return;
		}
		Sleep(150);
	}
	else if (score < 20)
	{
		if (c == 'j')
		{
			Sleep(60);
			return;
		}
		Sleep(120);
	}
	else
	{
		if (c == 'j')
		{
			Sleep(60);
			return;
		}
		Sleep(100);
	}
}

void controlV3(int score,char c)
{
	if (score < 10)
	{
		if (c == 'j')  //移动加速
		{
			Sleep(60);
			return;
		}
		Sleep(90);
	}
	else if (score < 20)
	{
		if (c == 'j')
		{
			Sleep(60);
			return;
		}
		Sleep(80);
	}
	else
	{
		if (c == 'j')
		{
			Sleep(60);
			return;
		}
		Sleep(70);
	}
}

void drawPicture(S *h,F *f,F *bigf,char *s)
{
	
	setfillcolor(RGB(255, 255, 255));  //背景眼色
	bar(0, 0, 1155, 700);
	setfillcolor(EGERGB(R, G, B));
	bar(840, 0, 1155, 700);  //游戏提醒
	setfont(60, 25, "楷体");
	outtextxy(895, 55, "游戏说明");
	setfont(35, 15, "楷体");
	outtextxy(870, 155, "通过方向键或 w、s、");
	setfont(35, 15, "楷体");
	outtextxy(870, 205, "a和d控制蛇移动的方");
	setfont(35, 15, "楷体");
	outtextxy(870, 255, "向；随着得分的增加，");
	setfont(35, 15, "楷体");
	outtextxy(870, 305, "蛇移动的速度也会越");
	setfont(35, 15, "楷体");
	outtextxy(870, 355, "来越快。按空格可使");
	setfont(35, 15, "楷体");
	outtextxy(870, 405, "游戏暂停，暂停后，");
	setfont(35, 15, "楷体");
	outtextxy(870, 455, "按任意键继续游戏。");
	setfont(35, 15, "楷体");
	outtextxy(870, 505, "期待你的超神发挥！");
	setfont(35, 15, "宋体");
	outtextxy(870, 555, "good luck for you!");
	setfont(60, 30, "宋体");
	outtextxy(870, 600, "得分：");
	setfont(60, 30, "宋体");
	outtextxy(1050, 600, s);  //游戏得分

	S *p = h;
	//画蛇
	while (p != NULL)  
	{
		setfillcolor(EGERGB(75, 233, 239));
		bar(p->x, p->y, p->x + 20, p->y + 20);
		p = p->next;
	}
	//画食物
	setfillcolor(EGERGB(255, 174, 200));
	fillellipse(f->x, f->y,10,10);
    //画大食物
	setfillcolor(EGERGB(255, 174, 200));
	fillellipse(bigf->x, bigf->y, 20, 20);
}

void gameStart()
{
	srand((unsigned)time(NULL));
	initgraph(1155, 700);
	PIMAGE img;
	img= newimage();
	getimage(img, "欢迎界面.png");
	putimage(-100, 0, img);
	mciSendString("open RocBoys.mp3 alias AA", 0, 0, 0);  //背景音乐
	mciSendString("play AA repeat", 0, 0, 0);
	setbkcolor(RGB(R, G, B));
	setcolor(RGB(rand() % 255, rand() % 255, rand() % 255));
	setfont(80, 40, "楷体");
	outtextxy(250, 400, "按任意键进入游戏");
	getch();
}

void gameStart1()
{
	while (1)
	{
		PIMAGE img;
		img = newimage();
		getimage(img, "游戏选择.png");
		putimage(0, 0, img);
		MOUSEMSG  m;  //鼠标结构体
		setcolor(RED);
		rectangle(360, 260, 800, 370);
		setcolor(RED);
		rectangle(360, 390, 800, 500);
		setcolor(RED);
		rectangle(360, 520, 800, 630);
		while (1)
		{
			m = GetMouseMsg();
			if (m.x >= 1050 && m.x <= 1150 && m.y >= 0 && m.y <= 100)  //鼠标位于退出游戏范围
				if (m.uMsg == WM_LBUTTONDOWN)  //点击左键
				{
					setfillcolor(RGB(255, 255, 255));
					bar(0, 0, 1155, 700);
					setfont(250, 120, "楷体");
					outtextxy(330, 225, "再见");
					Sleep(1000);
					exit(0);
				}
			if (m.x >= 360 && m.x <= 800 && m.y >= 260 && m.y <= 370)  //鼠标位于开始游戏范围
			{
				if (m.uMsg == WM_LBUTTONDOWN)  
				{
					gameStart2();  //选择难度
					if (Dif == 0)
						break;
					SNAKE();  //开始游戏
					//游戏结束结束重置得分和移动方向
					score = 0;
					c = 77;
					break;
				}
			}
			if (m.x >= 360 && m.x <= 800 && m.y >= 390 && m.y <= 500)  //鼠标位于游戏说明范围
			{
				if (m.uMsg == WM_LBUTTONDOWN)
				{
					gameDescription();
					break;
				}
			}
			if (m.x >= 360 && m.x <= 800 && m.y >= 520 && m.y <= 630)  //鼠标位于历史最高分范围
			{
				if (m.uMsg == WM_LBUTTONDOWN)
				{
					mostScore();
					break;
				}
			}
		}
	}
}

void gameStart2()
{
	srand((unsigned)time(NULL));
	PIMAGE img;
	img = newimage();
	getimage(img, "难度选择.png");
	putimage(0, 0, img);
	MOUSEMSG m;
	setcolor(RED);
	rectangle(450, 230, 670, 350);
	setcolor(RED);
	rectangle(450, 390, 670, 510);
	setcolor(RED);
	rectangle(450, 560, 670, 680);
	while (1)
	{
		m = GetMouseMsg();
		if (m.x >= 0 && m.x <= 100 && m.y >= 0 && m.y <= 60)  //鼠标位于返回范围
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				Dif = 0;
				break;
			}
		if (m.x >= 450 && m.x <= 670 && m.y >= 230 && m.y <= 350)  //鼠标位于简单难度范围
		{
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				Dif = 1;
				break;
			}
		}
		if (m.x >= 450 && m.x <= 670 && m.y >= 390 && m.y <= 510)  //鼠标位于中等难度范围
		{
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				Dif = 2;
				break;
			}
		}
		if (m.x >= 450 && m.x <= 670 && m.y >= 560 && m.y <= 680)  //鼠标位于困难难度范围
		{
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				Dif = 3;
				break;
			}
		}
	}
}

void endInterface()
{
	
	PIMAGE img;
	img = newimage();
	getimage(img, "游戏结束.png");
	putimage(0, 0, img);
	setfont(120, 60, "华文楷体");
	outtextxy(370, 330, "得分：");
	setfont(120, 60, "华文楷体");
	outtextxy(670, 330, s);
	getch();
}

void gameDescription()
{
	PIMAGE img;
	img = newimage();
	getimage(img, "游戏说明.png");
	putimage(0, 0, img);
	getch();
	
}

void mostScore()
{
	char st[6];
	srand((unsigned)time(NULL));
	PIMAGE img;
	img = newimage();
	getimage(img, "历史最高.png");
	putimage(0, 0, img);
	int t;
	FILE *fp;
	fp = fopen("SaveFile", "r");  //读文件
	if (fp  == NULL)  //为空说明第一次玩该游戏，没有得分纪录，显示暂无
	{
		setcolor(RGB(rand() % 255, rand() % 255, rand() % 255));
		setfont(160, 80, "楷体");
		outtextxy(400, 300, "暂无");
	}
	else  //不为空，则显示历史最高分数
	{
		fscanf(fp, "%d", &t);
		itoa(t, st, 10);
		setcolor(RGB(rand() % 255, rand() % 255, rand() % 255));
		setfont(160, 80, "楷体");
		outtextxy(490, 300, st);
		fclose(fp);
	}
	getch();
}

void save(int score)
{
	int t;
	FILE *fp;
	if ((fp = fopen("SaveFile", "r"))== NULL)  //读得方式打开文件为空时，所得分则为历史最高分
	{
		fp = fopen("SaveFile", "w");
		fprintf(fp, "%d", score);
	}
	//不为空时则读取文件中最高分数，与所得分进行比较，将大得数字重新存入文件。
	else
	{
		fp = fopen("SaveFile", "r+");  
		fscanf(fp, "%d", &t);
		if (t < score)
		{
			rewind(fp);
			fprintf(fp, "%d", score);
		}
	}
	fclose(fp);
}

void pauseGame()
{
	setfont(80, 40, "楷体");
	outtextxy(250, 250, "游戏暂停");
	getch();
}

void SNAKE()
{
	S *h, *t, p;  //蛇得头，中间以及尾节点
	srand((unsigned)time(NULL));  //随机数种子
	initSnake(&p);  //初始化蛇头
	h = t = &p;
	F f = { 610,410 };  //初始化食物
	F bigf = { -20,-20 };  //当不出现大食物时
	char addv='0';  //蛇加速
	int times = 0;  //大食物出现时间
	int m = 0;  //产生大食物得检索数
	int n = 0;  //进行有关大食物得操作的判断数
	int key = 0;  //规定随机产生大食物的条件
	while (1)
	{
		itoa(score, s, 10);  //将得分以10进制转化为字符串到s中
		drawPicture(h, &f, &bigf, s);  //画图
		if (Dif == 1)  //简单难度
			controlV1(score,addv);
		if (Dif == 2)  //中等难度
			controlV2(score,addv);
		if (Dif == 3)  //困难难度
			controlV3(score,addv);
		addv = '0';  //初始加速键
		snakeMove(h, t, c);  //蛇的移动
		if (isSnakeEatMeetFood(h, &f))  //吃到食物
		{
			//难度不同得分不同
			if (Dif == 1)
				score++;
			if (Dif == 2)
				score += 2;
			if (Dif == 3)
				score += 5;
			n = 0;  //每次吃到食物初始产生大食物的判断数
			t = snakeGrow(h);  //蛇增长一节
			//随机生成食物，直到不与蛇身重合
			do
			{
				creatFood(&f);
			} while (isOverlapSnake(&f, h));
		}
		//产生随机数，随机数为1时，产生大食物
		//srand((unsigned)time(NULL));  //随机数种子
		//int r = rand() % 20;
		if (score % 35 == 0 && score != 0)
			key = 1;
		//当产生的随机数为 1 时，且当小食物被吃后，产生大食物
		if (key == 1 && n == 0)
		{
			m ++;  //当第一次进入该分支时，产生大食物
			times++;  //每进入该分支一次，时间检索数增加
			if (m == 1)
			{
				//产生大食物，知道不与食物和蛇生重合为止
				do
				{
					creatBigFood(&bigf);
				} while (isBigOverlapSnake(&bigf, h) || isBigfOverlapf(&bigf, &f));
			}
			//当时间大于等于73时，并且蛇没有吃到大食物，大食物消失
			if (times >= 73 && isSnakeEatMeetBigFood(h, &bigf) == 0)
			{
				//初始化大食物坐标
				(&bigf)->x = -20;
				(&bigf)->y = -20;
				m = 0;  //初始产生大食物得检索数
				n = 1;  //初始进行有关大食物得操作的判断数
				times = 0;  //初始大食物出现时间
				key = 0;  //初始规定随机产生大食物的条件
				
			}
			//当时间小于73时，并且蛇吃到大食物后，大食物消失
			if (times < 73 && isSnakeEatMeetBigFood(h, &bigf) == 1)
			{
				t = snakeGrow(h);  //蛇增长一节
				score = score + 10;  //得分加10
				//初始大食物坐标
				(&bigf)->x = -20;  
				(&bigf)->y = -20;
				m = 0;  //初始产生大食物得检索数
				n = 1;  //初始进行有关大食物得操作的判断数
				times = 0;  //初始大食物出现时间
				key = 0;  //初始规定随机产生大食物的条件
				
			}
		}
		//按键盘
		if (kbhit())  
		{
			char c1;
			c1 = changedir(c);
			//当按空格时，暂停游戏
			if (c1 == ' ')  
			{
				pauseGame();
			}
			//当按j时，加速蛇得移动
			else if (c1 == 'j') {
				addv = c1;
			}
			//当按q时，退出游戏
			else if (c1 == 'q') {
				break;
			}
			else c = c1;
		}
		//游戏结束
		if (gameover(h))
		{
			save(score);  //与最高分比较
			endInterface();  
			break;
		}
	}
}

int changedir(int c)  
{
	int c1 = getch();
	if (c1 == ' ')return ' ';  //按空格时
	if (c1 == 'j')return 'j';  //按j键
	if (c1 == 'q' || c1 == 27) return 'q';  //按q键
	if ((c != 68 && c != 100) && (c1 == 65 || c1 == 97)) c = c1;  //当按下a键且蛇移动方向不为d时，向左移动
	else if ((c != 65 && c != 97) && (c1 == 100)) c = c1;  //当按下d键且蛇移动方向不为a时，向右移动
	else if ((c != 87 && c != 119) && (c1 == 83 || c1 == 115)) c = c1;  //当按下s键且蛇移动方向不为w时，向下移动
	else if ((c != 83 && c != 115) && (c1 == 87 || c1 == 119)) c = c1;  //当按下w键且蛇移动方向不为s时，向上移动
	return c;
}

//大食物为圆形，坐标为圆心
void creatBigFood(F *bigf) 
{
	bigf->x = (rand() % 21) * 40 + 20;  
	bigf->y = (rand() % 17) * 40 + 20;
}

int isSnakeEatMeetBigFood(S *h, F *bigf)
{
	if ((h->x == (bigf->x - 20) && h->y == (bigf->y - 20)) ||
		(h->x == (bigf->x - 20) && h->y == (bigf->y)) || 
		(h->x == (bigf->x) && h->y == (bigf->y - 20))|| 
		(h->x == (bigf->x) && h->y == (bigf->y)))
		return 1;
	else
		return 0;
}

int isBigOverlapSnake(F *bigf, S *h)
{
	S *q = h;
	while (q != NULL)
	{
		if ((q->x == (bigf->x - 20) && q->y == (bigf->y - 20)) ||
			(q->x == (bigf->x - 20) && q->y == (bigf->y)) ||
			(q->x == (bigf->x) && q->y == (bigf->y - 20)) ||
			(q->x == (bigf->x) && q->y == (bigf->y)))
			return 1;
		q = q->next;
	}
	return 0;
}

int isBigfOverlapf(F *bigf, F *f)
{
	if ((f->x == (bigf->x - 10) && f->y == (bigf->y - 10)) ||
		(f->x == (bigf->x - 10) && f->y == (bigf->y + 10)) ||
		(f->x == (bigf->x + 10) && f->y == (bigf->y - 10)) ||
		(f->x == (bigf->x + 10) && f->y == (bigf->y + 10)))
		return 1;
	else 
		return 0;
}