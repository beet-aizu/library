#include<iostream>
#include<stdio.h>
using namespace std;
int main(){
  double d;
  while(cin >> d){
    double a=d,b=0;
    for(int i=0;i<10;i++){
      b+=a;
      if(i%2==1) a/=3.0;
      else a*=2.0;
      //cout << a << endl;
    }
    //cout << b << endl;
    printf("%.10lf\n",b);
  }
}
