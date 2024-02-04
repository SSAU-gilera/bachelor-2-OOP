#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <Windows.h>
#include "Database.h"

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "");
	Database db;
	puts("Лабораторная работа № 3\nГижевская Валерия\nВариант 9\n");
	puts("\nВведите количество студентов: ");
	char buf[10];
	gets_s(buf);
	db.make_student_file(atoi(buf));
	db.make_indexname_file();
	db.make_indexkard_file();
	puts("\nВсе студенты в алфавитном порядке:");
	db.print_names_file();
	puts("\nВведите номер зачетной книжки:");
	gets_s(buf);
	unsigned kard = atoi(buf);
	db.print_name(kard);
	system("pause");
	return 0;
}