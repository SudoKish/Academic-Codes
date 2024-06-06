/*
1. Consider telephone book database of N clients.
Make use of a hash table implementation to quickly look up client‘s telephone number.
Make use of two collision handling techniques and compare them 
using number of comparisons required to find a set of telephone numbers

*/



#include <iostream>
using namespace std;

// Store details : Node-> Key Name Telephone 
class node{
    private:
        string name;
        string telephone;
        int key;
    public:
        node(){
            key=0;
        }
        friend class hashing;   // To access the private members of class node
};

// Hashng Fuction that generates different key value
// Sum of ascii value of each character in string
int ascii_generator(string s){
    int sum=0;
    for (int i = 0; s[i] != '\0'; i++)
        sum = sum + s[i];
    return sum%100;
}

// Class -> Hashing
class hashing{
    private:
        node data[100]; // Size of directory -> 100
        string n;
        string tele;
        int k, index;
        int size=100;
    public:
        hashing(){
            k=0;
        }

        // Function to create record
        void create_record(string n,string tele){
            k=ascii_generator(n);   //using ascii value of string as key
            index=k%size;   
            for (int j=0;j<size;j++){
                if(data[index].key==0){
                    data[index].key=k;
                    data[index].name=n;
                    data[index].telephone=tele;
                    break;
                }
                else
                    index=(index+1)%size;
            }
        }

        // Function to search for record based on name input
        void search_record(string name){
            int index1,k,flag=0;
            k=ascii_generator(name);
            index1=k%size;

            for(int a=0;a<size;a++){
                if(data[index1].key==k){
                    flag=1;
                    cout<<"\nRecord found\n";
                    cout<<"Name :: "<<data[index1].name<<endl;
                    cout<<"Telephone :: "<<data[index1].telephone<<endl;
                    break;
                }
                else
                    index1=(index1+1)%size;
            }
            if(flag==0)
                cout<<"Record not found";
        }

        // Function to delete existing record
        void delete_record(string name){
            int index1,key,flag=0;
            key=ascii_generator(name);
            index1=key%size;

            for(int a=0;a<size;a++){
                if(data[index].key==key){
                    flag=1;
                    data[index1].key=0;
                    data[index1].name=" ";
                    data[index1].telephone=" ";
                    cout<<"\nRecord Deleted successfully"<<endl;
                    break;
                }
                else
                    index1=(index1+1)%size;
            }
            if(flag==0)
                cout<<"\nRecord not found";
        }

        // Function to update existing record
        void update_record(string name){
            int index1,key,flag=0;
            key=ascii_generator(name);
            index1=key%size;

            for(int a=0;a<size;a++){
                if(data[index1].key==key){
                    flag=1;
                    break;
                }
                else
                    index1=(index1+1)%size;
            }

            if(flag==1){
                cout<<"Enter the new telephone number :: ";
                cin>>tele;
                data[index1].telephone=tele;
                cout<<"\nRecord Updated successfully";
            }
        }

        // Function to display the directory
        void display_record(){
            cout<<"\t  Name  \t\t Telephone";
            for (int a = 0; a < size; a++) {
                if(data[a].key!=0){
                    cout<<"\n\t"<<data[a].name<<" \t\t\t "<<data[a].telephone;
                }
            }
        }
};

// Main Function
int main(){
    hashing s;
    string name;
    string telephone;
    int choice,x;
    bool loop=1;
    // Menu driven code
    while(loop){
        cout<<"\n-------------------------"<<endl
            <<" Telephone book Database "<<endl
            <<"-------------------------"<<endl
            <<"1. Create Record"<<endl
            <<"2. Display Record"<<endl
            <<"3. Search Record"<<endl
            <<"4. Update Record"<<endl
            <<"5. Delete Record"<<endl
            <<"6. Exit"<<endl
            <<"Enter choice :: ";
        cin>>choice;
        switch (choice)
        {
        case 1:
            cout<<"\nEnter name :: ";
            cin>>name;
            cout<<"Enter Telephone number :: ";
            cin>>telephone;
            s.create_record(name,telephone);
            break;
        
        case 2:
            s.display_record();
            break;

        case 3:
            cout<<"\nEnter the name :: ";
            cin>>name;
            s.search_record(name);
            break;

        case 4:
            cout<<"\nEnter the name :: ";
            cin>>name;
            s.update_record(name);
            break;

        case 5:
            cout<<"\nEnter name to Delete :: ";
            cin>>name;
            s.delete_record(name);
            break;

        case 6:
            loop=0;
            break;

        default:
            cout<<"\nYou Entered something wrong!";
            break;
        }
    }   
    return 0;
}


/*

Theory:
Space Complexity:
Separate Chaining: Requires additional space to store pointers for linked lists in each bucket.
Open Addressing: Space efficiency depends on the load factor and the number of elements stored. With a low load factor, open addressing can be more space-efficient as it avoids the overhead of maintaining linked lists.
Collision Resolution:
Separate Chaining: Collisions are resolved by chaining elements in linked lists, which doesn't require moving existing elements.
Open Addressing: Collisions are resolved by finding alternative slots, which may involve additional computation to find the next available slot.
Performance in Dense and Sparse Data:
Separate Chaining: Works well with sparse data (low load factor) but may degrade in performance with dense data due to longer linked lists.
Open Addressing: Can be more suitable for dense data as it avoids the overhead of maintaining linked lists, but clustering can occur, leading to degraded performance.
Empirical Comparison:
Experimental Setup:
Generate a large dataset of telephone numbers and associated keys.
Implement both separate chaining and open addressing hash tables.
Vary the load factor and measure the number of comparisons required to find a set of telephone numbers.
Observations:
Compare the performance of separate chaining and open addressing under different load factors.
Consider scenarios with varying key distributions (uniform, clustered, etc.).
Evaluate the impact of hash function quality on collision resolution and overall performance.
Conclusion:
Based on empirical results, draw conclusions about which collision handling technique performs better under specific conditions.
Consider factors like average and worst-case performance, memory usage, and ease of implementation.
Real-World Considerations:
Implementation Overhead:
Consider the complexity and overhead of implementing each collision handling technique, including memory management and handling edge cases.
Dynamic Resizing:
Evaluate the impact of dynamic resizing on performance for both collision handling techniques. Resizing can become more frequent with open addressing as the load factor increases.
Concurrency:
Assess the concurrency support of each collision handling technique. Separate chaining may offer better concurrency due to independent linked lists, while open addressing may require additional synchronization mechanisms.

Conclusion:

For small to moderate-sized hash tables with low load factors, separate chaining may perform better due to its simplicity and ability to handle collisions efficiently.
For hash tables with high load factors or when memory is a concern, open addressing techniques may be preferable, but the specific technique used and its performance can depend heavily on factors like the hash function and the distribution of keys.
*/