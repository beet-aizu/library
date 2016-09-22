#include<iostream>
using namespace std;
bool isPrime(int n){
  for(int i=2;i*i<=n;i++) if(n%i==0) return false;
  return true;
}

int main(){
  int d[10005]={};
  int i=2,k=1;
  while(k<10005) {
    while(!isPrime(i)) i++;
    d[k]=d[k-1]+i;
    i++;k++;
  }
  while(cin >> k,k) cout << d[k] << endl;
  return 0;
}
