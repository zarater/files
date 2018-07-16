
#include "delivery.h"

int normal();
int fast();
int robot();

standard strd;
express exp;
drone dr;

int main()
{
	char response;
	cout << "Welcome to Lundquist Delivery!" << endl;
	cout << "What type of service are you looking for? Standard(S), Express(E), or our new Drone option(D)?" << endl;
	cin >> response; cin.ignore();
	toupper(response);
	switch(response)
	{
		case 'S':
			normal();
			break;
		
		case 'E':
			fast();
			break;
	
		case 'D':
			robot();
			break;
	}
	return 1;
}

int normal()
{
	int i = 0;
	cout << "Standard delivery" << endl << "How many packages would you like to send?" << endl;
	cin >> i; cin.ignore();
	do
	{
		char address[100];
		int size;
		char item[100];
		cout << "What is the address?" << endl;
		cin.get(address, 100, '\n'); cin.ignore();
		cout << "What is the item?" << endl;
		cin.get(item, 100, '\n'); cin.ignore();
		cout << "How big is the item?" << endl;
		cin >> size; cin.ignore();
		strd.add_package(item, size, address);
	}
	while(i != 0);
	int y;
	y = strd.send();
	cout << "Packages deliveried! It took " << y << " minutes." << endl;
	cout << "Would you like to send more packages?" << endl;
	char response;
	cin >> response; cin.ignore();
	toupper(response);
	if(response == 'Y')
	{
		main();
	}
	else
	{
		return 1;
	}
}

int fast()
{
	int i = 0;
	cout << "Express delivery" << endl << "How many packages would you like to send?" << endl << "Please be aware express can only hold up to three packages" << endl;
	cin >> i; cin.ignore();
	do
	{
		char address[100];
		int size;
		char item[100];
		cout << "What is the address?" << endl;
		cin.get(address, 100, '\n'); cin.ignore();
		cout << "What is the item?" << endl;
		cin.get(item, 100, '\n'); cin.ignore();
		cout << "How big is the item?" << endl;
		cin >> size; cin.ignore();
		exp.add_package(item, size, address);
	}
	while(i != 0 && i <= 3);
	int y;
	y = exp.block();
	cout << "Packages delivered! It took " << y << " minutes." << endl;
	cout << "Would you like to send more packages?" << endl;
	char response;
	cin >> response; cin.ignore();
	toupper(response);
	if(response == 'Y')
	{
		main();
	}
	else
	{
		return 1;
	}
}

int robot()
{
	char response;
	cout << "Drone delivery" << endl << "Drone can only deliver a single package up to ten pounds" << endl;
	char address[100];
	int size;
	char item[100];
	cout << "What is the address?" << endl;
	cin.get(address, 100, '\n'); cin.ignore();
	cout << "What is the item?" << endl;
	cin.get(item, 100, '\n'); cin.ignore();
	cout << "How big is the item?" << endl;
	cin >> size; cin.ignore();
	dr.add_package(item, size, address);
	int y;
	y = dr.send();
	cout << "Packages deliveried! It took " << y << " minuts." << endl;
	cout << "Would you like to send more packages?" << endl;
	cin >> response; cin.ignore();
	toupper(response);
	if(response == 'Y')
	{
		main();
	}
	else
	{
		return 1;
	}
}
