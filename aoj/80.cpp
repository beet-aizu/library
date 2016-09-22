#include<iostream>
#include<iomanip>
#include<math.h>
using namespace std;
int main(){
  double q,x;
  while(cin>>q,q!=-1){
    x=q/2;
    while(fabs(x*x*x-q)>=0.00001*q) x=x-((x*x*x-q)/(3*x*x));
    cout << fixed << setprecision(7) << x << endl;
  }
  return 0;
}
