#include "Logger.h"
#include <iostream>
#pragma warning(disable : 4996) // чтоб не ругался ctime
using namespace std;

//реализация функционала класса логгера

	void Logger::Write_log(string message)// записать лог - ок
	{
		ofstream Result; // создадим объект для чтения исходного файла
		Result.open("log.txt", ios::app); //откроем файл на запись

		//получаем текущую дату и время
		auto now = chrono::system_clock::now();
		time_t end_time = chrono::system_clock::to_time_t(now);

		if (Result.is_open()) // если удалось открыть исходный файл, то...
		{
			Result << ctime(&end_time) <<" "<< message << endl; // записываем 
			Result.close(); // закрываем 
		}
		else
		{
			cout << "Can not write" << message << endl;
		}
	}


