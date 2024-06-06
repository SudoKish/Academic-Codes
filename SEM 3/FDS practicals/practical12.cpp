// Implement C++ program for expression conversion as infix to postfix and its evaluation using stack based on given conditions: 
// 1. Operands and operator, both must be single character. 
// 2. Input Postfix expression must be in a desired format. 
// 3. Only '+', '-', '*' and '/ ' operators are expected.

#include <iostream>
#include <stack>
#include <cctype>

using namespace std;

int precedence(char op) {
    if (op == '+' || op == '-') {
        return 1;
    }
    if (op == '*' || op == '/') {
        return 2;
    }
    return 0;
}

int applyOp(int a, int b, char op) {
    switch (op) {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            return a / b;
    }
    return 0;
}

int evalPostfix(string postfix) {
    stack<int> Stack;
    for (int i = 0; i < postfix.length(); i++) {
        if (isdigit(postfix[i])) {
            Stack.push(postfix[i] - '0');
        } else {
            int a = Stack.top();
            Stack.pop();
            int b = Stack.top();
            Stack.pop();
            Stack.push(applyOp(a, b, postfix[i]));
        }
    }
    return Stack.top();
}

int main() {
    string postfix = "231*+9-";
    cout << "Value of Postfix: " << postfix << " is ";
    cout << evalPostfix(postfix) << endl;
    return 0;
}
