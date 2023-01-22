#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isOperator(char c) {
  if (c == '+' || c == '-' || c == '*' || c == '/') {
    return true;
  }
  return false;
}

int performOperation(int a, int b, char operation) {
  if (operation == '+') {
    return a + b;
  } else if (operation == '-') {
    return a - b;
  } else if (operation == '*') {
    return a * b;
  } else if (operation == '/') {
    return a / b;
  }
  return 0;
}

int evaluatePostfix(string expression) {
  stack<int> s;
  for (int i = 0; i < expression.length(); i++) {
    if (!isOperator(expression[i])) {
      s.push(expression[i] - '0');
    } else {
      int a = s.top();
      s.pop();
      int b = s.top();
      s.pop();
      int result = performOperation(b, a, expression[i]);
      s.push(result);
    }
  }
  return s.top();
}

int main() {
  string expression;
  cout << "Enter a postfix expression: ";
  cin >> expression;
  cout << "Result: " << evaluatePostfix(expression) << endl;
  return 0;
}
