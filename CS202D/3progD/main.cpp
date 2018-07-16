#include "avatar.h"

int again();
int description();
int backstory();
int awards();

int main()
{
	char response;
	cout << "Welcome to avatar creation, where your avatar is your own." << endl;
	cout << "What would you like to do? Add a description(D), add a backstory/history(B), or add an achievement(A)?" << endl;
	cin >> response; cin.ignore(100, '\n');
	toupper(response);
	switch(response)
	{
		case 'D':
			description();
		case 'B':
			backstory();

		case 'A':
			awards();

		default:
			main();
	}
}

int again()
{
	char response;
	cout << "Would you like to continue? (Y/N)" << endl;
	cin >> response; cin.ignore();
	toupper(response);
	if(response == 'Y')
		main();

	else
	{
		return 1;
	}
}

int description()
{
	style descript;
	char eyes[15];
	char hair[20];
	char armor[20];
	char weapon[20];
	char items[100];
	int year;
	char response;
	do
	{
		cout << "Would you like to add a new description(A), edit a description(E), or display a description(D), or remove a description(R)?" << endl;
		cin >> response; cin.ignore(100, '\n');
		switch(response)
		{
			case 'A':
				cout << "Eyes: "; cin.get(eyes, 15, '\n'); cin.ignore(100, '\n'); cout << endl;
				cout << "Hair: "; cin.get(hair, 20, '\n'); cin.ignore(100, '\n'); cout << endl;
				cout << "Armor: "; cin.get(armor, 20, '\n'); cin.ignore(100, '\n'); cout << endl;
				cout << "Weapon: "; cin.get(weapon, 20, '\n'); cin.ignore(100, '\n'); cout << endl;
				cout << "Items: "; cin.get(items, 100, '\n'); cin.ignore(100, '\n'); cout << endl;
				cout << "Year: "; cin >> year; cin.ignore(100, '\n'); cout << endl;
				descript.insert(eyes, hair, armor, weapon, items, year);
			case 'E':
				cout << "What year is the change in?"; cin >> year; cin.ignore(100, '\n'); cout << endl;
				cout << "Eyes: "; cin.get(eyes, 15, '\n'); cin.ignore(100, '\n'); cout << endl;
				cout << "Hair: "; cin.get(hair, 20, '\n'); cin.ignore(100, '\n'); cout << endl;
				cout << "Armor: "; cin.get(armor, 20, '\n'); cin.ignore(100, '\n'); cout << endl;
				cout << "Weapon: "; cin.get(weapon, 20, '\n'); cin.ignore(100, '\n'); cout << endl;
				cout << "Items: "; cin.get(items, 100, '\n'); cin.ignore(100, '\n'); cout << endl;
				descript.edit(eyes, hair, armor, weapon, items, year);
				descript.display(year);

			case 'D':
				cout << "What year do you want to display?"; cin >> year; cin.ignore(100, '\n'); cout << endl;
				descript.display(year);

			case 'R':
				cout << "What year do you want removed?"; cin >> year; cin.ignore(100, '\n');
				descript.remove_one(year, 1);

		}
		cout << "Would you like to enter another description?(Y/N)" << endl;
		cin >> response; cin.ignore(100, '\n');
		toupper(response);
	}while(response != 'N');
	again();
}

int backstory()
{
	story history;
	int year;
	char event[50];
	char story[200];
	char response;	
	do
	{
		cout << "Would you like to add a new story(A), edit a story(E), or display a story(D)?" << endl;
		cin >> response; cin.ignore(100, '\n');
		switch(response)
		{
			case 'A':			
				cout << "Event: "; cin.get(event, 50, '\n'); cin.ignore(100, '\n'); cout << endl;
				cout << "Story: "; cin.get(story, 200, '\n'); cin.ignore(100, '\n'); cout << endl;
				cout << "Year: "; cin >> year; cin.ignore(100, '\n'); cout << endl;
				history.insert(event, story, year);
			case 'E':
				cout << "What year is the change in?"; cin >> year; cin.ignore(100, '\n'); cout << endl;
				cout << "Event: "; cin.get(event, 50, '\n'); cin.ignore(100, '\n'); cout << endl;
				cout << "Story: "; cin.get(story, 200, '\n'); cin.ignore(100, '\n'); cout << endl;
				history.edit(event, story, year);
				history.display(year);

			case 'D':
				cout << "What year do you want to display?"; cin >> year; cin.ignore(100, '\n'); cout << endl;
				history.display(year);

			case 'R':
				cout << "What year do you want removed?"; cin >> year; cin.ignore(100, '\n');
				history.remove_one(year, 2);
		}
		cout << "Would you like to enter another description?(Y/N)" << endl;
		cin >> response; cin.ignore(100, '\n');
		toupper(response);
	}while(response != 'N');
	again();
}

int awards()
{
	achieve reward;
	int year;
	char event[50];
	char story[200];
	char response;	
	do
	{
		cout << "Would you like to add a new story(A), edit a story(E), or display a story(D)?" << endl;
		cin >> response; cin.ignore(100, '\n');
		switch(response)
		{
			case 'A':			
				cout << "Event: "; cin.get(event, 50, '\n'); cin.ignore(100, '\n'); cout << endl;
				cout << "Story: "; cin.get(story, 200, '\n'); cin.ignore(100, '\n'); cout << endl;
				cout << "Year: "; cin >> year; cin.ignore(100, '\n'); cout << endl;
				reward.insert(event, story, year);
			case 'E':
				cout << "What year is the change in?"; cin >> year; cin.ignore(100, '\n'); cout << endl;
				cout << "Event: "; cin.get(event, 50, '\n'); cin.ignore(100, '\n'); cout << endl;
				cout << "Story: "; cin.get(story, 200, '\n'); cin.ignore(100, '\n'); cout << endl;
				reward.edit(event, story, year);
				reward.display(year);

			case 'D':
				cout << "What year do you want to display?"; cin >> year; cin.ignore(100, '\n'); cout << endl;
				reward.display(year);

			case 'R':
				cout << "What year do you want removed?"; cin >> year; cin.ignore(100, '\n');
				reward.remove_one(year, 3);
		}
		cout << "Would you like to enter another description?(Y/N)" << endl;
		cin >> response; cin.ignore(100, '\n');
		toupper(response);
	}while(response != 'N');
	again();
}
