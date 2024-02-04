#include "Database.h"

Database::Database()
{
	studentstream = fopen("students.dat", "w+b");
	indexnamestream = fopen("indexname.idx", "w+b");
	indexkardstream = fopen("indexkard.idx", "w+b");
}

Database::~Database()
{
	fclose(studentstream);
	fclose(indexnamestream);
	fclose(indexkardstream);
}

//�������� ����� �������
void Database::make_student_file(int n)
{
	num_of_students = n;
	Student st;
	char buf[10];
	while (n--) {
		puts("������� ������� ��������: ");
		gets_s(st.name);
		puts("������� ����� �������� ������: ");
		gets_s(buf);
		st.kard = atoi(buf);
		fwrite(&st, sizeof(Student), 1, studentstream);
	}
}

//��������� �������� �� �����
int cmp_by_name(const void* a, const void* b) {
	return strcmp(((Database::IndexName*)a)->name, ((Database::IndexName*)b)->name);
}

//���������� ���������� ����� �� ��������
void Database::make_indexname_file()
{
	IndexName* index_arr = (IndexName*)malloc(sizeof(IndexName) * num_of_students);
	Student tmp;
	fseek(studentstream, 0, SEEK_SET);
	for (int i = 0; i < num_of_students; i++) {
		index_arr[i].index = ftell(studentstream);
		fread(&tmp, sizeof(Student), 1, studentstream);
		strcpy(index_arr[i].name, tmp.name);
	}
	qsort(index_arr, num_of_students, sizeof(IndexName), cmp_by_name);
	for (int i = 0; i < num_of_students; i++) {
		fwrite(&index_arr[i], sizeof(IndexName), num_of_students, indexnamestream);
	}
	free(index_arr);
}

//��������� �������� �� ������ �������
int cmp_by_kard(const void* a, const void* b) {
	return ((Database::IndexKard*)a)->kard - ((Database::IndexKard*)b)->kard;
}

//���������� ���������� ����� �� ������
void Database::make_indexkard_file()
{
	IndexKard* index_arr = (IndexKard*)malloc(sizeof(IndexKard) * num_of_students);
	Student tmp;
	fseek(studentstream, 0, SEEK_SET);
	for (int i = 0; i < num_of_students; i++) {
		index_arr[i].index = ftell(studentstream);
		fread(&tmp, sizeof(Student), 1, studentstream);
		index_arr[i].kard=tmp.kard;
	}
	qsort(index_arr, num_of_students, sizeof(IndexKard), cmp_by_kard);
	for (int i = 0; i < num_of_students; i++) {
		fwrite(&index_arr[i], sizeof(IndexKard), num_of_students, indexkardstream);
	}
	free(index_arr);
}

//��������� ������
int cmp_kard(const void* a, const void* b) {
	return (*(Database::IndexKard*)a).kard - (*(Database::IndexKard*)b).kard;
}

//����� ������� �������� �� ������ �������
void Database::print_name(unsigned kard)
{
	IndexKard* index_arr = (IndexKard*)malloc(sizeof(Student) * num_of_students);
	fseek(indexkardstream, 0, SEEK_SET);
	for (int i = 0; i < num_of_students; i++) { //��������� ��� ��������� ������ �� ������ � ������
		fread(&index_arr[i], sizeof(IndexKard), 1, indexkardstream);
	}
	IndexKard tmp;
	tmp.kard = kard;
	IndexKard* found = (IndexKard*)bsearch(&tmp, index_arr, num_of_students, sizeof(IndexKard), cmp_kard); //�������� �����
	fseek(studentstream, found->index, SEEK_SET); //������ ��������� �� ������ ������ ������
	Student st;
	fread(&st, sizeof(Student), 1, studentstream);//��������� ������
	puts(st.name);
	free(index_arr);
}


//����� ������� � ���������� �������
void Database::print_names_file()
{
	IndexName tmp;
	Student st;
	fseek(indexnamestream, 0, SEEK_SET);
	for (int i = 0; i < num_of_students; i++) {
		fread(&tmp, sizeof(IndexName), 1, indexnamestream);
		fseek(studentstream, tmp.index, SEEK_SET);
		fread(&st, sizeof(Student), 1, studentstream);
		puts(st.name);
	}
}
