//Point05_03.cpp
//Объявление трех классов . наследование.статические правила.раннее связывание.
//реализация двух классов.наследование

#include<Windows.h>
#include"Point05_03.h"
#include <conio.h>


extern HDC hdc;//объявим контест устройства
//реализация методов классов

//методы класса Location
//конструктор
Location::Location(int InitX, int InitY)
{
	X = InitX;
	Y = InitY;
}//Location()
//деструктор
Location::~Location()
{
	//пустое тело
}//~Location
//получить значение поля Х
int Location::GetX()
{
	return X;
};//GetX()
//получить значение поля У
int Location::GetY()
{
	return Y;
}//GetY()
void Location::SetX(int x)
{
	X = x;
}
void Location::SetY(int y)
{
	Y = y;
}



//методы класса Point
//конструктор
Point::Point(int InitX, int InitY) :Location(InitX, InitY)
{
	Visible = false;
}//Point()

//деструктор
Point::~Point()
{
	//пустое тело
}//~Point()

//узнать про светимость точки
bool Point::IsVisible()
{
	return Visible;
}//IsVisible()

//показать точку на экране
void Point::Show()
{
	Visible = true;//точку видно
	SetPixel(hdc, X, Y, RGB(0, 0, 0));//рисуем установленным цветом
	SetPixel(hdc, X + 1, Y, RGB(0, 0, 0));//рисуем установленным цветом
	SetPixel(hdc, X, Y + 1, RGB(0, 0, 0));//рисуем установленным цветом
	SetPixel(hdc, X + 1, Y + 1, RGB(0, 0, 0));//рисуем установленным цветом
}//Show()

//скрыть точку на экране
void Point::Hide()
{
	Visible = false;//точку НЕ видно
	SetPixel(hdc, X, Y, RGB(242,242,242));//рисуем установленным цветом
	SetPixel(hdc, X + 1, Y, RGB(242, 242, 242));//рисуем установленным цветом
	SetPixel(hdc, X, Y + 1, RGB(242, 242, 242));//рисуем установленным цветом
	SetPixel(hdc, X + 1, Y + 1, RGB(242, 242, 242));//рисуем установленным цветом
}//Hide()

//переместить точку по новым координатам
void Point::MoveTo(int NewX, int NewY)
{
	Hide();
	X = NewX;//поменять координаты
	Y = NewY;
	Show();
}

void Point::ChangeHdcPow(int x, int y)
{
	
	Visible = true;
	HPEN Pen1 = CreatePen(PS_SOLID, 2, RGB(242, 242, 242));
	SelectObject(hdc, Pen1);
	LineTo(hdc, x, y);
	DeleteObject(Pen1);
}



Glass::Glass(int InitX, int InitY) :Point(InitX,InitY)
{
	flag = 0;
	status = 0;
	first, second, third = 0;
	Visible = false;
	X = InitX;
	Y = InitY;
}
void Glass::ChangeFlag()
{
	flag = 1;
}
void Glass :: ChangeColor(int First, int Second, int Third)
{	
	first = First;
	second = Second;
	third = Third;
}
void Glass::Show()
{
	ChangeHdcPow(X, Y);
	HPEN Pen = CreatePen(PS_SOLID, 2, RGB(100,100,100));
	SelectObject(hdc, Pen);
	POINT pt[4];
	if (status == 0)
	{
		pt[0].x = X + 4;
		pt[0].y = Y + 21;
		pt[3].x = X + 56;
		pt[3].y = Y + 20;
		pt[1].x = X + 10;
		pt[1].y = Y + 50;
		pt[2].x = X + 50;
		pt[2].y = Y + 50;
	}
	else
	{
		pt[0].x = X + 2;
		pt[0].y = Y + 10;
		pt[3].x = X + 28;
		pt[3].y = Y + 10;
		pt[1].x = X + 5;
		pt[1].y = Y + 25;
		pt[2].x = X + 25;
		pt[2].y = Y + 25;
	}
	HRGN hrgn = CreatePolygonRgn(pt, 4, WINDING);
	HBRUSH hbrush;
	hbrush = CreateSolidBrush(RGB(first, second, third));
	FillRgn(hdc, hrgn, hbrush);
	DeleteObject(Pen);
}
void Glass::Hide()
{
	ChangeHdcPow(X, Y);
	HPEN Pen = CreatePen(PS_SOLID, 2, RGB(242, 242,242));
	SelectObject(hdc, Pen);
	POINT pt[4];
	if (status == 0)
	{
		pt[0].x = X + 4;
		pt[0].y = Y + 21;
		pt[3].x = X + 56;
		pt[3].y = Y + 20;
		pt[1].x = X + 10;
		pt[1].y = Y + 50;
		pt[2].x = X + 50;
		pt[2].y = Y + 50;
	}
	else
	{
		pt[0].x = X + 2;
		pt[0].y = Y + 10;
		pt[3].x = X + 28;
		pt[3].y = Y + 10;
		pt[1].x = X + 5;
		pt[1].y = Y + 25;
		pt[2].x = X + 25;
		pt[2].y = Y + 25;
	}
	HRGN hrgn = CreatePolygonRgn(pt, 4, WINDING);
	HBRUSH hbrush = CreateSolidBrush(RGB(242,242,242));
	FillRgn(hdc, hrgn, hbrush);
	DeleteObject(Pen);
}

Circle::Circle(int InitX, int InitY, int InitRadius) :Point(InitX, InitY)//Point(InitX, InitY) обеспечивает доступ к полям х у
{
	Radius = InitRadius;
}//Circle()

void Ball::Show()//показать круг на экране
{
	ChangeHdcPow(X, Y);
	HRGN hrgn = CreateEllipticRgn(X - Radius, Y - Radius, X + Radius, Y + Radius);
	HBRUSH hbrush;
	hbrush = CreateSolidBrush(RGB(first, second, third));
	HPEN Pen = CreatePen(PS_SOLID, 2, RGB(first, second, third));
	SelectObject(hdc, Pen);
	LineTo(hdc, X + 7, Y + 3);

	FillRgn(hdc, hrgn, hbrush);
}
int Ball::getSpeed()
{
	return speed;
}
void Ball::setSpeed(int Speed)
{
	speed = Speed;
}

Ball::Ball(int InitX, int InitY) : Circle(InitX, InitY)
{
	
}
firBall::firBall(int InitX, int InitY) : Ball(InitX, InitY)
{
	first = rand()%100 + 30;
	second = rand() % 100 + 30;
	third = rand() % 100 + 30;
}
secBall::secBall(int InitX, int InitY) : Ball(InitX, InitY)
{
	first = rand() % 150 + 100;
	second = rand() % 150 + 100;
	third = rand() % 150 + 100;
}
fouBall::fouBall(int InitX, int InitY) : Ball(InitX, InitY)
{
	first = rand() % 200 + 150;
	second = rand() % 200 + 150;
	third = rand() % 200 + 150;
}
fifBall::fifBall(int InitX, int InitY) : Ball(InitX, InitY)
{
	first = rand() % 255 + 200;
	second = rand() % 255 + 200;
	third = rand() % 255 + 200;
}

void Ball::Hide()
{
	Visible = false;
	ChangeHdcPow(X, Y);
	HRGN hrgn = CreateEllipticRgn(X - Radius - 5, Y - Radius - 5, X + Radius + 5, Y + Radius + 5);
	HBRUSH hbrush = CreateSolidBrush(RGB(242, 242, 242));
	FillRgn(hdc, hrgn, hbrush);
}

WrongBall::WrongBall(int InitX, int InitY) : Ball(InitX, InitY)
{
	first = 0;
	second = 0;
	third = 0;
}
void Leftside::Show()//показать круг на экране
{
	ChangeHdcPow(X, Y);
	HPEN Pen = CreatePen(PS_SOLID, 2, RGB(0, 0, 0));
	SelectObject(hdc, Pen);
	if (status == 0)
		LineTo(hdc, X + 10, Y + 50);
	else
		LineTo(hdc, X + 5, Y + 25);
	DeleteObject(Pen);
}
void Leftside::Hide()//показать круг на экране
{
	ChangeHdcPow(X, Y);
	HPEN Pen = CreatePen(PS_SOLID, 2, RGB(242, 242, 242));
	SelectObject(hdc, Pen);
	if (status == 0)
		LineTo(hdc, X + 10, Y + 50);
	else
		LineTo(hdc, X + 5, Y + 25);
	DeleteObject(Pen);
}
Leftside::Leftside(int InitX, int InitY) :Glass(InitX, InitY)// обеспечивает доступ к полям х у
{
	X = InitX;
	Y = InitY;
}
void Downside::Show()
{
	ChangeHdcPow(X, Y);
	HPEN Pen = CreatePen(PS_SOLID, 2, RGB(0, 0, 0));
	SelectObject(hdc, Pen);	
	if (status == 0)
		LineTo(hdc, X + 50, Y);
	else
		LineTo(hdc, X + 25, Y);
	DeleteObject(Pen);
}
void Downside::Hide()//показать круг на экране
{
	ChangeHdcPow(X, Y);
	HPEN Pen = CreatePen(PS_SOLID, 2, RGB(242, 242, 242));
	SelectObject(hdc, Pen);
	if (status == 0)
		LineTo(hdc, X + 50, Y);
	else
		LineTo(hdc, X + 25, Y);
	DeleteObject(Pen);
}
Downside::Downside(int InitX, int InitY) : Glass(InitX, InitY)// обеспечивает доступ к полям х у
{
	X = InitX;
	Y = InitY;
}
void Rightside::Show()//показать круг на экране
{
	ChangeHdcPow(X, Y);
	HPEN Pen = CreatePen(PS_SOLID, 2, RGB(0, 0, 0));
	SelectObject(hdc, Pen);
	if (status == 0)
		LineTo(hdc, X + 10, Y - 50);
	else
		LineTo(hdc, X + 5, Y - 25);
	DeleteObject(Pen);
}
void Rightside::Hide()//показать круг на экране
{
	ChangeHdcPow(X, Y);
	HPEN Pen = CreatePen(PS_SOLID, 2, RGB(242, 242, 242));
	SelectObject(hdc, Pen);
	if (status == 0)
		LineTo(hdc, X + 10, Y - 50);
	else
		LineTo(hdc, X + 5, Y - 25);
	DeleteObject(Pen);
}
Rightside::Rightside(int InitX, int InitY) : Glass(InitX, InitY)// обеспечивает доступ к полям х у
{
	X = InitX;
	Y = InitY;
}
void Upside::Show()//показать круг на экране
{
	ChangeHdcPow(X, Y);
	HPEN Pen = CreatePen(PS_SOLID, 2, RGB(0, 0, 0));
	SelectObject(hdc, Pen);
	if (status == 0)
		LineTo(hdc, X - 52, Y);
	else
		LineTo(hdc, X - 27, Y);
	DeleteObject(Pen);
}
void Upside::Hide()//показать круг на экране
{
	ChangeHdcPow(X, Y);
	HPEN Pen = CreatePen(PS_SOLID, 2, RGB(242, 242, 242));
	SelectObject(hdc, Pen);
	if (status == 0)
		LineTo(hdc, X - 50, Y);
	else
		LineTo(hdc, X - 25, Y);
	DeleteObject(Pen);
}
Upside::Upside(int InitX, int InitY) : Glass(InitX, InitY)// обеспечивает доступ к полям х у
{
	X = InitX;
	Y = InitY;
}