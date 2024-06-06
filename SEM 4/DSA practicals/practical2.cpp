/*
2. Implement all the functions of a dictionary (ADT) using hashing and handle collisions 
using chaining with / without replacement. 
Data: Set of (key, value) pairs, Keys are mapped to values, Keys must be comparable, Keys must be unique.
Standard Operations: Insert(key, value), Find(key), Delete(key) 

*/
#include<iostream>
#include<string.h>

using namespace std;

struct data {
    char name[30];
    char name1[30];
};

class hashing {
    int n, sum, x, c, i, j;
    char na[30], na1[30];
    ::data d[10]; // Specify the namespace explicitly

public:
    hashing() {
        for (i = 0; i < 10; i++) {
            strcpy(d[i].name, "0");
            strcpy(d[i].name1, "0");
        }
    }
    void insert();
    void search();
    void delet();
    void display();
};

void hashing::insert() {
    cout << "\nEnter no. of words :: ";
    cin >> n;
    for (j = 0; j < n; j++) {
        cout << "\nEnter the word :: ";
        cin >> na;
        cout << "Enter the meaning :: ";
        cin >> na1;
        sum = 0;
        for (i = 0; i < strlen(na); i++) {
            sum += na[i];
        }
        x = (sum / strlen(na)) % 10;
        c = x;
        while (1) {
            if (!strcmp(d[x].name, "0")) {
                strcpy(d[x].name, na);
                strcpy(d[x].name1, na1);
                break;
            }
            x = (x + 1) % 10;
            if (c == x) {
                cout << "\nHash table is full";
                break;
            }
        }

    }
}
void hashing::search() {
    cout << "\nEnter word :: ";
    cin >> na;

    sum = 0;
    for (i = 0; i < strlen(na); i++) {
        sum += (int)na[i];
    }
    x = (sum / strlen(na)) % 10;
    c = x;
    while (1) {
        if (!strcmp(d[x].name, na)) {
            cout << "\nKey :: " << d[x].name << "\nMeaning :: " << d[x].name1;
            break;
        }
        x = (x + 1) % 10;
        if (c == x) {
            cout << "\nWord not found";
            break;
        }
    }
}
void hashing::delet() {
    cout << "\nEnter the word to be deleted :: ";
    cin >> na;

    sum = 0;
    for (i = 0; i < strlen(na); i++) {
        sum += (int)na[i];
    }
    x = (sum / strlen(na)) % 10;
    c = x;
    while (1) {
        if (!strcmp(d[x].name, na)) {
            cout << "\nKeyword " << d[x].name << " Deleted";
            strcpy(d[x].name, "0");
            strcpy(d[x].name1, "0");
            break;
        }
        x = (x + 1) % 10;
        if (c == x) {
            cout << "\nWord not found";
            break;
        }
    }
}
void hashing::display() {
    cout << "\nKey\tMeaning";
    cout << "\n----------------";
    for (int i = 0; i < 10; i++) {
        if (strcmp(d[i].name, "0")) {
            cout << endl << d[i].name << "\t" << d[i].name1;
        }
    }
    cout << "\n";
}

int main() {
    hashing h;
    int n, loop = 1;
    while (loop == 1) {
        cout << "\n\n-------------------------";
        cout << "\n       DICTIONARY        ";
        cout << "\n-------------------------";
        cout << "\n1.Insert";
        cout << "\n2.Display";
        cout << "\n3.Search";
        cout << "\n4.Delete";
        cout << "\n5.Exit";
        cout << "\nEnter :: ";
        cin >> n;
        switch (n) {
        case 1:
            h.insert();
            break;
        case 2:
            h.display();
            break;
        case 3:
            h.search();
            break;
        case 4:
            h.delet();
            break;
        case 5:
            loop = 0;
            cout << "\n-------------------------";
            break;
        default:
            cout << "\nYou entered something wrong";
        }
    }
    return 0;
}


/*
Theory:
Hashing:
Hashing is a technique that converts keys into a hash code, which is then used to index the data structure (hash table). This allows for efficient key-based retrieval operations.
Chaining:
Chaining is a collision resolution technique where each bucket in the hash table maintains a linked list of elements that hash to the same index. When a collision occurs, the new element is simply appended to the linked list at that index.
With Replacement:
With replacement, when a new element collides with an existing one, it replaces the existing element. This simplifies insertion but can lead to potential data loss.
Standard Operations:
Insert(key, value):
Compute the hash code for the key.
If the bucket at the hashed index is empty, insert the key-value pair.
If the bucket is not empty, traverse the linked list:
If the key already exists, update its value.
If the key doesn't exist, append the new key-value pair to the end of the linked list.
Find(key):
Compute the hash code for the key.
Traverse the linked list at the hashed index:
If the key is found, return its associated value.
If the key is not found, return an appropriate indication (e.g., null).
Delete(key):
Compute the hash code for the key.
Traverse the linked list at the hashed index:
If the key is found, remove the key-value pair from the linked list.
If the key is not found, return an appropriate indication (e.g., key not found).
Handling Collisions:
Chaining without Replacement:
When a collision occurs, simply append the new element to the end of the linked list at the hashed index.
Chaining with Replacement:
When a collision occurs, replace the existing key-value pair with the new one.
Real-World Considerations:
Load Factor:
Monitor the load factor of the hash table to determine when to resize the underlying array and rehash elements.
Linked List Efficiency:
Choose an efficient linked list implementation (e.g., singly linked list, doubly linked list) to minimize traversal times.
Collision Rate:
Track the collision rate and evaluate the performance of the chosen collision resolution strategy under different scenarios.
Hash Function Quality:
Use a high-quality hash function to distribute keys evenly across the hash table and minimize collisions.

*/