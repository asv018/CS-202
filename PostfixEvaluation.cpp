#include <iostream>
#include <stack>
#include <cctype>
#include<bits/stdc++.h>
#include<math.h>
using namespace std;

float cal(float op1, float op2, char e) {
    if (e == '+')
        return op1 + op2;
    else if (e == '-')
        return op1 - op2;
    else if (e == '*')
        return op1 * op2;
    else if (e == '/')
        return op1 / op2;
    else
        return 0;
}

int main() {
    cout << "Enter the postfix algebraic expression: ";
    string ex;
    getline(cin, ex);
    float num = 0;
    stack<float> st;
    bool lastReaddigit = false;
    for (int i = 0; i < ex.length(); i++) {
        char e = ex[i];
        if (isdigit(e)) {
            num = num * 10 + (e - '0');
            lastReaddigit = true;
        } else if (e == ' ') {
            if(lastReaddigit)
            st.push(num);
            num = 0;
            lastReaddigit = false;
        } else {
            lastReaddigit = false;
            float op2 = st.top();
            st.pop();
            float op1 = st.top();
            st.pop();
            float ans = cal(op1, op2, e);
            st.push(ans);
        }
    }
    cout << "Result: " << st.top() << endl;
    return 0;
}

// 10 22 + 8 / 6 * 5 +


