#define _CRT_SECURE_NO_WARNINGS
#pragma once

#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>


typedef struct
{
	int stringLength;
	int stringNumber;
} String; //структура таблицы вывода
 static int cmpf(const void* _a, const void* _b)//функция сравнения 2 записей
{
	const String* a = (String*)_a;
	const String* b = (String*)_b;
	return a->stringLength - b->stringLength;
}

class TextFile
{
private:	
	FILE *fp; //поток к файлу
	int amount_of_strings; //количество строк
	int* mas_of_lengths;      //массив длин строк
	void make_mas(); //создание массива записей
	void make_length_mas();//создание массива длин строк
	
public:	
	char* filename; //имя файла 
	String* mas; //массив записей
	friend int cmpf(const void* first, const void* second); //функция сравнения для сортировки
	void sort_mas(); //сортировка массива записей	
	void print_table(); //вывод массива записей на консоль

	TextFile(); // конструктор (ввод имени файла, создание массива)
	~TextFile(); // деструктор
};
