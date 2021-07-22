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
	int No;
	int id;
	char* f_name;
	char* l_name;
	string gender;
	int day;
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
	double other_mark;
	double midterm_mark;
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
	string pw;
	string name;
};

void staff_working();
void student_working();

bool check_account_staff(account_staff& a);
void read_info_account_staff(ifstream& file, account_staff& a);
bool check_account_student(account_student& a);
void read_info_account_student(ifstream& file, account_student& a);

void checkdate(int day, int month, int year, int& check);
void changedate();
void showdate();
void get_date(int& day, int& month, int& year);

void create_school_year();
void create_class();

void view_list_of_classes();

void add_1_student_to_class();
void add_student_by_csv_file();

void create_semister();
string get_current_semister();

void create_course_registration_session();
void show_course_registration_session();

void create_course(string d);

void view_list_of_courses(string d);

void enroll_in_course(string d);

void output_file_class(account_student& a, string d);
bool s_register(i_course b, account_student& a);

void cancel_registration(account_student& a);

void read_info_student(ifstream& file, account_student& a);
bool read_file_info_student(account_student& a);

void copy_and_remove_file(string d, string h);

void view_personal_information(account_student a);

void value_creation(account_student& a);

double* read_mark(string d, string h);

void read_student_score(account_student & a);
void view_score(account_student & a);

void export_score_list(string& d);
void correct_score(string& d, string& h);

#endif