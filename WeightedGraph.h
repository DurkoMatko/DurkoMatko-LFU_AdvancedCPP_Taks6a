#ifndef WEIGHTED_GRAPH_H_INCLUDED
#define WEIGHTED_GRAPH_H_INCLUDED

#include "Graph.h"

class WeightedGraph : public Graph {
	public:
		WeightedGraph();
		void print(std::ostream& os) const;
		void addEdge(int firstVertex, int secondVertex,int dist);
		int getWeight(int v, int w);
		int minPath(int source,int target);
	protected:
	private:
};


#endif //WEIGHTED_GRAPH_H_INCLUDED