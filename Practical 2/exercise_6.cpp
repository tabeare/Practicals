#include <iostream>
using namespace std;

int n;
int rec = 0;

int fib(int n) {
  rec++;
  if (n == 0 | n == 1) {
    return n;
  } else {
    return fib(n-1) + fib(n-2);
  }
}

int main() {
  cout << "Which Fibonacci number do you want to get? ";
  cin >> n;
  int x = fib(n);
  cout << x << endl;
  cout << "Number of function calls needed: " << rec << endl;
}