
#include "Graph.cpp"
#include "WeightedGraph.cpp"
#include "DirectedGraph.cpp"
#include "DirectedWeightedGraph.cpp"
#include <iostream>

int main(){
	/*
	//testing not connected graph
	Graph g(5,false);	//not connected graph with 5 vertexes
	g.addVertex(30);
	g.addEdge(3,30);
	g.addEdge(3,32);
	std::cout << g;
	std::cout <<"Connected: "<< g.isConnected() <<std::endl;


	//testing connected graph
	std::cout << "\n\n\nConnected graph" <<std::endl;
	Graph gConnected(7,true);
	std::cout << gConnected;
	std::cout <<"Connected: "<< gConnected.isConnected() <<std::endl;


	
	//testing const graph
	std::cout << "\n\n\nConst graph" <<std::endl;
	const Graph gConst(4,true);
	std::cout << gConst;

	//testing copy constructor
	std::cout << "\n\n\nCopied graph" <<std::endl;
	Graph gCopied(g);
	std::cout << gCopied;

	//testing copy assignment operator
	std::cout << "\n\n\nCopy-assigned graph" <<std::endl;
	gCopied = g;
	std::cout << gCopied;

	//testing move constructor
	std::cout << "\n\n\nMoved graph" <<std::endl;
	Graph gMoved = std::move(g);
	std::cout << gMoved;

	//testing move assignment constructor
	std::cout << "\n\n\nMove-assigned graph" <<std::endl;
	gMoved = std::move(gConnected);
	std::cout << gMoved;
	*/


	std::cout << "\n\n\nWeighted graph" <<std::endl;
	WeightedGraph weighted;
	weighted.addVertex(1);
	weighted.addVertex(2);
	weighted.addVertex(3);
	weighted.addVertex(4);
	weighted.addVertex(5);
	weighted.addVertex(6);
	weighted.addEdge(1,6,14);
	weighted.addEdge(1,2,7);
	weighted.addEdge(1,3,9);
	weighted.addEdge(2,3,10);
	weighted.addEdge(2,4,14);
	weighted.addEdge(6,3,2);
	weighted.addEdge(3,4,11);
	weighted.addEdge(6,5,9);
	weighted.addEdge(4,5,6);;
	std::cout << weighted  <<std::endl;
	if(weighted.getWeight(6,5)==weighted.getWeight(5,6))
		std::cout << "True" << std::endl;

	std::cout <<"Connected: "<< weighted.isConnected() <<std::endl;
	std::cout <<"MinPath: " << weighted.minPath(5,2) << std::endl;
	std::cout <<"MinPath: " << weighted.minPath(2,5) << std::endl;


	std::cout << "\n\n\nWeighted moved graph" <<std::endl;
	Graph gMoved2 = std::move(weighted);
	std:: cout << gMoved2;


	std::cout << "\n\n\nDirected graph" <<std::endl;
	DirectedGraph directed;
	directed.addVertex(1);
	directed.addVertex(2);
	directed.addVertex(3);
	directed.addVertex(4);
	directed.addVertex(5);
	directed.addVertex(6);
	directed.addEdge(1,6);
	directed.addEdge(1,2);
	directed.addEdge(1,3);
	directed.addEdge(2,3);
	directed.addEdge(2,4);
	directed.addEdge(6,3);
	directed.addEdge(3,4);
	directed.addEdge(6,5);
	directed.addEdge(4,5);;
	std::cout << directed  <<std::endl;
	std::cout <<"MinPath: " << directed.minPath(1,5) << std::endl;	   // 5 is reachable but can't reach
	std::cout <<"MinPath: " << directed.minPath(5,1) << std::endl;	   // 5 is reachable but can't reach


	std::cout << "\n\n\nDirected & weighted graph" <<std::endl;
	DirectedWeightedGraph directedWeighted;
	directedWeighted.addVertex(1);
	directedWeighted.addVertex(2);
	directedWeighted.addVertex(3);
	directedWeighted.addVertex(4);
	directedWeighted.addVertex(5);
	directedWeighted.addVertex(6);
	directedWeighted.addEdge(1,6,14);
	directedWeighted.addEdge(1,2,7);
	directedWeighted.addEdge(1,3,9);
	directedWeighted.addEdge(2,3,10);
	directedWeighted.addEdge(2,4,14);
	directedWeighted.addEdge(6,3,2);
	directedWeighted.addEdge(3,4,11);
	directedWeighted.addEdge(6,5,9);
	directedWeighted.addEdge(4,5,6);;
	if(directedWeighted.getWeight(5,6)==directedWeighted.getWeight(6,5))
		std::cout << "True" << std::endl;
	else
		std::cout << "False" << std::endl;
	std::cout << directedWeighted  <<std::endl;

	std::cout <<"MinPath: " << directed.minPath(1,5) << std::endl;	   // 5 is reachable but can't reach
	std::cout <<"MinPath: " << directed.minPath(5,1) << std::endl;	   // 5 is reachable but can't reach



	Graph graph2 = directedWeighted;				//OK
	Graph graph3 = weighted;						//OK
	WeightedGraph weighted2 = directedWeighted;		//OK
	//DirectedGraph directed2 = weighted;					//error
	//DirectedGraph directed3 = directedWeighted;			//error
	//WeightedGraph weighted3 = directed;					//error
	//DirectedWeightedGraph directedWeighted2 = directed;   //error
	


	return EXIT_SUCCESS;
}