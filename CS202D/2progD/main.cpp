#include "node.h"

casting homework;
int reading();
int exercises();
int notes();
int again();

int main()
{
	char response;
	cout << "Welcome to Lundquist homework organizor!" << endl << "What would you like to update? Reading(R), Exercises(E), or Notes (N)?" << endl;
	cin >> response; cin.ignore(100, '\n');
	toupper(response);
	switch(response)
	{
		case 'R':
			reading();
		
		case 'E':
			exercises();

		case 'N':
			notes();

		default:
			main();
	}
	return 1;
}

int reading()
{
	homework.set_flag(1);
	char response;
	char title[100];
	char author[50];
	char chapter[2];
	char page[2];
	do
	{
		cout << "What would you like to do? Make a new reading requirement(N), Remove a reading(R), Find a reading (F), Show all readings(S), or delete all reading(D)?" << endl;
		cin >> response; cin.ignore(100, '\n');
		toupper(response);
		switch(response)
		{
			case 'N':
				cout << "Title: ";
				cin.get(title, 100, '\n'); cin.ignore(100, '\n');
				cout << "Author: ";
				cin.get(author, 50, '\n'); cin.ignore(100, '\n');
				cout << "Chapter: ";
				cin >> chapter; cin.ignore(100, '\n');
				cout << "Page: ";
				cin >> page; cin.ignore(100, '\n');
				homework.insert(title, author, chapter, page);
				break;

			case 'R':
				cout << "What reading would you like to remove?" << endl;
				cin.get(title, 100, '\n'); cin.ignore(100, '\n');
				homework.remove(title);
				break;

			case 'F':
				cout << "What reading would you like to find?" << endl;
				cin.get(title, 100, '\n'); cin.ignore(100, '\n');
				homework.retrieve(title);
				break;

			case 'S':
				cout << "All current readings are: " << endl;
				homework.display();
				break;

			case 'D':
				cout << "Removing all readings" << endl;
				homework.remove_all();
				cout << "All readings removed." << endl;
				break;

			default:
				break;
		}
		cout << "Would you like to continue? (Y/N)" << endl;
		cin >> response; cin.ignore(100, '\n');
		toupper(response);
	}
	while(response != 'Y');
	homework.reset();
	again();
	return 1;
}

int exercises()
{
	homework.set_flag(2);
	char response;
	char name[50];
	char question[100];
	char done[10];
	do
	{
		cout << "What would you like to do? Make a new exercise(N), Remove a (R), Find an exercise (F), Show all exercises(S), or delete all exercises(D)?" << endl;
		cin >> response; cin.ignore(100, '\n');
		toupper(response);
		switch(response)
		{
			case 'N':
				cout << "Name: ";
				cin.get(name, 50, '\n'); cin.ignore(100, '\n');
				cout << "Question: ";
				cin.get(question, 100, '\n'); cin.ignore(100, '\n');
				cout << "Are you finished? ";
				cin.get(done, 10, '\n'); cin.ignore(100, '\n');	
				homework.insert(name, question, done, NULL);
				break;

			case 'R':
				cout << "What exercise would you like to remove?" << endl;
				cin.get(name, 100, '\n'); cin.ignore(100, '\n');
				homework.remove(name);
				break;

			case 'F':
				cout << "What exercise would you like to find?" << endl;
				cin.get(name, 100, '\n'); cin.ignore(100, '\n');
				homework.retrieve(name);
				break;

			case 'S':
				cout << "All current exercises are: " << endl;
				homework.display();
				break;

			case 'D':
				cout << "Removing all exercises" << endl;
				homework.remove_all();
				cout << "All exercises removed." << endl;
				break;	

			default:
				break;
		}
		cout << "Would you like to continue? (Y/N)" << endl;
		cin >> response; cin.ignore(100, '\n');
		toupper(response);
	}
	while(response != 'Y');
	homework.reset();
	again();
	return 1;
}

int notes()
{
	homework.set_flag(3);
	char response;
	char name[50];
	char question[200];
	do
	{
		cout << "What would you like to do? Make new notes(N), Remove a (R), Find a note(F), Show all notes(S), or delete all notes(D)?" << endl;
		cin >> response; cin.ignore(100, '\n');
		toupper(response);
		switch(response)
		{
			case 'N':
				cout << "Name: ";
				cin.get(name, 50, '\n'); cin.ignore(100, '\n');
				cout << "Notes: ";
				cin.get(question,200, '\n'); cin.ignore(100, '\n');
				homework.insert(name, question, NULL, NULL);
				break;

			case 'R':
				cout << "What note would you like to remove?" << endl;
				cin.get(name, 100, '\n'); cin.ignore(100, '\n');
				homework.remove(name);
				break;

			case 'F':
				cout << "What note would you like to find?" << endl;
				cin.get(name, 100, '\n'); cin.ignore(100, '\n');
				homework.retrieve(name);
				break;

			case 'S':
				cout << "All current notes are: " << endl;
				homework.display();
				break;

			case 'D':
				cout << "Removing all notes" << endl;
				homework.remove_all();
				cout << "All notes removed." << endl;
				break;	

			default:
				break;
		}
		cout << "Would you like to continue? (Y/N)" << endl;
		cin >> response; cin.ignore(100, '\n');
		toupper(response);
	}
	while(response != 'Y');
	homework.reset();
	again();
	return 1;
}

int again()
{
	char response;
	cout << "Would you like to do anything else? (Y/N)" << endl;
	cin >> response; cin.ignore(100, '\n');
	toupper(response);
	if(response == 'Y')
		main();
	else
	{
		return 1;
	}
}
