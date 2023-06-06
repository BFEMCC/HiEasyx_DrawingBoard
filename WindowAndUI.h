#pragma once
#include <vector>
#include "HiEasyX/HiEasyX.h"

/*�����UI*/
class WindowAndUI
{
public:
	//ʵ�������󣬲���ʾ����
	WindowAndUI();

	//ָֻ���ô��ڴ�С������Ĭ�ϣ���ʵ����������ʾ����
	WindowAndUI(const int W, const int H);

	//�߶��Զ��崰�壬��ʵ����������ʾ����
	WindowAndUI(const int WW, const int WH, const int CW, const int CH, COLORREF Color = WHITE, int WindowSystle = 1 | 4);

	//�������죬��ʵ�������󣬲���ʾ���壬��������С���������ܸ���ԭ���ڵĻ�������
	WindowAndUI(const WindowAndUI& otherwnd);

	//operator=����,��ʵ�������󣬲���ʾ���壬��������С���������ܸ���ԭ���ڵĻ�������
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
	//���ô�����Ӧ����
	void SetWindowFunction(WNDPROC WindowProcess);

	//���������=��ֵ����ô˺�������ʾ����
	void Create();

	//Ĭ�Ϲ������ô˺�������ʾ����
	void Create(const int WW, const int WH, const int CW = 640, const int CH = 480, COLORREF Color = WHITE, int WindowSystle = 1 | 4);

	//��ȡ���ھ��
	HWND GetWindowHandle();

	//��ȡ����������Imageָ��
	IMAGE* GetCanvaImage();

	//�ػ洰��
	void _Redraw();

	//�жϴ����Ƿ����
	bool IsWindowAlive();

	//���û�����ʽ
	void _SetLineStyle(int style, int thickness, const DWORD* puserstyle = (DWORD*)nullptr, DWORD userstylecount = 0UL);

	//��ձ������Ƶ�ͼ��
	void _Clear();

	//������������
	void _Rectangle(int left, int top, int right, int bottom, bool isSetColor = false, COLORREF c = BLACK);

	//����ֱ��
	void _Line(int x1, int y1, int x2, int y2, bool isSetColor = false, COLORREF c = BLACK);
};