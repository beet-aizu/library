#include<iostream>
#include<math.h>
#include<stdio.h>
using namespace std;
int main(){
  double a,b,c,PI=3.1415926535;
  cin >> a >> b >> c;
  printf("%.5f\n",a*b*sin(c*PI/180)/2);
  printf("%.5f\n",sqrt(a*a+b*b-2*a*b*cos(c*PI/180))+a+b);
  printf("%.5f\n",b*sin(c*PI/180));
  return 0;
}
