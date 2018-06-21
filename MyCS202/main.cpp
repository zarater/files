#include "inh.h"

bool ask();
bool ask2();
int options(int numofpkgs);

int main()
{
	int weight =12;
	int size = 22;
	char dest[] = "e5";
	
	//int itemsinpkg=0;
	int numofpkgs =0;
	int d = 0;
	int user;
	int option;

	package a_pkg;
	delivery pkgs;
	drone a_drone;
	express car;
	standard van;
	do
	{
		cout << "please type weight, size, and destination "<< endl;
		cin >> weight;
		cin >> size;
		cin.get(dest, SIZE, '\n');
		cin.ignore(SIZE,'\n');

		a_pkg.create(weight, size, dest);
		cout << "display a package? 1 = yes" << endl;
		cin>> user;
		if(user == 1)
		{
			cout << "display a package: " << endl;
			a_pkg.display();
		}
		pkgs.rows(a_pkg);
		++numofpkgs;
	}while (ask2()== true);
	// finished making packages
	//determine which type of vehicle works.
	user = 0;
	cout << "display all packages to deliver?" << endl;
	cin >> user;
	if(user ==1)
	{
		pkgs.superdisplay();
	}
	option = options(numofpkgs);
	if(option == 1)
	{
		a_drone.display();
		van.display();
		car.display();
	}
	if(option == 2)
	{
		car.display();
		van.display();
	}
	if(option == 3)
	{
		van.display();
	}

	cout << "end program" <<endl;
	return 0;
	//cout << "issue here main: " << endl;
}

bool ask()
{
	int i = 0;
	char response[100];
	cout << "do you want to continue?" << endl;
	cin.get(response, 100,'\n');//resizes array with null at end
	cin.ignore(100, '\n');

	int len = strlen(response);//counts size not including null at end
	for(i=0; i< len; ++i)
	{
		response[i] = toupper(response[i]);

	}
	cout << "you typed: " << response <<endl; 
	if(strcmp(response,"YES") ==0 || strcmp(response,"Y")==0){return true;}
	//	else if((strcmp(response,"NO")==0) || (strcmp(response,"N"))){return false;}
	return false;
}
bool ask2()
{
	int i = 0;
	char response[100];
	cout << "do you want to continue another package?" << endl;
	cin.get(response, 100,'\n');//resizes array with null at end
	cin.ignore(100, '\n');

	int len = strlen(response);//counts size not including null at end
	for(i=0; i< len; ++i)
	{
		response[i] = toupper(response[i]);

	}
	cout << "you typed: " << response <<endl; 
	if(strcmp(response,"YES") ==0 || strcmp(response,"Y")==0){return true;}
	//	else if((strcmp(response,"NO")==0) || (strcmp(response,"N"))){return false;}
	return false;
}
int options(int numofpkgs)
{
	int option = 0;
	if(numofpkgs == 1){cout << "all vehicle option" << endl; option =1;}//all vehicles option.
	if(numofpkgs <=3){cout << "standard and express option" << endl; option = 2;} //standard and express possibility.
	if(numofpkgs <= 10){cout << "standard option only"<< endl; option = 3;} //standard option only.
	//ask if 1 then return options to call objects and display routes.
	//ask user if they want to see those options inside int main and call the drone, standard, express objects to display top three routes.
	//first ask here the variations 
	return 1;
}
/* do
		{
			d = d + itemsinpkg;
			cout << "please type number " << endl;
			//cin>> d;
			//cin.ignore();

			cout << "- items: " << itemsinpkg << "passed in pkg info: " << d << endl;
			a_pkg.create(d);

			++itemsinpkg;
		} while (ask() == true); */
