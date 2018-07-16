#include "node.h"

//Constructor for the tree class
tree::tree(): left(NULL), right(NULL) {}

//Destructor for the tree class
tree::~tree()
{
	if(left)
	{
		delete left;
		left = NULL;
	}
	if(right)
	{
		delete right;
		right = NULL;
	}
}

//Copy constructor for the tree class
tree::tree(tree & to_copy)
{
	avatar.insert(to_copy.avatar);
	story.insert(to_copy.story);
	medal.insert(to_copy.medal);
	left = to_copy.left;
	right = to_copy.right;
}

//This function overloads the assignment operator to assign a tree pointer
tree tree::operator =(tree *& to_copy) const
{
	tree * temp = new tree;
	temp = to_copy;
	return *temp;
}

//This function inserts a new character object to the root character object
int tree::insert(tree *& root, character & to_copy)
{	
	if(!root)
	{
		root -> avatar += to_copy;
		return 1;
	}
	else
	{
		if(root -> avatar.get_year() <= to_copy.get_year())
		{
			insert(root -> get_right(), to_copy);
			return 1;
		}
		else
		{
			insert(root -> get_left(), to_copy);
			return 1;
		}
	}
}

//This function inserts a new history object to the root history object
int tree:: insert(tree *& root, history & to_copy)
{
	if(!root)
	{
		root -> story += to_copy;
		return 1;
	}
	else
	{
		if(root -> story.get_year() <= to_copy.get_year())
		{
			insert(root -> get_right(), to_copy);
			return 1;
		}
		else
		{
			insert(root -> get_left(), to_copy);
			return 1;
		}
	}
}

//This function inserts a new award object to the root award object
int tree::insert(tree *& root, award & to_copy)
{
	if(!root)
	{
		root -> medal += to_copy;
		return 1;
	}
	else
	{
		if(root -> medal.get_year() <= to_copy.get_year())
		{
			insert(root -> get_right(), to_copy);
			return 1;
		}
		else
		{
			insert(root -> get_left(), to_copy);
			return 1;
		}
	}
}

//This function edits an existing character object in root with a new character object
int tree::edit(tree *& origin, character & to_copy, int match)
{
	if(!origin)
		return 0;

	if(match == to_copy.get_year())
	{
		origin -> avatar.insert(to_copy);
		return 1;
	}
	else
	{
		if(match < to_copy.get_year())
		{
			edit(origin -> get_left(), to_copy, match);
			return 0;
		}
		else
		{
			edit(origin -> get_right(), to_copy, match);
			return 0;
		}
	}
}

//This function edits an existing history object in the root with a new history object
int tree::edit(tree *& origin, history & to_copy, int match)
{
	if(!origin)
		return 0;

	if(match == to_copy.get_year())
	{
		origin -> story.insert(to_copy);
		return 1;
	}
	else
	{
		if(match < to_copy.get_year())
		{
			edit(origin -> get_left(), to_copy, match);
			return 0;
		}
		else
		{
			edit(origin -> get_right(), to_copy, match);
			return 0;
		}
	}
}

//This function edits an existing award object in the root with a new award object
int tree::edit(tree *& origin, award & to_copy, int match)
{
	if(!origin)
		return 0;

	if(match == to_copy.get_year())
	{
		origin -> medal.insert(to_copy);
		return 1;
	}
	else
	{
		if(match < to_copy.get_year())
		{
			edit(origin -> get_left(), to_copy, match);
			return 0;
		}
		else
		{
			edit(origin -> get_right(), to_copy, match);
			return 0;
		}
	}
}

//This function displays a character objects data in root
void tree::display_char(tree * root, int match)
{
	if(!root)
		return;

	else
	{
		if(match == root -> avatar.get_year())
		{
			root -> avatar.display(root -> avatar);
			return;
		}
		else
		{
			if(match < root -> avatar.get_year())
			{
				display_char(root -> get_left(), match);
				return;
			}
			else
			{
				display_char(root -> get_right(), match);
				return;
			}
		}
	}
}

//This function displays a history object data in root
void tree::display_his(tree * root, int match)
{
	if(!root)
		return;

	else
	{
		if(match == root -> story.get_year())
		{
			root -> story.display(root -> story);
			return;
		}
		else
		{
			if(match < root -> story.get_year())
			{
				display_his(root -> get_left(), match);
				return;
			}
			else
			{
				display_his(root -> get_right(), match);
				return;
			}
		}
	}
}

//This function displays an award object data in root
void tree::display_awa(tree * root, int match)
{
	if(!root)
		return;

	else
	{
		if(match == root -> medal.get_year())
		{
			root -> medal.display(root -> medal);
			return;
		}
		else
		{
			if(match < root -> medal.get_year())
			{
				display_awa(root -> get_left(), match);
				return;
			}
			else
			{
				display_awa(root -> get_right(), match);
				return;
			}
		}
	}
}

//This function removes a character object in root
int tree::remove_char(tree *& root, int match)
{
	if(!root)
		return 0;

	if(root -> avatar.get_year() == match)
	{
		if(!root -> get_right() && !root -> get_left())
		{
			delete root;
			root = NULL;
			return 1;
		}
		else
		{
			if(root -> get_right())
			{
				tree * temp = root -> get_right();
				delete root;
				root = temp;
			}
			else
			{
				tree * temp = root -> get_left();
				delete root;
				root = temp;
			}
		}
	}
	if(match < avatar.get_year())
	{
		remove_char(root -> get_left(), match);
		return 0;
	}
	else
	{
		remove_char(root -> get_right(), match);
		return 0;
	}
}
	
//This function removes a history object in root
int tree::remove_his(tree *& root, int match)
{
	if(!root)
		return 0;

	if(root -> story.get_year() == match)
	{
		if(!root -> get_right() && !root -> get_left())
		{
			delete root;
			root = NULL;
			return 1;
		}
		else
		{
			if(root -> get_right())
			{
				tree * temp = root -> get_right();
				delete root;
				root = temp;
			}
			else
			{
				tree * temp = root -> get_left();
				delete root;
				root = temp;
			}
		}
	}
	if(match < story.get_year())
	{
		remove_his(root -> get_left(), match);
		return 0;
	}
	else
	{
		remove_his(root -> get_right(), match);
		return 0;
	}
}
	
//This function removes an award object in root
int tree::remove_awa(tree *& root, int match)
{
	if(!root)
		return 0;

	if(root -> medal.get_year() == match)
	{
		if(!root -> get_right() && !root -> get_left())
		{
			delete root;
			root = NULL;
			return 1;
		}
		else
		{
			if(root -> get_right())
			{
				tree * temp = root -> get_right();
				delete root;
				root = temp;
			}
			else
			{
				tree * temp = root -> get_left();
				delete root;
				root = temp;
			}
		}
	}
	if(match < medal.get_year())
	{
		remove_awa(root -> get_left(), match);
		return 0;
	}
	else
	{
		remove_awa(root -> get_right(), match);
		return 0;
	}
}	

//This function returns the left pointer
tree *& tree::get_left()
{
	return left;
}

//This function returns the right pointer
tree *& tree::get_right()
{
	return right;
}

//Constructor for the character class
character::character(): eyes(NULL), hair(NULL), armor(NULL), weapon(NULL), items(NULL), year(0) {}

//Destructor for the character class
character::~character()
{
	delete eyes;
	delete hair;
	delete armor;
	delete weapon;
	delete items;
	year = 0;
}

//Copy constructor for the character class
character::character(character & to_copy)
{
	insert(to_copy);
}

//This function overloads the assignment operator to assign a char pointer
char * character::operator =(const char & to_copy)
{
	char * temp = new char[strlen(&to_copy) + 1];
	strcpy(temp, &to_copy);
	return temp;
}

//This function overloads the addition operator by taking a character object and copying the data into a temperory character object
character character::operator +(character & to_copy)
{
	character temp;
	temp.eyes = new char[strlen(to_copy.eyes) + 1];
	strcpy(temp.eyes, to_copy.eyes);
	temp.hair = new char[strlen(to_copy.hair) + 1];
	strcpy(temp.hair, to_copy.hair);
	temp.armor = new char[strlen(to_copy.armor) + 1];
	strcpy(temp.armor, to_copy.armor);
	temp.weapon = new char[strlen(to_copy.weapon) + 1];
	strcpy(temp.weapon, to_copy.weapon);
	temp.items = new char[strlen(to_copy.items) + 1];
	strcpy(temp.items, to_copy.items);
	temp.year = to_copy.year;
	return *this;
}

//This function overloads the plus/equals operator by using the previous two overloaded operators
character character::operator +=(character & to_copy)
{
	*this = *this + *(&to_copy);
	return *this;
}

//This function overloads the not equals operator.
bool character::operator !=(const int & match)
{
	if(this -> year == match)
		return false;

	else
	{
		return true;
	}
}

//This function overloads the comparison operator
bool character::operator ==(const int & match)
{
	if(this -> year != match)
		return false;
	
	else
	{
		return true;
	}
}

//The function overloads the less than operator
bool character::operator <(const int & match)
{
	if(!(this -> year > match))
		return true;

	else
	{
		return false;
	}
}

//This function overloads the greater than operator
bool character::operator >(const int & match)
{
	if(!(this -> year < match))
		return true;
	
	else
	{
		return false;
	}
}

//This function overloads the less-than-or-equal-to operator
bool character::operator <=(const int & match)
{
	if(this -> year < match || this -> year == match)
		return true;

	else
	{
		return false;
	}
}

//This function overloads the greater-than-or-equal-to operator
bool character::operator >=(const int & match)
{
	if(this -> year > match || this -> year == match)
		return true;

	else
	{
		return false;
	}
}

//This function overloads the out-to operator
ostream& operator <<(ostream & out, const character & c)
{
	cout << "Eye color: " << c.eyes << "Hair color: " << c.hair << "Armor worn: " << c.armor << "Weapon wielded: " << c.weapon << "Items in possession: " << c.items << endl;
}

//This function inserts a new character object
int character::insert(character & to_copy)
{
	eyes = to_copy.eyes;
	hair = to_copy.hair;
	armor = to_copy.armor;
	weapon = to_copy.weapon;
	items = to_copy.items;
	year = to_copy.year;
	return 1;
}

//This function creates a new character object by taking in all the arguments
int character::insert(char * new_eyes, char * new_hair, char * new_armor, char * new_weapon, char * new_items, int new_year)
{
	eyes = new_eyes;
	hair = new_hair;
	armor = new_armor;
	weapon = new_weapon;
	items = new_items;
	year = new_year;
	return 1;
}

//This function returns year
int character::get_year()
{
	return year;
}

//This function displays a character object
void character::display(character c)
{
	cout << c;
	return;
}

//Constructor for the history class
history::history(): year(0), event(NULL), story(NULL) {}

//Destructor for the history class
history::~history()
{
	delete event;
	delete story;
	year = 0;
}

//Copy constructor for the history class
history::history(history & to_copy)
{
	insert(to_copy);
}

//This function overloads the assignment operator
char * history::operator =(const char & to_copy)
{
	char * temp = new char[strlen(&to_copy) + 1];
	strcpy(temp, &to_copy);
	return temp;
}

//This function overloads the plus operator
history history::operator +(history & to_copy)
{
	history temp;
	temp.event = new char[strlen(to_copy.event) + 1];
	strcpy(temp.event, to_copy.event);
	temp.story = new char[strlen(to_copy.story) + 1];
	strcpy(temp.story, to_copy.story);
	temp.year = to_copy.year;
	return *this;
}

//This function overloads the plus/equals operator
history history::operator +=(history & to_copy)
{
	*this = *this + *(&to_copy);
	return *this;
}

//This function overloads the not equals operator
bool history::operator !=(const int & match)
{
	if(this -> year == match)
		return false;

	else
	{
		return true;
	}
}

//This function overloads the comparison operator
bool history::operator ==(const int & match)
{
	if(this -> year != match)
		return false;
	
	else
	{
		return true;
	}
}

//This function overloads the lesser-than operator
bool history::operator <(const int & match)
{
	if(!(this -> year > match))
		return true;

	else
	{
		return false;
	}
}

//This function overloads the greater-than operator
bool history::operator >(const int & match)
{
	if(!(this -> year < match))
		return true;
	
	else
	{
		return false;
	}
}

//This function overloads the less-than-or-equal-to operator
bool history::operator <=(const int & match)
{
	if(this -> year < match || this -> year == match)
		return true;

	else
	{
		return false;
	}
}

//This function overloads the greater-than-or-equal-to operator
bool history::operator >=(const int & match)
{
	if(this -> year > match || this -> year == match)
		return true;

	else
	{
		return false;
	}
}

//This function overloads the out operator
ostream & operator <<(ostream & out, const history & h)
{
	cout << "Year of the event: " << h.year << "Event title: " << h.event << "What happened: " << h.story << endl;
}

//This function is to assigns from a history object
int history::insert(history & to_copy)
{
	year = to_copy.year;
	event = to_copy.event;
	story = to_copy.story;
	return 1;
}

//This function takes the arguments and assigns them
int history::insert(int new_year, char * new_event, char * new_story)
{
	year = new_year;
	event = new_event;
	story = new_story;
	return 1;
}

//This function returns year
int history::get_year()
{
	return year;
}

//This function dislpays a history object
void history::display(history h)
{
	cout << h;
	return;
}

//Constructor for the award class
award::award(): year(0), event(NULL), medal(NULL) {}

//Destructor for the award class
award::~award()
{
	year = 0;
	delete event;
	delete medal;
}

//Copy constructor for the award class
award::award(award & to_copy)
{
	insert(to_copy);
}

//This function overloads the assignment operator
char * award::operator =(const char & to_copy)
{
	char * temp = new char[strlen(&to_copy) + 1];
	strcpy(temp, &to_copy);
	return temp;
}

//This function overloads the plus operator
award award::operator +(award & to_copy)
{
	award temp;
	temp.event = new char[strlen(to_copy.event) + 1];
	strcpy(temp.event, to_copy.event);
	temp.medal = new char[strlen(to_copy.medal) + 1];
	strcpy(temp.medal, to_copy.medal);
	temp.year = to_copy.year;
	return *this;
}

//This function overloads the plus/equals operator
award award::operator +=(award & to_copy)
{
	*this = *this + *(&to_copy);
	return *this;
}

//This function overloads the not equals operator
bool award::operator !=(const int & match)
{
	if(this -> year == match)
		return false;

	else
	{
		return true;
	}
}

//This function overloads the comparison operator
bool award::operator ==(const int & match)
{
	if(this -> year != match)
		return false;
	
	else
	{
		return true;
	}
}

//This function overloads the less than operator
bool award::operator <(const int & match)
{
	if(!(this -> year > match))
		return true;

	else
	{
		return false;
	}
}

//This function overloads the greater than operator
bool award::operator >(const int & match)
{
	if(!(this -> year < match))
		return true;
	
	else
	{
		return false;
	}
}

//This function overloads the less-than-or-equal-to operator
bool award::operator <=(const int & match)
{
	if(this -> year < match || this -> year == match)
		return true;

	else
	{
		return false;
	}
}

//This function overloads the greater-than-or-equal-to operator
bool award::operator >=(const int & match)
{
	if(this -> year > match || this -> year == match)
		return true;

	else
	{
		return false;
	}
}

//This function overloads the out operator
ostream & operator <<(ostream & out, const award & a)
{
	cout << "Year of medal recieved: " << a.year << "Event to recieve medal: " << a.event << "What was earned: " << a.medal << endl;
}

//This function assigns the data from an award object
int award::insert(award & to_copy)
{
	year = to_copy.year;
	event = to_copy.event;
	medal = to_copy.medal;
	return 1;
}

//This function inserts the arguments for a new award object
int award::insert(int new_year, char * new_event, char * new_medal)
{
	year = new_year;
	event = new_event;
	medal = new_medal;
	return 1;
}

//This function returns year
int award::get_year()
{
	return year;
}

//This function displays an award object
void award::display(award a)
{
	cout << a;
	return;
}
