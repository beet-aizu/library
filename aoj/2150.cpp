#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int isPrime(int n){
  for(int i=2;i*i<=n;i++) if(n%i==0) return 0;
  return 1;
}
int main(){
  int n,p,i,j,k,o,dp[200000]={};
  for(i=2;i<200000;i++) dp[i]=isPrime(i);
  cin >> n >> p;
  while(n!=-1){
    int c=0;
    int l[100]={};
    i=n;
    while(c<100){
      i++;
      if(dp[i]==1){
	l[c]=i;
	c++;
      }
    }
    vector <int> v;
    for(i=0;i<100;i++){
      for(j=i;j<100;j++){
	v.push_back(l[i]+l[j]);
      }
    }
    sort(v.begin(),v.end());
    cout << v[p-1] << endl;
    cin >> n >> p;
  }
  return 0;
}

