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
			cout << "10. Update course info" << endl;
			cout << "11. Delete course" << endl;
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

			if (p == 10)
			{
				current_semister = get_current_semister();
				update_course_info(current_semister);
			}

			if (p == 11)
			{
				current_semister = get_current_semister();
				delete_course(current_semister);
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
		while (p != 0)
		{
			cout << "1. View info student" << endl;
			cout << "2. Enroll in a course" << endl;
			cout << "3. View list of erolled courses" << endl;
			cout << "4. View list of courses will study in" << endl;
			cout << "5. View list of class" << endl;
			cout << "7. View list of courses" << endl;
			cout << "0. Exit" << endl;
			cout << "Choose option you want: ";
			cin >> p;
			cout << endl;
			
			if (p == 1)
			{
				get_info_student(a.id, b);
				show_info_student(b);
			}

			if (p == 2)
			{
				current_semister = get_current_semister();
				get_info_student(a.id, b);
				enroll_in_course(current_semister,b);
			}
			
			if (p == 3)
			{
				current_semister = get_current_semister();
				get_info_student(a.id, b);
				view_list_enrolled(current_semister, b);
			}
			
			if (p == 4)
			{
				current_semister = get_current_semister();
				get_info_student(a.id, b);
				view_list_enrolled(current_semister, b);
			}

			if (p == 5)
			{
				view_list_of_classes();
			}

			if (p == 7)
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
	outfile << 0 << " ";
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
	outfile << n << endl;
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
	f << n << endl;
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
		cout << left << setw(15) << "Session 1" << left << setw(9) << "Day 2" << left << setw(14) << "Session 2" << endl;
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
			getline(infile, s, '\n');
			cout << endl;
		}
		infile.close();
	}
}

void update_course_info(string d)
{
	ifstream infile;
	ofstream outfile1, outfile2;
	string s;
	string h;
	int id;
	int n;

	infile.open(d);
	if (!infile.is_open())
	{
		cout << "Don't have course to update info" << endl;
		infile.close();
	}
	else
	{
		view_list_of_courses(d);
		cout << "Input course's id you want to update info: ";
		cin >> id;
		outfile1.open("temp.txt");
		while (!infile.eof())
		{
			infile >> n;
			if (infile.eof())
			{
				break;
			}
			if (n != id)
			{
				outfile1 << n;
				getline(infile, s, '\n');
				outfile1 << s << endl;
			}
			else
			{
				outfile1 << id << ";";
				getline(infile, s, ';');
				getline(infile, s, ';');
				outfile1 << s << ";";

				outfile2.open(s + ".txt");
				outfile2 << 0 << " ";

				getline(infile, s, '\n');

				cout << "Update course info: " << endl;
				cin.ignore();
				cout << " enter teacher's name : ";
				getline(cin, h);
				outfile1 << h << ";";
				cout << " enter number of credits : ";
				cin >> n;
				outfile1 << n << ";";
				cout << " enter maximum number of student: ";
				cin >> n;
				outfile1 << n << ";";
				cin.ignore();

				outfile2 << n << endl;
				outfile2.close();

				cout << " enter day 1 :";
				getline(cin, h);
				outfile1 << h << ";";
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
				outfile1 << n << ";";
				cout << " enter day 2 : ";
				cin.ignore();
				getline(cin, h);
				outfile1 << h << ";";
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
				outfile1 << n << endl;
				cout << "Update course info suscessfully" << endl;
			}
		}
		infile.close();
		outfile1.close();
		char c[30];
		for (int j = 0; j < d.length(); j++)
		{
			c[j] = d[j];
		}
		c[d.length()] = '\0';
		remove(c);
		rename("temp.txt", c);
	}
}

void delete_course(string d)
{
	ifstream infile;
	ofstream outfile;
	int n = 0;
	int id = 0;
	string s;
	char c[30];
	char f[30];

	infile.open(d);
	if (!infile.is_open())
	{
		cout << "Don't have course to delete";
		infile.close();
		return;
	}
	else
	{
		outfile.open("temp.txt");
		view_list_of_courses(d);
		cout << endl;
		cout << "Input course's id you want to delete: ";
		cin >> id;
		while (!infile.eof())
		{
			infile >> n;
			if (infile.eof())
			{
				break;
			}
			if (n != id)
			{
				outfile << n;
				getline(infile, s, '\n');
				outfile << s << endl;
			}
			else
			{
				getline(infile, s, ';');
				getline(infile, s, ';');
				s = s + ".txt";
				for (int j = 0; j < s.length(); j++)
				{
					c[j] = s[j];
				}
				c[s.length()] = '\0';
				remove(c);
				getline(infile, s, '\n');
				cout << "Delete course successfully" << endl;
			}
		}
		outfile.close();
		infile.close();
		for (int j = 0; j < d.length(); j++)
		{
			f[j] = d[j];
		}
		f[d.length()] = '\0';
		remove(f);
		rename("temp.txt", f);
	}
}

void get_info_student(int id,info_student &a)
{
	ifstream infile1, infile2;
	string s;
	string clas;
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
			clas = s;
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
					a.clas = clas;
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

void enroll_in_course(string d,info_student& a)
{
	ifstream infile1;
	ifstream infile2;
	ofstream outfile;
	int n = 0;
	int no = 0;
	int max = 0;
	int registed = 0;
	string s, s2;

	infile1.open(d);
	if (!infile1.is_open())
	{
		cout << "Don't have course to enroll" << endl;
		infile1.close();
		return;
	}
	else
	{
		if (a.course_registed == 5)
		{
			cout << "Already enrolled 5 courses. Can't enroll more course" << endl;
			return;
		}
		else
		{
			cout << "List course" << endl;
			view_list_of_courses(d);
			cout << endl;
			infile1.close();

			cout << "Enter course's name you want to enroll in: ";
			cin.ignore();
			getline(cin, s);
			infile2.open(s + ".txt");
			if (!infile2.is_open())
			{
				cout << "Course isn't existed. Can't enroll" << endl;
				infile2.close();
				return;
			}
			else
			{

				infile2 >> registed;
				infile2 >> max;
				if (registed >= max)
				{
					cout << "This course had full student. Can't enroll" << endl;
					infile2.close();
					return;
				}
				else
				{
					infile2.close();
					outfile.open(s + ".txt", ios_base::app);
					outfile << a.id << " " << a.f_name << " " << a.l_name << endl;
					outfile.close();

					update_course_file_after_enroll(s, registed, max);

					a.course_registed = a.course_registed + 1;

					update_class_file_after_enroll(a);

					cout << "Enroll in a course successfully" << endl;
				}
			}
		}
	}
}

void update_course_file_after_enroll(string s, int registed, int max)
{
	string s2;
	ofstream outfile;
	ifstream infile2;

	outfile.open("temp.txt");
	outfile << registed + 1 << " " << max << endl;

	infile2.open(s + ".txt");
	getline(infile2, s2, '\n');
	while (!infile2.eof())
	{
		getline(infile2, s2, '\n');
		if (infile2.eof())
		{
			break;
		}
		outfile << s2 << endl;
	}
	outfile.close();
	infile2.close();
	s = s + ".txt";
	char c[20];
	for (int j = 0; j < s.length(); j++)
	{
		c[j] = s[j];
	}
	c[s.length()] = '\0';
	remove(c);
	rename("temp.txt", c);
}

void update_class_file_after_enroll(info_student a)
{
	ofstream outfile;
	ifstream infile2;
	int no = 0;
	int n = 0;
	string s;

	outfile.open("temp.csv");
	infile2.open(a.clas + ".csv");
	getline(infile2, s, '\n');
	outfile << s << endl;
	while (!infile2.eof())
	{
		infile2 >> no;
		getline(infile2, s, ',');
		infile2 >> n;
		if (infile2.eof())
		{
			break;
		}
		if (n != a.id)
		{
			getline(infile2, s, '\n');
			outfile << no << "," << n << s << endl;
		}
		else
		{
			getline(infile2, s, '\n');
			outfile << no << "," << n << "," << a.f_name << "," << a.l_name << "," << a.gender << "," << a.day << "," << a.month << ",";
			outfile << a.year << "," << a.social_id << "," << a.course_registed << endl;
		}
	}
	outfile.close();
	infile2.close();
	s = a.clas + ".csv";
	char c[20];
	for (int j = 0; j < s.length(); j++)
	{
		c[j] = s[j];
	}
	c[s.length()] = '\0';
	remove(c);
	rename("temp.csv", c);
}

void view_list_enrolled(string d, info_student a)
{
	ifstream infile1, infile2;
	int id_clas = 0;
	int id_student = 0;
	int n = 0;
	string clas;
	string s;

	infile1.open(d);
	if (infile1.is_open())
	{
		cout << "List enrolled course: " << endl;
		cout << "ID    " << "Course's name" << endl;
		while (!infile1.eof())
		{
			infile1 >> id_clas;
			getline(infile1, s, ';');
			getline(infile1, clas, ';');

			if (infile1.eof())
			{
				break;
			}

			infile2.open(clas + ".txt");
			getline(infile2, s, '\n');
			while (!infile2.eof())
			{
				infile2 >> id_student;
				if (infile2.eof())
				{
					break;
				}

				if (id_student == a.id)
				{
					cout << id_clas << "    " << clas << endl;
					break;
				}
				getline(infile1, s, '\n');
			}
			infile2.close();
			getline(infile1, s, '\n');
		}
		infile1.close();
	}
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

