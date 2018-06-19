//David Lundquist, CS202, Program 2
#include "node.h"

//This function is to make the compiler happy
int material::insert(char * arg1, char * arg2, int arg3, int arg4)
{
	return 0;
}

//This function is to make the compiler happy
int material::insert(char * arg1, char * arg2, char * arg3)
{
	return 0;
}

//This function is to make the compiler happy
int material::insert(char * arg1, char * arg2)
{
	return 0;
}

//Constructor for the reading class
reading::reading(): head(NULL) {}

//Destructor for the reading class
reading::~reading()
{
	remove_all(head);
}

//This function takes in the arguments for a new node and passes it to a recursive function
int reading::insert(char * title, char * author, int chapter, int page)
{
	insert(head, title, author, chapter, page);
	return 1;
}

//This function looks for a null node along the list and passes it to heads set functions
int reading::insert(lll *& head, char * title, char * author, int chapter, int page)
{
	if(!head)
	{
		head = new lll;
		head -> set(title, author, chapter, page);
		head -> get_next() = NULL;
		return 1;
	}
	else
	{
		insert(head -> get_next(), title, author, chapter, page);
		return 1;
	}
}

//This function takes a title to find and passes it to a recursive function
int reading::remove(char * title)
{
	if(remove(head, title) == 0)
	{
		cout << "Could not find title. Please try again later." << endl;
		return 0;
	}
	return 1;
}

//This function looks for a matching title to the passed in argument and if found deletes it
int reading::remove(lll * head, char * title)
{
	if(!head)
	{
		return 0;
	}
	else
	{
		if(strcmp(head -> get_title(), title) == 0)
		{
			lll * temp = head -> get_next();
			delete head;
			head = NULL;
			head = temp;
			return 1;
		}
		else
		{	
			remove(head -> get_next(), title);
			return 0;
		}
	}
}

//Wrapper function for the display recursive function
void reading::display()
{
	display(head);
	return;
}

//Recursively displays everything in the list
void reading::display(lll * head)
{
	head -> display();
	display(head -> get_next());
	return;
}

//Wrapper function for the retrieve recursive function
int reading::retrieve(char * title)
{
	if(retrieve(head, title) == 0)
	{
		cout << "Could not find title, please try again later" << endl;
		return 0;
	}
	return 1;
}

//Recursive function that looks for a matching title from the argument list and if found displays it
int reading:: retrieve(lll * head, char * title)
{
	if(!head)
		return 0;
	else
	{
		if(strcmp(head -> get_title(), title) == 0)
		{
			head -> display();
			return 1;
		}
		else
		{
			retrieve(head -> get_next(), title);
			return 0;
		}
	}
}

//Wrapper function for the remove all function
int reading::remove_all()
{
	remove_all(head);
	return 1;
}

//Recursively deletes everything in the list
int reading::remove_all(lll *& head)
{
	if(!head)
		return 1;
	else
	{
		lll * temp = head -> get_next();
		delete head;
		head = NULL;
		remove_all(temp);
		return 1;
	}
}

//Constructor for the exercises class
exercises::exercises(): rear(NULL) {}

//Destructor for the exercises class
exercises::~exercises()
{
	if(rear)
	{
		delete rear;
		rear = NULL;
	}
}

//This function sets a new node at rear
int exercises::insert(char * name, char * question, char * done)
{
	if(!rear)
	{
		rear = new cll;
		rear -> set_question(name, question, done);
		rear -> get_next() = rear;
		return 1;
	}
	else
	{
		cll * temp = new cll;
		temp -> set_question(name, question, done);
		temp -> get_next() = rear;
		rear = temp;
		return 1;
	}
}

//Wrapper function for the remove recursive function, also checks rear for the name, if found deletes it
int exercises::remove(char * name)
{
	if(strcmp(rear -> get_name(), name) == 0)
	{
		cll * temp = rear -> get_next();
		delete rear;
		rear = NULL;
		rear = temp;
		return 1;
	}
	else
	{
		if(remove(rear -> get_next(), name) == 0)
		{
			cout << "Could not find exercise, please try again later" << endl;
			return 0;
		}
	}
	return 1;
}

//This function recursively looks for a match to the argument passed in, if found deletes it
int exercises::remove(cll *& original, char * name)
{
	if(rear == original)
	{
		return 0;
	}
	else
	{
		if(strcmp(original -> get_name(), name) == 0)
		{
			cll * temp = rear -> get_next();
			delete original;
			original = NULL;
			original = temp;
			return 1;
		}
		else
		{
			remove(original -> get_next(), name);
			return 0;
		}
	}
}

//Wrapper function for the display function after displaying at rear
void exercises::display()
{
	rear -> display();
	display(rear -> get_next());
	return;
}

//Recursively displays all the nodes in the cll
void exercises::display(cll * original)
{
	if(rear == original)
	{
		return;
	}
	else
	{
		rear -> display();
		display(original -> get_next());
		return;
	}
}

//Wrapper function for the retrieve recursive function after check to see if rear is the match
int exercises::retrieve(char * name)
{
	if(strcmp(rear -> get_name(), name) == 0)
	{
		rear -> display();
		return 1;
	}
	else
	{
		if(retrieve(rear -> get_next(), name) == 0)
		{
			cout << "Could not find exercise, please try again later." << endl;
			return 0;
		}
		return 1;
	}
}

//Recursively checks to see if the node is a match with the passed in argument
int exercises::retrieve(cll * original, char * name)
{
	if(rear == original)
	{
		return 0;
	}
	else
	{
		if(strcmp(original -> get_name(), name) == 0)
		{
			original -> display();
			return 1;
		}
		else
		{
			retrieve(original -> get_next(), name);
			return 0;
		}
	}
}

//Wrapper function for the recursive remove all function
int exercises::remove_all()
{
	remove_all(rear);
	return 1;
}

//Recursively deletes everything in the cll
int exercises::remove_all(cll *& original)
{
	if(rear -> get_next() == original)
	{
		original -> get_next() = NULL;
		delete original;
		original = NULL;
		return 1;
	}
	else
	{
		cll * temp = original -> get_next();
		delete original;
		original = temp;
		remove_all(original -> get_next());
		return 1;
	}
}

//Constructor for the notes class
notes::notes(): rear(NULL) {}

//Destructor for the notes class
notes::~notes()
{
	remove_all(rear);
}

//This function sets a new node at rear
int notes::insert(char * name, char * question)
{
	if(!rear)
	{
		rear = new cll;
		rear -> set_notes(name, question);
		rear -> get_next() = rear;
		return 1;
	}
	else
	{
		cll * temp = new cll;
		temp -> set_notes(name, question);
		temp -> get_next() = rear;
		rear = temp;
		return 1;
	}
}

//Wrapper function for the remove function after it checks to see if rear is a match for the argument
int notes::remove(char * name)
{
	if(strcmp(rear -> get_name(), name) == 0)
	{
		cll * temp = rear -> get_next();
		delete rear;
		rear = NULL;
		rear = temp;
		return 1;
	}
	else
	{
		if(remove(rear -> get_next(), name) == 0)
		{
			cout << "Could not find notes, please try again later" << endl;
			return 0;
		}
	}
	return 1;
}

//Recursively checks to see if the node is a match for the passed in argument, deletes the node if it is;
int notes::remove(cll *& original, char * name)
{
	if(rear == original)
	{
		return 0;
	}
	else
	{
		if(strcmp(original -> get_name(), name) == 0)
		{
			cll * temp = rear -> get_next();
			delete original;
			original = NULL;
			original = temp;
			return 1;
		}
		else
		{
			remove(original -> get_next(), name);
			return 0;
		}
	}
}

//Wrapper function for the display recursive function
void notes::display()
{
	rear -> display_notes();
	display(rear -> get_next());
	return;
}

//Recursively displays everything in the cll
void notes::display(cll * original)
{
	if(rear == original)
	{
		return;
	}
	else
	{
		rear -> display_notes();
		display(original -> get_next());
		return;
	}
}

//Wrapper function for the retrieve recursive function after it checks to see if rear is a match, displays the node if it is
int notes::retrieve(char * name)
{
	if(strcmp(rear -> get_name(), name) == 0)
	{
		rear -> display();
		return 1;
	}
	else
	{
		if(retrieve(rear -> get_next(), name) == 0)
		{
			cout << "Could not notes, please try again later." << endl;
			return 0;
		}
		return 1;
	}
}

//Recursively searchs the cll for a match to the argument, displays the results if found
int notes::retrieve(cll * original, char * name)
{
	if(rear == original)
	{
		return 0;
	}
	else
	{
		if(strcmp(original -> get_name(), name) == 0)
		{
			original -> display();
			return 1;
		}
		else
		{
			retrieve(original -> get_next(), name);
			return 0;
		}
	}
}

//Wrapper function for the remove all recursive function
int notes::remove_all()
{
	remove_all(rear -> get_next());
	return 1;
}

//Recursive deletes the entire node
int notes::remove_all(cll *& original)
{
	if(rear -> get_next() == original)
	{
		original -> get_next() = NULL;
		delete original;
		original = NULL;
		return 1;
	}
	else
	{
		cll * temp = original -> get_next();
		delete original;
		original = temp;
		remove_all(original -> get_next());
		return 1;
	}
}

//This function calls the head set done function
int notes::set_done(char * name)
{
	if(rear -> set_done(rear, name) == 0)
		return 0;
	return 1;
}

//Constructor for the casting class
casting::casting(): head(NULL), tail(NULL), hold(NULL), flag(0) {set();}

//Destructor for the casting class
casting::~casting()
{
	dll * temp = head -> get_next();
	delete head;
	head = NULL;
	head = temp;
	temp = temp -> get_next();
	delete head;
	head = NULL;
	delete temp;
	temp = NULL;
}

//Copy constructor for the casting class
casting::casting(casting & to_copy)
{
	copy(head, to_copy.head);
}

//This function is used by the copy constructor to build a new list
void casting::copy(dll *& head, dll * to_copy)
{
	if(!head)
		return;
	
	head = new dll;
	head = to_copy;
	copy(head -> get_next(), to_copy -> get_next());
	return;
}

//This function sets the flag data member to 1 <= x <= 3 and dynamically casts hold to as a result
void casting::set_flag(int x)
{
	flag = x;
	switch(flag)
	{
		case 1:
			make_hold(head);
			dynamic_cast <reading *> (hold -> get_data());
			return;
		case 2:
			make_hold(head -> get_next());
			dynamic_cast <exercises *> (hold -> get_data());
			return;
		case 3:
			make_hold(tail);
			dynamic_cast <notes *> (hold -> get_data());
			return;
	}
}

//This function sets hold to whatever origin is
void casting::make_hold(dll * origin)
{
	hold = new dll;
	hold = origin;
	return;
}

//This function sets the next and tail pointer with the proper data items
void casting::set()
{
	head = new dll;
	*(head -> get_data()) = read;
	head -> get_next() = new dll;
	head -> get_previous() = NULL;
	tail = head -> get_next();
	*(tail -> get_data()) = question;
	tail -> get_previous() = head;
	tail -> get_next() = new dll;
	tail -> get_next() -> get_previous() = tail;
	tail = tail -> get_next();
	*(tail -> get_data()) = note;
	return;
}

//This function checks the flag case and calls the appropriate hold insert function
int casting::insert(char * arg1, char * arg2, char * arg3, char * arg4)
{
	switch(flag)
	{
		case 1:
			hold -> get_data() -> insert(arg1, arg2, (int) *arg3, (int) *arg4);
			return 1;
		
		case 2:
			hold -> get_data() -> insert(arg1, arg2, arg3);
			return 1;

		case 3:
			hold -> get_data() -> insert(arg1, arg2);
			return 1;
	}
}

//This function calls the hold remove function
int casting::remove(char * to_find)
{
	if(hold -> get_data() -> remove(to_find) == 0)
		return 0;
	else
	{
		return 1;
	}
}

void casting::display()
{
	hold -> get_data() -> display();
}

//This function calls the hold retrieve function
int casting::retrieve(char * to_find)
{
	if(hold -> get_data() -> retrieve(to_find) == 0)
		return 0;
	else
	{
		return 1;
	}
}

//This function calls the hold remove all function
int casting::remove_all()
{
	hold -> get_data() -> remove_all();
	return 1;
}

//This function resets flag to zero and deletes hold so that both can be used again later on
void casting::reset()
{
	flag = 0;
	delete hold;
	hold = NULL;
	return;
}
