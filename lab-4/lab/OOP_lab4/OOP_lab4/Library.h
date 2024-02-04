#define _CRT_SECURE_NO_WARNINGS
#pragma once

#include <list>
#include <string>
#include <iostream>

using namespace std;

class Library
{


public:

	~Library();

	void add_book(string name, int num, string author, char* code_author);//добавление книги в библиотеку
	void give_book(string name, string author);//выдача книга
	void return_book(string name, string author);//возврат книги
	void list_of_books();//вывод всех книг
	void list_of_authors();//вывод всех авторов
	void available_books(string author);//вывод книг заданного автора на полках


private:

	//запись о книге
	struct Book
	{
		string name_book;//название книги
		int num_of_books_all;//количество экземпл€ров в библиотеке
	} ;

	//запись с авторами
	struct Author
	{
		char code_author[3];//шифр автора
		string name_author;//им€ автора
	} ;

	//индексна€ запись
	struct Index
	{
		char code_author[3];//шифр автора
		Book* index_book;//индекс книги
		int num_of_books;//колиесство экземпл€ров на полке
	} ;

	list <Book*> listBook;//список книг
	list <Author*> listAuthor;//список авторов
	list <Index*> listIndex;//список, св€зывающий книги и авторов

	Book* get_book(string name);//ищем книгу(указатель в списке) по названию
	Author* get_author(string author);//ищем автора(указатель в списке) по имени
	Index* get_index(Book* book, char* code_author);//получение индексной записи по индексу книги и шифру
};

