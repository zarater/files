#include "graph.h"



vertex :: vertex(): numrow(0), Row(NULL)
{}
//copy constructor
//vertex :: vertex(): numrow()

vertex :: ~vertex()
{}
int vertex :: setVertexRow(char *neighbor)
{
	Row = new char [strlen(neighbor)+1];
	strcpy(neighbor, Row);
	cout << neighbor << "neighbor" << endl;
	
	return 1;
}

graph::graph(): speedlimit(0), neighbor(NULL)
{}
graph :: ~graph()
{}
int graph::mappull()
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
		file_in.get(neighbor,MAXSIZE, ':');
		//file_in >> neighbor; 
		file_in.ignore();
		//file_in >> speed; 
		//file_in.ignore();
		vertexRow[x].setVertexRow(neighbor);
		++x;
	}
	file_in.close();



		return 1;
}
