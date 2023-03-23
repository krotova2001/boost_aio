#pragma once
#include <chrono> // дл€ печати текущего времени
#include <iostream> // дл€ вывода текста 
#include <string> // дл€ работы со строками
#include <fstream> // дл€ вывода в файл
using namespace std;

//класс логгера, которые записывает событи€ в файл
//все функции будут статическими, больше одного экземпл€ра класса нам не надо
class Logger

{
public:
	static void Write_log(string message); // записать лог - ок

};

