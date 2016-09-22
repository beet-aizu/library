#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;
int main(){
  double d,o=d;
  cin >> d;
    for(int i=1;i<=d;i++){
      double x,y;
      x=i;
      y=sqrt(d*d-x*x);
      //cout << x<<":"<<y << endl;
      if(y<1.0) o=max(o,x+1);
      else o=max(o,x+y);
    }
    o=max(o,d*sqrt(2.0));
  
  printf("%.12lf\n",o);
}
