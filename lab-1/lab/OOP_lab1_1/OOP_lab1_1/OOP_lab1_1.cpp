// OOP_lab1_1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <iostream>
#include <cstring>
#include <cstdio>
#include "cstdlib"
#include <Windows.h>
using namespace std;

class Sentence
{

	char** lexArray; // массив слов
	int lexCounter = 0; // количество слов
	char code[32][7] = { "00000*","00001*","00010*","00011*","00100*","00101*","00110*","00111*","01000*","01001*","01010*","01011*","01100*","01101*","01110*","01111*","10000*",
	"10001*","10010*","10011*","10100*","10101*","10110*","10111*","11000*","11001*","11010*","11011*","11100*","11101*","11110*","11111*"};
public:
	char* str; // последовательность символов предложения
	
	// конструктор - создание предложения с помощью ввода с консоли
	Sentence(int flag)
	{
		printf("Введите строку: ");
		str = (char*)malloc(sizeof(char) * 81);
		char ch;
		int iter = 0;
		while ((ch = getchar()) != '\n' && iter <= 80)
		{
			str[iter] = tolower(ch);
			iter++;
		}
		str = (char*)realloc(str, sizeof(char) * (iter + 1));
		str[iter] = '\0';
		lexArray = (char**)malloc(sizeof(char*) * 81);
	}
	//конструктор создание пустого предложения
	Sentence()
	{
		str = (char*)malloc(sizeof(char));
		*str = '\0';
		lexArray = (char**)malloc(sizeof(char*));
	}


	void GetLexArray()//разбиение предожения на слова
	{
		char* lex = strtok(str, " ");
		int iter = 0;
		while (lex != NULL)
		{
			lexArray[iter] = lex;
			lex = strtok(NULL, " ");
			iter++;
			lexCounter++;
		}
		lexArray = (char**)realloc(lexArray, sizeof(char*) * lexCounter);
	}

	Sentence& GetCodedSent()//получение нового закодированного предложения
	{
		Sentence* codedSentence = (Sentence*)malloc(sizeof(Sentence));
		int symbolCode;
		int memory = 0;
		codedSentence->str = (char*)malloc(sizeof(char) * 81 * 7);
		codedSentence->lexArray = (char**)malloc(sizeof(char*));
		*(codedSentence->str) = '\0';
		for (int i = 0; i < lexCounter; i++)
		{
			for (int j = 0; j < strlen(lexArray[i]); j++)
			{
				if (lexArray[i][j] == 'ё') symbolCode = (int)'е' - (int)'a';
				else symbolCode = (int)lexArray[i][j] - (int)'а';
				strcat(codedSentence->str, code[symbolCode]);//конкатенация закодированной последовательноси к строке
				memory += 6;
			}
			strcat(codedSentence->str, " ");//добавление пробела после каждого слова
			memory += 1;

		}
		strcat(codedSentence->str, "\0");
		memory++;
		codedSentence->str = (char*)realloc(codedSentence->str, memory);
		return *codedSentence;
	}

	~Sentence()//деструктор удаление предложения
	{
		free(str);
		free(lexArray);
	}

};

int main() {
	SetConsoleCP(1251);//Установка кодировки win-cp 1251 для ввода
	SetConsoleOutputCP(1251);//Установка win-cp 1251 для вывода
	setlocale(LC_ALL, "Rus");//Разрешить кириллицу
	puts("Лабораторная работа #1\nПо курсу ООП\nСтудента группы 6213-020302D\nГижевской Валерии\nВариант 9");

	Sentence sentence = Sentence(0);
	sentence.GetLexArray();
	Sentence finalString = sentence.GetCodedSent();
	printf("Закодированная строка: ");
	puts(finalString.str);


	system("pause");//Задержать консоль на экране при завершении программы
	return 0;
}



// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
