#include"WindowAndUI.h"


WindowAndUI::WindowAndUI()
{
	wnd = new hiex::Window;
	canva = new hiex::Canvas;
}

WindowAndUI::WindowAndUI(const int W, const int H) :
	windowsW(W), windowsH(H), canvaW(W), canvaH(H)
{
	wnd = new hiex::Window(this->windowsW, this->windowsH, 1 | 4);
	canva = new hiex::Canvas;
	canva->InItAndBindWindow(this->canvaW, this->canvaH, this->canva_color, this->wnd);
}

WindowAndUI::WindowAndUI(const int WW, const int WH, const int CW, const int CH, COLORREF Color, int WindowSystle) :
	windowsW(WW), windowsH(WH), canvaW(CW), canvaH(CH), canva_color(Color), window_systle(WindowSystle)
{
	wnd = new hiex::Window(this->windowsW, this->windowsH, window_systle);
	canva = new hiex::Canvas;
	canva->InItAndBindWindow(this->canvaW, this->canvaH, this->canva_color, this->wnd);
}

WindowAndUI::WindowAndUI(const WindowAndUI& otherwnd)
{
	this->windowsW = otherwnd.windowsW;
	this->windowsH = otherwnd.windowsH;
	this->canvaW = otherwnd.canvaW;
	this->canvaH = otherwnd.canvaH;
	this->canva_color = otherwnd.canva_color;
	wnd = new hiex::Window;
	canva = new hiex::Canvas;
}

void WindowAndUI::operator=(const WindowAndUI& otherwnd)
{
	this->windowsW = otherwnd.windowsW;
	this->windowsH = otherwnd.windowsH;
	this->canvaW = otherwnd.canvaW;
	this->canvaH = otherwnd.canvaH;
	this->canva_color = otherwnd.canva_color;
	wnd = new hiex::Window;
	canva = new hiex::Canvas;
}

WindowAndUI::~WindowAndUI()
{
	if (this->wnd != nullptr)
		delete this->wnd;
	if (this->canva != nullptr)
		delete this->canva;
}

int WindowAndUI::GetWindowWidth()
{
	return this->windowsW;
}

int WindowAndUI::GetWindowHeight()
{
	return this->windowsH;
}

int WindowAndUI::GetCanvaWidth()
{
	return this->canvaW;
}

int WindowAndUI::GetCanvaHeight()
{
	return this->canvaH;
}

void WindowAndUI::SetWindowFunction(WNDPROC WindowProcess)
{
	this->wnd->SetProcFunc(WindowProcess);
}

void WindowAndUI::Create()
{
	if (this->wnd != nullptr && this->canva != nullptr)
	{
		this->wnd->Create(this->windowsW, this->windowsH, this->window_systle);
		this->canva->InItAndBindWindow(this->canvaW, this->canvaH, this->canva_color, this->wnd);
	}
}

void WindowAndUI::Create(const int WW, const int WH, const int CW, const int CH, COLORREF Color, int WindowSystle)
{
	this->windowsW = WW;
	this->windowsH = WH;
	this->canvaW = CW;
	this->canvaH = CH;
	this->canva_color = Color;
	this->window_systle = WindowSystle;
	if (wnd != nullptr && canva != nullptr)
	{
		this->wnd->Create(this->windowsW, this->windowsH, this->window_systle);
		this->canva->InItAndBindWindow(this->canvaW, this->canvaH, this->canva_color, this->wnd);
	}
}

HWND WindowAndUI::GetWindowHandle()
{
	return this->wnd->GetHandle();
}

IMAGE* WindowAndUI::GetCanvaImage()
{
	return this->canva->GetImagePointer();
}

void WindowAndUI::_Redraw()
{
	this->wnd->Redraw();
}

bool WindowAndUI::IsWindowAlive()
{
	return this->wnd->IsAlive();
}

void WindowAndUI::_SetLineStyle(int style, int thickness, const DWORD* puserstyle , DWORD userstylecount )
{
	this->canva->SetLineStyle(style, thickness, puserstyle);
}

void WindowAndUI::_Clear()
{
	this->canva->Clear();
}

void WindowAndUI::_Rectangle(int left, int top, int right, int bottom, bool isSetColor , COLORREF c )
{
	this->canva->Rectangle(left, top, right, bottom, isSetColor, c);
}

void WindowAndUI::_Line(int x1, int y1, int x2, int y2, bool isSetColor, COLORREF c )
{
	this->canva->Line(x1, y1, x2, y2, isSetColor, c);
}
