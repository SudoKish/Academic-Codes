/*

There are flight paths between cities. If there is a flight between city A and city B then there is an
edge between the cities. The cost of the edge can be the time that flight take to reach city B from
A, or the amount of fuel used for the journey. Represent this as a graph. The node can be
represented by airport name or name of the city. Use adjacency list representation of the graph or
use adjacency matrix representation of the graph. Check whether the graph is connected or not.
Justify the storage representation used.

*/

#include <iostream>
#include<queue>
#define n 10        // max size for adjacency matrix
int adj_m[n][n];    // adjaceny matrix declaration

void traverse(int u,int x, bool visited[]){
    visited[u] = true; //mark vertex as visited
    for(int v = 0; v<x; v++){
        if(adj_m[u][v]!=0){
            //check if visited; if not visited traverse again
            if(!visited[v])
                traverse(v,x, visited);
      }
   }
}
bool isConnected(int x){
    bool *vis = new bool[n];
    // here we consider u as start point=0(city 1) which can also be dyanmically allocated
    for(int u=0; u < x; u++){
        for(int i = 0; i<x; i++)
            vis[i] = false;     //initialize as no node is visited
            traverse(u,x, vis); //As we call the function we update the visited array
            for(int i = 0; i<x; i++){
                if(!vis[i]) 
                //if there is a node, not visited we can conclude graph is not connected
                    return false;
      }
   }
   return true;
}

using namespace std;
int main(){
    int x; //Number of cities
    cout<<"Enter number of cities :: ";
    cin>>x;

    //Input cities
    char arr[x][20];
    for (int i=0;i<x;i++){
        cout<<"Enter "<<i+1<<" city name :: ";
        cin>>arr[i];
    }
    
    //adjacency matrix
    for(int i=0;i<x;i++){
        for(int j=0;j<x;j++)
        {
            cout<<"\nIs city "<<arr[i]<<" connected to city "<<arr[j]<<endl
                <<"Enter y if yes :: ";
            char ch;
            cin>>ch;
            if(ch=='y' || ch=='Y')
            {
                int a;
                cout<<"Enter fuel reuired to go from "<<arr[i]<<" to "<<arr[j]<<"\n"
                    <<"Enter :: ";
                cin>>a;
                adj_m[i][j]=a;
            }
            else
            {
                adj_m[i][j]=0;
            }
        }
        cout<<"\n-------------------------------\n";
    }
    
    //Printing adjacency matrix
    cout<<"ADJ MAT\n";
    for(int i=0;i<x;i++){
        for(int j=0;j<x;j++){
            cout<<adj_m[i][j]<<"\t";
        }
        cout<<"\n";
    }
    cout<<"\n-------------------------------\n";
    if(isConnected(x))
        cout << "The Graph is connected.";
    else
        cout << "The Graph is not connected.";
    
    return 0;
}

/*

Theory:
Graph Representation:
Represent flight paths between cities as a graph, where each city is a node and each flight path is an edge.
The cost of an edge can represent the time taken for the flight or the amount of fuel used for the journey.
Adjacency List Representation:
In the adjacency list representation, each node (city) is associated with a list of its adjacent nodes (cities), along with the corresponding edge costs.
This representation is space-efficient for sparse graphs (graphs with fewer edges) since it only stores information about connected nodes.
Connectivity:
A graph is connected if there is a path between every pair of vertices (cities) in the graph.
To check for connectivity, perform a depth-first or breadth-first traversal starting from a node and ensure that all nodes are visited.
Storage Representation Justification:
Adjacency List:
Advantages:
Space-efficient for sparse graphs, which is common for flight networks where not all cities are directly connected.
Allows for efficient access to neighbors of each node.
Compact representation, especially for large graphs.
Justification:
Flight networks typically exhibit a sparse connectivity pattern, with many cities having a limited number of direct flight connections. Using an adjacency list representation conserves memory by only storing information about connected cities, making it well-suited for this scenario.
Connectivity Check:
Algorithm:
Choose any node as the starting point.
Perform a depth-first or breadth-first traversal from the starting node, marking visited nodes.
If all nodes are visited, the graph is connected; otherwise, it's disconnected.
Time Complexity:
Depth-first or breadth-first traversal takes O(V + E) time, where V is the number of vertices (cities) and E is the number of edges (flight paths).
Checking connectivity involves visiting all nodes once, so the time complexity is O(V + E).
Real-World Considerations:
Edge Costs:
Ensure that the cost associated with each edge accurately reflects the relevant metric for flight paths, such as travel time or fuel consumption.
Efficient Connectivity Checks:
For large graphs, consider optimizations like parallel processing or using specialized algorithms for connectivity checks to improve efficiency.
Graph Update Frequency:
Consider the frequency of updates to the flight network when choosing the storage representation. If the network changes frequently, a more dynamic representation may be necessary.
Conclusion:
Representing flight paths between cities as a graph using the adjacency list representation provides a space-efficient and effective way to model connectivity. Checking for graph connectivity can be efficiently performed using traversal algorithms. The choice of adjacency list representation is justified for its space efficiency, especially in scenarios where the graph exhibits sparse connectivity patterns.*/