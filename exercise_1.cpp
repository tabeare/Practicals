#include <iostream>
#include <cmath>
using namespace std;

double x;
double y;
double x_center;
double y_center; 
double radius; 
bool is_in_circle(double, double, double, double, double);

int main() {
  cout << "x-coordinate of the center of your circle:" << endl;
  cin >> x_center; 
  cout << "y-coordinate of the center of your circle:" << endl;
  cin >> y_center; 
  cout << "radius of your circle:" << endl;
  cin >> radius;
  cout << "x-coordinate of your point:" << endl;
  cin >> x; 
  cout << "y-coordinate of your point:" << endl;
  cin >> y; 
  if (is_in_circle(x, y, x_center, y_center, radius)) {
    cout << "Point lies in circle." << endl;
  } else {
    cout << "Point doesn't lie in circle." << endl;
  }
}

bool is_in_circle(double x, double y, double x_center, double y_center, double radius) {
  double dist = sqrt(pow(x - x_center, 2) + pow(y - y_center, 2));
  if (dist >= radius){
    return false;
  }
  else {
    return true;
  }
}