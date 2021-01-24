#include <iostream>
using namespace std;

int x = 2;
int y = 3;
int z;

void swap(int &x, int &y) {
  z = x;
  x = y;
  y = z;
}

int main() {
  swap(x, y);
  cout << "x: " << x << ", y: " << y;
}