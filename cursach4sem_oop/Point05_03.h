//Point05_03.h
#pragma once
/*******************************************************
Project Name: cursach4sem_oop
File Name:	  Point05_03.h
Programmer:   Kolotilov Danila
Modifyed by:  Kolotilov Danila
Created:      05/03/21
Last Revision:31/05/21
******************************************************/
/*-------------------------------------------------------------------------------------------------------------------------------------------*/
class Location
{
protected://предоставляет возможность потомкам(производному классу) иметь доступ к закрытым данным
	int X;//координаты точки
	int Y;
public:
	Location(int InitX, int InitY);//конструктор
	~Location();//деструктор
	int GetX();//получить значение поля Х
	int GetY();//получить значение поля У
	void SetX(int x);
	void SetY(int y);
};//class Location
/*---------------------------------------------------------------------------------------------------------------------------------------------*/
class Point :public Location
{
protected:
	bool Visible;
public:
	Point(int InitX, int InitY);
	~Point();
	virtual void Show();
	virtual void Hide();
	virtual void MoveTo(int NewX, int NewY);
	virtual void ChangeHdcPow(int x, int y);
};
//Круг
class Circle :public Point
{
public:
	int Radius;
	Circle(int InitX = 10, int InitY = 10, int InitRadius = 10);
};
//Мяч
class Ball :public Circle
{
private:
	int speed;
public:
	Ball(int InitX, int InitY);
	int first;
	int second;
	int third;
	int status;
	void Show();
	void Hide();
	int getSpeed();
	void setSpeed(int Speed);
};
//Классы шариков
class firBall : public Ball
{
public:
	firBall(int InitX, int InitY);
};
class secBall : public Ball
{
public:
	secBall(int InitX, int InitY);
};

class fouBall : public Ball
{
public:
	fouBall(int InitX, int InitY);
};
class fifBall : public Ball
{
public:
	fifBall(int InitX, int InitY);
};
class WrongBall :public Ball
{
public:
	WrongBall(int InitX, int InitY);
};
//Стакан
class Glass : public Point
{
protected:
	int flag;
	int first;
	int second;
	int third;
public:
	int status;
	Glass(int x, int y);
	virtual void Show();
	virtual void Hide();
	virtual void ChangeFlag();
	virtual void ChangeColor(int First, int Second, int Third);
};
//Классы частей стакана
class Leftside : public Glass
{
public:
	Leftside(int InitX, int InitY);
	void Show();
	void Hide();
};
class Downside : public Glass
{
public:
	Downside(int InitX, int InitY);
	void Show();
	void Hide();
};
class Upside : public Glass
{
public:
	Upside(int InitX, int InitY);
	void Show();
	void Hide();
};
class Rightside : public Glass
{
public:
	Rightside(int InitX, int InitY);
	void Show();
	void Hide();
};
