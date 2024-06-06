/* 
Implement a class Complex which represents the Complex Number data type. Implement the following
1.	Constructor (including a default constructor which creates the complex number 0+0i).
2.	Overload operator+ to add two complex numbers.
3.	Overload operator* to multiply two complex numbers.
4.	Overload operators << and >> to print and read Complex Numbers
*/

#include <iostream>
using namespace std;
class Complex
{
    double real;
    double img;

public:
    Complex();
    friend istream &operator>>(istream &, Complex &);
    friend ostream &operator<<(ostream &, const Complex &);
    Complex operator+(Complex);
    Complex operator*(Complex);
};
Complex::Complex()
{
    real = 0;
    img = 0;
}
istream &operator>>(istream &, Complex &i)
{
    cin >> i.real >> i.img;
    return cin;
}
ostream &operator<<(ostream &, const Complex &d)
{
    cout << d.real << " + " << d.img << "i" << endl;
    return cout;
}
Complex Complex::operator+(Complex c1)
{
    Complex temp;
    temp.real = real + c1.real;
    temp.img = img + c1.img;
    return temp;
}
Complex Complex::operator*(Complex c2)
{
    Complex tmp;
    tmp.real = real * c2.real - img * c2.img;
    tmp.img = real * c2.img + img * c2.real;
    return tmp;
}
int main()
{
    Complex C1, C2, C3, C4;
    int flag = 1;
    char b;
    while (flag == 1)
    {
        cout << "Enter Real and Imaginary part of the Complex Number 1 : \n";
        cin >> C1;
        cout << "Enter Real and Imaginary part of the Complex Number 2 : \n";
        cin >> C2;
        int f = 1;
        while (f == 1)
        {
            cout << "Complex Number 1 : " << C1 << endl;
            cout << "Complex Number 2 : " << C2 << endl;
            cout << "**********MENU**********" << endl;
            cout << "1. Addition of Complex Numbers" << endl;
            cout << "2. Multiplication of Complex Numbers" << endl;
            cout << "3. Exit\n";
            int a;
            cout << "Enter your choice from above MENU (1 to 3) : ";
            cin >> a;
            if (a == 1)
            {
                C3 = C1 + C2;
                cout << "Addition : " << C3 << endl;
                cout << "Do you wan to perform another operation (y/n) : \n";
                cin >> b;
                if (b == 'y' || b == 'Y')
                {
                    f = 1;
                }
                else
                {
                    cout << "Thanks for using this program!!\n";
                    flag = 0;
                    f = 0;
                }
            }
            else if (a == 2)
            {
                C4 = C1 * C2;
                cout << "Multiplication : " << C4 << endl;
                cout << "Do you wan to perform another operation (y/n) : \n";
                cin >> b;
                if (b == 'y' || b == 'Y')
                {
                    f = 1;
                }
                else
                {
                    cout << "Thanks for using this program!!\n";
                    flag = 0;
                    f = 0;
                }
            }
            else
            {
                cout << "Thanks for using this program!!\n";
                flag = 0;
                f = 0;
            }
        }
    }
    return 0;
}

/*

Title: Demonstrate use of operator overloading for Complex class.
Theory:
C++ allows you to specify more than one definition for a function name or an operator in
the same scope, which is called function overloading and operator overloading
respectively.
An overloaded declaration is a declaration that had been declared with the same name as
a previously declared declaration in the same scope, except that both declarations have
different arguments and obviously different definition (implementation). When you call
an overloaded function or operator, the compiler determines the most appropriate
definition to use by comparing the argument types you used to call the function or
operator with the parameter types specified in the definitions. The process of selecting the
most appropriate overloaded function or operator is called overload resolution.
Operator overloading is one of the special feature of C++. It also shows the extensibility
of C++. C++ permits us to add two variables of user defined types with the same way that
is applied with built in type data type. This refers to ability to provide special meaning for
existing data type. This mechanism of giving such special meaning to an operator is
known as overloading.
Operator overloading provides a flexible option for creation of new definition for most of
the C++ operators. We can assign additional meaning to all existing C++ operators
except following:
1) Class member access operators ( . , .*)
2) Scope resolution operator ( : : )
3) Size of operator (sizeof)
4) Conditional operator (? 
These operators are attributed to fact that an operator takes names as their operand
instead of values.

Conclusion: Hence, we have studied, used and demonstrated use of binary operator
overloading and insertion-extraction operator overloading using friend function.



*/