#ifndef header_h
#define header_h

#include <iostream>
#include <math.h>
#include <fstream>
#include<string>
#include<ctime>
#include <iomanip>

using namespace std;

struct info_student;
struct account_student;
struct account_staff;

struct info_student
{
	string clas;
	int no;
	int id;
	string f_name;
	string l_name;
	string gender;
	int day;
	int month;
	int year;
	int social_id;
	int course_registed;
};

struct account_student
{
	int id;
	char* pw;
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
int count_dates(int day, int month, int year);

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
void update_course_info(string d);
void delete_course(string d);

void get_info_student(int id, info_student& a);
void show_info_student(info_student a);

void enroll_in_course(string d,info_student& a);
void update_course_file_after_enroll(string s, int registed, int max);
void update_class_file_after_enroll(info_student a);

void view_list_enrolled(string d, info_student a);

void view_list_of_students_in_class();

void view_list_of_students_in_course();

void export_list_students(string d);
void import_scoreboard(string d);

void view_course_scoreboard(string d);

void view_student_scoreboard(string d, info_student a);

#endif