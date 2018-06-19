//David Lundquist, CS202, Program 1
#include "delivery.h"

//Constructor for the delivery base class that sets the head, gps, limit and package to null
delivery::delivery(): head(NULL), GPS(NULL), limit(0), package(0){}

//Destructor for the delivery base class that destroys head and gps
delivery::~delivery()
{
	if(head)
		delete head;
	if(GPS)
		delete GPS;
}

//A boolan function that checks if the limit is greater than the number of packages
bool delivery::check()
{
	if(limit > package)
	{
		return true;
	}
	if(limit == package)
	{
		return false;
	}
}

//Adds a new package to the list
int delivery::add_package(char * new_item, int new_size, char * new_address)
{
	if(check() == true)
	{
		if(!head)
		{
			head = new node_p;
			head -> set(new_item, new_size, new_address);
			return 1;
		}
		else
		{
			node_p * temp = new node_p;
			temp -> set(new_item, new_size, new_address);
			temp -> get_next() = head;
			head = temp;
			return 1;
		}
	}
	else
	{
		return -1;
	}
}

//Sends the delivery vehicle off to deliver the packages in head
int delivery::send()
{
	int x;
	GPS -> find_path(head, x);
	return x;
}

//Standard constructor that sets the limit to 10
standard::standard()
{
	limit = 10;
}

//Express constructor that sets the limit to 3
express::express()
{
	limit = 3;
}

//Express's function that determines road problems while delivering
int express::block()
{
	int x;
	int y = 0;
	x = send();
	y = block(x, y);
	return y;
}

//Recursive function that determines how many extra minutes it took to delivery up to 15 minutes using GPS's random function. A maximum delay of 15 minutes.
int express::block(int x, int y)
{
	if(x == 0)
	{
		return y;
	}
	else
	{
		int i = GPS -> random() % 15;
		y += i;
		y = block(--x, y);
		return y;
	}
}

//Drone constructor that sets the limit to 10 to indicate its weight limit
drone::drone()
{
	limit = 10;
}
