#ifndef header_h
#define header_h

#include <iostream>
#include <math.h>
#include <fstream>
#include<string>
#include<ctime>
#include <iomanip>

using namespace std;

struct i_student;
struct i_course;
struct mark;
struct i_s_course;
struct account_student;
struct account_staff;

struct i_student
{
	string my_class;
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

struct account_student
{
	int id;
	char* pw;
	i_student i_s;
	i_s_course* head;
};


struct account_staff
{
	int id;
	char* pw;
};

void checkdate(int day, int month, int year, int& check);
void changedate();
void showdate();
void get_date(int& day, int& month, int& year);

void stafflogin();
bool check_account_staff(account_staff& a);
void read_info_account_staff(ifstream& file, account_staff& a);

void studentlogin();
bool check_account_student(account_student& a);
void read_info_account_student(ifstream& file, account_student& a);

void removed_memory(account_student& a);
void create_class();
void read_info_student(ifstream& file, account_student& a);
bool read_file_info_student(account_student& a);
void read_file_list_scienci(ifstream& f, i_course& a,int n);
void create_school_year();

void output_i_course(i_course a);
void removed_i_course(i_course& a);
bool s_register(i_course b, account_student& a);

void copy_and_remove_file(string d, string h);
void output_file_class(account_student & a, string d);
void output_list_course(i_s_course* a);
void View_personal_information(account_student a);

bool scienci_registration(account_student& a);

#endif