#include <time.h>
#include <iostream>
#include <graphics.h>

#define SCREEN_WIDTH 1560 //屏幕的宽度
#define SCREEN_HEIGHT 640 // 屏幕的高度
#define RAIN_NUM 100 //字符串的数量

char g_StrRain[RAIN_NUM][10] = { 0 };  //数字雨字符串
POINT g_RainPos[RAIN_NUM] = { 0 };  //数字雨开始的位置

void InitGame()
{
	//随机生成数字雨
	char RandChar = 0;
	for (int i = 0; i < RAIN_NUM; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			while (1)
			{
				RandChar = rand() % 123;
				if ((RandChar >= 65 && RandChar <= 90) || (RandChar >= 97 && RandChar <= 122))
					break;
			}
			g_StrRain[i][j] = RandChar;
		}
	}

	//随机生成位置
	for (int i = 0; i < RAIN_NUM; i++)
	{
		g_RainPos[i].x = rand() % SCREEN_WIDTH;
		g_RainPos[i].y = rand() % SCREEN_HEIGHT;
	}
}

void UpdateGame()
{
	for (int i = 0; i < RAIN_NUM; i++)
	{
		g_RainPos[i].y += 15;
		if (g_RainPos[i].y - 10 * 15 >= SCREEN_HEIGHT)
		{
			g_RainPos[i].x = rand() % SCREEN_WIDTH;
			g_RainPos[i].y = 0;
		}
	}
}

void RenderGame()
{
	BeginBatchDraw();
	cleardevice();

	for (int i = 0; i < RAIN_NUM; i++)
	{
		settextcolor(RGB(255, 255, 255)); // 白色
		for (int j = 0; j < 8; j++)
		{
			outtextxy(g_RainPos[i].x, g_RainPos[i].y - 15 * j, g_StrRain[i][j]);
			settextcolor(RGB(0, 255 - 28 * j, 0));
		}
	}
	EndBatchDraw();
	Sleep(100);
}

int main()
{
	//创建窗口
	HWND hwnd = initgraph(GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN));
	//设置窗口风格
	SetWindowLong(hwnd, GWL_STYLE, GetWindowLong(hwnd, GWL_STYLE) - WS_CAPTION);
	//设置窗口位置
	SetWindowPos(hwnd, HWND_TOPMOST, 0, 0, GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN), SWP_SHOWWINDOW);
	//设置为透明
	LONG WindowLong = GetWindowLong(hwnd, GWL_EXSTYLE) | WS_EX_LAYERED;
	//设置窗口风格
	SetWindowLong(hwnd,GWL_EXSTYLE,WindowLong);
	//背景修改为黑色
	SetLayeredWindowAttributes(hwnd, RGB(0, 0, 0), 0, LWA_COLORKEY);

	srand((unsigned)time(NULL));
	InitGame();
	while (1)
	{
		RenderGame();
		UpdateGame();
	}

	closegraph();
	return 0;
}