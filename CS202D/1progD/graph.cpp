
#include "graph.h"

//Node vertex constructor that sets next to null and creates a new adjacent object
node_v::node_v():next(NULL), adjacent(new vertex){}

//Node vertex destructor that deletes next
node_v::~node_v()
{
	if(next)
	{
		delete next;
		next = NULL;
	}
}

//Node vertex copy constructor
node_v::node_v(node_v & to_copy)
{
	adjacent = new vertex;
	adjacent = to_copy.adjacent;
	next = new node_v;
	next = to_copy.next;
}

//Node vertex get next function
node_v *& node_v::get_next()
{
	return next;
}

//Node vertex get address function
char * node_v::get_address()
{
	return address;
}

//node vertex returns adjacent to attach in vertex
vertex *& node_v::attach()
{
	return adjacent;
}

//Node vertex set function
int node_v::set(char * new_address, int new_mph)
{
	address = new char[strlen(new_address) + 1];
 	strcpy(address, new_address);
 	mph = mph;
 	return 1;
}

//Node package constructor that sets next, item, size, and address to null
node_p::node_p(): next(NULL), item(NULL), size(0), address(NULL){}

//Node package destructor
node_p::~node_p()
{
	if(next)
	{
		delete next;
		next = NULL;
	}
	delete item;
	delete address;
}

//Node package copy constructor
node_p::node_p(node_p & to_copy)
{
	next = new node_p;
	next = to_copy.next;
}

//Node package get next function
node_p *& node_p::get_next()
{
	return next;
}

//Node package get address function
char * node_p::get_address()
{
	return address;
}

//Node package set function
int node_p::set(char * new_item, int new_size, char * new_address)
{
	address = new char[strlen(new_address) + 1];
	strcpy(address, new_address);
	item = new char[strlen(new_item) + 1];
	strcpy(item, new_item);
	size = new_size;
	return 1;
}

//Vertex constructor that sets head to null
vertex::vertex(): head(NULL){}

//Vertex destructor
vertex::~vertex()
{
	node_v * temp = head -> get_next();
	while(head)
	{
		delete head;
		head = temp;
		temp = temp -> get_next();
	}
	head = NULL;
	delete temp;
	temp = NULL;
}

//Vertex copy constructor
vertex::vertex(vertex & to_copy)
{
	head = new node_v;
	head = to_copy.head;
}

//Vertex get head for node vertex
node_v *& vertex::get_head()
{
	return head;
}

//Vertex set function for node vertex
int vertex::set(char * new_address, int new_mph)
{
	head -> set(new_address, new_mph);		
}

//Map constructor that sets the size, and creates the vertex array and calls a load function and the make graph function
map::map():size(20), position(new vertex[size]){load(); make_graph(0);}

//Map deconstructor
map::~map()
{
	if(position)
	{
		delete position;
		position = NULL;
	}
}

//Map copy constructor
map::map(map& to_copy)
{
	position = new vertex;
	position = to_copy.position;
}

//Map make graph function that randomly generates a graph
int map::make_graph(int i)
{
	if(i > size)
	{
		return 1;
	}
	int x = random() % size;
	node_v * hold;
	if(x == i)
		--x;
	while(x != -1)
	{
		hold = position[i].get_head();
		position[i].get_head() = new node_v;
		position[i].get_head() -> get_next() = hold;
		position[i].get_head() -> attach() = &position[x];
		--x;
		if(x == i)
		{
			x = -1;
		}
	}
	make_graph(++i);
	return 1;
}

//Map find path wrapper function 
int map::find_path(node_p * address, int x)
{
	if(!address)
	{
		return -1;
	}
	else
	{
		find_path(0, address -> get_address(), x);
		find_path(address -> get_next(), 0);
		return x;
	}
}

//Map find path second wrapper function
int map::find_path(int i, char * address, int x)
{
	node_v * temp = new node_v;
	temp = position[i].get_head();
	find_path(temp, address, x);
	return x;
}

//Map find path recursive function
int map::find_path(node_v * to_find, char * address, int x)
{
	if(strcmp(to_find -> get_address(), address) == 0)
	{
		return x;
	}
	else
	{
		find_path(to_find -> get_next(), address, ++x);
		return x;
	}
}

//Maps random generator
int map::random()
{
	int x;
	struct timeval tv;
	gettimeofday(&tv, NULL);
	srand(tv.tv_usec);
	x = rand();
	return x;
}

//Map load function that loads the address from the text file
void map::load()
{
	char word[200];
	int speed;
	int x = 0;
	ifstream file_in;
	file_in.open("address.txt");
	if(!file_in)
	{
		cout << "Error, could not load GPS. Please try again later" << endl;
	}
	else
	{
		while(!file_in.eof())
		{
			file_in.get(word, 200, ':'); file_in.ignore();
			file_in >> speed; file_in.ignore();
			position[x].set(word, speed);
			++x;
		}
		file_in.close();
	}	
}

//Package constructor that sets head to null
package::package():head(NULL){}

//Package deconstructor
package::~package()
{
	delete head;
	head = NULL;	
}

//Package get head function for node package
node_p *& package::get_head()
{
	return head;
}

//Package set function for node package
int package::set(char * new_item, int new_size, char * new_address)
{
	head -> set(new_item, new_size, new_address);
	return 1;
}
