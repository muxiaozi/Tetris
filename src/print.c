#include "print.h"
#include <stdio.h>

int s_x = 9+2+28+2+4;
int s_y = 4+1+6+1+5;
int l_x = 9+2+28+2+4;
int l_y = 4+1+6+1+10;



int num, mode, color;
int n_num, n_mode, n_color;
int i_x = 9+2+28/2-1, i_y = 6;
int n_x = 46, n_y = 8;
int x, y;

static char num_buf[8];
//shape[][][16]:距离 右侧空格项  [17]:距离 下方空格项
int shape[7][4][18] = 
	{
		{
			{1,1,0,0, 1,1,0,0, 0,0,0,0, 0,0,0,0, 2,2},
			{1,1,0,0, 1,1,0,0, 0,0,0,0, 0,0,0,0, 2,2},
			{1,1,0,0, 1,1,0,0, 0,0,0,0, 0,0,0,0, 2,2},
			{1,1,0,0, 1,1,0,0, 0,0,0,0, 0,0,0,0, 2,2},
		},
		{
			{1,0,0,0, 1,0,0,0, 1,0,0,0, 1,0,0,0, 3,0},
			{1,1,1,1, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,3},
			{1,0,0,0, 1,0,0,0, 1,0,0,0, 1,0,0,0, 3,0},
			{1,1,1,1, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,3},
		},
		{
			{0,1,0,0, 1,1,1,0, 0,0,0,0, 0,0,0,0, 1,2},
			{1,0,0,0, 1,1,0,0, 1,0,0,0, 0,0,0,0, 2,1},
			{1,1,1,0, 0,1,0,0, 0,0,0,0, 0,0,0,0, 1,2},
			{0,1,0,0, 1,1,0,0, 0,1,0,0, 0,0,0,0, 2,1}
		},
		{
			{1,1,0,0, 0,1,1,0, 0,0,0,0, 0,0,0,0, 1,2},
			{0,1,0,0, 1,1,0,0, 1,0,0,0, 0,0,0,0, 2,1},
			{1,1,0,0, 0,1,1,0, 0,0,0,0, 0,0,0,0, 1,2},
			{0,1,0,0, 1,1,0,0, 1,0,0,0, 0,0,0,0, 2,1},
		},
		{
			{0,1,1,0, 1,1,0,0, 0,0,0,0, 0,0,0,0, 1,2},
			{1,0,0,0, 1,1,0,0, 0,1,0,0, 0,0,0,0, 2,1},
			{0,1,1,0, 1,1,0,0, 0,0,0,0, 0,0,0,0, 1,2},
			{1,0,0,0, 1,1,0,0, 0,1,0,0, 0,0,0,0, 2,1},
		},
		{
			{0,0,1,0, 1,1,1,0, 0,0,0,0, 0,0,0,0, 1,2},
			{1,0,0,0, 1,0,0,0, 1,1,0,0, 0,0,0,0, 2,1},
			{1,1,1,0, 1,0,0,0, 0,0,0,0, 0,0,0,0, 1,2},
			{1,1,0,0, 1,0,0,0, 1,0,0,0, 0,0,0,0, 2,1}
		},
		{
			{1,0,0,0, 1,1,1,0, 0,0,0,0, 0,0,0,0, 1,2},
			{1,1,0,0, 1,0,0,0, 1,0,0,0, 0,0,0,0, 2,1},
			{1,1,1,0, 0,0,1,0, 0,0,0,0, 0,0,0,0, 1,2},
			{0,1,0,0, 0,1,0,0, 1,1,0,0, 0,0,0,0, 2,1}},
	};

#ifdef WIN32 //Windows
#include <windows.h>

#define random() rand()

const int COLORS[6] = {
	0xf0,0xf0,0xf0,0x0f,0xf0,0xf0
};

HANDLE hand;

void gotoxy(int x, int y){
	COORD loc;
	loc.X = x;
	loc.Y = y;
	SetConsoleCursorPosition(hand, loc);
}

void print(char *str, int c)
{
	SetConsoleTextAttribute(hand, COLORS[c - 41]);
	printf("%s", str);
}

void clear(){
	system("cls");
}

void setCursorVisable(int v){
	CONSOLE_CURSOR_INFO cursor_info = {100, v};
	SetConsoleCursorInfo(hand, &cursor_info);
}

#else //Linux

void gotoxy(x,y) 
{
	printf("\033[%d;%dH", y, x);
}

void print(char *str, int c){
	printf("\033[%dm%s\033[0m", c, str);
}

void clear(){
	printf("\033[2J");
}

void setCursorVisable(int v){
	if(v){
		printf("\033[?25h");
	}else{
		printf("\033[?25l");
	}
}

#endif //WIN32

void printxy(char *str, int color, int x, int y){
	gotoxy(x, y);
	print(str, color);
}

void print_start_interface()
{
#ifdef WIN32 //Windows
	//get output handle 
	hand = GetStdHandle(STD_OUTPUT_HANDLE);
#endif
	//清屏
	int l;
	int w;
	clear();
	int a, b;

	for (l = 5; l < 30; l++)
	{
		a = 10;
		b = l;
		printxy(" ", 45, a, b);
		a = 40;
		printxy(" ", 45, a, b);
		a = 58;
		printxy(" ", 45, a, b);
	}
	for (w = 10; w < 59; w++)
	{
		a=w;
		b=5;
		printxy(" ", 45, a, b);
		b=30;
		printxy(" ", 45, a, b);
	}
	//打印分数等级位置
	printxy("Score:", 45, s_x, s_y);
	printxy("Level:", 45, l_x, l_y);
	//打印边框 行，（5,10-58） （30，10-58）
	//打印另外一行，（12，42-56）
	for(w=40;w<59;w++)
	{	
		 b=12;
		 a=w;
		 printxy(" ", 45, a, b);
	}
	//打印边框 列三条（5-31,10）（5-31,40）（5-31,56）
	//隐藏光标
	setCursorVisable(0);
}


//指定位置，输出图形
void print_mode_shape(int n, int m, int x, int y, int c)
{
	//指定位置输出方块
	int m_x = x;
	int m_y = y;
	int i;
	for (i = 0; i < 16; i++)
	{
		if (i != 0 && i % 4 == 0)
		{
			m_x = x;
			m_y++;
		}	
		if(shape[n][m][i] == 1)
		{
			printxy("[]", c, m_x, m_y);
		}
		m_x = m_x + 2;
	}	
	fflush(NULL);
}


//消除制定位置的图形
void eraser_shape(int n, int m, int x, int y, int c)
{
	//指定位置消除方块
	int m_x = x;
	int m_y = y;
	int i;
	for (i = 0; i < 16; i++)
	{
		if( i != 0 && i % 4 == 0)
		{
			m_x = x;
			m_y++;
		}
		if(shape[n][m][i]==1)
		{
			printxy("  ", c, m_x, m_y);
		}
		m_x = m_x + 2;
	}
}




//输出下一个将要出现的图形
void print_next()
{
	//消除原有图形
	eraser_shape(n_num,n_mode,n_x,n_y,n_color);
	//获取下一图形，打印输出，随机数及函数调用
	//	srand(time(NULL));
	n_num = random()%(6-0+1)+0;
	n_mode = random()%(3-0+1)+0;
	n_color = random()%(46-41+1)+41;
	print_mode_shape(n_num, n_mode, n_x, n_y, n_color);
}



void game_over()
{
	//固定地点打印游戏结束字样
	i_x=9+2+10;
	i_y=4+1+9+1;
	printxy(" Game Over!!", 45, i_x, i_y);
	return ;
}



//打印棋盘
void print_matrix()
{
	int l;
	int w;
	for (w = 0; w < 24; w++)
	{
		for(l = 0; l < 28; l += 2)
		{
			if (matrix[w][l] == 0)
			{
				printxy("  ", 45, l + 12, w + 6);
			}
			else
			{
				printxy("[]", matrix[w][l + 1], l + 12, w + 6);
			}
		}
	}
}

//打印方块分数及等级
void print_score_level()
{
	int ss_x=s_x+5;
	int ss_y=s_y;
	int lv_x = l_x + 5;
	int lv_y = l_y;
	
	printxy(itoa(score, num_buf, 10), 46, ss_x, ss_y);
	i_x=l_x+2;
	i_y=l_y;
	printxy(itoa(level, num_buf, 10), 46, lv_x, lv_y);
}


