#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <Windows.h>
#include "Library.h"

int main() {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "");
	Library library;
	char s;
	do {
		system("cls");
		cout << "������������ ������ � 4\n��������� �������\n������� 9" << endl;
		cout << "��� �� ������ �������?" << endl;
		cout << "1 - �������� ����� � ����������" << endl
			<< "2 - ������ ����� �������� �� ����" << endl
			<< "3 - ������� ����� � ����������" << endl
			<< "4 - ������� �� ����� ���� ������������������ � ���������� ������������" << endl
			<< "5 - ������� �� ����� ������� ���� ������������������ � ���������� ����" << endl
			<< "6 - �� ������� ������ ������� �� ����� ��� ��� ������������, ������� � ���������� �� ������" << endl
			<< "0 - �����" << endl;
		cin >> s;
		try {
			switch (s)
			{
			case '1': {
				cout << "�������� �����: ";
				string name;
				cin >> name;
				cout << "��� ������: ";
				string author;
				cin >> author;
				cout << "���������� �����������: ";
				int num;
				cin >> num;
				cout << "���������� ���� ������: ";
				char code[3];
				cin >> code;
				library.add_book(name, num, author, code);
				break;
			}
			case '2': {
				cout << "�������� �����: ";
				string name;
				cin >> name;
				cout << "��� ������: ";
				string author;
				cin >> author;
				library.give_book(name, author);
				break;
			}
			case '3': {
				cout << "�������� �����: ";
				string name;
				cin >> name;
				cout << "��� ������: ";
				string author;
				cin >> author;
				library.return_book(name, author);
				break;
			}
			case '4': {
				library.list_of_books();
				break;
			}
			case '5': {
				library.list_of_authors();
				break;
			}
			case '6': {
				cout << "��� ������: ";
				string author;
				cin >> author;
				library.available_books(author);
				break;
			}
			case '0': {
				break;
			}
			default: {
				cout << "��� ������ ������" << endl;
				break;
			}
			}
		}
		catch (const char* exc) {
			cout << exc << endl;
		}
		system("pause");

	} while (s != '0');



	return 0;
}
