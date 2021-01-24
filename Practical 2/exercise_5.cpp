#include <iostream>
using namespace std;

int n;

int Fib(int n) {
  int a;
  int b;
  for (int i=1; i<=n; i++) {
    if (i <= 1) {
      a = b; 
      b = i;
    } else {
      int x = a + b; 
      a = b; 
      b = x;
    }
  }
  return b;
}

int main() {
  cout << "Which Fibonacci number do you want to get? ";
  cin >> n;
  int x = Fib(n);
  cout << x << endl;
}