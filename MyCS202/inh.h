#include "graph.h"



const int SIZE = 100;
class package 
{
	public:
	package();
	~package();

	int copy(package &pkg);
	int display();
	int create(int, int, char[]);
	int compare(char key_value[]);
	//int LinearLinked();
	class node* head;//protect later ..[TODO]

	//protected:
	private:
	int num;
	int num2;
	char *dest;
	node *start;
};

class node
{
	public:
	node();
	//virtual ~node();
	~node();

	node *getnext();
	void setnext(node* newnext);
	int getdata();
	
	//void setdata(int);//DATA
	package *adjacent;//DATA //protect later..[TODO]

	//protected:
	private:
	int data;
	node* next;
};




class delivery
{
	public:
	delivery();
	~delivery();

	int rows(package &);//insert
	int edge();
	bool scan();// scans if its true that its not the same route as before.
	int best3();//creates a lll -> lll and inserts route to lll if best 3
	int route();//creates a lll  from graph
	int superdisplay();

	protected:

	int nums;//is a total of the route
	int row;
	package *adjacency_list;
	node *head;
	node *start;
//	graph grid;
};



class drone: public delivery
{
	public:
	int pay(int weight, int time);
	int route(char * dest);//finds the fastest route to deliver by returning a number of destination. 
	//finds numbers for all possible routes and chooses best four.
	int display();
	protected:


};
//pay: distance and weight should be determiner
//shortest time receives best pay.
//shortest route should be used to deliver package
//find shortest route and use it to deliver
//limit of how many packages
class standard: public delivery
{
	public:
	int display();
	protected:
};
class express: public delivery
{
	public:
	int display();
	protected:

};
