#include <iostream>
#include <cmath>
using namespace std;

int n;
int a;
int rec_1 = 0;
int rec_2 = 0;


// The first function below is called exactly n+1 times for the calculation a^n (One initial call plus n recursions).
int power(int a, int n) {
  rec_1++;
  if (n == 0) {
    return 1;
  } else {
    return a * power(a, n-1);
  }
}

// The second function is called less often: It depends how often the exponent n can be divided by 2. Therefore, if we want to compute a^n and 2^(x-1) <= n < 2^x, this will make x + 1 function calls (1 initial call + x recursions).
int alternate_power(int a, int n) {
  rec_2++;
  if (n == 0) {
    return 1;
  } else if (n%2 == 0) {
    int a_n_half = alternate_power(a, n/2);
    return a_n_half*a_n_half;
  } else {
    int a_n_half = alternate_power(a, n/2);
    return a * a_n_half * a_n_half;
  }
}

int main() {
  cout << "a: ";
  cin >> a;
  cout << "To the power of: ";
  cin >> n;
  int result = power(a, n);
  int alternate_result = alternate_power(a, n);
  cout << result << endl << alternate_result << endl;
  cout << "Recursions for first function: " << rec_1 << endl;
  cout << "Recursions for second function: " << rec_2 << endl;
}

