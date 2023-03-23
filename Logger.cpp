#include "Logger.h"
#include <iostream>
#pragma warning(disable : 4996) // ���� �� ������� ctime
using namespace std;

//���������� ����������� ������ �������

	void Logger::Write_log(string message)// �������� ��� - ��
	{
		ofstream Result; // �������� ������ ��� ������ ��������� �����
		Result.open("log.txt", ios::app); //������� ���� �� ������

		//�������� ������� ���� � �����
		auto now = chrono::system_clock::now();
		time_t end_time = chrono::system_clock::to_time_t(now);

		if (Result.is_open()) // ���� ������� ������� �������� ����, ��...
		{
			Result << ctime(&end_time) <<" "<< message << endl; // ���������� 
			Result.close(); // ��������� 
		}
		else
		{
			cout << "Can not write" << message << endl;
		}
	}


