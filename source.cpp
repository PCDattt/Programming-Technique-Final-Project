#include "header.h"

void staff_working()
{
	account_staff a;
	int day = 0;
	int month = 0;
	int year = 0;
	int p = -1;
	string current_semister;

	if (check_account_staff(a) == true)
	{
		cout << endl;
		cout << "Staff login successfully." << endl;
		get_date(day, month, year);
		showdate();
		show_course_registration_session();
		while (p != 0)
		{
			cout << "Staff name: " << a.name << endl;
			cout << "Staff option: " << endl;
			cout << "1. Create a school year " << endl;
			cout << "2. Create a class " << endl;
			cout << "3. View list of classes" << endl;
			cout << "4. Add 1 student to class" << endl;
			cout << "5. Add student by using csv file" << endl;
			cout << "6. Create a semister " << endl;
			cout << "7. Create course registration session" << endl;
			cout << "8. Create course" << endl;
			cout << "9. View list of courses" << endl;
			cout << "0. Exit " << endl;
			cout << "Choose option you want: ";
			cin >> p;
			cout << endl;

			if (p == 1)
			{
				if (month == 9)
				{
					cout << "This month is September, you can create school year" << endl;
					create_school_year();
				}
				else
				{
					cout << "This month is not September, you can not create school year" << endl;
				}
			}

			if (p == 2)
			{
				create_class();
			}

			if (p == 3)
			{
				view_list_of_classes();
			}

			if (p == 4)
			{
				add_1_student_to_class();
			}

			if (p == 5)
			{
				add_student_by_csv_file();
			}

			if (p == 6)
			{
				create_semister();
			}

			if (p == 7)
			{
				create_course_registration_session();
			}

			if (p == 8)
			{
				current_semister = get_current_semister();
				create_course(current_semister);
			}

			if (p == 9)
			{
				current_semister = get_current_semister();
				view_list_of_courses(current_semister);
			}
			cout << endl;
		}
	}
	else
	{
		cout << "Invalid ID or password, can not log in" << endl;
	}
	cout << endl;
}

void student_working()
{
	account_student a;
	info_student b;
	int day = 0;
	int month = 0;
	int year = 0;
	int p = -1;
	string current_semister;

	if (check_account_student(a) == true)
	{
		cout << endl;
		cout << "Student login sucessfully" << endl;
		get_date(day, month, year);
		showdate();
		show_course_registration_session();
		get_info_student(a.id, b);
		show_info_student(b);
		while (p != 0)
		{
			cout << "1. Enroll in a course" << endl;
			cout << "0. Exit" << endl;
			cout << "Choose option you want: ";
			cin >> p;
			cout << endl;
			
			if (p == 1)
			{
				current_semister = get_current_semister();
				enroll_in_course(current_semister);
			}
			
			cout << endl;
		}
	}
	else
	{
		cout << "Invalid ID or password, can not log in" << endl;
	}

	cout << endl;
}

bool check_account_staff(account_staff& a)
{
	ifstream f1;
	f1.open("account_staff.csv", ios_base::in);
	if (f1.fail())
	{
		cout << "Can't open file account staff " << endl;
		return false;
	}
	int x;
	string y;
	cout << " + enter ID : ";
	cin >> x;
	cin.ignore();
	cout << " + enter password :";
	getline(cin, y);
	while (!f1.eof())
	{
		read_info_account_staff(f1, a);
		if (a.id == x)
		{
			if (y.compare(a.pw) == 0)
			{
				f1.close();
				return true;
			}
			f1.close();
			return false;
		}
	}
	f1.close();
	return false;
}

void read_info_account_staff(ifstream& file, account_staff& a)
{
	char b[50];
	int i = 0;

	file >> a.id;
	file.ignore();
	file.getline(b, 50, '\n');

	a.pw = b[0];
	for (i = 1; i < strlen(b); i++)
	{
		if (b[i] != ',')
		{
			a.pw = a.pw + b[i];
		}
		else
		{
			i = i + 1;
			break;
		}
	}

	a.name = b[i];
	for (i = i + 1; i < strlen(b); i++)
	{
		a.name = a.name + b[i];
	}
#pragma warning(suppress : 4996)
}

bool check_account_student(account_student& a)
{
	ifstream f1;
	f1.open("account_student.csv", ios_base::in);
	if (f1.fail())
	{
		cout << "Can't open file account student " << endl;
		return false;
	}
	int x;
	char y[50];
	cout << " + enter ID : ";
	cin >> x;
	cin.ignore();
	cout << " + enter password :";
	cin.getline(y, 50);
	while (!f1.eof())
	{
		read_info_account_student(f1, a);
		if (a.id == x)
		{
			if (strcmp(y, a.pw) == 0)
			{
				f1.close();
				return true;
			}
			f1.close();
			return false;
		}
	}
	f1.close();
	return false;
}

void read_info_account_student(ifstream& file, account_student& a)
{
	char b[50];
	file >> a.id;
	file.ignore();
	file.getline(b, 50, '\n');
	a.pw = new char[strlen(b) + 1];
#pragma warning(suppress : 4996)
	strcpy(a.pw, b);
}

void checkdate(int day, int month, int year, int& check)
{
	if (month > 12 || month < 1)
	{
		cout << "Invalid date, please try again." << endl;
		check = -1;
	}

	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
	{
		if (day < 1 || day > 31)
		{
			cout << "Invalid date, please try again." << endl;
			check = -1;
		}
	}

	if (month == 4 || month == 6 || month == 9 || month == 11)
	{
		if (day < 1 || day > 30)
		{
			cout << "Invalid date, please try again." << endl;
			check = -1;
		}
	}

	if (month == 2)
	{
		if ((year % 4 == 0 && year % 100 != 0) || (year % 100 == 0 && year % 400 == 0))
		{
			if (day < 1 || day > 29)
			{
				cout << "Invalid date, please try again." << endl;
				check = -1;
			}
		}
		else
		{
			if (day < 1 || day > 28)
			{
				cout << "Invalid date, please try again." << endl;
				check = -1;
			}
		}
	}
}

void changedate()
{
	int day = 0;
	int month = 0;
	int year = 0;
	int check = -1;

	ofstream file;
	file.open("date.txt");
	if (file.is_open())
	{
		while (check != 0)
		{
			cout << "Input day: ";
			cin >> day;
			cout << "Input month: ";
			cin >> month;
			cout << "Input year: ";
			cin >> year;
			check = 0;
			cout << endl;
			checkdate(day, month, year, check);
		}
		file << day << " " << month << " " << year;
		cout << "Change date successfully" << endl;
		file.close();
	}
	else
	{
		cout << "Can't open file." << endl;
		file.close();
	}
}

void showdate()
{
	int day = 0;
	int month = 0;
	int year = 0;
	
	ifstream file;
	file.open("date.txt");
	if (file.is_open())
	{
		file >> day;
		file >> month;
		file >> year;
		cout << "Current date: " << day << " / " << month << " / " << year << endl;
		file.close();
	}
	else
	{
		cout << "Haven't create today file" << endl;
	}
}


void get_date(int& day, int& month, int& year)
{
	ifstream file;
	file.open("date.txt");
	if (file.is_open())
	{
		file >> day;
		file >> month;
		file >> year;
		file.close();
	}
	else
	{
		cout << "Can't open file." << endl;
	}
}

void create_school_year()
{
	string school_year;
	int start = 0;
	int end = 0;
	ofstream fout;
	ifstream fin;


	cout << "Input start school year: ";
	cin >> start;
	cout << "Input end school year: ";
	cin >> end;
	school_year = to_string(start) + "-" + to_string(end) + ".txt";
	fin.open(school_year);
	if (fin.is_open() == false)
	{
		fout.open(school_year);
		fout.close();
		cout << "Create school year successfully" << endl;
	}
	else
	{
		cout << "School year is already existed" << endl;
	}
	fin.close();
}

void create_class()
{
	fstream f;
	fstream f2;
	string a;
	string d;

	f.open("list_class.txt", ios_base::in);

	if (!f.is_open())
	{
		f2.open("list_class.txt", ios_base::out);
		f2.close();
		f.open("list_class.txt", ios_base::in);
	}

	cout << "enter class's name : ";
	cin.ignore();
	getline(cin, d);
	while (!f.eof())
	{
		getline(f, a, '\n');
		if (a == d)
		{
			cout << "This class already exists" << endl;
			f.close();
			return;
		}
	}
	f.close();
	a = d + ".csv";
	f.open(a, ios_base::out);
	f << "No,Student ID,First name,Last name,Gender,Day,Month,Year,Social ID,Course Registed" << endl;
	f.close();
	f.open("list_class.txt", ios::app);
	f << d << endl;
	cout << " Create class successfully " << endl;
	f.close();
}

void view_list_of_classes()
{
	ifstream file;
	file.open("list_class.txt");
	if (!file.is_open())
	{
		cout << "Don't have any class" << endl;
		file.close();
		return;
	}
	else
	{
		cout << "List of classes: " << endl;
		while (!file.eof())
		{
			string s;
			file >> s;
			cout << s << endl;
		}
		file.close();
	}
}

void add_1_student_to_class()
{
	string s;
	ifstream infile;
	ofstream file;
	int n;

	cout << "Input class's name you want to add student: ";
	cin.ignore();
	getline(cin, s);
	s = s + ".csv";
	infile.open(s);
	if (!infile.is_open())
	{
		cout << "Class isn't existed" << endl;
		infile.close();
		return;
	}
	else
	{
		infile.close();
		file.open(s, ios_base::app);
		cout << "Input student's No: ";
		cin >> n;
		file << n << ",";
		cout << "Input student's ID: ";
		cin >> n;
		file << n << ",";
		cout << "Input student's first name: ";
		cin.ignore();
		getline(cin, s);
		file << s << ",";
		cout << "Input student's last name: ";
		getline(cin, s);
		file << s << ",";
		cout << "Input student's gender: ";
		getline(cin, s);
		file << s << ",";
		cout << "Input student birth's day: ";
		cin >> n;
		file << n << ",";
		cout << "Input student birth's month: ";
		cin >> n;
		file << n << ",";
		cout << "Input student birth's year: ";
		cin >> n;
		file << n << ",";
		cout << "Input student's Social ID: ";
		cin >> n;
		file << n << "," << 0 << endl;
		cout << "Add student successfully" << endl;
		file.close();
	}
}

void add_student_by_csv_file()
{
	ifstream infile;
	fstream outfile;
	string s1, s2, temp;

	cout << "Input csv file's name you want to use to add student: ";
	cin.ignore();
	getline(cin, s1);
	s1 = s1 + ".csv";
	infile.open(s1);
	if (!infile.is_open())
	{
		cout << "Can't open csv file" << endl;
		infile.close();
		return;
	}
	else
	{
		cout << "Input class's name you want to add student: ";
		getline(cin, s2);
		s2 = s2 + ".csv";
		outfile.open(s2, ios_base::in);
		if (!outfile.is_open())
		{
			cout << "Class isn't existed" << endl;
			infile.close();
			outfile.close();
			return;
		}
		else
		{
			outfile.close();
			outfile.open(s2, ios_base::app);
			getline(infile, temp,'\n');
			while (!infile.eof())
			{
				getline(infile, temp,'\n');
				outfile << temp << "," << 0 << endl;
			}
			infile.close();
			outfile.close();
			cout << "Add student by using csv file successfully" << endl;
		}
	}
}

void create_semister()
{
	string school_year;
	string semister;
	int startyear = 0;
	int opt = 0;
	int day_start, month_start, year_start, day_end, month_end, year_end;
	ofstream fout1;
	ofstream fout2;
	ifstream fin1;
	ifstream fin2;

	cout << "Input the start of school year you want this semister belong to: ";
	cin >> startyear;
	school_year = to_string(startyear) + "-" + to_string(startyear + 1) + ".txt";
	fin1.open(school_year);
	if (fin1.is_open())
	{
		cout << "Input semister you want to create: " << endl;
		cout << "1: Semister 1 " << endl;
		cout << "2: Semister 2 " << endl;
		cout << "3: Semister 3 " << endl;
		cin >> opt;

		semister = to_string(startyear) + "-" + to_string(startyear + 1) + " semister " + to_string(opt) + ".txt";
		fin2.open(semister);
		if (fin2.is_open())
		{
			cout << "Semister is already existed" << endl;
		}
		else
		{
			fout1.open(semister);
			fout1.close();

			cout << "Input semister's start day: ";
			cin >> day_start;
			cout << "Input semister's start month: ";
			cin >> month_start;
			cout << "Input semister's start year: ";
			cin >> year_start;
			cout << "Input semister's end day: ";
			cin >> day_end;
			cout << "Input semister's end month: ";
			cin >> month_end;
			cout << "Input semister's end year: ";
			cin >> year_end;

			fout2.open(school_year, ios_base::app);
			fout2 << "Semister " << opt << " " << day_start << " " << month_start << " " << year_start << " - "
				<< day_end << " " << month_end << " " << year_end << endl;
			fout2.close();
			cout << "Create semister successfully" << endl;

			fstream file;
			string s;

			file.open("course registration.txt", ios_base::in);
			if (!file.is_open())
			{
				file.close();
				file.open("course registration.txt", ios_base::out);
				file << endl;
				file << semister;
				file.close();
			}
			else
			{
				getline(file, s, '\n');
				file.close();

				file.open("course registration.txt", ios_base::out);
				file << s << endl;
				file << semister;
				file.close();
			}
		}
		fin2.close();
	}
	else
	{
		cout << "School year isn't existed" << endl;
	}
	fin1.close();
}

string get_current_semister()
{
	ifstream file;
	string s;

	file.open("course registration.txt");
	getline(file, s);
	getline(file, s);
	return s;
}

void create_course_registration_session()
{
	ofstream outfile;
	ifstream infile;
	int day = 0;
	int month = 0;
	int year = 0;
	int check = -1;
	string s;

	infile.open("course registration.txt");
	if (!infile.is_open())
	{
		infile.close();

		outfile.open("course registration.txt");

		while (check != 0)
		{
			cout << "Input start day: ";
			cin >> day;
			cout << "Input start month: ";
			cin >> month;
			cout << "Input start year: ";
			cin >> year;
			check = 0;
			cout << endl;
			checkdate(day, month, year, check);
		}

		outfile << day << " " << month << " " << year << " ";

		check = -1;

		while (check != 0)
		{
			cout << "Input end day: ";
			cin >> day;
			cout << "Input end month: ";
			cin >> month;
			cout << "Input end year: ";
			cin >> year;
			check = 0;
			cout << endl;
			checkdate(day, month, year, check);
		}

		outfile << day << " " << month << " " << year << endl;
		outfile.close();
	}
	else
	{
		getline(infile, s);
		getline(infile, s);
		infile.close();

		outfile.open("course registration.txt");

		while (check != 0)
		{
			cout << "Input start day: ";
			cin >> day;
			cout << "Input start month: ";
			cin >> month;
			cout << "Input start year: ";
			cin >> year;
			check = 0;
			cout << endl;
			checkdate(day, month, year, check);
		}

		outfile << day << " " << month << " " << year << " ";

		check = -1;

		while (check != 0)
		{
			cout << "Input end day: ";
			cin >> day;
			cout << "Input end month: ";
			cin >> month;
			cout << "Input end year: ";
			cin >> year;
			check = 0;
			cout << endl;
			checkdate(day, month, year, check);
		}

		outfile << day << " " << month << " " << year << endl;
		outfile << s;
		outfile.close();
	}

}

void show_course_registration_session()
{
	int day = 0;
	int month = 0;
	int year = 0;

	ifstream file;
	file.open("course registration.txt");
	if (file.is_open())
	{
		file >> day;
		file >> month;
		file >> year;
		cout << "Course registration is activated: " << day << " / " << month << " / " << year <<" - ";
		file >> day;
		file >> month;
		file >> year;
		cout << day << " / " << month << " / " << year << endl;
		file.close();
	}
	else
	{
		cout << "Course registration isn't activated" << endl;
	}
}

void create_course(string d)
{
	fstream f;
	ofstream outfile;
	f.open(d, ios::in);
	if (f.fail())
	{
		cout << "Don't have semister, can't create course " << endl;
		return;
	}
	int n = 0;
	string h;
	cout << "========= Create course ===========" << endl;
	cout << " enter course id : ";
	cin >> n;
	while (!f.eof())
	{
		getline(f, h);
		if (h.find(to_string(n)) == 0)
		{
			cout << "Sorry ! The course was created before " << endl;
			f.close();
			return;
		}
	}
	f.close();
	f.open(d, ios::app);
	f << n << ";";
	cin.ignore();
	cout << " enter course's name : ";
	getline(cin, h);
	f << h << ";";
	outfile.open(h + ".txt");
	outfile.close();
	cout << " enter teacher's name : ";
	getline(cin, h);
	f << h << ";";
	cout << " enter number of credits : ";
	cin >> n;
	f << n << ";";
	cout << " enter maximum number of student: ";
	cin >> n;
	f << n << ";";
	cin.ignore();
	cout << " enter day 1 :";
	getline(cin, h);
	f << h << ";";
	do
	{
		cout << " session 1 : " << endl;
		cout << " 1: start 7h30 " << endl;
		cout << " 2: start 9h30" << endl;
		cout << " 3: start 13h30" << endl;
		cout << " 4: start 15h30" << endl;
		cout << "enter : ";
		cin >> n;
	} while (n < 1 || n>4);
	f << n << ";";
	cout << " enter day 2 : ";
	cin.ignore();
	getline(cin, h);
	f << h << ";";
	do
	{
		cout << " session 2 : " << endl;
		cout << " 1: start 7h30 " << endl;
		cout << " 2: start 9h30" << endl;
		cout << " 3: start 13h30" << endl;
		cout << " 4: start 15h30" << endl;
		cout << "enter : ";
		cin >> n;
	} while (n < 1 || n>4);
	f << n << ";" << 0 << endl;
	cout << "Create course suscessfully" << endl;
	f.close();
}

void view_list_of_courses(string d)
{
	ifstream infile;
	int n = 0;
	int id = -1;
	string s;

	infile.open(d);
	if (!infile.is_open())
	{
		cout << "Don't have course to view" << endl;
		infile.close();
	}
	else
	{
		cout << "List of course: " << endl;
		cout << left << setw(9) << "ID" << left << setw(9) << "Name" << left << setw(12) << "Teacher";
		cout << left << setw(12) << "Credits" << left << setw(18) << "Max Student" << left << setw(9) << "Day 1";
		cout << left << setw(15) << "Session 1" << left << setw(9) << "Day 2" << left << setw(14) << "Session 2" << "Registed" << endl;
		while (!infile.eof())
		{
			infile >> n;
			if (infile.eof())
			{
				break;
			}
			cout << left << setw(9) << n;
			getline(infile, s, ';');
			getline(infile, s, ';');
			cout << left << setw(9) << s;

			getline(infile, s, ';');
			cout << left << setw(14) << s;

			getline(infile, s, ';');
			cout << left << setw(14) << s;

			getline(infile, s, ';');
			cout << left << setw(15) << s;

			getline(infile, s, ';');
			cout << left << setw(9) << s;

			infile >> n;
			switch (n)
			{
			case 1:
			{
				cout << left << setw(15) << "7:30";
				break;
			}
			case 2:
			{
				cout << left << setw(15) << "9:30";
				break;
			}
			case 3:
			{
				cout << left << setw(15) << "13:30";
				break;
			}
			case 4:
			{
				cout << left << setw(15) << "15:30";
				break;
			}
			default:
				break;
			}

			getline(infile, s, ';');
			getline(infile, s, ';');
			cout << left << setw(9) << s;

			infile >> n;
			switch (n)
			{
			case 1:
			{
				cout << left << setw(15) << "7:30";
				break;
			}
			case 2:
			{
				cout << left << setw(15) << "9:30";
				break;
			}
			case 3:
			{
				cout << left << setw(15) << "13:30";
				break;
			}
			case 4:
			{
				cout << left << setw(15) << "15:30";
				break;
			}
			default:
				break;
			}
			getline(infile, s, ';');
			infile >> n;
			cout << left << setw(9) << n << endl;
		}
		infile.close();
	}
}

void get_info_student(int id,info_student &a)
{
	ifstream infile1, infile2;
	string s;
	int n;

	infile1.open("list_class.txt");
	if (!infile1.is_open())
	{
		cout << "Don't have any class to get student's info" << endl;
		infile1.close();
	}
	else
	{
		while (!infile1.eof())
		{
			getline(infile1, s);
			infile2.open(s + ".csv");
			getline(infile2, s, '\n');
			while (!infile2.eof())
			{
				infile2 >> n;
				getline(infile2, s, ',');
				infile2 >> n;
				if (n == id)
				{
					a.id = n;
					getline(infile2, s, ',');
					getline(infile2, s, ',');
					a.f_name = s;
					getline(infile2, s, ',');
					a.l_name = s;
					getline(infile2, s, ',');
					a.gender = s;
					infile2 >> n;
					a.day = n;
					getline(infile2, s, ',');
					infile2 >> n;
					a.month = n;
					getline(infile2, s, ',');
					infile2 >> n;
					a.year = n;
					getline(infile2, s, ',');
					infile2 >> n;
					a.social_id = n;
					getline(infile2, s, ',');
					infile2 >> n;
					a.course_registed = n;
					infile1.close();
					infile2.close();
					return;
				}
				getline(infile2, s, '\n');
			}
			infile2.close();
		}
		cout << "Can't find student's info" << endl;
		infile1.close();
	}
}

void show_info_student(info_student a)
{
	cout << "Id : " << a.id << endl;
	cout << "Name : " << a.f_name << " " << a.l_name << endl;
	cout << "Gender : " << a.gender << endl;
	cout << "date/month/year : " << a.day << "/" << a.month << "/" << a.year << endl;
	cout << "Social id : " << a.social_id << endl;
	cout << "Course registed :" << a.course_registed << endl;
}

void enroll_in_course(string d)
{
	ifstream infile;
	ofstream outfile;
	int n = 0;
	string s;

	infile.open(d);
	if (!infile.is_open())
	{
		cout << "Don't have course to enroll" << endl;
		infile.close();
		return;
	}
	else
	{
		cout << "List course" << endl;
		view_list_of_courses(d);
		cout << endl;
		infile.close();

		cout << "Enter course's name you want to enroll in";
		getline(infile, s);

		outfile.open(s + ".txt", ios_base::app);

	}
}

void copy_and_remove_file(string d, string h)
{
	string a;
	ifstream f1;
	a = d + ".csv";
	f1.open(a, ios::in);
	ofstream f2;
	if (f1.fail())
	{
		cout << "can not open file " << endl;
		return;
	}
	f2.open("text.csv", ios::out);
	getline(f1, a);
	f2 << a;
	while (!f1.eof())
	{
		getline(f1, a);
		if (a.find(h) != 0)
		{
			f2 << endl;
			f2 << a;
		}
	}
	f1.close();
	f2.close();
	char c[20];
	a = d + ".csv";
	for (int j = 0; j < a.length();j++)
	{
		c[j] = a[j];
	}
	c[a.length()] = '\0';
	remove(c);
	rename("text.csv", c);
}

void value_creation(account_student & a)
{
	a.id = -1;
	a.pw = nullptr;
	a.i_s.day = -1;
	a.i_s.month = -1;
	a.i_s.course_registed = -1;
	a.i_s.social_id = -1;
	a.i_s.year = -1;
	a.i_s.f_name = nullptr;
	a.i_s.l_name = nullptr;
}

double* read_mark(string d, string h)
{
	double* a = new double[4];
	fstream f1;
	f1.open(d, ios::in);
	while (!f1.eof())
	{
		getline(f1, d);
		if (d.find(h) == 0)
		{
			break;
		}
	}
	f1.close();
	int j = 0;
	int g = 0;
	int k = 0;
	a[0] = -1;
	a[1] = -1;
	a[2] = -1;
	a[3] = -1;
	cout << d << endl;
	for (int i = d.length() - 1;j < 4;i--)
	{
		if (d[i] == ';')
		{
			k = 0;
			j++;
			g = 0;
			continue;
		}
		if (d[i] >= '0' && d[i] <= '9')
		{
			if (k == 0)
			{
				a[j]++;
			}
			a[j] = a[j] + int(d[i] - '0') * pow(10, g);
			g++;
			k++;
			continue;
		}
		if (d[i] == '.')
		{
			a[j] = 1.0f * (a[j] / pow(10, g));
			g = 0;
		}

	}
	return a;
}

void export_score_list(string& d)
{
	string h;
	string a;
	fstream f;
	f.open(d, ios::in);
	if (f.fail())
	{
		cout << "can not open file " << endl;
		return;
	}
	cout << setw(11) << left << "id" << setw(21) << left << "name " << setw(5) << left << "m_m" << setw(5) << left << "f_m";
	cout << setw(5) << left << "t_m" << setw(5) << left << "o_m" << endl;
	getline(f, h);
	while (!f.eof())
	{
		getline(f, h, ';');
		cout << setw(11) << left << h;
		getline(f, h, ';');
		a = h;
		getline(f, h, ';');
		a = a + " " + h;
		cout << setw(21) << left << a;
		getline(f, a);
		h = "";
		for (int i = 0; i < a.length(); i++)
		{
			if (a[i] != ';')
			{
				h = h + a[i];
			}
			else
			{
				cout << setw(5) << h;
				h = "";
			}
		}
		cout << setw(5) << h;
		cout << endl;
	}
	f.close();
}

void correct_score(string& d, string& h)
{
	int l = 1;
	string a;
	string g;
	g = d + ".csv";
	fstream f;
	f.open(g, ios::in);
	if (f.fail())
	{
		cout << "can not open file " << endl;
		return;
	}
	while (!f.eof())
	{
		getline(f, a);
		if (a.find(h) == 0)
		{
			l = 0;
			break;
		}
	}
	if (l)
	{
		cout << "Sorry there are no students in this course" << endl;
		f.close();
		return;
	}
	f.close();
	copy_and_remove_file(d, h);
	f.open(g, ios::app);
	f << h << ";";
	l = 0;
	for (int i = h.length() + 1; l < 2; i++)
	{
		if (a[i] == ';')
		{
			l++;
		}
		f << a[i];
	}
	double n = 0;
	cout << "enter midterm mark :";
	cin >> n;
	if (n >= 0)
	{
		f << n << ";";
	}
	else {
		f << ";";
	}
	cout << "enter final mark :";
	cin >> n;
	if (n >= 0)
	{
		f << n << ";";
	}
	else {
		f << ";";
	}
	cout << "enter total mark :";
	cin >> n;
	if (n >= 0)
	{
		f << n << ";";
	}
	else {
		f << ";";
	}
	cout << "enter other mark :";
	cin >> n;
	if (n >= 0)
	{
		f << n;
	}
	f << endl;
	f.close();
	return;
}

