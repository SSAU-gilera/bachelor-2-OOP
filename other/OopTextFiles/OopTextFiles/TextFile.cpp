#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include "pch.h"
#include"TextFile.h"

//конструктор - создание объекта файла
TextFile::TextFile()
{
	puts("Введите имя файла (не больше 20 символов):");
	filename = (char*)malloc(sizeof(char) * 15);
	amount_of_strings = 0; // число строк
	scanf_s("%s", filename);//считываем имя файла c консоли
	strcat(filename, ".txt");
	fp = fopen(filename, "rt");//открытие файла
	if (fp == NULL) 
	{
		puts("Ошибка открытия файла");	
		exit(1); 
	}
	else
	{	
		free(filename);
		make_length_mas();		
		make_mas();
	}

}
//получение массива длин строк
void TextFile::make_length_mas()
{				
	char* str = (char*)malloc(100 * sizeof(char));
	mas_of_lengths = (int*)malloc(sizeof(int) * 50); // массив длин строк
	while (fgets(str,99,fp) != NULL)
	{		 		
		mas_of_lengths[amount_of_strings] = strlen(str);	    
		amount_of_strings ++;		
	}
	free(str);
	fclose(fp);
}

//получение массива записей вида <длина строки, количество строк>
void TextFile::make_mas()
{
	mas = (String*)malloc(sizeof(String) * amount_of_strings); //массив записей 
	int same_size;
	for (int i = 0; i < amount_of_strings; i++)
	{
		same_size = 0;
		for (int ind = 0; ind < amount_of_strings; ind++)//подсчитывае количество строк каждой длины
	    {
			if (mas_of_lengths[i] == mas_of_lengths[ind])
			   same_size++;
		}
		mas[i] = { mas_of_lengths[i],same_size };	
	}
	free(mas_of_lengths);
}

//вывод на консоль массива записей
void TextFile::print_table()
{
	for (int m = 0; m < amount_of_strings; m++)
	{
		bool check = false;
		for (int num = m - 1; num >= 0; num--)
		{
			if (mas[m].stringLength == mas[num].stringLength)
			{
				check = true;
				break;
			}
		}
		if(!check) printf("\t<%d,%d>\n", mas[m].stringLength, mas[m].stringNumber);
	}	
}

//сортировка массива записей
void TextFile:: sort_mas()
{
	qsort(mas, amount_of_strings,sizeof(String),cmpf);
}

//деструктор - удаление объекта файла
TextFile::~TextFile()
{	
	free(fp);
	free(mas);	
}
