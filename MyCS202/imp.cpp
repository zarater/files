#include "inh.h"


node:: node(): data(0) , next(NULL)
{}
node::~node()
{}
int node:: getdata()
{
	adjacent -> display();
	return 1;
}
/*
 void node :: setdata(int num)
{
	data = num;
} */
void node:: setnext(node * newnext)
{
	next = newnext;
}
node *node:: getnext() 
{
	return next;
}

package::package(): num(0), head(NULL),start(NULL)//default constructor
{}

package::~package()  
{
	delete head;
}
int package :: copy(package & pkg)
{
	//if(!pkg.head){return 0;}
	num = pkg.num;
	num2 = pkg.num2;
	dest = new char [strlen(pkg.dest)+1];
	strcpy(dest, pkg.dest);
	//pkg.xxx = new char[strlen...]
	//strcpy
	return 1;
	
}



int package:: display()
{
	cout << num << endl;//weight
	cout << num2 << endl;//size
	cout << dest << endl;
	return 1;
}

int package::create(int weight, int size, char destination[])
{
	//creating a LLL
	num = weight;
	num2 = size;
	dest = new char[strlen(destination)+1];
	strcpy(dest, destination);
	return 1;
}

/* int package :: LinearLinked()
{
	node *temp = new node;
	temp->setdata(num);
	if (!head)
	{
		head = temp;
		start = head;
		head->setnext(NULL);
		return 0;
	}

	else if (head->getnext() == NULL)
	{
		temp->setnext(head->getnext());
		head->setnext(temp);
		//temp = head;
	}
	head = head->getnext();
	return 1;
}
 */

delivery :: delivery(): row(0), adjacency_list(NULL), start(NULL)
{
}
delivery :: ~delivery()
{

	if(adjacency_list){ delete adjacency_list;}

}

int delivery::rows(package &pkg)
{
	//head == x aka rows
	//package == y aka column
	node * temp = new node;
	temp -> adjacent = new package;
	package *apkg = temp -> adjacent;
	apkg -> copy(pkg);//getdata()
	
	apkg -> display();

	if(head == NULL)
	{
	head -> adjacent = new package;
	head -> adjacent -> copy(pkg);//getdata
	head -> setnext(NULL);
	start = head;
		return 0;
	}
	else if(head -> getnext()==NULL)
	{
		cout << "issue here rows: " << endl;
		cout << "issue here: " << endl;
		temp -> setnext(head -> getnext());
	 	head->setnext(temp);
	 	temp = head;
	}
	head = head -> getnext();

	return 1;
}
int delivery :: superdisplay()
{
	if(!start){cout << "NULL" << endl; return 0;}
	/*
	   while(head != NULL)
	   {
	   cout << head -> getdata() << "->";
	//if(head -> getdata() == NULL){cout<< "NULL << endl;
	head = head->getnext();

	}
	//return 1;
	 */
	cout << start-> getdata() << "->";
	start = start->getnext();

	return superdisplay();

}
// int delivery::edge()
// {
// 	node *temp = new node;
// 	temp -> adjacent = &adjacency_list;

// }
bool delivery::scan(){}
int delivery:: best3(){}

//**************************************** drone*************************************
int drone :: display()
{
	superdisplay();
}

//**************************************** express *************************************
int express :: display(){}
//**************************************** standard*************************************
int standard :: display(){}
