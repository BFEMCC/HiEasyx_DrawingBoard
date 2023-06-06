#pragma once
#include <vector>
#include "HiEasyX/HiEasyX.h"
#include "WindowAndUI.h"
using namespace std;

#define straight_line 10000
#define no_fill_rectangle 10001

extern struct HIstoryPointAndShap
{
	POINT XY1;
	POINT XY2;
	int shape;
};
extern vector<HIstoryPointAndShap> history;
void ClearHistory();


/* 笔刷自由绘制*/
class Brush
{
public:
	Brush();

private:
	POINT DownXY;
	int size;
	COLORREF color;
	bool isdown;
	static const int shape = straight_line;
	HIstoryPointAndShap historylineAndshape;

public:
	void SetSize(const int size);
	void SetColor(const COLORREF color);
	void MouseEvent(const ExMessage& msg, WindowAndUI& wnd);
};

/*绘制无填充矩形*/
class NoFill_DrawRectangle
{
public:
	NoFill_DrawRectangle();
private:
	POINT DownXY;
	int size;
	COLORREF color;
	bool isdown;
	static const int shape = no_fill_rectangle;
	HIstoryPointAndShap historylineAndshape;

public:
	void SetSize(const int size);
	void SetColor(const COLORREF color);
	void MouseEvent(const ExMessage& msg, WindowAndUI& wnd);
};

/*绘制直线*/
class StraighLine
{
public:
	StraighLine();
private:
	POINT DownXY;
	int size;
	COLORREF color;
	bool isdown;
	static const int shape = straight_line;
	HIstoryPointAndShap historylineAndshape;

public:
	void SetSize(const int size);
	void SetColor(const COLORREF color);
	void MouseEvent(const ExMessage& msg, WindowAndUI& wnd);
};

