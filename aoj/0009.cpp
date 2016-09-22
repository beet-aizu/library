#include <iostream>
using namespace std;

int isPrime(int n);

int dp[1000000]={};

int main(){
  int n;
  for(int i=2;i<=1000000;i++){
      if(isPrime(i)) dp[i]=dp[i-1]+1;
      else dp[i]=dp[i-1];
  }
  
  while(cin >> n){
    cout << dp[n]<< endl;
  }
  
}

int isPrime(int n){
  for(int i=2;i*i<=n;i++){
    if(n%i==0) return 0;
  }
  return 1;
}
