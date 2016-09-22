#include<iostream>
using namespace std;
int main(){
  int n,i,j;
  cin >> n;
  while(n!=0) {
    long long sum[5001]={};
    int b;
    long long o=1<<20;
    o*=-1;
    cin >> sum[1];
    for(i=2;i<=n;i++){
      cin >> b;
      sum[i]=sum[i-1]+b;
      //cout << sum[i] << endl;
    }
    
    for(i=0;i<=n;i++){
      for(j=i+1;j<=n;j++){
	o=max(o,sum[j]-sum[i]);
      }
    }
    cout << o << endl;
    cin >> n;
  }
  return 0;
  
}
