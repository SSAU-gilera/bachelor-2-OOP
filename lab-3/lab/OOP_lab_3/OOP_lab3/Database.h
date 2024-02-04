#define _CRT_SECURE_NO_WARNINGS
#pragma once

#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

class Database
{
	friend int cmp_by_name(const void* a, const void* b);//������� ���������
	friend int cmp_by_kard(const void* a, const void* b);//������� ���������
	friend int cmp_kard(const void* a, const void* b); 
public:
	Database();
	~Database();

	void make_student_file(int n);//�������� ����� �������
	void make_indexname_file();//���������� ���������� ����� �� ��������
	void make_indexkard_file();//���������� ���������� ����� �� ������
	void print_name(unsigned kard);//����� ������� �������� �� ������ �������
	void print_names_file();//����� ���������������� ������ � ���������

private:
	typedef struct {//������ � ��������
		unsigned kard;//����� �������
		char name[21];//�������
	} Student;

	typedef struct {//��������� ������ � ��������
		long index;//������ ������ � ��������
		char name[21];//�������
	} IndexName;

	typedef struct {//��������� ������ � �������
		long index;//������ ������ � ��������
		unsigned kard;//����� �������
	} IndexKard;

	FILE* studentstream;//����� � ������ �����
	FILE* indexnamestream;//����� � ������� ������ �� �������
	FILE* indexkardstream;//����� � ������� ������ �� ������
	int num_of_students;//���������� ���������
};

