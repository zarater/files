#include <iostream>
#include <fstream>
#include <sys/time.h>
#include <cstring>
#include <stdlib.h>
using namespace std;

class node_v
{
	public:
		node_v();
		~node_v();
		node_v(node_v & to_copy);
		node_v *& get_next();
		class vertex *& attach();
		int set(char * new_address, int new_mph);
		char * get_address();

	protected:
		node_v * next;
		char * address;
		int mph;
		class vertex * adjacent;
};

class node_p
{
	public:
		node_p();
		~node_p();
		node_p(node_p & to_copy);
		node_p *& get_next();
		char * get_address();
		int set(char * new_item, int new_size, char * new_address);

	protected:
		node_p * next;
		char * item;
		int size;
		char * address;
};

class vertex
{
	public:
		vertex();
		~vertex();
		vertex(vertex & to_copy);
		node_v *& get_head();
		int set(char * new_address, int new_mph);

	protected:
		node_v * head;
};

class map
{
	public:
		map();
		~map();
		map(map & to_copy);
		int make_graph(int i);
		int random();
		void load();
		int find_path(node_p * address, int x);
	
	protected:
		int find_path(int i, char * address, int x);
		int find_path(node_v * to_find, char * address, int x);
		int size;
		vertex * position;
};

class package
{
	public:
		package();
		~package();
		package(package & to_copy);
		int new_package(char * item, int size);
		node_p *& get_head();
		int set(char * new_item, int new_size, char * new_address);

	protected:
		node_p * head;
};
