#include "header.h"

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
		cout << "Can't open file." << endl;
	}
}

void stafflogin()
{
	char username[50];
	char pass[50];

	cout << "Enter Staff Username: ";
	cin.ignore();
	cin.getline(username, 50);

	cout << "Enter Staff Password: ";
	cin.getline(pass, 50);
	
	cout<< endl;
}

bool check_account_staff(account_staff& a)
{
	ifstream f1;
	f1.open("account_staff.csv", ios_base::in);
	if (f1.fail())
	{
		cout << "not file " << endl;
		return false;
	}
	int x;
	char y[50];
	cout << " + enter name email : ";
	cin >> x;
	cin.ignore();
	cout << " + enter password :";
	cin.getline(y, 50);
	while (!f1.eof())
	{
		read_info_account_staff(f1, a);
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

void read_info_account_staff(ifstream& file, account_staff& a)
{
	char b[50];
	file >> a.id;
	file.ignore();
	file.getline(b, 50, '\n');
	a.pw = new char[strlen(b) + 1];
#pragma warning(suppress : 4996)
	strcpy(a.pw, b);
	//file.ignore();
}

void studentlogin()
{
	char username[50];
	char pass[50];

	cout << "Enter Student Username: ";
	cin.ignore();
	cin.getline(username, 50);

	cout << "Enter Student Password: ";
	cin.getline(pass, 50);

	cout << endl;
}

bool check_account_student(account_student& a)
{
	ifstream f1;
	f1.open("account_student.csv", ios_base::in);
	if (f1.fail())
	{
		cout << "not file " << endl;
		return false;
	}
	int x;
	char y[50];
	cout << " + enter name email : ";
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

void removed_memory(account_student& a)
{
	i_s_course* d;
	delete[]a.pw;
	delete[]a.i_s.f_name;
	delete[]a.i_s.l_name;
	for (int i = 0; i < a.i_s.number_course; i++)
	{
		d = a.head;
		a.head = a.head->node;
		delete d;
	}
}

void create_class()
{
	fstream f;
	f.open("class.txt", ios_base::in);
	string a;
	string d;
	cout << "enter name class : ";
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
	f.open(a);
	if (f.fail())
	{
		cout << "You need to create a file for the student information of the class" << endl;
		return;
	}
	f.close();
	f.open("class.txt", ios::app);
	f << endl << d;
	cout << " you have successfully created the class " << endl;
	f.close();
}

void read_info_student(ifstream& file, account_student& a)
{
	string h;
	char b[50];
	file.ignore();
	file.getline(b, 50, ';');
	a.i_s.f_name = new char[strlen(b) + 1];
#pragma warning(suppress : 4996)
	strcpy(a.i_s.f_name, b);
	file.getline(b, 50, ';');
	a.i_s.l_name = new char[strlen(b) + 1];
#pragma warning(suppress : 4996)
	strcpy(a.i_s.l_name, b);
	file >> a.i_s.date;
	file.ignore();
	file >> a.i_s.month;
	file.ignore();
	file >> a.i_s.year;
	file.ignore();
	file >> a.i_s.social_id;
	file.ignore();
	file >> a.i_s.number_course;
	file.ignore();
	a.head = nullptr;
	for (int i = 0; i < a.i_s.number_course;i++)
	{
		i_s_course* d = new i_s_course();
		file >> d->i_c.course_id;
		d->node = a.head;
		a.head = d;
		file.ignore();
	}
}

bool read_file_info_student(account_student& a)
{
	ifstream file;
	ifstream file2;
	string d;
	int b = 0;
	file.open("class.txt", ios_base::in);
	while (!file.eof())
	{
		getline(file, d, '\n');
		d = d + ".csv";
		file2.open(d, ios::in);
		getline(file2, d, '\n');
		while (!file2.eof())
		{
			file2 >> b;
			if (a.id == b)
			{
				read_info_student(file2, a);
				file.close();
				file2.close();
				return true;
			}
			getline(file2, d, '\n');
		}
		file2.close();
	}
	file.close();
	return false;
}

void read_file_list_scienci(ifstream& f, i_course& a,int n)
{
	char b[50];
	if (n == 0)
	{
		f >> a.course_id;
	}
	f.ignore();
	f.getline(b, 50, ';');
	a.course_name = new char[strlen(b) + 1];
#pragma warning(suppress : 4996)
	strcpy(a.course_name, b);
	f.getline(b, 50, ';');
	a.teacher = new char[strlen(b) + 1];
#pragma warning(suppress : 4996)
	strcpy(a.teacher, b);
	f >> a.n_o_credits;
	f.ignore();
	f >> a.n_o_student;
	f.ignore();
	f.getline(b, 50, ';');
	a.day1 = new char[strlen(b) + 1];
#pragma warning(suppress : 4996)
	strcpy(a.day1, b);
	f >> a.session1;
	f.ignore();
	f.getline(b, 50, ';');
	a.day2 = new char[strlen(b) + 1];
#pragma warning(suppress : 4996)
	strcpy(a.day2, b);
	f >> a.session2;
	string d;
	getline(f, d);
}

void create_school_year()
{
	string school_year;
	int start = 0;
	int end = 0;
	ofstream file;
	cout << "Input start school year: ";
	cin >> start;
	cout << "Input end school year: ";
	cin >> end;
	school_year = to_string(start) + "-" + to_string(end) + ".txt";
	file.open(school_year);
	file.close();
	cout << "Create school year successfully" << endl;
}
void output_i_course(i_course a)
{
	cout << left << setw(10) << a.course_id << left << setw(15) << a.course_name << left << setw(21) << a.teacher;
	cout << left << setw(7) << a.n_o_credits << left << setw(7) << a.n_o_student << left << setw(6) << a.day1 << left << setw(6) << a.day2;
	int n = a.session1;
	for (int i = 0; i < 2; i++)
	{
		switch (n)
		{
		case 1:
		{
			cout << left << setw(6) << "7:30";
			break;
		}
		case 2:
		{
			cout << left << setw(6) << "9:30";
			break;
		}
		case 3:
		{
			cout << left << setw(6) << "13:30";
			break;
		}
		case 4:
		{
			cout << left << setw(6) << "15:30";
			break;
		}
		default:
			break;
		}

		n = a.session2;
	}
	cout << endl;
}
void removed_i_course(i_course& a)
{
	delete[] a.course_name;
	delete[] a.teacher;
	delete[]a.day1;
	delete[]a.day2;
}
bool s_register(i_course b, account_staff& a)
{
	i_s_course* d = a.head;
	for (int i = 0; i < a.i_s.number_course;i++)
	{
		if (d->i_c.course_id != b.course_id)
		{
			if (strcmp(d->i_c.day1, b.day1) == 0)
			{
				if (d->i_c.session1 == b.session1)
				{
					return false;
				}
			}
			if (strcmp(d->i_c.day1, b.day2) == 0)
			{
				if (d->i_c.session1 == b.session2)
				{
					return false;
				}
			}
			if (strcmp(d->i_c.day2, b.day1) == 0)
			{
				if (d->i_c.session2 == b.session1)
				{
					return false;
				}
			}
			if (strcmp(d->i_c.day2, b.day2) == 0)
			{
				if (d->i_c.session2 == b.session2)
				{
					return false;
				}
			}
		}
		else
		{
			return false;
		}
		d = d->node;
	}
	return true;
}


