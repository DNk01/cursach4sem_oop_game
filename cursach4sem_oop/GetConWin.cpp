//GetConWin.cpp
#include<windows.h>
#include"GetConWin.h"
//создать консольное окно
HWND GetConsolWindow()
{
	char str[128];
	//char title[128]="xxxxxxxxxxxxxxxxxxxxx";
	LPWSTR title = (LPWSTR)"xxxxxxxxxxxxxxxxxxx";//нова€ верси€ видноус
	GetConsoleTitle((LPWSTR)str, sizeof((LPWSTR)str));//получить заголовок файла
	SetConsoleTitle(title);//установить новый заголовок окна
	Sleep(100);//∆дем смены заголовка окна(100 мс)

	HWND hwnd = FindWindow(NULL, (LPWSTR)title);//определ€ем дескриптор окна
	SetConsoleTitle((LPWSTR)str);// возвращаем прежний заголовок

	return hwnd;//вернуть дескриптор окна
}//end GetConsolWindow()