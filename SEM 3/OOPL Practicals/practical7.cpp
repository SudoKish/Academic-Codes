/*pratical 7
 */

#include <iostream>
#include <map>
#include <string>
#include <utility>

using namespace std;

int main()
{
	typedef map<string,int> mapType;
	mapType populationMap;
	
	populationMap.insert(make_pair("Maharashtra", 125));
	populationMap.insert(make_pair("Uttar Pradesh", 225));
	populationMap.insert(make_pair("Bihar", 120)); 
	populationMap.insert(make_pair("West Bengal", 100)); 
	populationMap.insert(make_pair("Madhya Pradesh", 90)); 
	populationMap.insert(make_pair("Tamil Nadu", 80)); 
	populationMap.insert(make_pair("Rajasthan", 78));
	populationMap.insert(make_pair("Andhra Pradesh", 53));
	populationMap.insert(make_pair("Odisha", 47));
	populationMap.insert(make_pair("Kerala", 38));
	populationMap.insert(make_pair("Telangana", 37));
	populationMap.insert(make_pair("Assam", 35));
	populationMap.insert(make_pair("Jharkhand", 38));
	populationMap.insert(make_pair("Karnataka", 68));
	populationMap.insert(make_pair("Gujarat", 70));
	populationMap.insert(make_pair("Punjab", 31));
	populationMap.insert(make_pair("Chhattisgarh", 30));
	populationMap.insert(make_pair("Haryana", 29));
	populationMap.insert(make_pair("UT Delhi", 19));
	populationMap.insert(make_pair("UT Jammu and Kashmir", 14));
	populationMap.insert(make_pair("Uttarakhand", 12));
	populationMap.insert(make_pair("Himachal Pradesh", 8));
	populationMap.insert(make_pair("Tripura", 04));
	populationMap.insert(make_pair("Meghalaya", 4));
	populationMap.insert(make_pair("Manipur[", 3));
	populationMap.insert(make_pair("Nagaland", 2));
	populationMap.insert(make_pair("Goa", 2));
	populationMap.insert(make_pair("Arunachal Pradesh", 2));
	populationMap.insert(make_pair("UT Puducherry", 2));
	populationMap.insert(make_pair("Mizoram", 1));
	populationMap.insert(make_pair("UT Chandigarh", 1));
	populationMap.insert(make_pair("Sikkim", 1));
	populationMap.insert(make_pair("UT Dadra and Nagar Haveli and Daman and Diu", 1));
	populationMap.insert(make_pair("UT Andaman and Nicobar Islands", 1));
	populationMap.insert(make_pair("UT Lakshadweep", 0.0003));
	populationMap.insert(make_pair("UT Ladakh", 0.00006));
	
	mapType::iterator iter = --populationMap.end();
	populationMap.erase(iter);
	 
	cout << "Total state and UT of India with Size of populationMap: " << populationMap.size() << '\n';
	
	for (iter = populationMap.begin(); iter != populationMap.end(); ++iter) 
	{
	 cout << iter->first <<":" << iter->second << " million\n";
	}
	
	char c;
	do
	{
		string state;
		cout<<"\nEnter that state you want to know the population of: ";
		cin>>state;
		iter = populationMap.find(state);
		if( iter != populationMap.end() ) 
		    cout << state <<"'s populations is "
		        << iter->second << " million\n";
		else
		    cout << "State is not in populationMap" << '\n';
		    
		cout<<"Do you wish to continue?(y/n):";
		cin>>c;
	}while(c=='y'||c=='Y');
	 
	populationMap.clear();
	
	return 0;
}

/*

To use map associative container.
Write a program in C++ to use map associative container. The keys will be the
names of states and the values will be the populations of the states. When the
program runs, the user is prompted to type the name of a state. The program then
looks in the map, using the state name as an index and returns the population of the
state

Theory:

Map associative con
Map associative cont
element has a key va
This operator is used
to the at() function, th
the position is not in
Syntax :

tainer:
ainer are associative containers that store elements in a mapped fashion. Each
lue and a mapped value. No two mapped values can have same key values.

map::operator[]

to reference the element present at position given inside the operator. It is similar
e only difference is that the at() function throws an out-of-range exception when
the bounds of the size of map, while this operator causes undefined behaviour.


Conclusion:
Hence, we have successfully studied the concept of map associative container
*/