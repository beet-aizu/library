#include<iostream>
using namespace std;
int isPrime(int n);
int main(){
  int n,dp[250000]={},i;
  for(i=2;i<250000;i++){
    dp[i]=dp[i-1]+isPrime(i);
  }
  cin >> n;
  while(n!=0) {
    cout << dp[2*n] - dp[n] << endl;
    cin >> n;
  }
  return 0;
}

int isPrime(int n){
  int i;
  for(i=2;i*i<=n;i++) if(n%i==0) return 0;
  return 1;
}
