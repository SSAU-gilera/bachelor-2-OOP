
#define _CRT_SECURE_NO_WARNINGS
#pragma once

#include "pch.h"
#include <iostream>
#include<Windows.h>
#include"TextFile.h"

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(0, "");
	puts("Лабораторная работа № 2\nГижевская Валерия\nВариант 9\n");
	TextFile lr;
	lr.sort_mas();
	puts("Массив записей вида <длина строк,количество строк>");
	lr.print_table();
	system("pause\n");
	return 0;
}

