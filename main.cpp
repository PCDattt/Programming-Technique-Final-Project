#include "header.h"

int main()
{

	int o = -1;
	while (o != 0)
	{
		showdate();
		show_course_registration_session();
		cout << "Options: " << endl;
		cout << "1. Change date " << endl;
		cout << "2. Staff Log in " << endl;
		cout << "3. Student Log in " << endl;
		cout << "0. Exit " << endl;
		cout << "Enter option you want: ";
		cin >> o;
		cout << endl;
		if (o == 1)
		{
			changedate();
		}
		if (o == 2)
		{
			staff_working();
		}
		if (o == 3)
		{
			student_working();
		}
	}
	return 0;
}