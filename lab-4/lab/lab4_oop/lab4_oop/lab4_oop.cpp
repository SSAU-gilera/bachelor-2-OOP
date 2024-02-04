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
		cout << "Лабораторная работа № 4\nГижевская Валерия\nВариант 9" << endl;
		cout << "Что вы хотите сделать?" << endl;
		cout << "1 - Добавить книгу в библиотеку" << endl
			<< "2 - Выдать книгу читателю на руки" << endl
			<< "3 - Вернуть книгу в библиотеку" << endl
			<< "4 - Вывести на экран всех зарегистрированные в библиотеке произведения" << endl
			<< "5 - Вывести на экран авторов всех зарегистрированных в библиотеке книг" << endl
			<< "6 - По фамилии автора вывести на экран все его произведения, стоящие в библиотеке на полках" << endl
			<< "0 - Выход" << endl;
		cin >> s;
		try {
			switch (s)
			{
			case '1': {
				cout << "Название книги: ";
				string name;
				cin >> name;
				cout << "Имя автора: ";
				string author;
				cin >> author;
				cout << "Количество экземпляров: ";
				int num;
				cin >> num;
				cout << "Трёхзначный шифр автора: ";
				char code[3];
				cin >> code;
				library.add_book(name, num, author, code);
				break;
			}
			case '2': {
				cout << "Название книги: ";
				string name;
				cin >> name;
				cout << "Имя автора: ";
				string author;
				cin >> author;
				library.give_book(name, author);
				break;
			}
			case '3': {
				cout << "Название книги: ";
				string name;
				cin >> name;
				cout << "Имя автора: ";
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
				cout << "Имя автора: ";
				string author;
				cin >> author;
				library.available_books(author);
				break;
			}
			case '0': {
				break;
			}
			default: {
				cout << "Нет такого пункта" << endl;
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
