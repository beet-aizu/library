#include <iostream>

using namespace std;
int isPrime(int n);
int main(){
  int memo[1000000]={},i;
  for(i=2;i<1000000;i++){
    memo[i]=isPrime(i);
  }
  int a,d,n,o;
  cin >> a >> d >> n;
  while(a!=0){
    o=0;
    i=0;
    while(o!=n){
      o+=memo[a+d*i];
      i++;
    }
    cout << a+d*(i-1) << endl;
    cin >> a >> d >> n;
  }
  return 0;
}
int isPrime(int n){
  int i;
  for(i=2;i*i<=n;i++) if(n%i==0) return 0;
  return 1;
}
