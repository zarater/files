//David Lundquist, CS202, Program 3
#include "node.h"

class avatar
{
	public:
		avatar();
		~avatar();
		avatar(avatar & to_copy);
		avatar operator =(avatar & to_copy) const;
		int remove_one(int match, int flag);

	protected:
		int remove_one(tree *& origin, int match);
		int remove(tree *& origin);
		int copy(tree *& original, tree * source);
		tree * root;
};

class style: public avatar
{
	public:
		int insert(char * eyes, char * hair, char * armor, char * weapon, char * items, int year);
		void display(int match);
		int edit(char * eyes, char * hair, char * armor, char * weapon, char * items, int year);
		
	protected:
		character descript;
};

class story: public avatar
{
	public:
		int insert(char * event, char * story, int year);
		void display(int match);
		int edit(char * event, char * story, int year);

	protected:
		history back;
};

class achieve: public avatar
{
	public:
		int insert(char * event, char * medal, int year);
		void display(int match);
		int edit(char * event, char * medal, int year);

	protected:
		award reward;
};
