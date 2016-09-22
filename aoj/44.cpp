#include<iostream>
using namespace std;
int isPrime(int n){
  for(int i=2;i*i<=n;i++) if(n%i==0) return false;
  return true;
}
int main(){
  bool d[70000];
  for(int i=0;i<70000;i++) d[i]=isPrime(i);
  int n;
  while(cin >> n){
    int k=1;
    while(!d[n-k]) k++;
    cout << n-k << " ";
    k=1;
    while(!d[n+k]) k++;
    cout << n+k << endl;
  }
}
