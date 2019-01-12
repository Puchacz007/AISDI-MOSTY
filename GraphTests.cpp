#include <boost/lambda/lambda.hpp>
#include <iostream>
#include<vector>
#include "graph.h"

#define BOOST_TEST_MODULE MyTest
#include <boost/test/unit_test.hpp>
#include <boost/test/test_tools.hpp>



BOOST_AUTO_TEST_CASE(IsEmptyGraphConsistent_test)
{
	Graph graph;
	BOOST_CHECK(graph.isConsistent());
}
BOOST_AUTO_TEST_CASE(IsNonConsistent_test)
{
	std::vector< std::pair<int, int> > edges;
	std::pair<int, int> newEdge =std::make_pair(0, 1);
	edges.push_back(newEdge);
	newEdge = std::make_pair(2,3);
	edges.push_back(newEdge);
	Graph graph(4, edges);
	BOOST_CHECK(!graph.isConsistent());
}
BOOST_AUTO_TEST_CASE(IsNonEmptyConsistent_test)
{
	std::vector< std::pair<int, int> > edges;
	std::pair<int, int> newEdge=std::make_pair(0, 1);
	edges.push_back(newEdge);
	newEdge = std::make_pair(1, 2);
	edges.push_back(newEdge);
	Graph graph(3,edges);
	BOOST_CHECK(graph.isConsistent());
}
BOOST_AUTO_TEST_CASE(HaveGoodSizeTest_test)
{
	std::vector< std::pair<int, int> > edges;
	std::pair<int, int> newEdge =std::make_pair(0, 1);
	edges.push_back(newEdge);
	newEdge = std::make_pair(1, 2);
	edges.push_back(newEdge);
	Graph graph(3,edges);
	BOOST_CHECK(graph.numberOfVerticles()==3);
}
/*BOOST_AUTO_TEST_CASE(Empty_Copy_Constructor_test)
{
	std::vector< std::pair<int, int> > edges;
	std::pair<int, int> newEdge = std::make_pair(0, 1);
	edges.push_back(newEdge);
	newEdge = std::make_pair(1, 2);
	edges.push_back(newEdge);
	Graph graph(3,edges);
	Graph testGraph = graph;
	BOOST_CHECK(graph.numberOfVerticles()==3);
	//BOOST_CHECK(graph.connectedVerticles == testGraph.connectedVerticles);
//	BOOST_CHECK(graph != testGraph);
}*/
BOOST_AUTO_TEST_CASE(IsEdgeImportant_test)
{
	std::vector< std::pair<int, int> > edges;
	std::pair<int, int> newEdge = std::make_pair(0, 1);
	edges.push_back(newEdge);
	newEdge = std::make_pair(1, 2);
	edges.push_back(newEdge);
	newEdge = std::make_pair(1, 3);
	edges.push_back(newEdge);
	newEdge = std::make_pair(0, 3);
	edges.push_back(newEdge);
	Graph graph(4, edges);
	BOOST_CHECK(graph.isEdgeImportant(*edges.begin())==1);
	BOOST_CHECK(!graph.isEdgeImportant(*(edges.begin()+1)));
	BOOST_CHECK(graph.isEdgeImportant(*(edges.begin()+2)));
	BOOST_CHECK(!graph.isEdgeImportant(*(edges.begin()+3)));
}



// g++ GraphTests.cpp -o test -DBOOST_TEST_DYN_LINK -lboost_unit_test_framework