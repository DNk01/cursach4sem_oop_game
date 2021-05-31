//Point05_03.h
#pragma once
//Объявление трех классов . наследование.статические правила.раннее связывание.
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
	//void SetX(int NewX){X=NewX;};//поменять значение поля Х
	//void SetY(int NewY){Y=NewY;};//поменять значение поля У
};//class Location
/*---------------------------------------------------------------------------------------------------------------------------------------------*/
class Point :public Location //по умолчанию private-все закрыто
{
	//Point-производный класс от Location
	//атрибут public в объявлении производного лкасса означает
	//что Х и У являются защищенными(protected) внутри Point
	//-полученными по наследству
protected:
	bool Visible;//светиться точка или нет
public:
	Point(int InitX, int InitY);//конструктор
	~Point();//деструктор
	bool IsVisible();//узнать про светимость точки
	//void SetVisible(bool NewVisible){Visible=NewVisible;};
	virtual void Show();//показать точку на экране
	virtual void Hide();//скрыть точку на экране
	virtual void MoveTo(int NewX, int NewY);//переместить точку по новым координатам
	virtual void ChangeHdcPow(int x, int y);
};
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

class Circle :public Point
{
public:
	int Radius;
	Circle(int InitX = 10, int InitY = 10, int InitRadius = 10);
	
};
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