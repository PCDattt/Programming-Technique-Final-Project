#include "header.h"

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
