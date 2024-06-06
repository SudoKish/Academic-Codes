/*
Experiment Number 2 : Develop a program in C++ to create a database of
student’s information system
containing the following information: Name, Roll number, Class, Division,
Date of Birth, Blood group,
Contactaddress, Telephone number, Driving license no. and other. Construct
the database with
suitable member functions. Make use of constructor, default constructor,
copy constructor,
destructor, static member functions, friend class, this pointer, inline
code and dynamic
memory allocation operators-new and delete as well as exception handling.
*/

#include <iostream>
#include <string.h>
using namespace std;

class StudData;

class Student
{
    string name;
    int roll_no;
    string cls;
    char *division;
    string dob;
    char *bloodgroup;
    static int count;

public:
    Student() 
    {
        name = "";
        roll_no = 0;
        cls = "";
        division = new char;
        dob = "dd/mm/yyyy";
        bloodgroup = new char[4];
    }

    ~Student()
    {
        delete division;
        delete[] bloodgroup;
    }

    static int getCount()
    {
        return count;
    }

    void getData(StudData *);
    void dispData(StudData *);
};

class StudData
{
    string caddress;
    long int *telno;
    long int *dlno;
    friend class Student;

public:
    StudData()
    {
        caddress = "";
        telno = new long;
        dlno = new long;
    }

    ~StudData()
    {
        delete telno;
        delete dlno;
    }

    void getStudData()
    {
        cout << "Enter Contact Address : ";
        cin.get();
        getline(cin, caddress);
        cout << "Enter Telephone Number : ";
        cin >> *telno;
        cout << "Enter Driving License Number : ";
        cin >> *dlno;
    }

    void dispStudData()
    {
        cout << "Contact Address : " << caddress << endl;
        cout << "Telephone Number : " << *telno << endl;
        cout << "Driving License Number : " << *dlno << endl;
    }
};

inline void Student::getData(StudData *st)
{
    cout << "Enter Student Name : ";
    getline(cin, name);
    cout << "Enter Roll Number : ";
    cin >> roll_no;
    cout << "Enter Class : ";
    cin.get();
    getline(cin, cls);
    cout << "Enter Division : ";
    cin >> division;
    cout << "Enter Date of Birth : ";
    cin.get();
    getline(cin, dob);
    cout << "Enter Blood Group : ";
    cin >> bloodgroup;
    st->getStudData();
    count++;
}

inline void Student::dispData(StudData *st1)
{
    cout << "Student Name : " << name << endl;
    cout << "Roll Number : " << roll_no << endl;
    cout << "Class : " << cls << endl;
    cout << "Division : " << division << endl;
    cout << "Date of Birth : " << dob << endl;
    cout << "Blood Group : " << bloodgroup << endl;
    st1->dispStudData();
}

int Student::count;

int main()
{
    Student *stud1[100];
    StudData *stud2[100];
    int n = 0;
    char ch;

    do
    {
        stud1[n] = new Student;
        stud2[n] = new StudData;
        stud1[n]->getData(stud2[n]);
        n++;
        cout << "Do you want to add another student (y/n) : ";
        cin >> ch;
        cin.get();
    } while (ch == 'y' || ch == 'Y');

    for (int i = 0; i < n; i++)
    {
        cout << "---------------------------------------------------------------" << endl;
        stud1[i]->dispData(stud2[i]);
    }

    cout << "---------------------------------------------------------------" << endl;
    cout << "Total Students : " << Student::getCount();
    cout << endl
         << "---------------------------------------------------------------" << endl;

    for (int i = 0; i < n; i++)
    {
        delete stud1[i];
        delete stud2[i];
    }

    return 0;
}

/*

Title: Demonstrate basic concepts of object oriented programming for a class to store
details of student.

Theory :
Constructor:  Constructor is a special member function whose task is to initialize the
objects of it’s class. This is the first method that is run when an instance of a type is
created. A constructor is invoked whenever an object of its associated class is created. If
a class contains a constructor, then an object created by that class will be initialized
automatically. We pass data to the constructor by enclosing it in the parentheses
following the class name when creating an object
Characteristics of a constructor:
1. They should be declared in the public section
2. Constructor name and class name must ne same
3. They are invoked automatically when the objects are created.
4. They cannot be inherited
5. They cannot be virtual
Constructors are special member functions which are having some different properties
than that of the normal member functions of C++ class. They are special because they
shares exactly same name as that of class name and they gets called automatically when
the object of corresponding class is created in memory. In other words it means that
constructor is invoked whenever the object of associated class is created. It’s called
constructor because it construct the values of data members of class.
A constructor is declared and defined as :
class Sample
{

int  a, b;
public:
Sample();
};
Sample :: Sample ()
{
a=0;  b=0;
}
When a class contains a constructor like the defined one above, it is guaranteed that an
object created by class will initialized automatically
For example:
Sample S;
It will not only creates the object S of type Sample but also initializes its data members a
&amp; b to zero. A constructor with no parameter is called as the default constructor. If no
constructor is defined then the complier supplies a default constructor.
The constructors function has some special characteristics:
1. The constructor should be declared in public section.
2. They are automatically invoke when the objects are created.
3. They do not have return type, not even void type is present. They do not have return
values.
4. They cannot be inherited though a derived class can call the   base class constructor
5. Similar to other C++ function they can have also default argument.
6. Constructors cannot be Virtual.
7. We cannot refer to their addresses.
8. As object with constructor cannot be used as a member of union
9. They may implicit calls to the operators new and delete when memory allocation is
required.


Conclusion: Hence, we are able to study, use arithmetic operators with switch statement.



*/