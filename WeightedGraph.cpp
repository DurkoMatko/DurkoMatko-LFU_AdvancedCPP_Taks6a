#include "WeightedGraph.h"
#include <iostream>
#include <stdexcept>
#include <climits>
#include <limits.h>

struct NameAlreadyUsedException2: public std::exception{
  virtual const char* what() const throw(){
    return "Vertice id already in use";
  }
};


WeightedGraph::WeightedGraph()
{
    std::cout << "Derived weighted constructor without parameters" <<std::endl;
}

WeightedGraph::WeightedGraph(unsigned n, bool isConnected) : Graph(n,isConnected){
	std::cout << "Derived weighted constructor with parameters" <<std::endl;

	//define random generator needed
	std::random_device rd; // obtain a random number from hardware
    std::mt19937 eng(rd()); // seed the generator
	std::uniform_int_distribution<> distanceGenerator(1, 256);

	//add random values to already existing edges
	for(auto &nodeEdgesPair : adjacencyList){
		for(auto &edge : nodeEdgesPair.second){
			edge.second = distanceGenerator(eng);
		}
	}
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

int WeightedGraph::getWeight(int v, int w) const{
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
