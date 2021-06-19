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

void stafflogin()
{
	account_staff a;
	int day = 0;
	int month = 0;
	int year = 0;
	int p = -1;

	if (check_account_staff(a) == true)
	{
		cout << endl;
		cout << "Staff login successfully." << endl;
		get_date(day, month, year);
		while (p != 4)
		{
			cout << "Staff option: " << endl;
			cout << "1. Create a school year: " << endl;
			cout << "4. Exit " << endl;
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
				cout << endl;
			}
		}
	}
	else
	{
		cout << "Invalid ID or password, can not log in" << endl;
	}
	delete[] a.pw;
	cout << endl;
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
bool s_register(i_course b, account_student& a)
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
void output_file_class(account_student & a, string d)
{
	fstream f1;
	i_s_course* b;
	f1.open(d, ios::app);
	f1 << a.id << ';' << a.i_s.f_name << ';' << a.i_s.l_name << ';' << a.i_s.date << '/' << a.i_s.month << '/' << a.i_s.year;
	f1 << ';' << a.i_s.social_id << ';' << a.i_s.number_course << ';';
	b = a.head;
	for (int i = 0; i < a.i_s.number_course;i++)
	{
		f1 << b->i_c.course_id << ';';
		b = b->node;
	}
	f1 << endl;
	f1.close();
}
void output_list_course(i_s_course* a)
{
	cout << left << setw(10) << "id" << left << setw(15) << "course_name" << left << setw(21) << "teacher name";
	cout << left << setw(7) << "n_o_c" << left << setw(7) << "n_o_s" << left << setw(6) << "day1" << left << setw(6) << "day2";
	cout << left << setw(6) << "ses1" << left << setw(6) << "ses2" << endl;
	cout << "===================================================================================" << endl;
	while (a != nullptr)
	{
		output_i_course(a->i_c);
		a = a->node;
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
void View_personal_information(account_student a)
{
	cout << "Id : " << a.id << endl;
	cout << "Name : " << a.i_s.f_name << " " << a.i_s.l_name << endl;
	cout << "date/month/year : " << a.i_s.date << "/" << a.i_s.month << a.i_s.year << endl;
	cout << "Class : " << a.i_s.my_class << endl;
	cout << "Social id : " << a.i_s.social_id << endl;
	cout << "Numbur course :" << a.i_s.number_course << endl;
	output_list_course(a.head);
}
void value_creation(account_student & a)
{
	a.head = nullptr;
	a.id = -1;
	a.pw = nullptr;
	a.i_s.date = -1;
	a.i_s.month = -1;
	a.i_s.number_course = -1;
	a.i_s.social_id = -1;
	a.i_s.year = -1;
	a.i_s.my_class = "chua co";
	a.i_s.f_name = nullptr;
	a.i_s.l_name = nullptr;
}
bool scienci_registration(account_student& a)
{
	if (a.i_s.number_course < 5)
	{
		int g = 1;
		int i = 0;
		i_course b;
		string d;
		string h;
		ifstream f;
		f.open("list_scienci.csv", ios_base::in);
		if (f.fail())
		{
			cout << "can't open file" << endl;
			return false;
		}
		getline(f, d);
		cout << left << setw(10) << "id" << left << setw(15) << "course_name" << left << setw(21) << "teacher name";
		cout << left << setw(7) << "n_o_c" << left << setw(7) << "n_o_s" << left << setw(6) << "day1" << left << setw(6) << "day2";
		cout << left << setw(6) << "ses1" << left << setw(6) << "ses2" << endl;
		cout << "===================================================================================" << endl;
		while (!f.eof())
		{
			read_file_list_scienci(f, b, 0);
			if (i != b.course_id)
			{
				output_i_course(b);
			}
			removed_i_course(b);
			i = b.course_id;
		}
		f.close();
		cout << "+ enter course id :";
		cin >> i;
		system("cls");
		f.open("list_scienci.csv", ios_base::in);
		getline(f, d);
		i_s_course* c = new i_s_course();
		c->node = nullptr;
		while (!f.eof())
		{
			f >> c->i_c.course_id;
			if (c->i_c.course_id == i)
			{
				read_file_list_scienci(f, c->i_c, 1);
				g = 0;
				break;
			}
			getline(f, d);
		}
		f.close();
		if (g)
		{
			delete c;
			cout << "Sorry this course is not available" << endl;
			return false;
		}
		if (c->i_c.n_o_student >= 50)
		{
			removed_i_course(c->i_c);
			delete c;
			cout << "full slot" << endl;
			return false;
		}
		if (s_register(c->i_c, a))
		{
			int n = 0;
			c->node = a.head;
			a.head = c;
			a.head->i_c.n_o_student++;
			a.i_s.number_course++;
			fstream f1;
			d = a.i_s.my_class;
			h = to_string(a.name_gmail);
			copy_and_remove_file(d, h);
			d = a.i_s.my_class + ".csv";
			output_file_class(a, d);
			d = "course_" + to_string(a.head->i_c.course_id) + ".csv";
			f1.open(d, ios::app);
			f1 << a.id << ";" << a.i_s.f_name << ";" << a.i_s.l_name << endl;
			f1.close();
			f1.open("list_scienci.csv", ios::in);
			getline(f1, d);
			n = d.length();
			h = to_string(a.head->i_c.course_id);
			g = 0;
			while (true)
			{
				getline(f1, d);
				if (d.find(h) == 0)
				{
					n = n + 2;
					for (int j = 0; true; j++)
					{
						n++;
						if (d[j] == ';')
						{
							g++;
							if (g == 4)
							{
								break;
							}
						}
					}
					break;
				}
				n = n + d.length() + 2;
			}
			f1.close();
			f1.open("list_scienci.csv", ios::in | ios::out);
			f1.seekp(n);
			f1 << a.head->i_c.n_o_student;
			f1.close();
			cout << "You have successfully registered" << endl;
			return true;
		}
		else
		{
			cout << "you cannot sign up for this course" << endl;
			removed_i_course(c->i_c);
			delete c;
			return false;
		}
	}
	else
	{
		cout << "you only have a maximum of 5 subjects in 1 semester" << endl;
		return false;
	}

}
void cancel_registration(account_student& a)
{
	if (a.head == nullptr)
	{
		cout << " sorry you have not course " << endl;
		return;
	}
	string d;
	string h;
	i_s_course* b;
	i_s_course* c;
	int n;
	int i = 0;
	output_list_course(a.head);
	cout << "enter the course id you want to delete : ";
	cin >> n;
	b = a.head;
	c = b;
	if (a.head->i_c.course_id == n)
	{
		c = a.head;
		i = 1;
		a.head = a.head->node;
		a.i_s.number_course--;
		c->i_c.n_o_student--;
	}
	else
	{
		while (b->node != nullptr)
		{
			if (n == b->node->i_c.course_id)
			{
				c = b->node;
				b->node = b->node->node;
				a.i_s.number_course--;
				i = 1;
				c->i_c.n_o_student--;
				break;
			}
			b = b->node;
		}
	}
	if (i == 0)
	{
		cout << "You have not registered for this course yet" << endl;
		return;
	}
	d = "course_" + to_string(n);
	h = to_string(a.id);
	copy_and_remove_file(d, h);
	d = a.i_s.my_class;
	copy_and_remove_file(d, h);
	d = a.i_s.my_class + ".csv";
	output_file_class(a, d);
	h = to_string(n);
	copy_and_remove_file("list_scienci", h);
	d = "list_scienci.csv";
	output_file_caurse(d, c->i_c);
	removed_i_course(c->i_c);
	return;
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
void  output_file_caurse(string d, i_course a)
{
	fstream f;
	f.open(d, ios::app);
	f << a.course_id << ";" << a.course_name << ';' << a.teacher << ';' << a.n_o_credits << ';' << a.n_o_student << ';';
	f << a.day1 << ';' << a.session1 << ';' << a.day2 << ';' << a.session2 << endl;
	f.close();
}


