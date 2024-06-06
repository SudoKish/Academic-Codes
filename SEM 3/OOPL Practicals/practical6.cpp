/*
Write C++ program using STL for Sorting and searching with user-defined records such as
Person Record (Name, birth date, telephone no), item record (item code, item name, quantity
and cost)
*/
#include <iostream>    
#include <algorithm>    
#include <vector>   

using namespace std;
class Item       
{
      public:   
          char name[10];
        int quantity;
        int cost;
        int code;

        bool operator==(const Item& i1)    
    {
        if(code==i1.code)    
        return 1;
        return 0;
    }

    bool operator<(const Item& i1)
    {
        if(code<i1.code)                                            
        return 1;
        return 0;
    }

};

vector<Item> o1;
void print(Item &i1);
void display();
void insert();
void search();
void dlt();

bool compare(const Item &i1, const Item &i2)
{
   return i1.cost < i2.cost;
}

int main()
{
    int ch;
      do
    {  
        cout<<"\n***** Menu *****";
        cout<<"\n1.Insert";
        cout<<"\n2.Display";
        cout<<"\n3.Search";
        cout<<"\n4.Sort";
        cout<<"\n5.Delete";
        cout<<"\n6.Exit";
        cout<<"\nEnter your choice:";
        cin>>ch;
       
        switch(ch)
        {
               case 1:
                          insert();
                          break;
                   
               case 2:
                          display();
                          break;
                   
               case 3:
                         search();
                         break;
                              
               case 4:
                        sort(o1.begin(),o1.end(),compare);
                        cout<<"\n\n Sorted on Cost";
                        display();
                        break;
                  
               case 5:
                       dlt();
                        break;
                     
               case 6:
                        exit(0);
        }
   
    }while(ch!=7);

      return 0;
}

void insert()
{
    Item i1;
    cout<<"\nEnter Item Name:";
    cin>>i1.name;
    cout<<"\nEnter Item Quantity:";
    cin>>i1.quantity;
    cout<<"\nEnter Item Cost:";
    cin>>i1.cost;
    cout<<"\nEnter Item Code:";
    cin>>i1.code;
    o1.push_back(i1);
}

void display()
{
    for_each(o1.begin(),o1.end(),print);
}

void print(Item &i1)
{
     cout<<"\n";
     cout<<"\nItem Name:"<<i1.name;
     cout<<"\nItem Quantity:"<<i1.quantity;
     cout<<"\nItem Cost:"<<i1.cost;
     cout<<"\nItem Code:"<<i1.code;
}

void search()
{
    vector<Item>::iterator p;
    Item i1;
    cout<<"\nEnter Item Code to search:";
    cin>>i1.code;
    p=find(o1.begin(),o1.end(),i1);
    if(p==o1.end())
    {
         cout<<"\nNot found.";
    }
    else
    {
         cout<<"\nFound.";
    }
}

void dlt()
{
     vector<Item>::iterator p;
    Item i1;
    cout<<"\nEnter Item Code to delete:";
    cin>>i1.code;
    p=find(o1.begin(),o1.end(),i1);
    if(p==o1.end())
    {
         cout<<"\nNot found.";
    }
    else
    {
         o1.erase(p);
         cout<<"\nDeleted.";
    }
}

/*
Title: Personnel information system using sorting and searching for STL and vector
container.

STL:
The Standard Template Library (STL) is a set of C++ template classes to provide common
programming data structures and functions such as lists, stacks, arrays, etc. It is a library of container
classes, algorithms, and iterators. It is a generalized library and so, its components are parameterized.
A working knowledge of template classes is a prerequisite for working with STL.
STL has four components
 Algorithms
 Containers
 Functions
 Iterators
Algorithms
 The algorithm defines a collection of functions especially designed to be used on ranges of
elements.They act on containers and provide means for various operations for the contents of
the containers.
 Algorithm
 Sorting
 Searching
 Important STL Algorithms
 Useful Array algorithms
 Partition Operations
 Numeric

Conclusion:
Hence, we have successfully studied the concept of STL(Standard Template Library) and how it
makes many data structures easy. It briefs about the predefined functions of STL and their uses such
a search() and sort()

*/