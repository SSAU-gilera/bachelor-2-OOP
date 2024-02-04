#define _CRT_SECURE_NO_WARNINGS
#pragma once

#include <list>
#include <string>
#include <iostream>

using namespace std;

class Library
{


public:
	Library();
	~Library();

	void add_book(string name, int num, string author, char* code_author);
	void give_book(string name, string author);
	void return_book(string name, string author);
	void list_of_books();
	void list_of_authors();
	void available_books(string author);


private:

	typedef struct
	{
		string name_book;
		int num_of_books_all;
	} Book;

	typedef struct
	{
		char code_author[3];
		string name_author;
	} Author;

	typedef struct
	{
		char code_author[3];
		Book* index_book;
		int num_of_books;
	} Index;

	list <Book*> listBook;
	list <Author*> listAuthor;
	list <Index*> listIndex;

	Book* get_book(string name);
	Author* get_author(string author);
	Index* get_index(Book* book, char* code_author);
};

