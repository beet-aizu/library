#include<iostream>
using namespace std;
int isPrime(int n){
  for(int i=2;i*i<=n;i++) if(n%i==0) return 0;
  return 1;
}
int main(){
  int m,a,b;
  int i,j,k;
  int memo[200001]={};
  for(i=2;i<200001;i++) memo[i]=isPrime(i);
  cin >> m >> a >> b;
  while((m+a+b)!=0){
    int p,q,o=0;
    for(i=1;i*i<=m;i++){
      
      for(j=i;j<=b*i/a;j++){
	if(j<100001){
	  if(memo[i]*memo[j]==1){
	    if(o<i*j&&i*j<=m) {
	      o=i*j;
	      p=i;q=j;
	    }
	  }
	}
      }
    }
    //cout << o << endl;
    cout << p << " " << q << endl;
    cin >> m >> a >> b;
  }
  return 0;
}
