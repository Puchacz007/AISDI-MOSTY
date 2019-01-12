#include <iostream>
#include "graph.h"




int main()
{
	int vertexCount;
	std::cin >> vertexCount;

	if (vertexCount <= 3)
		return 0;

	std::vector< std::pair<int, int> > edges;

	int vertex1, vertex2;
	while (std::cin >> vertex1 >> vertex2)
	{
		std::pair<int, int> newEdge = std::make_pair(vertex1, vertex2);
		edges.push_back(newEdge);
	}

	Graph graph(vertexCount, edges);
	std::cout << "Test without remove\n";
	for (auto it : edges)
	{
		if (graph.isEdgeImportant(it)==1)//is extensive bridge
			std::cout << it.first << " " << it.second << std::endl;
	}
	
	Graph testGraph = graph;
	
	std::cout << "Test with remove\n";
	for (auto it : edges)
	{
	
		testGraph = graph;
		//std::cout << "edge " << it.first << " " << it.second << std::endl;
		testGraph.removeEdge(it);
	//	testGraph.printfEdges();
		testGraph.resetCheck();
		
		if (testGraph.isConsistent()==0)//is extensive bridge
			std::cout << it.first << " " << it.second << std::endl;
	}

	return 0;
}