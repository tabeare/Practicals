#include <iostream>
#include <cmath>
using namespace std;

double * read_poly(int &n){
  cout << "Degree of your polynomial: ";
  cin >> n;
  double * c=new double[n+1];
  for(int i=0;i<=n;i++){
    cout << "coefficient of degree " << i << ": ";
    cin >> c[i];
  }
  return c;
}

void print_poly(double *c, int n){
  int i;
  cout << c[0];
  if(n>0)
    cout << " + ";
  for(i=1;i<n;i++)
    cout << c[i] << "*x^" << i << " + ";
  if(n>0)
    cout << c[n] << "*x^" << i;
  cout << endl << endl;
}

double value_for_x(double *c, int g1){
  double x;
  double v;
  cout << "Value of x: ";
  cin >> x;
  for (int i=0; i <=g1; i++){
    //cout << c[i] << "*" << x << "^" << i << "=" << c[i]*pow(x, i) << endl;
    v += c[i]*pow(x, i);
  }
  cout << "Value of the polynomial for x=" << x << ": " << v << endl;
  return v;
}

double * poly_sum(int d1, int d2, int &dr, double *c1, double *c2){
  dr = max(d1, d2);
  double * c = new double[dr+1];
  for (int i=0; i <= dr; i++){
    c[i] = c1[i] + c2[i];
  }
  return c;
}

double * poly_product(int d1, int d2, int &dr, double *c1,double *c2){
  dr = d1 + d2;
  double * c = new double[dr+1];
  for (int i=0; i <=d1; i++){
    for (int j=0; j<=d2; j++){
      c[i+j] += c1[i] * c2[j];
    }
  }
  return c;
}

int main()
{
  double *p1;
  int g1;
  double vfx;
  double *p2;
  int g2;
  double *sum;
  int g_sum;
  double *prod;
  int g_prod;

  // read a polynomial
  p1=read_poly(g1);
  cout << "\n Polynomial 1: \n";
  print_poly(p1,g1);

  // calculate the value for a position x
  vfx = value_for_x(p1,g1);

  // read in a second polynomial
  p2=read_poly(g2);
  cout << "\n Polynomial 2: \n";
  print_poly(p2, g2);

  // calculate the sum of both polynomials
  sum=poly_sum(g1, g2, g_sum, p1, p2);
  cout << "\n Sum of polynomials 1 and 2: \n";
  print_poly(sum, g_sum);

  // calculate the product of both polynomials
  prod=poly_product(g1, g2, g_prod, p1, p2);
  cout << "\n Product of polynomials 1 and 2: \n";
  print_poly(prod, g_prod);

  delete[] p1;
  delete[] p2;
  delete[] sum;
  delete[] prod;
  return 0;
}