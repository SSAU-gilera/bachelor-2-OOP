#define _CRT_SECURE_NO_WARNINGS
#pragma once

#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

class Database
{
	friend int cmp_by_name(const void* a, const void* b);//функция сравнения
	friend int cmp_by_kard(const void* a, const void* b);//функция сравнения
	friend int cmp_kard(const void* a, const void* b); 
public:
	Database();
	~Database();

	void make_student_file(int n);//создание файла записей
	void make_indexname_file();//заполнение индексного файла по фамилиям
	void make_indexkard_file();//заполнение индексного файла по номеру
	void print_name(unsigned kard);//вывод фамилии студента по номеру зачётки
	void print_names_file();//вывод остортированного списка с фамилиями

private:
	typedef struct {//запись о студенте
		unsigned kard;//номер зачётки
		char name[21];//фамилия
	} Student;

	typedef struct {//индексная запись с фамилией
		long index;//индекс записи о студенте
		char name[21];//фамилия
	} IndexName;

	typedef struct {//индексная запись с номером
		long index;//индекс записи о студенте
		unsigned kard;//номер зачётки
	} IndexKard;

	FILE* studentstream;//поток к записи файла
	FILE* indexnamestream;//поток к индексу записи по фамилии
	FILE* indexkardstream;//поток к индексу записи по номеру
	int num_of_students;//количество студентов
};

