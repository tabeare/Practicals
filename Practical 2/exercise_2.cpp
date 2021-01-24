#include <iostream>
#include <cmath>
#include <unistd.h>
using namespace std;

float init_pos;
float pos;
float v;
float a;
int n;
float dt;
float calc_position(float, float, float, float);

int main() {
  cout << "Enter the initial position, speed and the acceleration:" << endl;
  cin >> init_pos; 
  cin >> v; 
  cin >> a;
  cout << "How many times do you want to display the position of the moving body?" << endl;
  cin >> n;
  cout << "How often do you want to update the position of the object? (in seconds)" << endl;
  cin >> dt;
  float i = 0;
  while (i < n*dt) {
    pos = calc_position(init_pos, v, a, i);
    cout << "At time " << i << " the position is " << pos << endl;
    i += dt;
    sleep(dt);
  }
}

float calc_position(float init_pos, float v, float a, float t) {
  return init_pos + v * t + 0.5 * a * pow(t, 2);
}