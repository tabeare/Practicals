#include <iostream>
#include <cmath>
using namespace std;

int n;
int a;

int power(int a, int n) {
  if (n == 0) {
    return 1;
  } else {
    return a * power(a, n-1);
  }
}

int main() {
  cout << "a: ";
  cin >> a;
  cout << "To the power of: ";
  cin >> n;
  int result = power(a, n);
  cout << result << endl;
}