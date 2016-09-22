#include<iostream>
using namespace std;
bool isPrime(int n){
  for(int i=2;i*i<=n;i++) if(n%i==0) return false;
  return true;
}
int main(){
  bool d[50000]={};
  int i,j,k;
  for(i=2;i<50000;i++) d[i]=isPrime(i);
  int n;
  while(cin>>n,n){
    int o=0;
    for(i=1;i<=n/2;i++) if(d[i]&&d[n-i]) o++;
    cout << o << endl;
  }
  return 0;
}
