#include "header.h"

int main()
{

	int o = -1;
	while (o != 0)
	{
		showdate();
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
			stafflogin();
		}
		if (o == 3)
		{
			studentlogin();
		}
	}
	return 0;
}