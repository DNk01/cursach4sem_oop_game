//Point05_03.h
#pragma once
//���������� ���� ������� . ������������.����������� �������.������ ����������.
/*-------------------------------------------------------------------------------------------------------------------------------------------*/
class Location
{
protected://������������� ����������� ��������(������������ ������) ����� ������ � �������� ������
	int X;//���������� �����
	int Y;
public:
	Location(int InitX, int InitY);//�����������
	~Location();//����������
	int GetX();//�������� �������� ���� �
	int GetY();//�������� �������� ���� �
	void SetX(int x);
	void SetY(int y);
	//void SetX(int NewX){X=NewX;};//�������� �������� ���� �
	//void SetY(int NewY){Y=NewY;};//�������� �������� ���� �
};//class Location
/*---------------------------------------------------------------------------------------------------------------------------------------------*/
class Point :public Location //�� ��������� private-��� �������
{
	//Point-����������� ����� �� Location
	//������� public � ���������� ������������ ������ ��������
	//��� � � � �������� �����������(protected) ������ Point
	//-����������� �� ����������
protected:
	bool Visible;//��������� ����� ��� ���
public:
	Point(int InitX, int InitY);//�����������
	~Point();//����������
	bool IsVisible();//������ ��� ���������� �����
	//void SetVisible(bool NewVisible){Visible=NewVisible;};
	virtual void Show();//�������� ����� �� ������
	virtual void Hide();//������ ����� �� ������
	virtual void MoveTo(int NewX, int NewY);//����������� ����� �� ����� �����������
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