#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <Windows.h>
#include "Database.h"

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "");
	Database db;
	puts("������������ ������ � 3\n��������� �������\n������� 9\n");
	puts("\n������� ���������� ���������: ");
	char buf[10];
	gets_s(buf);
	db.make_student_file(atoi(buf));
	db.make_indexname_file();
	db.make_indexkard_file();
	puts("\n��� �������� � ���������� �������:");
	db.print_names_file();
	puts("\n������� ����� �������� ������:");
	gets_s(buf);
	unsigned kard = atoi(buf);
	db.print_name(kard);
	system("pause");
	return 0;
}