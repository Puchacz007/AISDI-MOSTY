#include <vector>
#include <iostream>
class Graph
{
private:
	std::vector< std::vector<int> > connectedVerticles;
	std::vector<bool> checked;
	int vertexCount;
	void checkVerticles(int vertex)
	{
		checked[vertex] = true;
		for (std::vector<int>::iterator it = connectedVerticles[vertex].begin(); it != connectedVerticles[vertex].end(); it++)
		{
			int vert = *it;
			if (checked[vert]==0)
				checkVerticles(vert);
		}
	}
public:
	Graph(int vertexCount, std::vector< std::pair<int, int> > edges) :vertexCount(vertexCount)
	{
		connectedVerticles.resize(vertexCount);
		checked.resize(vertexCount);

		for (auto it : edges)
		{
			int vertex1 = it.first, vertex2 = it.second;
			connectedVerticles[vertex2].push_back(vertex1);
			connectedVerticles[vertex1].push_back(vertex2);
		}
	}
	Graph()
	{
		vertexCount = 0;
	}
	~Graph()
	{
	}
	
	Graph &operator=(const Graph & graph)
	{
		if (graph.vertexCount == vertexCount && graph.connectedVerticles == connectedVerticles && graph.checked == checked)return *this;
		vertexCount = graph.vertexCount;
		std::copy(graph.connectedVerticles.begin(), graph.connectedVerticles.end(), connectedVerticles.begin());
		std::copy(graph.checked.begin(), graph.checked.end(), checked.begin());
	}
	
	bool isEdgeImportant(std::pair<int, int> edge)
	{
		resetCheck();

		checked[edge.first] = true;
		checked[edge.second] = true;


		return !isConsistent();
	}
	bool isConsistent()
	{
		if (vertexCount == 0)return true;

		int j = 0;
		for (int i = 0; i < vertexCount; i++)
		{
			
			if (checked[i] == 0 && connectedVerticles[i].size()>0)
			{
				checkVerticles(i);
				j++;
			}
			if (j > 1) return false;
		}
		if (j < 1)return false;
		return true;
	}

	void removeEdge(std::pair<int, int> edge)
	{
		int connectedVertex;
		int vect1 = edge.first;
		removeVertexConnections(vect1);
		int vect2 = edge.second;
		removeVertexConnections(vect2);
	}

	void removeVertexConnections(int vertex)
	{
		if (vertexCount == 0)return;
		for (std::vector<int>::iterator it = connectedVerticles[vertex].begin(); it != connectedVerticles[vertex].end(); it++)
		{
			int connectedVertex = *it;
			for (std::vector<int>::iterator it2 = connectedVerticles[connectedVertex].begin(); it2 != connectedVerticles[connectedVertex].end(); it2++)
			{
				if (*it2 == vertex)
				{
					connectedVerticles[connectedVertex].erase(it2);
					break;
				}
			}

		}
		connectedVerticles[vertex].erase(connectedVerticles[vertex].begin(), connectedVerticles[vertex].end());
	}
	void resetCheck()
	{

		for (auto it : checked)
			it = false;
	}
	void printfEdges()
	{
	
		resetCheck();
		std::cout << "Printing Edges \n";
		for (int i = 0;i < vertexCount; i++)
		{
			
			checked[i] = true;
			for (std::vector<int>::iterator it = connectedVerticles[i].begin(); it != connectedVerticles[i].end(); it++)
			{
				int vert = *it;
				if (checked[vert] == 0)
					std::cout << i << " " << vert << std::endl;
			}
			
		}
		
		}
	int numberOfVerticles()
	{
		return vertexCount;
	}
};
