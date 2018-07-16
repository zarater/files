#include <iostream>
#include <cstring>
using namespace std;

class character
{
	public:
		character();
		~character();
		character(character & to_copy);
		char * operator =(const char & to_copy);
		character operator +(character & to_copy);
		character operator +=(character & to_copy);
		bool operator !=(const int & match);
		bool operator ==(const int & match);
		bool operator <(const int & match);
		bool operator >(const int & match);
		bool operator <=(const int & match);
		bool operator >=(const int & match);
		friend ostream & operator <<(ostream & out, const character & c);
		int insert(character & to_copy);
		int insert(char * new_eyes, char * new_hair, char * new_armor, char * new_weapon, char * new_items, int new_year);
		int get_year();
		void display(character c);

	protected:
		char * eyes;
		char * hair;
		char * armor;
		char * weapon;
		char * items;
		int year;
};

class history
{
	public:
		history();
		~history();
		history(history & to_copy);
		char * operator =(const char & to_copy);
		history operator +(history & to_copy);
		history operator +=(history & to_copy);
		bool operator !=(const int & match);
		bool operator ==(const int & match);
		bool operator <(const int & match);
		bool operator >(const int & match);
		bool operator <=(const int & match);
		bool operator >=(const int & match);
		friend ostream & operator <<(ostream & out, const history & h);
		int insert(history & to_copy);
		int insert(int new_year, char * new_event, char * new_story);
		int get_year();
		void display(history h);
		
	protected:
		int year;
		char * event;
		char * story;
};

class award
{
	public:
		award();
		~award();
		award(award & to_copy);
		char * operator =(const char & to_copy);
		award operator +(award & to_copy);
		award operator +=(award & to_copy);
		bool operator !=(const int & match);
		bool operator ==(const int & match);
		bool operator <(const int & match);
		bool operator >(const int & match);
		bool operator <=(const int & match);
		bool operator >=(const int & match);
		friend ostream & operator <<(ostream & out, const award & a);
		int insert(award & to_copy);
		int insert(int new_year, char * new_event, char * new_medal);
		int get_year();
		void display(award a);

	protected:
		int year;
		char * event;
		char * medal;
};

class tree
{
	public:
		tree();
		~tree();
		tree(tree & to_copy);
		tree operator =(tree *& to_copy)const;
		int insert(tree *& root, character & to_copy);
		int insert(tree *& root, history & to_copy);
		int insert(tree *& root, award & to_copy);
		int edit(tree *& root, character & to_copy, int match);
		int edit(tree *& root, history & to_copy, int match);
		int edit(tree *& root, award & to_copy, int match);
		void display_char(tree * root, int match);
		void display_his(tree * root, int match);
		void display_awa(tree * root, int match);
		int remove_char(tree *& root, int match);
		int remove_his(tree *& root, int match);
		int remove_awa(tree *& root, int match);
		tree *& get_left();
		tree *& get_right();

	protected:
		tree * left;
		tree * right;
		character avatar;
		history story;
		award medal;
};
