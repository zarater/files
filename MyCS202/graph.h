#include <fstream>
#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

const int MAXSIZE = 100;
class vertex
{
	public:
	vertex();
	~vertex();
	int setVertexRow(char *neighbor);

	protected:
	int row;
};

class graph
{
	public:
	graph();
	~graph();
	int mappull();
	
	
	protected:
	int speedlimit;
	char * neighbor;
	vertex *vertexRow;

};


