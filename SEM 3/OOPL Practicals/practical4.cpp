/*
Write a C++ program that creates an output file, writes information to it, closes the file, open it again as an input file and read the information from the file.
*/

#include <iostream>
#include <fstream>
using namespace std;
class Employee 
{
    string Name;
    int ID;
    double salary;

public:
    void accept()
    {
        cout << "\n Name : ";
        cin.ignore();
        getline(cin, Name);
        cout << "\n Id : ";
        cin >> ID;
        cout << "\n Salary : ";
        cin >> salary;
    }
    void display()
    {
        cout << "\n Name : " << Name;
        cout << "\n Id : " << ID;
        cout << "\n Salary : " << salary << endl;
    }
};

int main()
{
    Employee o[5];
    fstream f;
    int i, n;

    f.open("demo.txt", ios::out);
    cout << "\n Enter the number of employees you want to store : ";
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cout << "\n Enter information of Employee " << i + 1 << "\n";
        o[i].accept();
        f.write((char *)&o[i], sizeof o[i]);
    }

    f.close();

    f.open("demo.txt", ios::in);
    cout << "\n Information of Employees is as follows : \n";
    for (i = 0; i < n; i++)
    {
        cout << "\nEmployee " << i + 1 << "\n";
        f.write((char *)&o[i], sizeof o[i]);
        o[i].display();
    }
    f.close();

    return 0;
}

/*

Title: Demonstrate various file operations using C++.


Theory:
The iostream library is an object-oriented library that provides input and output
functionality using streams. A stream is an abstraction that represents a device on which
input and ouput operations are performed. A stream can basically be represented as a
source or destination of characters of indefinite length.

Streams are generally associated to a physical source or destination of characters, like a
disk file, the keyboard, or the console, so the characters gotten or written to/from our
abstraction called stream are physically input/output to the physical device. For example,
file streams are C++ objects to manipulate and interact with files; Once a file stream is
used to open a file, any input or output operation performed on that stream is physically
reflected in the file.
So far, we have been using the iostream standard library, which provides cin and cout
methods for reading from standard input and writing to standard output respectively.
This tutorial will teach you how to read and write from a file. This requires another
standard C++ library called fstream, which defines three new data types:


Conclusion: Hence, we have studied and learnt various file handling operations and
methods available in fstream header file.

*/