/*

Read the marks obtained by students of second year in an online examination of particular
subject. Find out maximum and minimum marks obtained in that subject. Use heap data structure.
Analyze the algorithm.

*/

#include<iostream>
using namespace std;
class Heap
{
	int n;
	int *minheap,*maxheap;
	public:
	void get();
	void displayMin(){cout<<"Minimum marks are :"<<minheap[0]<<endl;}
	void displayMax(){cout<<"Maximum marks are :"<<maxheap[0]<<endl;}
	void upAdjust(bool,int);
};

void Heap::get()
{
	cout<<"Enter number of students."<<endl;
	cin>>n;
	int k;
	minheap=new int[n];
	maxheap=new int[n];
	cout<<"Enter marks of students."<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>k;
		minheap[i]=k;
		upAdjust(0,i);
		maxheap[i]=k;
		upAdjust(1,i);
	}
}

void Heap::upAdjust(bool m,int l)
{
	int s;
	if(!m)
	{
		while(minheap[(l-1)/2]<minheap[l])
		{
			s=minheap[l];
			minheap[l]=minheap[(l-1)/2];
			minheap[(l-1)/2]=s;
			l=(l-1)/2;
			if(l==-1)
				break;
		}
	}
	else
	{
		while(maxheap[(l-1)/2]>maxheap[l])
		{
			s=maxheap[l];
			maxheap[l]=maxheap[(l-1)/2];
			maxheap[(l-1)/2]=s;
			l=(l-1)/2;
			if(l==-1)
				break;
		}
	}
}

main()
{
	Heap H;
	H.get();
	H.displayMin();
	H.displayMax();
	return(0);
}

/*
Algorithm:
Build a Max-Heap:
Read the marks obtained by each student in the subject.
Insert each mark into a max-heap data structure.
Find Maximum Mark:
The maximum mark will be the root of the max-heap.
Find Minimum Mark:
To find the minimum mark, build a min-heap and repeat the process for finding the maximum mark. The minimum mark will be the root of the min-heap.
Analysis:
Building Max-Heap:
Time Complexity: O(n log n) using standard heap insertion for n marks.
Space Complexity: O(n) for storing the marks in the heap.
Finding Maximum Mark:
Time Complexity: O(1) as it only requires accessing the root of the max-heap.
Space Complexity: O(1).
Finding Minimum Mark:
Building the min-heap: O(n log n) similar to building the max-heap.
Finding the minimum mark: O(1) as it only requires accessing the root of the min-heap.
Overall Time Complexity: O(n log n).
Space Complexity: O(n) for storing the marks in the min-heap.
Real-World Considerations:
Handling Large Datasets:
Efficient implementation techniques should be employed for handling large datasets, such as using a binary heap or priority queue.
Error Handling:
Ensure proper error handling for cases where there are no marks or invalid inputs.
Optimization:
For a one-time operation, simple sorting algorithms like quicksort or mergesort may be more efficient than building a heap.
Conclusion:
Using a heap data structure allows us to efficiently find the maximum and minimum marks obtained by students in a particular subject. By analyzing the algorithm, we understand its time and space complexity, enabling us to make informed decisions regarding its implementation and potential optimizations.*/