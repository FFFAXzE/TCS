#include<graphics.h>
#include<time.h>
#include"snake.h"

#define R 242
#define G 208
#define B 162
int Dif = -1;  //��Ϸ�Ѷ�ֵ
char s[6];  //�ȷ���ֵת��Ϊ�ַ���
int score ;  //�÷�
int  c = 77;  //�ƶ�����


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
	while (p != h)  //�����ƶ�ʱ��ÿ�ƶ�һ�Σ���һ�������������ǰһ����������
	{
		p->x = p->pre->x;
		p->y = p->pre->y;
		p = p->pre;
	}

	if (c == 68||c == 100)  //��λ��Ϊd����D�����ƶ�
	{
		h->x += 20;
		h->y = h->y;
	}
	else if ( c == 65 || c == 97)  //��λ��Ϊa����A�����ƶ�
	{
		h->x -= 20;
		h->y = h->y;
	}
	else if ( c == 83 || c == 115)  //��λ��Ϊs����S�����ƶ�
	{
		h->y += 20;
		h->x = h->x;
	}
	else if ( c == 87 || c == 119)  //��λ��Ϊw����D�����ƶ�
	{
		h->y -= 20;
		h->x = h->x;
	}
}

int isSnakeEatMeetFood(S *h, F *f)
{
	//����������,���ߵ�������ʳ�������ͬʱ������ʳ���غ�
	if (h->x == (f->x-10)&&h->y == (f->y-10))  //�ߵ���״Ϊ�����Σ�ʳ����״ΪԲ�Σ�
		return 1;
	else
		return 0;
}

S *snakeGrow(S *h)
{
	S *p = (S*)malloc(sizeof(S));  //���붯̬�ռ�
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
		if (q->x == (f->x-10)&&q->y == (f->y-10))  //ʳ��ΪԲ�Σ�����ΪԲ��
			return 1;
		q = q->next;
	}
	return 0;
}

int gameover(S *h)
{
	S *p = h;
	if (p->x <= -1 || p->y <= -1 || p->x>=840 || p->y>=700)  //��������ǽ��
		return 1;
	p = p->next;
	while (p!= NULL)  //������������
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
		if (c == 'j') //�ƶ�����
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
		if (c == 'j')  //�ƶ�����
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
		if (c == 'j')  //�ƶ�����
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
	
	setfillcolor(RGB(255, 255, 255));  //������ɫ
	bar(0, 0, 1155, 700);
	setfillcolor(EGERGB(R, G, B));
	bar(840, 0, 1155, 700);  //��Ϸ����
	setfont(60, 25, "����");
	outtextxy(895, 55, "��Ϸ˵��");
	setfont(35, 15, "����");
	outtextxy(870, 155, "ͨ��������� w��s��");
	setfont(35, 15, "����");
	outtextxy(870, 205, "a��d�������ƶ��ķ�");
	setfont(35, 15, "����");
	outtextxy(870, 255, "�����ŵ÷ֵ����ӣ�");
	setfont(35, 15, "����");
	outtextxy(870, 305, "���ƶ����ٶ�Ҳ��Խ");
	setfont(35, 15, "����");
	outtextxy(870, 355, "��Խ�졣���ո��ʹ");
	setfont(35, 15, "����");
	outtextxy(870, 405, "��Ϸ��ͣ����ͣ��");
	setfont(35, 15, "����");
	outtextxy(870, 455, "�������������Ϸ��");
	setfont(35, 15, "����");
	outtextxy(870, 505, "�ڴ���ĳ��񷢻ӣ�");
	setfont(35, 15, "����");
	outtextxy(870, 555, "good luck for you!");
	setfont(60, 30, "����");
	outtextxy(870, 600, "�÷֣�");
	setfont(60, 30, "����");
	outtextxy(1050, 600, s);  //��Ϸ�÷�

	S *p = h;
	//����
	while (p != NULL)  
	{
		setfillcolor(EGERGB(75, 233, 239));
		bar(p->x, p->y, p->x + 20, p->y + 20);
		p = p->next;
	}
	//��ʳ��
	setfillcolor(EGERGB(255, 174, 200));
	fillellipse(f->x, f->y,10,10);
    //����ʳ��
	setfillcolor(EGERGB(255, 174, 200));
	fillellipse(bigf->x, bigf->y, 20, 20);
}

void gameStart()
{
	srand((unsigned)time(NULL));
	initgraph(1155, 700);
	PIMAGE img;
	img= newimage();
	getimage(img, "��ӭ����.png");
	putimage(-100, 0, img);
	mciSendString("open RocBoys.mp3 alias AA", 0, 0, 0);  //��������
	mciSendString("play AA repeat", 0, 0, 0);
	setbkcolor(RGB(R, G, B));
	setcolor(RGB(rand() % 255, rand() % 255, rand() % 255));
	setfont(80, 40, "����");
	outtextxy(250, 400, "�������������Ϸ");
	getch();
}

void gameStart1()
{
	while (1)
	{
		PIMAGE img;
		img = newimage();
		getimage(img, "��Ϸѡ��.png");
		putimage(0, 0, img);
		MOUSEMSG  m;  //���ṹ��
		setcolor(RED);
		rectangle(360, 260, 800, 370);
		setcolor(RED);
		rectangle(360, 390, 800, 500);
		setcolor(RED);
		rectangle(360, 520, 800, 630);
		while (1)
		{
			m = GetMouseMsg();
			if (m.x >= 1050 && m.x <= 1150 && m.y >= 0 && m.y <= 100)  //���λ���˳���Ϸ��Χ
				if (m.uMsg == WM_LBUTTONDOWN)  //������
				{
					setfillcolor(RGB(255, 255, 255));
					bar(0, 0, 1155, 700);
					setfont(250, 120, "����");
					outtextxy(330, 225, "�ټ�");
					Sleep(1000);
					exit(0);
				}
			if (m.x >= 360 && m.x <= 800 && m.y >= 260 && m.y <= 370)  //���λ�ڿ�ʼ��Ϸ��Χ
			{
				if (m.uMsg == WM_LBUTTONDOWN)  
				{
					gameStart2();  //ѡ���Ѷ�
					if (Dif == 0)
						break;
					SNAKE();  //��ʼ��Ϸ
					//��Ϸ�����������õ÷ֺ��ƶ�����
					score = 0;
					c = 77;
					break;
				}
			}
			if (m.x >= 360 && m.x <= 800 && m.y >= 390 && m.y <= 500)  //���λ����Ϸ˵����Χ
			{
				if (m.uMsg == WM_LBUTTONDOWN)
				{
					gameDescription();
					break;
				}
			}
			if (m.x >= 360 && m.x <= 800 && m.y >= 520 && m.y <= 630)  //���λ����ʷ��߷ַ�Χ
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
	getimage(img, "�Ѷ�ѡ��.png");
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
		if (m.x >= 0 && m.x <= 100 && m.y >= 0 && m.y <= 60)  //���λ�ڷ��ط�Χ
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				Dif = 0;
				break;
			}
		if (m.x >= 450 && m.x <= 670 && m.y >= 230 && m.y <= 350)  //���λ�ڼ��Ѷȷ�Χ
		{
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				Dif = 1;
				break;
			}
		}
		if (m.x >= 450 && m.x <= 670 && m.y >= 390 && m.y <= 510)  //���λ���е��Ѷȷ�Χ
		{
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				Dif = 2;
				break;
			}
		}
		if (m.x >= 450 && m.x <= 670 && m.y >= 560 && m.y <= 680)  //���λ�������Ѷȷ�Χ
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
	getimage(img, "��Ϸ����.png");
	putimage(0, 0, img);
	setfont(120, 60, "���Ŀ���");
	outtextxy(370, 330, "�÷֣�");
	setfont(120, 60, "���Ŀ���");
	outtextxy(670, 330, s);
	getch();
}

void gameDescription()
{
	PIMAGE img;
	img = newimage();
	getimage(img, "��Ϸ˵��.png");
	putimage(0, 0, img);
	getch();
	
}

void mostScore()
{
	char st[6];
	srand((unsigned)time(NULL));
	PIMAGE img;
	img = newimage();
	getimage(img, "��ʷ���.png");
	putimage(0, 0, img);
	int t;
	FILE *fp;
	fp = fopen("SaveFile", "r");  //���ļ�
	if (fp  == NULL)  //Ϊ��˵����һ�������Ϸ��û�е÷ּ�¼����ʾ����
	{
		setcolor(RGB(rand() % 255, rand() % 255, rand() % 255));
		setfont(160, 80, "����");
		outtextxy(400, 300, "����");
	}
	else  //��Ϊ�գ�����ʾ��ʷ��߷���
	{
		fscanf(fp, "%d", &t);
		itoa(t, st, 10);
		setcolor(RGB(rand() % 255, rand() % 255, rand() % 255));
		setfont(160, 80, "����");
		outtextxy(490, 300, st);
		fclose(fp);
	}
	getch();
}

void save(int score)
{
	int t;
	FILE *fp;
	if ((fp = fopen("SaveFile", "r"))== NULL)  //���÷�ʽ���ļ�Ϊ��ʱ�����÷���Ϊ��ʷ��߷�
	{
		fp = fopen("SaveFile", "w");
		fprintf(fp, "%d", score);
	}
	//��Ϊ��ʱ���ȡ�ļ�����߷����������÷ֽ��бȽϣ�������������´����ļ���
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
	setfont(80, 40, "����");
	outtextxy(250, 250, "��Ϸ��ͣ");
	getch();
}

void SNAKE()
{
	S *h, *t, p;  //�ߵ�ͷ���м��Լ�β�ڵ�
	srand((unsigned)time(NULL));  //���������
	initSnake(&p);  //��ʼ����ͷ
	h = t = &p;
	F f = { 610,410 };  //��ʼ��ʳ��
	F bigf = { -20,-20 };  //�������ִ�ʳ��ʱ
	char addv='0';  //�߼���
	int times = 0;  //��ʳ�����ʱ��
	int m = 0;  //������ʳ��ü�����
	int n = 0;  //�����йش�ʳ��ò������ж���
	int key = 0;  //�涨���������ʳ�������
	while (1)
	{
		itoa(score, s, 10);  //���÷���10����ת��Ϊ�ַ�����s��
		drawPicture(h, &f, &bigf, s);  //��ͼ
		if (Dif == 1)  //���Ѷ�
			controlV1(score,addv);
		if (Dif == 2)  //�е��Ѷ�
			controlV2(score,addv);
		if (Dif == 3)  //�����Ѷ�
			controlV3(score,addv);
		addv = '0';  //��ʼ���ټ�
		snakeMove(h, t, c);  //�ߵ��ƶ�
		if (isSnakeEatMeetFood(h, &f))  //�Ե�ʳ��
		{
			//�ѶȲ�ͬ�÷ֲ�ͬ
			if (Dif == 1)
				score++;
			if (Dif == 2)
				score += 2;
			if (Dif == 3)
				score += 5;
			n = 0;  //ÿ�γԵ�ʳ���ʼ������ʳ����ж���
			t = snakeGrow(h);  //������һ��
			//�������ʳ�ֱ�����������غ�
			do
			{
				creatFood(&f);
			} while (isOverlapSnake(&f, h));
		}
		//����������������Ϊ1ʱ��������ʳ��
		//srand((unsigned)time(NULL));  //���������
		//int r = rand() % 20;
		if (score % 35 == 0 && score != 0)
			key = 1;
		//�������������Ϊ 1 ʱ���ҵ�Сʳ�ﱻ�Ժ󣬲�����ʳ��
		if (key == 1 && n == 0)
		{
			m ++;  //����һ�ν���÷�֧ʱ��������ʳ��
			times++;  //ÿ����÷�֧һ�Σ�ʱ�����������
			if (m == 1)
			{
				//������ʳ�֪������ʳ��������غ�Ϊֹ
				do
				{
					creatBigFood(&bigf);
				} while (isBigOverlapSnake(&bigf, h) || isBigfOverlapf(&bigf, &f));
			}
			//��ʱ����ڵ���73ʱ��������û�гԵ���ʳ���ʳ����ʧ
			if (times >= 73 && isSnakeEatMeetBigFood(h, &bigf) == 0)
			{
				//��ʼ����ʳ������
				(&bigf)->x = -20;
				(&bigf)->y = -20;
				m = 0;  //��ʼ������ʳ��ü�����
				n = 1;  //��ʼ�����йش�ʳ��ò������ж���
				times = 0;  //��ʼ��ʳ�����ʱ��
				key = 0;  //��ʼ�涨���������ʳ�������
				
			}
			//��ʱ��С��73ʱ�������߳Ե���ʳ��󣬴�ʳ����ʧ
			if (times < 73 && isSnakeEatMeetBigFood(h, &bigf) == 1)
			{
				t = snakeGrow(h);  //������һ��
				score = score + 10;  //�÷ּ�10
				//��ʼ��ʳ������
				(&bigf)->x = -20;  
				(&bigf)->y = -20;
				m = 0;  //��ʼ������ʳ��ü�����
				n = 1;  //��ʼ�����йش�ʳ��ò������ж���
				times = 0;  //��ʼ��ʳ�����ʱ��
				key = 0;  //��ʼ�涨���������ʳ�������
				
			}
		}
		//������
		if (kbhit())  
		{
			char c1;
			c1 = changedir(c);
			//�����ո�ʱ����ͣ��Ϸ
			if (c1 == ' ')  
			{
				pauseGame();
			}
			//����jʱ�������ߵ��ƶ�
			else if (c1 == 'j') {
				addv = c1;
			}
			//����qʱ���˳���Ϸ
			else if (c1 == 'q') {
				break;
			}
			else c = c1;
		}
		//��Ϸ����
		if (gameover(h))
		{
			save(score);  //����߷ֱȽ�
			endInterface();  
			break;
		}
	}
}

int changedir(int c)  
{
	int c1 = getch();
	if (c1 == ' ')return ' ';  //���ո�ʱ
	if (c1 == 'j')return 'j';  //��j��
	if (c1 == 'q' || c1 == 27) return 'q';  //��q��
	if ((c != 68 && c != 100) && (c1 == 65 || c1 == 97)) c = c1;  //������a�������ƶ�����Ϊdʱ�������ƶ�
	else if ((c != 65 && c != 97) && (c1 == 100)) c = c1;  //������d�������ƶ�����Ϊaʱ�������ƶ�
	else if ((c != 87 && c != 119) && (c1 == 83 || c1 == 115)) c = c1;  //������s�������ƶ�����Ϊwʱ�������ƶ�
	else if ((c != 83 && c != 115) && (c1 == 87 || c1 == 119)) c = c1;  //������w�������ƶ�����Ϊsʱ�������ƶ�
	return c;
}

//��ʳ��ΪԲ�Σ�����ΪԲ��
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