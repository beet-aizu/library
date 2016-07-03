#include<iostream>
#include<stdio.h>
using namespace std;
int main(){
  int n,mi=10000000,ma=-10000000;
    long long sum=0;
  cin >> n;
  int i,b;
  for(i=0;i<n;i++){
    cin >> b;
    mi=min(mi,b);
    ma=max(ma,b);
    sum+=b;
  }
  cout << mi <<  " " << ma << " " << sum << endl;
  return 0;
}
