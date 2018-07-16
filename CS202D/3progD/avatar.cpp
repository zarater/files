#include "avatar.h"

//Constructor for the avatar class
avatar::avatar(): root(NULL) {}

//Destructor for the avatar class
avatar::~avatar()
{
	remove(root);
}

//Copy constructor for the avatar class
avatar::avatar(avatar & to_copy)
{
	copy(root, to_copy.root);
}

//This function overloads the assignment operator
avatar avatar::operator =(avatar & to_copy) const
{
	avatar temp;
	temp.root = new tree;
	temp.root = to_copy.root;
	return temp;
}

//This function takes a match and flag and calls the correct case to remove the correct object
int avatar::remove_one(int match, int flag)
{
	switch(flag)
	{
		case 1:
			root -> remove_char(root, match);
			return 1;
		
		case 2:
			root -> remove_his(root, match);
			return 1;

		case 3:
			root -> remove_awa(root, match);
			return 1;
	}
}

//This function destroys the entire tree
int avatar::remove(tree *& origin)
{
	if(!origin)
		return 0;
	
	remove(origin -> get_left());
	remove(origin -> get_right());
	delete origin;
	origin = NULL;
	return 1;
}

//This function copies the entire tree
int avatar::copy(tree *& original, tree * source)
{
	if(!source)
		return 0;

	original = new tree;
	original -> get_left() = NULL;
	original -> get_right() = NULL;
	original = source;
	copy(original -> get_left(), source -> get_left());
	copy(original -> get_right(), source -> get_right());
	return 1;
}

//This function takes in arguments to create a character object and passes it to root to be insert
int style::insert(char * eyes, char * hair, char * armor, char * weapon, char * items, int year)
{
	descript.insert(eyes, hair, armor, weapon, items, year);
	root -> insert(root, descript);
	return 1;
}

//This function displays a matching integer character object
void style::display(int match)
{
	root -> display_char(root, match);
	return;
}

//This function collects the data to edit an existing character object
int style::edit(char * eyes, char * hair, char * armor, char * weapon, char * items, int year)
{
	descript.insert(eyes, hair, armor, weapon, items, year);
	root -> edit(root, descript, year);
	return 1;
}

//This function takes in arguments to create a history object and passes it to root to be insert
int story::insert(char * event, char * story, int year)
{
	back.insert(year, event, story);
	root -> insert(root, back);
	return 1;
}

//This function displays a matching integer history object
void story::display(int match)
{
	root -> display_his(root, match);
	return;
}

//This function collects the data to edit an existing history object
int story::edit(char * event, char * story, int year)
{
	back.insert(year, event, story);
	root -> edit(root, back, year);
	return 1;
}

//This function takes in arguments to create an award object and passes it to root to be insert
int achieve::insert(char * event, char * medal, int year)
{
	reward.insert(year, event, medal);
	root -> insert(root, reward);
	return 1;
}

//This function displays a matching integer award object
void achieve::display(int match)
{
	root -> display_awa(root, match);
}

//This function collects the data to edit an existing award object
int achieve::edit(char * event, char * medal, int year)
{
	reward.insert(year, event, medal);
	root -> edit(root, reward, year);
	return 1;
}
