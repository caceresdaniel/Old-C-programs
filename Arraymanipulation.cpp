#include <conio.h>
#include <iostream>
#include <iomanip>
using namespace std;
void search(char sentence[50]);
void change(char sentence[50], char newchar, int inch);
void display_first(char sentence[50], int n);
void display_last(char sentence[50], int n);
void display_all(char sentence[50], int in1, int in2);
void nullstring(char sentence[50]);
int main()
{
	char sentence[50], newchar;
	int selection, inch = 0, n, in1, in2;
	do
	{
		cout << "\nPlease enter a string: ";
		cin.getline(sentence, 50, '\n');

		cout << "\nMake a selection: "
			<< "\n1. Search for a character in the string"
			<< "\n2. Change a character within the string"
			<< "\n3. Display the first n characters of the string"
			<< "\n4. Display the last n character of the string"
			<< "\n5. display all character that lie between two given indices"
			<< "\n6. Null the string"
			<< "\n7. Exit"
			<< "\nChoice: ";
		cin >> selection;

		if (selection == 1)
			search(sentence);
		else if (selection == 2)
		{
			cout << "\nWhat is the index of the character you want to change? ";
			cin >> inch;

			cout << "\nWhat character do you want in that position? ";
			cin >> newchar;

			change(sentence, newchar, inch);
		}
		else if (selection == 3)
		{
			cout << "\nHow many characters from the beginning of the string do you want to display? ";
			cin >> n;
			display_first(sentence, n);
		}
		else if (selection == 4)
		{
			cout << "\nHow many characters from the end of the string do you want to display? ";
			cin >> n;
			display_last(sentence, n);
		}
		else if (selection == 5)
		{
			cout << "\nPlease enter the beginning index: ";
			cin >> in1;
			cout << "\nPlease enter the ending index: ";
			cin >> in2;
			display_all(sentence, in1, in2);
		}
		else if (selection == 6)
		{
			nullstring(sentence);
		}
		cin.clear();
		cin.ignore(INT_MAX, '\n');

	} while (selection != 7);


	cout << "\nPress any key to continue.";
	_getch();
	return 0;
}
void search(char sentence[50])
{
	int index = 0, amount = 0;
	char search;

	cout << "\nPlease enter the character to search for: ";
	cin >> search;

	for (int i = 0; i < 50; i++)
	{
		if (search == sentence[i])
			amount++;
	}
	for (int i = 0; i < 50; i++)
	{
		if (search == sentence[i])
		{
			index = i;
			break;
		}
	}
	cout << "There are " << amount << ' ' << search << "'s in " << '"' << sentence << '"' << " with the 1st one at index " << index << ".\n";
}
void change(char sentence[50], char newchar, int inch)
{
	int size = 0;
	for (int i = 0; i < sentence[i + 1]; i++)
	{
		if (sentence[i] != NULL)
		{
			size++;
		}
	}
	if (inch > size)
	{
		cout << "That position is outside the bounds of the string. String unchanged.\n";
	}
	else
	{
		sentence[inch] = newchar;
		cout << "The new string is " << '"' << sentence << '"' << '\n';
	}

}
void display_first(char sentence[50], int n)
{
	char newsen[50];
	int si = 0;
	for (int i = 0; i < sentence[i + 1]; i++)
	{
		if (sentence[i] != NULL)
			si++;
	}
	if (n > si)
	{
		cout << "\nError: Too many characters.";
	}
	else
	{
		strncpy_s(newsen, sentence, n);
		cout << newsen << '\n';
	}

}
void display_last(char sentence[50], int n)
{
	char newsen[50];
	int si = 0;
	for (int i = 0; i < sentence[i + 1]; i++)
	{
		if (sentence[i] != NULL)
			si++;
	}
	if (n > si)
	{
		cout << "\nError: Too many characters.";
	}
	else
	{
		strcpy_s(newsen, sentence + (si - n + 1));
		cout << newsen << '\n';
	}
}
void display_all(char sentence[50], int in1, int in2)
{
	char newsen[50] = { 0 };
	int si = 0;
	for (int i = 0; i < sentence[i + 1]; i++)
	{
		if (sentence[i] != NULL)
			si++;
	}
	if (in1 > si || in2 > si || in2 < in1)
	{
		cout << "\nError: One of more indices are outside the bounds of the array.";
	}
	else
	{
		for (int i = 0; i < si; i++)
		{
			if (i >= in1 && i <= in2)
				newsen[i] = sentence[i];

		}
	}
	for (int i = 0; i < si; i++)
	{
		if (newsen[i] != 0)
			cout << newsen[i];
	}
}
void nullstring(char sentence[50])
{
	int si = 0;
	for (int i = 0; i < sentence[i + 1]; i++)
	{
		if (sentence[i] != NULL)
			si++;
	}
	if (si == 0)
		cout << "\nThe string was already Null. Nothing was changed.";
	else if (si > 0 && si != 0)
	{
		cin.clear();
		cout << "\nThe string is now Null";
	}
}
