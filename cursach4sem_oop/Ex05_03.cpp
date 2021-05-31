#pragma once                  
#include <windows.h>
#include <conio.h>
#include <iostream>    
using namespace std;        // Пространство имен std

#include "Point05_03.h" 	//объявление классов
#include "GetConWin.h"		//указатель на консольное окно

//макрос для определения кода нажатой клавиши
#define KEY_DOWN(vk_code) ((GetAsyncKeyState(vk_code) & 0x8000) ? 1 : 0)

HDC hdc;	

/*---------------------------------------------------------------------*/
/*               П Р О Т О Т И П Ы    Ф У Н К Ц И Й                    */
/*---------------------------------------------------------------------*/
HWND GetConcolWindow(); //указатель на консольное окно теперь в  "GetConlWin.h"
void border();
void changestatus(Glass* glass0, Glass* glass1, Glass* glass2, Glass* glass3, Glass* glass4);
void changestatus2(Glass* glass0, Glass* glass1, Glass* glass2, Glass* glass3, Glass* glass4);
/***********************************************************************/
/*               О С Н О В Н А Я    П Р О Г Р А М М А                  */
/***********************************************************************/
int main()
{
	HWND hwnd = GetConcolWindow();
	system("color F0");
	int x = 600, y = 500;
	int count = 0;
	int speed = 15;
	Ball* BufBall[5];
	Glass* glass[5];
	if (hwnd != NULL)
	{
		hdc = GetWindowDC(hwnd);
		if (hdc != 0)
		{
			border();
			//Glass glass(600, 500);
			//glass.Show();
			srand(time(NULL));
			cout << "YOUR SCORE: ";
			firBall firstBall(450, 100);
			secBall secondBall(525, 120);
			WrongBall thirdBall(600, 140);
			fouBall fourthBall(675, 160);
			fifBall fifthBall(750, 180);
			Leftside left(500, 500);
			Downside down(510, 550);
			Rightside right(550, 550);
			Upside up(555, 520);
			Glass full(500,500);
			
			firstBall.status = 1;
			secondBall.status = 2;
			thirdBall.status = 3;
			fourthBall.status = 4;
			fifthBall.status = 5;

			BufBall[0] = &firstBall;
			BufBall[1] = &secondBall;
			BufBall[2] = &thirdBall;
			BufBall[3] = &fourthBall;
			BufBall[4] = &fifthBall;
			glass[0] = &left;
			glass[1] = &down;
			glass[2] = &right;
			glass[3] = &up;
			glass[4] = &full;
			for (int i = 0; i < 5; i++)
			{
				BufBall[i]->Show();
				BufBall[i]->setSpeed(1);
			}
			for (int i = 0; i < 5; i++)
				glass[i]->Show();
			//Sleep(100000);
			while (true)
			{
				if (KEY_DOWN(27))
					break;
				if (KEY_DOWN(65))	
					for (int i = 0; i < 5; i++)
					{
						glass[i]->Hide();
						glass[i]->SetX(glass[i]->GetX() - speed);
					}
				if (KEY_DOWN(68))
					for (int i = 0; i < 5; i++)
					{
						glass[i]->Hide();
						glass[i]->SetX(glass[i]->GetX() + speed);
					}
				if (KEY_DOWN(16))
				{
					if (glass[0]->GetX() < 425)
						for (int i = 0; i <5; i++)
						{
							glass[i]->Hide();
							glass[i]->SetX(glass[i]->GetX() + speed);
						}
					if (glass[0]->GetX() > 720)
						for (int i = 0; i < 5; i++)
						{
							glass[i]->Hide();
							glass[i]->SetX(glass[i]->GetX() - speed);
						}
					speed = 40;
				}
				if (!KEY_DOWN(16))
					speed = 20;
				for (int i = 0; i < 5; i++)
				{
					if (KEY_DOWN(49 + i))
					{
						BufBall[i]->MoveTo(BufBall[i]->GetX(), BufBall[i]->GetY() + BufBall[i]->getSpeed());
						BufBall[i]->SetY(BufBall[i]->GetY() + BufBall[i]->getSpeed());
					}
				}
				for (int i = 0; i < 5; i++)
					glass[i]->Show();
				if (KEY_DOWN(16))
				{
					if (glass[0]->GetX() < 380)
						for (int i = 0; i < 5; i++)
						{
							glass[i]->Hide();
							glass[i]->SetX(glass[i]->GetX() + speed * 2);
						}
					if (glass[3]->GetX() >820)
						for (int i = 0; i < 5; i++)
						{
							glass[i]->Hide();
							glass[i]->SetX(glass[i]->GetX() - speed * 2);
						}
					speed = 40;
				}
				if (glass[0]->GetX() < 420)
					for (int i = 0; i < 5; i++)
					{
						glass[i]->Hide();
						glass[i]->SetX(glass[i]->GetX() + speed * 2);
					}
				if (glass[3]->GetX() > 780)
					for (int i = 0; i < 5; i++)
					{
						glass[i]->Hide();
						glass[i]->SetX(glass[i]->GetX() - speed * 2);
					}
				for (int i = 0; i < 5; i++)
				{
					BufBall[i]->MoveTo(BufBall[i]->GetX(), BufBall[i]->GetY() + BufBall[i]->getSpeed());
					BufBall[i]->SetY(BufBall[i]->GetY() + BufBall[i]->getSpeed());
				}
				Sleep(50);
				for (int i = 0; i < 5; i++)
				{
					if (BufBall[i]->GetY() > 500)
					{
						if (BufBall[i]->GetX() < glass[3]->GetX() + 5 && BufBall[i]->GetX() > glass[0]->GetX())
						{
							if (i == 2)
							{
								full.ChangeColor(242, 242, 242);
								if (glass[0]->status == 0)
								{
									for (int i = 0; i < 5; i++)
										glass[i]->Hide();
									changestatus(glass[0], glass[1], glass[2], glass[3], glass[4]);
									for (int i = 0; i < 5; i++)
										glass[i]->Show();
								}
							}
							else
							{
								full.ChangeColor(BufBall[i]->first, BufBall[i]->second, BufBall[i]->third);
								if (glass[0]->status == 1)
								{
									for (int i = 0; i < 5; i++)
										glass[i]->Hide();
									changestatus2(glass[0], glass[1], glass[2], glass[3], glass[4]);
									for (int i = 0; i < 5; i++)
										glass[i]->Show();
								}
							}
							BufBall[i]->Hide();
							BufBall[i]->SetY(80);
							BufBall[i]->setSpeed(BufBall[i]->getSpeed() + 1);
							if (i == 3)
								count = 0;
							else
								count++;
							cout << count << endl;
						}
						else if (BufBall[i]->GetY() > 580)
						{
							BufBall[i]->Hide();
							BufBall[i]->SetY(80);
							if (i != 3)
							{
								count = 0;
								cout << count << endl;
							}
						}

					}
				}
			}
		}	
		cout << "YOUR FINAL SCORE: " << count << endl;
		cout << "For exit click on 'ESC'";
		while (true)
		{
			if (KEY_DOWN(27))
				break;
		}
	}
	
}
void border()
{
	HPEN Pen = CreatePen(PS_SOLID, 2, RGB(0, 0, 0));
	SelectObject(hdc, Pen);
	LineTo(hdc, 400, 0);
	LineTo(hdc, 400, 600);
	LineTo(hdc, 800, 600);
	LineTo(hdc, 800, 50);
	LineTo(hdc, 400, 50);
}
void changestatus(Glass *glass0, Glass *glass1, Glass *glass2, Glass *glass3, Glass *glass4)
{
	glass0->status = 1;
	glass1->status = 1;
	glass2->status = 1;
	glass3->status = 1;
	glass4->status = 1;
	glass0->SetX(glass0->GetX() + 6);
	glass0->SetY(glass0->GetY() + 25);
	glass2->SetX(glass2->GetX() - 17);
	glass3->SetX(glass3->GetX() - 20);
	glass3->SetY(glass3->GetY() + 15);
	glass4->SetX(glass4->GetX() + 7);
	glass4->SetY(glass4->GetY() + 25);
}
void changestatus2(Glass* glass0, Glass* glass1, Glass* glass2, Glass* glass3, Glass* glass4)
{
	glass0->status = 0;
	glass1->status = 0;
	glass2->status = 0;
	glass3->status = 0;
	glass4->status = 0;
	glass0->SetX(glass0->GetX() - 6);
	glass0->SetY(glass0->GetY() - 25);
	glass2->SetX(glass2->GetX() + 17);
	glass3->SetX(glass3->GetX() + 20);
	glass3->SetY(glass3->GetY() - 15);
	glass4->SetX(glass4->GetX() - 7);
	glass4->SetY(glass4->GetY() - 25);
}
HWND GetConcolWindow()
{

	char str[128];

	LPWSTR title = (LPWSTR)"xxxxxxxxxxxxxxxxxx";	//новая версия Windows
	GetConsoleTitle((LPWSTR)str, sizeof((LPWSTR)str)); // получить заголовок окна
	SetConsoleTitle(title);						// установить новый заголовок окна
	Sleep(100);									// ждем смены заголовка окна (100 мс);

	HWND hwnd = FindWindow(NULL, (LPWSTR)title);// определяем дескриптор окна
	SetConsoleTitle((LPWSTR)str);				//возвращаем прежний заголовок

	return hwnd;//вернуть дескриптор окна
}//end GetConcolWindow()

 /**********************  End Of Ex05_03_Con.CPP File ********************/
