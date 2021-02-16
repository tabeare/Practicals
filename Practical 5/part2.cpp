#include <iostream>
#include <cmath>
using namespace std;

class Point {
  private:
    double x;
    double y;

  public:
    Point(double x, double y): x{x}, y{y} {
    }

    double getX () {
      return x;
    }

    double getY () {
      return y;
    }

    double distance(Point p) {
      double d = sqrt(pow(x - p.getX(), 2) + pow(y - p.getY(), 2));
      return d;
    }

};

int main() {
  double x1;
  double y1;
  double x2;
  double y2;

  cout << "First point:" << endl << "x-coordinate: ";
  cin >> x1;
  cout << "y-coordinate: ";
  cin >> y1;
  cout << "Second point:" << endl << "x-coordinate: ";
  cin >> x2;
  cout << "y-coordinate: ";
  cin >> y2;

  Point p1 = Point{x1, y1};
  Point p2 = Point{x2, y2}; 

  cout << "Distance: " << p1.distance(p2) << endl;
}