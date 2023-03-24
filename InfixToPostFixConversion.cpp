#include <iostream>
#include <stack>
#include <string>

using namespace std;

int precedence(char op) {
    if (op == '^') 
        return 3;
    else if (op == '*' || op == '/')
        return 2;
    else if (op == '+' || op == '-')
         return 1;
    else 
        return 0;
}


string infixToPostfix(string infix) {
    stack<char> st;
    string postfix = "";
    for (int i = 0; i < infix.length(); i++) {
        char c = infix[i];
        if (c >= '0' && c <= '9' || c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z') {
            postfix += c;
        }
        else if (c == '(') {
            st.push(c);
        }
        else if (c == ')') {
            while (st.top() != '(') {
                postfix += st.top();
                st.pop();
            }
            st.pop(); 
        }
        else {
            while (!st.empty() && st.top() != '(' && precedence(c) <= precedence(st.top())) {
                postfix += st.top();
                st.pop();
            }
            st.push(c);
        }
    }
    while (!st.empty()) {
        postfix += st.top();
        st.pop();
    }
    return postfix;
}

int main() {
    string infix = "a+b*c-d/e^f";
    string postfix = infixToPostfix(infix);
    cout << postfix << '\n';
    return 0;
}
