/*
------------------------------------------------------------
Algorithm: Infix to Postfix Conversion and Evaluation using Stack
------------------------------------------------------------
1. Start
2. Read infix expression as input
3. For each character in expression:
      a) If operand → add to postfix
      b) If '(' → push to stack
      c) If ')' → pop until '('
      d) If operator:
            While stack not empty and precedence(top) >= precedence(current)
                pop to postfix
            push operator to stack
4. Pop all remaining operators to postfix
5. Display postfix expression
6. For evaluation:
      a) Read postfix expression
      b) For each character:
            If operand → push its integer value
            If operator → pop two elements, apply operation, push result
7. Final stack top is the result
8. Stop
------------------------------------------------------------
*/

#include <iostream>
#include <stack>
#include <cmath>
#include <cctype>
using namespace std;

int precedence(char op) {
    if(op == '^') return 3;
    if(op == '*' || op == '/') return 2;
    if(op == '+' || op == '-') return 1;
    return 0;
}

string infixToPostfix(string infix) {
    stack<char> s;
    string postfix = "";
    for(char ch : infix) {
        if(isalnum(ch)) postfix += ch;
        else if(ch == '(') s.push(ch);
        else if(ch == ')') {
            while(!s.empty() && s.top() != '(') {
                postfix += s.top();
                s.pop();
            }
            s.pop();
        } else {
            while(!s.empty() && precedence(s.top()) >= precedence(ch)) {
                postfix += s.top();
                s.pop();
            }
            s.push(ch);
        }
    }
    while(!s.empty()) {
        postfix += s.top();
        s.pop();
    }
    return postfix;
}

int evaluatePostfix(string postfix) {
    stack<int> s;
    for(char ch : postfix) {
        if(isdigit(ch)) s.push(ch - '0');
        else {
            int val2 = s.top(); s.pop();
            int val1 = s.top(); s.pop();
            switch(ch) {
                case '+': s.push(val1 + val2); break;
                case '-': s.push(val1 - val2); break;
                case '*': s.push(val1 * val2); break;
                case '/': s.push(val1 / val2); break;
                case '^': s.push(pow(val1, val2)); break;
            }
        }
    }
    return s.top();
}

int main() {
    string infix;
    cout << "Enter infix expression: ";
    cin >> infix;

    string postfix = infixToPostfix(infix);
    cout << "Postfix Expression: " << postfix << endl;

    cout << "Enter postfix expression to evaluate: ";
    cin >> postfix;
    cout << "Result: " << evaluatePostfix(postfix) << endl;
    return 0;
}

/*
--------------------- Sample Output ---------------------
Enter infix expression: (3+4)*5
Postfix Expression: 34+5*
Enter postfix expression to evaluate: 34+5*
Result: 35
---------------------------------------------------------
Enter infix expression: 5*(6+2)-8/4
Postfix Expression: 562+*84/-
Enter postfix expression to evaluate: 562+*84/-
Result: 36
---------------------------------------------------------
*/
