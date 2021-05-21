#ifndef header_h
#define header_h

#include <iostream>
#include <math.h>
#include <fstream>
#include<string>
#include<ctime>

using namespace std;
struct i_student;
struct i_course;
struct mark;
struct course;
struct gmail_student;
struct i_student
{
	//int student_id;
	char* f_name;
	char* l_name;
	int date;
	int month;
	int year;
	int social_id;
};

struct i_course
{
	int course_id;
	char* course_name;
	char* teacher;
	int number_of_credits;
	int day1;
	int session1;
	int day2;
	int session2;
};
struct mark
{
	double total_mark;
	double final_mark;
	double orther_mark;
	i_course* i_c;
	mark* node;
};
struct gmail_student
{
	int name_gmail;
	char* pw;
	i_student i_s;
	mark* m_s;
};
struct course
{
	i_course* i_c;
	int n_o_student;
	gmail_student head;
	course* node;
};
bool check_email_student(gmail_student& a);
void read_info_email_student(ifstream& file, gmail_student& a);
void removed_memory(gmail_student& a);
void create_class(fstream& f);
bool read_file_info_student(gmail_student& a);
void read_info_student(ifstream& file, i_student& a);
void changedate();
void showdate();
void stafflogin();
void studentlogin();
void checkdate(int day, int month, int year, int& check);

#endif