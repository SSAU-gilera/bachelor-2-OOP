#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include "pch.h"
#include"TextFile.h"

//����������� - �������� ������� �����
TextFile::TextFile()
{
	puts("������� ��� ����� (�� ������ 20 ��������):");
	filename = (char*)malloc(sizeof(char) * 15);
	amount_of_strings = 0; // ����� �����
	scanf_s("%s", filename);//��������� ��� ����� c �������
	strcat(filename, ".txt");
	fp = fopen(filename, "rt");//�������� �����
	if (fp == NULL) 
	{
		puts("������ �������� �����");	
		exit(1); 
	}
	else
	{	
		free(filename);
		make_length_mas();		
		make_mas();
	}

}
//��������� ������� ���� �����
void TextFile::make_length_mas()
{				
	char* str = (char*)malloc(100 * sizeof(char));
	mas_of_lengths = (int*)malloc(sizeof(int) * 50); // ������ ���� �����
	while (fgets(str,99,fp) != NULL)
	{		 		
		mas_of_lengths[amount_of_strings] = strlen(str);	    
		amount_of_strings ++;		
	}
	free(str);
	fclose(fp);
}

//��������� ������� ������� ���� <����� ������, ���������� �����>
void TextFile::make_mas()
{
	mas = (String*)malloc(sizeof(String) * amount_of_strings); //������ ������� 
	int same_size;
	for (int i = 0; i < amount_of_strings; i++)
	{
		same_size = 0;
		for (int ind = 0; ind < amount_of_strings; ind++)//����������� ���������� ����� ������ �����
	    {
			if (mas_of_lengths[i] == mas_of_lengths[ind])
			   same_size++;
		}
		mas[i] = { mas_of_lengths[i],same_size };	
	}
	free(mas_of_lengths);
}

//����� �� ������� ������� �������
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

//���������� ������� �������
void TextFile:: sort_mas()
{
	qsort(mas, amount_of_strings,sizeof(String),cmpf);
}

//���������� - �������� ������� �����
TextFile::~TextFile()
{	
	free(fp);
	free(mas);	
}
