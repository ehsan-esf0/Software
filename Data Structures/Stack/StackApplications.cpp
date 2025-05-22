#include <iostream>
#include <math.h>
#include "stack.h"
using namespace std;

bool isOperator(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

int precedence(char op)
{
    if (op == '^')
        return 3;
    if (op == '*' || op == '/')
        return 2;
    if (op == '+' || op == '-')
        return 1;
    return 0;
}

string infixToPostfix(const string &infix)
{
    Stack<char> s;
    string postfix;

    for (char ch : infix)
    {
        if (isspace(ch))
            continue;

        if (isalnum(ch))
        {
            postfix += ch;
        }
        else if (ch == '(')
        {
            s.push(ch);
        }
        else if (ch == ')')
        {
            while (!s.isEmpty() && s.top() != '(')
            {
                postfix += s.top();
                s.pop();
            }
            if (!s.isEmpty())
                s.pop();
        }
        else if (isOperator(ch))
        {
            while (!s.isEmpty() && precedence(s.top()) >= precedence(ch))
            {
                postfix += s.top();
                s.pop();
            }
            s.push(ch);
        }
    }

    while (!s.isEmpty())
    {
        postfix += s.top();
        s.pop();
    }

    return postfix;
}

int evaluate(int op1, int op2, char oper) {
    switch (oper) {
        case '+': return op1 + op2;
        case '-': return op1 - op2;
        case '*': return op1 * op2;
        case '/': return op1 / op2;
        case '^': return pow(op1, op2);
        default: throw runtime_error("Invalid operator");
    }
}

int evaluatePostfix(const string& postfix) {
    Stack<int> s;
    for (char ch : postfix) {
        if (isspace(ch)) continue;

        if (isdigit(ch)) {
            s.push(ch - '0'); 
        } else if (isOperator(ch)) {
            if (s.size() < 2) throw runtime_error("Invalid expression");
            int op2 = s.top(); s.pop();
            int op1 = s.top(); s.pop();
            int result = evaluate(op1, op2, ch);
            s.push(result);
        } else {
            throw runtime_error(string("Invalid character: ") + ch);
        }
    }

    if (s.size() != 1) throw runtime_error("Invalid expression");
    return s.top();
}
int main()
{
    // infix => 3 + 8 * 2
    // postfix => 3 8 2 * +
    // prefix => + 3 * 8 2

    string infix = "3 + 8 * 2 + ( 6 / 2 ) * 7";
    string postfix = infixToPostfix(infix);
    cout << "Infix: " << infix << endl;
    cout << "Postfix: " << postfix << endl;

    cout << evaluatePostfix(postfix) << endl;

    return 0;
}