#include<bits/stdc++.h>
using namespace std;
#define PI 3.1415926535
int main(){
  double r,n,s;
  cin >> r >> n;
  cout << n << endl;
  s=r*r*sin(2*PI/n)*n/2;
  printf("%.7lf\n",s);
}
