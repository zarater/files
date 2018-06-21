#include "inh.h"
#include <fstream>

const int MAXSIZE = 100;
class vertex
{
	public:
	vertex();
	~vertex();
	int setVertexRow();

	protected:
	int row;
};
vertex :: vertex(): row(0)
{}
vertex :: ~vertex()
{}
int vertex :: setVertexRow()
{
	return 1;
}

class graph
{
	public:
	graph();
	~graph();
	int mappull();
	
	protected:
	int speedlimit;
	char * neighbor;
	vertex *vertextrow;

};

graph::graph(): speedlimit(0), neighbor(NULL)
{}
graph :: ~graph()
{}


int graph::mapppull()
{
	int x = 0;
	ifstream file_in;
	file_in.open("grid.txt");
	if(!file_in)
	{
		cout << "Not able to load grid" <<endl;
	}
	while(!file_in.eof())
	{
		//file_in >> speed; 
		file_in.get(speedlimit, :);
		file_in.ignore();
		//file_in.ignore();
		vertexRow[x].setVertexRow(neighbor);
		++x;
	}
	file_in.close();
}


		return 1;
}
