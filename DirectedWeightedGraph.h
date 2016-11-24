#ifndef DIRECTED_WEIGHTED_GRAPH_H_INCLUDED
#define DIRECTED_WEIGHTED_GRAPH_H_INCLUDED

#include "WeightedGraph.h"

class DirectedWeightedGraph : public WeightedGraph {
	public:
		DirectedWeightedGraph();
		void addEdge(int firstVertex, int secondVertex, int dist);
	protected:
	private:
};


#endif //DIRECTED_WEIGHTED_GRAPH_H_INCLUDED