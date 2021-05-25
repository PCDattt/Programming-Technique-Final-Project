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
struct gmail_student;
struct i_s_course;
struct i_student
{
	char* f_name;
	char* l_name;
	int date;
	int month;
	int year;
	int social_id;
	int number_course;
};

struct i_course
{
	int course_id;
	char* course_name;
	char* teacher;
	int n_o_credits;
	char* day1;
	int session1;
	char* day2;
	int session2;
	int n_o_student;
};
struct mark
{
	double total_mark;
	double final_mark;
	double orther_mark;
};
struct i_s_course
{
	mark s_mark;
	i_course i_c;
	i_s_course* node;
};
struct gmail_student
{
	int name_gmail;
	char* pw;
	i_student i_s;
	i_s_course* head;
};

bool check_email_student(gmail_student& a);
void read_info_email_student(ifstream& file, gmail_student& a);
void removed_memory(gmail_student& a);
void create_class(fstream& f);
bool read_file_info_student(gmail_student& a);
void read_info_student(ifstream& file, gmail_student& a);
void changedate();
void showdate();
void stafflogin();
void studentlogin();
void checkdate(int day, int month, int year, int& check);
void read_file_list_scienci(ifstream& f, i_course& a);

#endif