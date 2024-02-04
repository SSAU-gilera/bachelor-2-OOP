#include "Library.h"





Library::~Library()
{
	for (Book*& book : listBook) delete book;
	for (Author*& author : listAuthor) delete author;
	for (Index*& index : listIndex) delete index;
}

void Library::add_book(string name, int num, string author, char* code_author)
{
	Book* book = new Book;
	book->name_book = name;
	book->num_of_books_all = num;
	listBook.push_back(book);
	Author* book_author = get_author(author);
	if (!book_author) {
		book_author = new Author;
		book_author->name_author = author;
		strcpy(book_author->code_author, code_author);
		listAuthor.push_back(book_author);
	}
	Index* index = new Index;
	strcpy(index->code_author, code_author);
	index->num_of_books = num;
	index->index_book = book;
	listIndex.push_back(index);

}

void Library::give_book(string name, string author)
{
	Book* book_ptr = get_book(name);
	if (!book_ptr) {
		throw "Такой книги в библиотеке нет";
	}
	Author* author_ptr = get_author(author);
	if (!author_ptr) {
		throw "Такого автора в библиотеке нет";
	}
	Index* index = get_index(book_ptr, author_ptr->code_author);
	if (index->num_of_books > 0) {
		index->num_of_books--;
	}
	else {
		throw "Все книги уже выданы";
	}
}

void Library::return_book(string name, string author)
{
	Book* book_ptr = get_book(name);
	if (!book_ptr) {
		throw "Такой книги в библиотеке нет";
	}
	Author* author_ptr = get_author(author);
	if (!author_ptr) {
		throw "Такого автора в библиотеке нет";
	}
	Index* index = get_index(book_ptr, author_ptr->code_author);
	if (index->num_of_books < book_ptr->num_of_books_all) {
		index->num_of_books++;
	}
	else {
		throw "Все книги на месте!";
	}
}

void Library::list_of_books()
{
	for (Index*& index : listIndex) {
		string name_author = "";
		for (Author*& author : listAuthor) {
			if (!strcmp(index->code_author, author->code_author)) {
				name_author = author->name_author;
			}
		}
		cout << index->index_book->name_book << ", " << name_author << " - " << index->index_book->num_of_books_all << " штук" << endl;
	}
}

void Library::list_of_authors()
{
	for (Author*& author : listAuthor)
	{
		cout << author->name_author << endl;
	}
}

void Library::available_books(string author)
{
	Author* author_ptr = get_author(author);
	if (!author_ptr) {
		throw "Такого автора в библиотеке нет";
	}
	for (Index*& index : listIndex) {
		if ((index->num_of_books > 0) && (!strcmp(index->code_author, author_ptr->code_author))) {
			cout << index->index_book->name_book << " - " << index->num_of_books << " штук" << endl;
		}
	}
}

Library::Book* Library::get_book(string name)
{
	Book* book_ptr = NULL;
	for (Book*& book : listBook) {
		if (book->name_book == name) {
			book_ptr = book;
			break;
		}
	}
	return book_ptr;
}

Library::Author* Library::get_author(string author)
{
	Author* author_ptr = NULL;
	for (Author*& _author : listAuthor) {
		if (_author->name_author == author) {
			author_ptr = _author;
		}
	}
	return author_ptr;
}

Library::Index* Library::get_index(Book * book, char* code_author)
{
	Index* index = NULL;
	for (Index*& idx : listIndex) {
		if (idx->index_book == book && !strcmp(idx->code_author, code_author)) {
			index = idx;
		}
	}
	return index;
}

