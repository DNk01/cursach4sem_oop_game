//GetConWin.cpp
#include<windows.h>
#include"GetConWin.h"
//������� ���������� ����
HWND GetConsolWindow()
{
	char str[128];
	//char title[128]="xxxxxxxxxxxxxxxxxxxxx";
	LPWSTR title = (LPWSTR)"xxxxxxxxxxxxxxxxxxx";//����� ������ �������
	GetConsoleTitle((LPWSTR)str, sizeof((LPWSTR)str));//�������� ��������� �����
	SetConsoleTitle(title);//���������� ����� ��������� ����
	Sleep(100);//���� ����� ��������� ����(100 ��)

	HWND hwnd = FindWindow(NULL, (LPWSTR)title);//���������� ���������� ����
	SetConsoleTitle((LPWSTR)str);// ���������� ������� ���������

	return hwnd;//������� ���������� ����
}//end GetConsolWindow()