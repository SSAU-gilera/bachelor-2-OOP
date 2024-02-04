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
} String; //��������� ������� ������
 static int cmpf(const void* _a, const void* _b)//������� ��������� 2 �������
{
	const String* a = (String*)_a;
	const String* b = (String*)_b;
	return a->stringLength - b->stringLength;
}

class TextFile
{
private:	
	FILE *fp; //����� � �����
	int amount_of_strings; //���������� �����
	int* mas_of_lengths;      //������ ���� �����
	void make_mas(); //�������� ������� �������
	void make_length_mas();//�������� ������� ���� �����
	
public:	
	char* filename; //��� ����� 
	String* mas; //������ �������
	friend int cmpf(const void* first, const void* second); //������� ��������� ��� ����������
	void sort_mas(); //���������� ������� �������	
	void print_table(); //����� ������� ������� �� �������

	TextFile(); // ����������� (���� ����� �����, �������� �������)
	~TextFile(); // ����������
};
