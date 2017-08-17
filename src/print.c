#include "print.h"
#include <stdio.h>

int s_x = 9+2+28+2+4;
int s_y = 4+1+6+1+5;
int l_x = 9+2+28+2+4;
int l_y = 4+1+6+1+10;

int num,mode,color;
int n_num,n_mode,n_color;
int i_x = 9+2+28/2-1,i_y = 6;
int n_x = 46,n_y = 8;
int x,y;

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
		{0,1,0,0, 0,1,0,0, 1,1,0,0, 0,0,0,0, 2,1}
	},
};

#ifdef WIN32	//Windows 
#include <windows.h>

HANDLE hand;

#define gotoxy(x,y) do{\
	COORD loc;\
	loc.X = x;\
	loc.Y = y;\
	SetConsoleCursorPosition(hand, loc);\
}while(0)

#define print(ch, color) do{printf("\033[45m \033[0m")}while(0)


#else

#define gotoxy(x,y) do{printf("\033[y;xH");}while(0)
#define p

}


#endif

#ifdef WIN32	//Windows 
#include <windows.h>

#define gotoxy(x,y) 

HANDLE hand;



void print_start_interface()
{
	hand = GetStdHandle(STD_OUTPUT_HANDLE);
	
	//隐藏光标 
	CONSOLE_CURSOR_INFO cursor_info = {100, 0};
	SetConsoleCursorInfo(hand, &cursor_info);
	
	gotoxy(10, 20);
	
	printf("hello world\n");
	
	
	//清屏
	//打印分数等级位置

	//打印边框 行，（5,10-58） （30，10-58）
	//打印另外一行，（12，42-56）



	//打印边框 列三条（5-31,10）（5-31,40）（5-31,56）

	//隐藏光标
}

//指定位置，输出图形
void print_mode_shape(int n,int m,int x,int y,int c)
{
	//指定位置输出方块
	fflush(NULL);
}

//消除制定位置的图形
void eraser_shape(int n,int m,int x,int y,int c)
{
	//指定位置消除方块
}

//输出下一个将要出现的图形
void print_next()
{
	//消除原有图形
	//获取下一图形，打印输出，随机数及函数调用

}

#else	//Linux 

void print_start_interface()
{
	//清屏
	int l;
	int w;
	printf("\033[2J");
	int a, b;

	for (l = 5; l < 30; l++)
	{
		a = 10;
		b = l;
		printf("\033[%d;%dH\033[45m  \033[0m", b, a);
		a = 39;
		printf("\033[%d;%dH\033[45m  \033[0m", b, a);
		a = 58;
		printf("\033[%d;%dH\033[45m  \033[0m", b, a);
	}
	for (w = 10; w < 59; w++)
	{
		a=w;
		b=5;
		printf("\033[%d;%dH\033[45m  \033[0m",b,a);
		b=30;
		printf("\033[%d;%dH\033[45m  \033[0m",b,a);		
	}
	//打印分数等级位置
	printf("\033[%d;%dH分数:\033[0m", s_y, s_x);
	printf("\033[%d;%dH等级:\033[0m", l_y, l_x);
	//打印边框 行，（5,10-58） （30，10-58）
	//打印另外一行，（12，42-56）
	for(w=40;w<59;w++)
	{	
		 b=12;
		 a=w;
		 printf("\033[%d;%dH\033[45m \033[0m",b,a);
	}
	//打印边框 列三条（5-31,10）（5-31,40）（5-31,56）
	//隐藏光标
	printf("\033[?25h");
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
		if(shape[n][m][i]==1)
		{
			printf("\033[%d;%dH\033[%dm[]\033[0m",m_y,m_x,c);
		}
		m_x = m_x+2;
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
			printf("\033[%d;%dH  \033[0m", m_y, m_x);
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
	printf("\033%d;%dH\33[45m Game Over!!\033[0m\n",i_y,i_x);
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
				printf("\033[%d;%dH  \033[0m", w + 5, l + 12);
			}
			else
			{
				printf("\033[%d;%dH\33[%dm[]\033[0m", w + 5, l + 12, color);
			}
		}
	}
}

//打印方块分数及等级
void print_score_level()
{
	i_x=s_x+2;
	i_y=s_y;
	printf("\033[%d;%dH\33[46m%d\033[0m\n",i_y,i_x,score);
	i_x=l_x+2;
	i_y=l_y;
	printf("\033[%d;%dH\33[46m%d\033[0m\n",i_y,i_x,level);
}

#endif
