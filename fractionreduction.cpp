/*
Daniel Caceres
CSIT 839
Assignment #1
*/
#include <iostream>
#include <conio.h>
using namespace std;
void calc(int n1, int d1, int n2, int d2, char sym, int& n, int& d); 
bool reduce(int& n, int& d);
int main()
{
	int n, d, newn = 0, newd = 0;
	int n1, d1, n2, d2;
	char slash, sym, answer = 0;

	do
	{
		cout << "Enter a fraction expression:\n ";
		cin >> n1 >> slash >> d1 >> sym >> n2 >> slash >> d2;

		calc(n1, d1, n2, d2, sym, n, d);
		reduce(n, d);
		
		if (true)
			cout << "The result was reduced." << endl;
		else 
			cout << "The result was not reduced." << endl;

		cout << "More[y/n]: ";
		cin >> answer;
	} while (answer == 'y' || answer == 'Y');

	_getch();
	return 0;
}
void calc(int n1, int d1, int n2, int d2, char sym, int& n, int& d)
{

	if (sym == '-')
	{
		n = n1*d2 - d1*n2;
		d = d1*d2;
	}
	else if (sym == '+')
	{
		n = n1*d2 + d1*n2;
		d = d1*d2;
	}
	else if (sym == '/')
	{
		n = n1*d2;
		d = d1*n2;
	}
	else if (sym == '*')
	{
		n = n1*n2;
		d = d1*d2;
	}
	else;
	
}
bool reduce(int& n, int& d)
{
	
	for (int i = n; i > 1; i--)
	if (n % i == 0 && d % i == 0)
	{
		n /= i;
		d /= i;	
		return true;
	}
	return false;
	
	cout << n << '/' << d << endl; 
	
}
