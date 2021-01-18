#include <iostream>
using namespace std;

int n;

void floyd(int n, int x) {
  for (int i=1; i<=n; i++){
    for (int j=0; j<i; j++){
      cout << x << " ";
      x++;
    }
    cout << endl;
  } 
}

int main() {
  int x = 1;
  cout << "Number of lines: ";
  cin >> n;
  floyd(n, x);
}