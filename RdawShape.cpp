#include"RdawShape.h"

struct HIstoryPointAndShap;

vector<HIstoryPointAndShap> history;

void ClearHistory()
{
	history.clear();
}


Brush::Brush()
	{
		this->size = 1;
		this->color = BLACK;
		this->isdown = false;
		this->DownXY.x = 0;
		this->DownXY.y = 0;
	}

void Brush::SetSize(const int size)
	{
		this->size = size;
	}

void Brush::SetColor(const COLORREF color)
	{
		this->color = color;
	}

void Brush::MouseEvent(const ExMessage& msg, WindowAndUI& wnd)
	{
		if (msg.message == WM_LBUTTONDOWN && this->isdown == false)
		{
			this->isdown = true;
			this->DownXY.x = msg.x;
			this->DownXY.y = msg.y;
		}
		if (msg.message == WM_LBUTTONUP && this->isdown == true)
		{
			this->isdown = false;
		}
		if (msg.message == WM_MOUSEMOVE && this->isdown == true)
		{
			this->historylineAndshape.XY1.x = this->DownXY.x;
			this->historylineAndshape.XY1.y = this->DownXY.y;
			wnd._SetLineStyle(PS_ENDCAP_ROUND | PS_ENDCAP_ROUND, this->size);
			wnd._Line(static_cast<int>(this->DownXY.x), static_cast<int>(this->DownXY.y), static_cast<int>(msg.x), static_cast<int>(msg.y), true, this->color);
			this->historylineAndshape.XY2.x = msg.x;
			this->historylineAndshape.XY2.y = msg.y;
			this->historylineAndshape.shape = this->shape;
			history.push_back(this->historylineAndshape);
			wnd._Redraw();
			this->DownXY.x = msg.x;
			this->DownXY.y = msg.y;
		}
	}


NoFill_DrawRectangle::NoFill_DrawRectangle()
	{
		this->size = 1;
		this->color = BLACK;
		this->isdown = false;
		this->DownXY.x = 0;
		this->DownXY.y = 0;
	}

void NoFill_DrawRectangle::SetSize(const int size)
	{
		this->size = size;
	}

void NoFill_DrawRectangle::SetColor(const COLORREF color)
	{
		this->color = color;
	}

void NoFill_DrawRectangle::MouseEvent(const ExMessage& msg, WindowAndUI& wnd)
	{
		if (msg.message == WM_LBUTTONDOWN && this->isdown == false)
		{
			this->isdown = true;
			this->DownXY.x = msg.x;
			this->DownXY.y = msg.y;
		}
		if (msg.message == WM_LBUTTONUP && this->isdown == true)
		{
			this->isdown = false;
			this->historylineAndshape.XY1.x = this->DownXY.x;
			this->historylineAndshape.XY1.y = this->DownXY.y;
			this->historylineAndshape.XY2.x = msg.x;
			this->historylineAndshape.XY2.y = msg.y;
			this->historylineAndshape.shape = this->shape;
			history.push_back(this->historylineAndshape);
		}
		if (msg.message == WM_MOUSEMOVE && this->isdown == true)
		{
			wnd._Clear();
			wnd._SetLineStyle(PS_ENDCAP_ROUND | PS_ENDCAP_ROUND, this->size);
			wnd._Rectangle(static_cast<int>(this->DownXY.x), static_cast<int>(this->DownXY.y), static_cast<int>(msg.x), static_cast<int>(msg.y), true, this->color);
			if (history.size() != 0)
			{
				for (auto& i : history)
				{
					if (i.shape == no_fill_rectangle)
						wnd._Rectangle(static_cast<int>(i.XY1.x), static_cast<int>(i.XY1.y), static_cast<int>(i.XY2.x), static_cast<int>(i.XY2.y));
					else if (i.shape == straight_line)
						wnd._Line(static_cast<int>(i.XY1.x), static_cast<int>(i.XY1.y), static_cast<int>(i.XY2.x), static_cast<int>(i.XY2.y));
				}
			}
			wnd._Redraw();
		}
	}


StraighLine::StraighLine()
	{
		this->size = 1;
		this->color = BLACK;
		this->isdown = false;
		this->DownXY.x = 0;
		this->DownXY.y = 0;
	}

void StraighLine::SetSize(const int size)
	{
		this->size = size;
	}

void StraighLine::SetColor(const COLORREF color)
	{
		this->color = color;
	}

void StraighLine::MouseEvent(const ExMessage& msg, WindowAndUI& wnd)
	{
		if (msg.message == WM_LBUTTONDOWN && this->isdown == false)
		{
			this->isdown = true;
			this->DownXY.x = msg.x;
			this->DownXY.y = msg.y;
		}
		if (msg.message == WM_LBUTTONUP && this->isdown == true)
		{
			this->isdown = false;

			this->historylineAndshape.XY1.x = this->DownXY.x;
			this->historylineAndshape.XY1.y = this->DownXY.y;
			this->historylineAndshape.XY2.x = msg.x;
			this->historylineAndshape.XY2.y = msg.y;
			this->historylineAndshape.shape = this->shape;
			history.push_back(this->historylineAndshape);
		}
		if (msg.message == WM_MOUSEMOVE && this->isdown == true)
		{
			wnd._Clear();
			wnd._SetLineStyle(PS_ENDCAP_ROUND | PS_ENDCAP_ROUND, this->size);
			wnd._Line(static_cast<int>(this->DownXY.x), static_cast<int>(this->DownXY.y), static_cast<int>(msg.x), static_cast<int>(msg.y), true, this->color);
			if (history.size() != 0)
			{
				for (auto& i : history)
				{
					if (i.shape == no_fill_rectangle)
						wnd._Rectangle(static_cast<int>(i.XY1.x), static_cast<int>(i.XY1.y), static_cast<int>(i.XY2.x), static_cast<int>(i.XY2.y));
					else if (i.shape == straight_line)
						wnd._Line(static_cast<int>(i.XY1.x), static_cast<int>(i.XY1.y), static_cast<int>(i.XY2.x), static_cast<int>(i.XY2.y));
				}
			}
			wnd._Redraw();
		}
	}
