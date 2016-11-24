#include "DirectedWeightedGraph.h"
#include <iostream>

DirectedWeightedGraph::DirectedWeightedGraph()
{
    std::cout << "Derived directed & weighted graph constructor without parameters" <<std::endl;
}


void DirectedWeightedGraph::addEdge(int firstVertex, int secondVertex,int dist){
	try{
		if(this->vertexExists(firstVertex) && this->vertexExists(secondVertex)){
			adjacencyList.at(firstVertex).push_back(std::make_pair(secondVertex,dist));
			//adjacencyList.at(secondVertex).push_back(std::make_pair(firstVertex,dist));	
		}
		else{
			throw std::out_of_range("Vertex does not exist");	
		}
	}
	catch(const std::out_of_range& oor){
		std::cerr << "Out of Range error - addEdge(" << firstVertex << ", " << secondVertex << "," << dist << ") " << oor.what() <<  '\n';
	}
}