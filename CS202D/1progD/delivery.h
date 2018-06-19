#include "graph.h"

class delivery
{
	public:
		delivery();
		~delivery();
		int add_package(char * new_item, int new_size, char * new_address);
		int send();

	protected:
		bool check();
	 	node_p * head;
		map * GPS;
		int limit;
		int package;
};

class standard: public delivery
{
	public:
		standard();

	protected:
		void set();

};

class express: public delivery
{
	public:
		express();
		int block();

	protected:
		int block(int x, int y);
		void set();

};

class drone: public delivery
{
	public:
		drone();

	protected:
		void set();

};
