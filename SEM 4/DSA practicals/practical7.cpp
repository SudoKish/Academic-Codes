
/*
You have a business with several offices; you want to lease phone lines to connect them up with
each other; and the phone company charges different amounts of money to connect different
pairs of cities. You want a set of lines that connects all your offices. with a minimum total cost.
Solve the problem by suggesting appropriate data structures.
*/

#include<iostream>
using namespace std;

class tree
{
	int a[20][20],l,u,w,i,j,v,e,visited[20];
public:
	void input();
	void display();
	void minimum();
};

void tree::input()
{
	cout<<"Enter the no. of branches: ";
	cin>>v;

	for(i=0;i<v;i++)
	{
		visited[i]=0;
		for(j=0;j<v;j++)
		{
			a[i][j]=999;
		}
	}

	cout<<"\nEnter the no. of connections: ";
	cin>>e;

	for(i=0;i<e;i++)
	{
		cout<<"Enter the end branches of connections:  "<<endl;
		cin>>l>>u;
		cout<<"Enter the phone company charges for this connection:  ";
		cin>>w;
		a[l-1][u-1]=a[u-1][l-1]=w;
	}
}

void tree::display()
{
	cout<<"\nAdjacency matrix:";
	for(i=0;i<v;i++)
	{
		cout<<endl;
		for(j=0;j<v;j++)
		{
			cout<<a[i][j]<<"   ";
		}
		cout<<endl;
	}
}

void tree::minimum()
{
	int p=0,q=0,total=0,min;
	visited[0]=1;
	for(int count=0;count<(v-1);count++)
	{
		min=999;
		for(i=0;i<v;i++)
		{
			if(visited[i]==1)
			{
				for(j=0;j<v;j++)
				{
					if(visited[j]!=1)
					{
						if(min > a[i][j])
						{
							min=a[i][j];
							p=i;
							q=j;
						}
					}
				}
			}
		}
		visited[p]=1;
		visited[q]=1;
		total=total+min;
		cout<<"Minimum cost connection is"<<(p+1)<<" -> "<<(q+1)<<"  with charge : "<<min<< endl;
		
	}
	cout<<"The minimum total cost of connections of all branches is: "<<total<<endl;
}

int main()
{
	int ch;
	tree t;
	do
	{
		cout<<"==========PRIM'S ALGORITHM================="<<endl;
		cout<<"\n1.INPUT\n \n2.DISPLAY\n \n3.MINIMUM\n"<<endl;
		cout<<"Enter your choice :"<<endl;
		cin>>ch;
	
	switch(ch)
	{	
	case 1: cout<<"*******INPUT YOUR VALUES*******"<<endl;	
		t.input();
		break;

	case 2: cout<<"*******DISPLAY THE CONTENTS********"<<endl;
		t.display();
		break;

	case 3: cout<<"*********MINIMUM************"<<endl;
		t.minimum();
		break;
	}
	
	}while(ch!=4);
	return 0;
}

/*Theory:
Graph Representation:
Represent the offices as nodes in a graph, with the cost of connecting each pair of offices as the weight of the corresponding edge.
This problem can be modeled as a weighted undirected graph, where each node represents an office and each edge represents a phone line connecting two offices.
Minimum Spanning Tree (MST):
The objective is to find a spanning tree of the graph that connects all offices with minimum total cost.
The Minimum Spanning Tree (MST) of a graph is a subset of edges that connects all nodes with the minimum possible total edge weight.
Data Structures:
Graph: Use an adjacency list or adjacency matrix to represent the graph.
Priority Queue (Min-Heap): Use a priority queue to efficiently select the next edge with the minimum weight during MST construction.
Union-Find Data Structure: Use Union-Find (Disjoint Set) to efficiently detect and avoid cycles during MST construction.
Data Structures Justification:
Graph Representation:
For sparse graphs (where the number of edges is much smaller than the number of nodes), an adjacency list is more space-efficient. It only stores information about connected nodes, reducing memory usage.
For dense graphs, an adjacency matrix may be more suitable, offering constant-time access to edge weights.
Priority Queue:
A priority queue, implemented as a min-heap, allows efficient retrieval of the edge with the minimum weight. This is essential for Kruskal's or Prim's algorithm, which are commonly used to find MSTs.
Union-Find Data Structure:
Union-Find data structure efficiently maintains disjoint sets and facilitates cycle detection during MST construction. It is crucial for Kruskal's algorithm, which relies on detecting and avoiding cycles.
Time and Space Complexity:
Graph Construction:
Time Complexity: O(E), where E is the number of edges (phone lines) connecting the offices.
Space Complexity: O(V + E) for adjacency list representation, where V is the number of vertices (offices).
Minimum Spanning Tree Construction:
Both Kruskal's and Prim's algorithms have time complexity of O(E log V), where V is the number of vertices and E is the number of edges.
Space Complexity: O(V + E) for maintaining the priority queue and Union-Find data structure.
Real-World Considerations:
Edge Costs:
Ensure that the costs associated with each edge accurately reflect the charges imposed by the phone company for connecting pairs of offices.
Efficiency vs. Accuracy:
Consider the trade-off between algorithmic efficiency and the accuracy of cost calculations. Sometimes, simpler algorithms may be preferred for practical implementation.
Dynamic Graphs:
If the connectivity requirements between offices change frequently, consider dynamic algorithms or data structures to adapt to changes efficiently.
Conclusion:
Using appropriate graph-based data structures like adjacency lists, priority queues, and Union-Find, you can efficiently solve the problem of finding the minimum cost set of lines that connect all offices in your business. By leveraging algorithms like Kruskal's or Prim's, you can find the Minimum Spanning Tree, ensuring optimal connectivity at minimum cost.*/