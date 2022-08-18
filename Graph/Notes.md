<!-- /********************************************************************************************* -->
Notes :
Adjecncy List of weighted graph
array of vectors
vector<pair<int,int> adjList []

Forest : group of components 


Always assume there are several components in graph so always loop for every node


BFS or Breadth-First Traversal of a graph is an algorithm used to visit all of the nodes of a given graph. In this traversal algorithm, one node is selected, and then all of the adjacent nodes are visited one by one.

An undirected graph is a graph where all the edges are bidirectional, i.e., they point from source to destination and destination to source.

A graph is disconnected if at least two vertices of the graph are not connected by a path.


A Directed Acyclic Graph (DAG) is a directed graph that contains no cycles.
Topological Sorting of DAG is a linear ordering of vertices such that for every directed edge from vertex ‘u’ to vertex ‘v’, vertex ‘u’ comes before ‘v’ in the ordering. Topological Sorting for a graph is not possible if the graph is not a DAG.
Note that there are multiple topological sortings possible for a DAG.
<!-- **********************************************************************************************/ -->