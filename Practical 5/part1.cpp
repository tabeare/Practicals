#include <iostream> 
using namespace std;

bool only_digits(string a) {
  bool c = true;
  for (int i=0; i<a.length(); i++) {
    if (a[i] < '0' || a[i] > '9') {
      c = false;
    }
  }
  return c;
}

void pair_of_chars(string a) {
  int x = 0;
  for (int i=0; i<a.length()-1; i++) {
    int occ = 0;
    for (int j=i; j<a.length()-1; j++) {
      if (a[j] == a[i]) {
        if (a[j+1] == a[i+1]) {
          occ++;
        }
      }
    }
    x = max(x, occ);
  }
  cout << "The highest occurence of the same pair of characters in your string is " << x << " times." << endl;
}

void pair_of_chars(char a[]) {
  int x = 0;
  int i = 0;
  while (a[i+1] != '\0') {
    int occ = 0;
    int j = i;
    while (a[j+1] != '\0') {
      if (a[j] == a[i]) {
        if (a[j+1] == a[i+1]) {
          occ++;
        } 
      }
      j++;
    }
    x = max(x, occ);
    i++;
  }
  cout << "The highest occurence of the same pair of characters in your array of chars is " << x << " times." << endl;
}

int main() {
  string a;
  cout << "Your string: ";
  cin >> a;
  if (only_digits(a)) {
    cout << "Your string contains only digits." << endl;
  } else {
    cout << "Your string doesn't contain only digits." << endl;
  }
  pair_of_chars(a);
  int n;
  cout << "How many characters do you want to enter?" << endl;
  cin >> n;
  char ch[n+1]; 
  for (int i=0; i<n; i++) {
    char c;
    cout << "Enter character nb. " << i+1 << ": ";
    cin >> c; 
    ch[i] = c;
  }
  ch[n] = '\0';
  pair_of_chars(ch);
}