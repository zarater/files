//David Lundquist, CS202, Program 2
#include "node.h"

//Constructor for the lll class
lll::lll(): title(NULL), author(NULL), chapter(0), page(0), next(NULL) {}

//Destructor for the lll class
lll::~lll()
{
	delete title;
	delete author;
	chapter = 0;
	page = 0;
}

//Copy constructor for the lll class
lll::lll(lll & to_copy)
{
	title = new char[strlen(to_copy.title) + 1];
	strcpy(title, to_copy.title);
	author = new char[strlen(to_copy.author) + 1];
	strcpy(author, to_copy.author);
	chapter = to_copy.chapter;
	page = to_copy.page;
}

//This function takes in arguments and they are set as the data members for that node
int lll::set(char * new_title, char * new_author, int new_chapter, int new_page)
{	
	title = new char[strlen(new_title) + 1];
	strcpy(title, new_title);
	author = new char[strlen(new_author) + 1];
	strcpy(author, new_author);
	chapter = new_chapter;
	page = new_page;
	return 1;
}

//This function displays the data in the current node
void lll::display()
{
	cout << title << " Written by: " << author << "Read chapter " << chapter << " page number " << page << endl;
	return;
}

//This function returns the next pointer
lll *& lll::get_next()
{
	return next;
}

//This function returns the title data member
char * lll::get_title()
{
	return title;
}

//Constructor for the cll class
cll::cll(): name(NULL), question(NULL), done(NULL), next(NULL) {}

//Destructor for the cll class
cll::~cll()
{
	delete name;
	delete question;
	delete done;
}

//Copy constructor for the cll class
cll::cll(cll & to_copy)
{
	name = new char[strlen(to_copy.name) + 1];
	strcpy(name, to_copy.name);
	question = new char[strlen(to_copy.question) + 1];
	strcpy(question, to_copy.question);
	done = new char[strlen(to_copy.done) + 1];
	strcpy(done, to_copy.done);
}

//This function is used by the exercises class to set its data
int cll::set_question(char * new_name, char * new_question, char * new_done)
{
	name = new char[strlen(new_name) + 1];
	strcpy(name, new_name);
	question = new char[strlen(new_question) + 1];
	strcpy(question, new_question);
	done = new char[strlen(new_done) + 1];
	strcpy(done, new_done);
	return 1;
}

//This function is used by the notes class to set its data
int cll::set_notes(char * new_name, char * new_question)
{
	name = new char[strlen(new_name) + 1];
	strcpy(name, new_name);
	question = new char[strlen(new_question) + 1];
	strcpy(question, new_question);
	return 1;
}

//This function displays the data for the exercises class
void cll::display()
{
	cout << "Assignment: " << name << " Problem is: " << question << "Finished? " << done << endl;
	return;
}

//This function displays the data for the notes class
void cll::display_notes()
{
	cout << "Notes for: " << name << "\n" << question << endl;
	return;
}

//This function changes the done data member to indicate it has been completed
int cll::set_done(cll *& head, char * name)
{
	if(!head)
		return 0;

	if(strcmp(head -> name, name) == 0)
	{
		strcpy(head -> done, "Yes");
		return 1;
	}
	else
	{
		set_done(head -> next, name);
		return 0;
	}
}

//This function returns the next pointer
cll *& cll::get_next()
{
	return next;
}

//This function returns the name data member
char * cll::get_name()
{
	return name;
}

//Constructor for the dll class
dll::dll(): data(NULL), previous(NULL), next(NULL) {}

//Destructor for the dll class
dll::~dll()
{
	if(next)
	{
		delete data;
		delete next;
		delete previous;
		next = NULL;
		previous = NULL;
	}
}

//Copy constructor for the dll class
dll::dll(dll & to_copy)
{
	tail = new dll;
	tail = to_copy.tail;
	data = to_copy.data;
}

//This function returns the material pointer
material *& dll::get_data()
{
	return data;
}

//This function returns the next pointer
dll *& dll::get_next()
{
	return next;
}

//This function returns the previous pointer
dll *& dll::get_previous()
{
	return previous;
}
