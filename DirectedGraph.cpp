#include "DirectedGraph.h"
#include <iostream>

DirectedGraph::DirectedGraph()
{
    std::cout << "Derived directed graph constructor without parameters" <<std::endl;
}


void DirectedGraph::addEdge(int firstVertex, int secondVertex){
	try{
		if(this->vertexExists(firstVertex) && this->vertexExists(secondVertex)){
			adjacencyList.at(firstVertex).push_back(std::make_pair(secondVertex,NULL));
			//adjacencyList.at(secondVertex).push_back(std::make_pair(firstVertex,dist));	
		}
		else{
			throw std::out_of_range("Vertex does not exist");	
		}
	}
	catch(const std::out_of_range& oor){
		std::cerr << "Out of Range error - addEdge(" << firstVertex << ", " << secondVertex << ") " << oor.what() <<  '\n';
	}
}