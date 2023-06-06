#pragma once
#include <vector>
#include "HiEasyX/HiEasyX.h"

/*窗体和UI*/
class WindowAndUI
{
public:
	//实例化对象，不显示窗体
	WindowAndUI();

	//只指设置窗口大小，其余默认，并实例化对象，显示窗体
	WindowAndUI(const int W, const int H);

	//高度自定义窗体，并实例化对象，显示窗体
	WindowAndUI(const int WW, const int WH, const int CW, const int CH, COLORREF Color = WHITE, int WindowSystle = 1 | 4);

	//拷贝构造，仅实例化对象，不显示窗体，仅拷贝大小参数，不能复制原窗口的绘制内容
	WindowAndUI(const WindowAndUI& otherwnd);

	//operator=重载,仅实例化对象，不显示窗体，仅拷贝大小参数，不能复制原窗口的绘制内容
	void operator=(const WindowAndUI& otherwnd);

	~WindowAndUI();

private:
	hiex::Window* wnd = nullptr;
	hiex::Canvas* canva = nullptr;

	int windowsW;
	int windowsH;
	int canvaW;
	int canvaH;
	int window_systle = 1 | 4;
	COLORREF canva_color = WHITE;

public:
	int GetWindowWidth();
	int GetWindowHeight();
	int GetCanvaWidth();
	int GetCanvaHeight();
private:


public:	
	//设置窗口响应函数
	void SetWindowFunction(WNDPROC WindowProcess);

	//拷贝构造或=赋值后调用此函数以显示窗体
	void Create();

	//默认构造后调用此函数以显示窗体
	void Create(const int WW, const int WH, const int CW = 640, const int CH = 480, COLORREF Color = WHITE, int WindowSystle = 1 | 4);

	//获取窗口句柄
	HWND GetWindowHandle();

	//获取背景画布的Image指针
	IMAGE* GetCanvaImage();

	//重绘窗口
	void _Redraw();

	//判断窗口是否存在
	bool IsWindowAlive();

	//设置画线样式
	void _SetLineStyle(int style, int thickness, const DWORD* puserstyle = (DWORD*)nullptr, DWORD userstylecount = 0UL);

	//清空背景绘制的图像
	void _Clear();

	//绘制无填充矩形
	void _Rectangle(int left, int top, int right, int bottom, bool isSetColor = false, COLORREF c = BLACK);

	//绘制直线
	void _Line(int x1, int y1, int x2, int y2, bool isSetColor = false, COLORREF c = BLACK);
};