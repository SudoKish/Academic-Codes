/*
Write a function template for selection sort that inputs, sorts and outputs an integer array and
a float array.
*/

#include <iostream>
using namespace std;
int n;
#define size 10
template <class T>
void sel(T A[size])
{
    int i, j, min;
    T temp;
    for (i = 0; i < n - 1; i++)
    {
        min = i;
        for (j = i + 1; j < n; j++)
        {
            if (A[j] < A[min])
                min = j;
        }
        temp = A[i];
        A[i] = A[min];
        A[min] = temp;
    }
    cout << "\nSorted array:";
    for (i = 0; i < n; i++)
    {
        cout << " " << A[i];
    }
}

int main()
{
    int A[size];
    float B[size];
    int i;
    int ch;
    do
    {
        cout << "\n* * * * * SELECTION SORT SYSTEM * * * * *";
        cout << "\n--------------------MENU-----------------------";
        cout << "\n1. Integer Values";
        cout << "\n2. Float Values";
        cout << "\n3. Exit";
        cout << "\n\nEnter your choice : ";
        cin >> ch;

        switch (ch)
        {
        case 1:
            cout << "\nEnter total no of int elements:";
            cin >> n;
            cout << "\nEnter int elements:";
            for (i = 0; i < n; i++)
            {
                cin >> A[i];
            }
            sel(A);
            break;

        case 2:
            cout << "\nEnter total no of float elements:";
            cin >> n;
            cout << "\nEnter float elements:";
            for (i = 0; i < n; i++)
            {
                cin >> B[i];
            }
            sel(B);
            break;

        case 3:
            exit(0);
        }
    } while (ch != 3);

    return 0;
}

/*
Title: Demonstrate function template for sorting algorithm..

Theory:
Templates are a feature of the C++ programming language that allows functions and
classes to operate with generic types. This allows a function or class to work on many
different data types without being rewritten for each one  Templates are the foundation of
generic programming, which involves writing code in a way that is independent of any
particular type. A template is a blueprint or formula for creating a generic class or a
function. The library containers like iterators and algorithms are examples of generic
programming and have been developed using template concept. There is a single
definition of each container, such as vector, but we can define many different kinds of
vectors for example, vector &lt;int&gt; or vector &lt;string&gt;.

Conclusion: Hence, we demonstrated  use of function template for selection sort


*/