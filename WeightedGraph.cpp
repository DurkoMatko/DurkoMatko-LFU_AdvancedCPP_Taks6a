#include "WeightedGraph.h"
#include <iostream>
#include <stdexcept>
#include <climits>
#include <limits.h>
#include <set>


struct NameAlreadyUsedException2: public std::exception{
  virtual const char* what() const throw(){
    return "Vertice id already in use";
  }
};


WeightedGraph::WeightedGraph()
{
    std::cout << "Derived weighted constructor without parameters" <<std::endl;
}

void WeightedGraph::print(std::ostream& os) const{
    //here I have to iterate keys - because user can add vertex with random ID
	for(auto iter = adjacencyList.cbegin(); iter != adjacencyList.cend(); ++iter){		
		os << "Vertice " << iter->first << ":" << std::endl;
		//iterate list of pairs representing edges to other vertices
		for(const auto& onePair : adjacencyList.at(iter->first)){
			os << "\t" << onePair.first << "-" << onePair.second << std::endl;
		}
		os << std::endl;
	}
}

void WeightedGraph::addEdge(int firstVertex, int secondVertex,int dist){
	try{
		if(this->vertexExists(firstVertex) && this->vertexExists(secondVertex)){
			adjacencyList.at(firstVertex).push_back(std::make_pair(secondVertex,dist));
			adjacencyList.at(secondVertex).push_back(std::make_pair(firstVertex,dist));	
		}
		else{
			throw std::out_of_range("Vertex does not exist");	
		}
	}
	catch(const std::out_of_range& oor){
		std::cerr << "Out of Range error - addEdge(" << firstVertex << ", " << secondVertex << "," << dist << ") " << oor.what() <<  '\n';
	}
}


int WeightedGraph::getWeight(int v, int w){
	if(this->vertexExists(v) && this->vertexExists(w)){
		for(const auto& edge : adjacencyList.at(v)){
			if(edge.first == w){
				return edge.second;
			}
		}
	}
	else
		return -1;
}


int WeightedGraph::minPath(int source,int target){
	//create map of minimal distances to all nodes
	std::map<int,int> min_distance;
	for(const auto &listElement : adjacencyList){
		min_distance[listElement.first] = INT_MAX;
	}

	min_distance[ source ] = 0;
	//map of <target,distance> pairs
	std::map<int,int> active_vertices;
	active_vertices.insert( std::make_pair(source,0) );

	while (!active_vertices.empty()) {
		//get first node in "queue" to inspect its edges
		int current = active_vertices.begin()->first;
		if (current == target) {
			return min_distance[current];
		}
		//delete current visited one
		active_vertices.erase(current);

		//loop edges for current node
		for (const auto &edge : adjacencyList.at(current)){
			//if min distance to current + value of ispected edge < so far possible min to inspected edge, then overwrite to new value
			if( (min_distance[current] + edge.second) < min_distance[edge.first]){
				min_distance[edge.first] = min_distance[current] + edge.second;
				//insert or overwrite
				active_vertices[edge.first] = min_distance[edge.first];
			}
		}
	}

	return -1;
}