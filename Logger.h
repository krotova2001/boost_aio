#pragma once
#include <chrono> // ��� ������ �������� �������
#include <iostream> // ��� ������ ������ 
#include <string> // ��� ������ �� ��������
#include <fstream> // ��� ������ � ����
using namespace std;

//����� �������, ������� ���������� ������� � ����
//��� ������� ����� ������������, ������ ������ ���������� ������ ��� �� ����
class Logger

{
public:
	static void Write_log(string message); // �������� ��� - ��

};

