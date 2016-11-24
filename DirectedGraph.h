#ifndef DIRECTED_GRAPH_H_INCLUDED
#define DIRECTED_GRAPH_H_INCLUDED

#include "Graph.h"

class DirectedGraph : public Graph {
	public:
		DirectedGraph();
		void addEdge(int firstVertex, int secondVertex);
	protected:
	private:
};


#endif //DIRECTED_GRAPH_H_INCLUDED