
#ifndef node_h
#define node_h
#include <iostream>
#include <cstring>
using namespace std;

class lll
{
	public:
		lll();	
		~lll();
		lll(lll & to_copy);
		int set(char * title, char * author, int chapter, int page);
		void display();
		char * get_title();
		lll *& get_next();

	protected:
		char * title;
		char * author;
		int chapter;
		int page;
		lll * next;
};

class cll
{
	public:
		cll();
		~cll();
		cll(cll & to_copy);
		int set_question(char * new_name, char * new_question, char * new_done);
		int set_notes(char * new_name, char * new_question);
		void display();
		void display_notes();
		int set_done(cll *& head, char * name);
		char * get_name();
		cll *& get_next();

	protected:
		char * name;
		char * question;
		char * done;
		cll * next;
};

class dll
{
	public:
		dll();
		~dll();
		dll(dll & to_copy);
		class material *& get_data();
		dll *& get_tail();
		dll *& get_next();
		dll *& get_previous();
	
	protected:
		material * data;
		dll * next;
		dll * previous;
		dll * tail;
};

class material
{
	public:
		virtual int insert(char * arg1, char * arg2, int arg3, int arg4);
		virtual int insert(char * arg1, char * arg2, char * arg3);
		virtual int insert(char * arg1, char * arg2);
		virtual int remove(char * to_find) = 0;
		virtual void display() = 0;
		virtual int retrieve(char * to_find) = 0;
		virtual int remove_all() = 0;

	protected:
};

class reading : public material
{
	public:
		reading();
		~reading();
		int insert(char * title, char * author, int chapter, int page);
		int remove(char * title);
		void display();
		int retrieve(char * title);
		int remove_all();

	protected:
		int insert(lll *& head, char * title, char * author, int chapter, int page);
		int remove(lll * head, char * title);
		int retrieve(lll * head, char * title);
		void display(lll * head);
		int remove_all(lll *& head);
		lll * head;

};

class exercises : public material
{
	public:
		exercises();
		~exercises();
		int insert(char * name, char * question, char * done);
		int remove(char * name);
		void display();
		int retrieve(char * name);
		int remove_all();
		void done();

	protected:
		int remove(cll *& original, char * name);
		void display(cll * original);
		int retrieve(cll * original, char * name);
		int remove_all(cll *& original);
		cll * rear;

};

class notes : public material
{
	public:
		notes();
		~notes();
		int insert(char * name, char * note);
		int remove(char * name);
		void display();
		int retrieve(char * name);
		int remove_all();
		int set_done(char * name);

	protected:
		int remove(cll *& original, char * name);
		void display(cll * original);
		int retrieve(cll * original, char * name);
		int remove_all(cll *& original);
		cll * rear;
};

class casting
{
	public:
		casting();
		~casting();
		casting(casting & to_copy);
		void set_flag(int x);
		int insert(char * arg1, char * arg2, char * arg3, char * arg4);
		int remove(char * to_find);
		void display();
		int retrieve(char * to_find);
		int remove_all();
		void reset();
		int set_done(char * name);

	protected:
		void set();
		int flag;
		void make_hold(dll * origin);
		void copy(dll *& head, dll * to_copy);
		reading read;
		exercises question;
		notes note;
		dll * head;
		dll * tail;
		dll * hold;
};
#endif
