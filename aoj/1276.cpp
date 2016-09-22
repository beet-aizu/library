#include<iostream>
using namespace std;
int isPrime(int n){
  for(int i=2;i*i<=n;i++) if(n%i==0) return 0;
  return 1;
}
int main(){
  int i,j,dp[1500000]={},c;
  i=2;
  
  while(i<1500000){
    c=1;
    dp[i]=0;
    while(isPrime(i+c)==0){
      c++;
    }
    if(i+c<1500000){
      for(j=i+1;j<i+c;j++) dp[j]=c;
      dp[i+c]=0;
    }
    i+=c;
  }
  int n;
  cin >> n;
  while(n!=0){
    cout << dp[n] << endl;
    cin >> n;
  }
  return 0;
}
