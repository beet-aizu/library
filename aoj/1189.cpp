#include<iostream>
#include<math.h>
using namespace std;
int isPrime(int n){
  for(int i=2;i*i<=n;i++) if(n%i==0) return 0;
  return 1;
}
int xy2i(int x,int y){
  int n=0;
  if(x==y){
    
  }
  return n;
}
int i2x(int k){
  int x=0;
  int r = sqrt(k);
  r = (r + r%2) / 2;
  int s = k - r * r;
  return x;
}
int i2y(int k){
  int y=0;
  return y;
}
int main(){
  int p[1000001];
  int i,j,k=1;
  for(i=2;i<1000001;i++) {
    p[i]=isPrime(i);
  }
  
  int m,n;
  cin >> m >> n;
  while(m!=0){
    int dp[1000001]={};
    int x=i2x(n),y=i2y(n);
    
    cin >> m >> n;
  }
  //cout << sqrt(9) << ":" << sqrt(10)<<endl;
  return 0;
}
