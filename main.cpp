#include "WindowAndUI.h"
#include"RdawShape.h"

WindowAndUI* wnd = new WindowAndUI;
StraighLine* straigh_line = new StraighLine;								//绘制直线类
NoFill_DrawRectangle* nofill_rectangle = new NoFill_DrawRectangle;			//绘制填充矩形类
Brush* free_line = new Brush;												//自由绘制类
ExMessage* msg =new ExMessage{};							
hiex::SysRadioButton* shape=new hiex::SysRadioButton[3];
hiex::SysButton* clearbtn = new hiex::SysButton;

void InitUI()
{
	wnd->Create(900, 600, 900, 600, RGB(240, 240, 240), 4);
	//wnd->SetWindowFunction(
	//	[](HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)->LRESULT CALLBACK {
	//		switch (msg)
	//		{
	//		case WM_SIZE:
	//			wnd->_Clear();
	//			wnd->_Redraw();
	//			break;
	//		default:
	//			return HIWINDOW_DEFAULT_PROC;
	//			break;
	//		}
	//	}
	//);
	shape[0].Create(wnd->GetWindowHandle(), 30, 30, 65, 20, L"直线");
	shape[1].Create(wnd->GetWindowHandle(), 100, 30, 65, 20, L"矩形");
	shape[2].Create(wnd->GetWindowHandle(), 170, 30, 65, 20, L"画笔");
	shape[0].Check(true);
	for (int i = 0; i < 3; i++)
		shape[i].SetFont(20, 0, L"微软雅黑");
	clearbtn->Create(wnd->GetWindowHandle(), 240, 30, 65, 25, L"清空");
	clearbtn->SetFont(20, 0, L"微软雅黑");
	clearbtn->RegisterMessage([]()->void {
		ClearHistory();
		wnd->_Clear();
		wnd->_Redraw();
		});
}

void CoreFunction()
{
	while (wnd->IsWindowAlive())
	{
		while (hiex::peekmessage_win32(msg, EX_MOUSE, true, wnd->GetWindowHandle()))//在这里调用MouseEvent方法实现绘制，三个类的方法同名
		{
			if (shape[0].IsChecked())
				straigh_line->MouseEvent(*msg, *wnd);
			if (shape[1].IsChecked())
				nofill_rectangle->MouseEvent(*msg, *wnd);
			if (shape[2].IsChecked())
				free_line->MouseEvent(*msg, *wnd);
		}
		Sleep(5);
	}
}

void FreeMemory()
{
	delete wnd;
	delete straigh_line;
	delete nofill_rectangle;
	delete free_line;
	delete msg;
	delete[] shape;
	delete clearbtn;
}

int main()
{
	InitUI();
	CoreFunction();
	FreeMemory();
	return 0;
}