#include<iostream>
#include<vector>
using namespace std;
int x,y;
int m[1000005]={};
int memo[1000005]={};
int memo2[1000005]={};
vector<int> odd;
void saiki(int n,int d){
  int i,j;
  //cout << n << ":" << d << ":" << x << endl;
  if(n==0) {
    //cout << x << d << endl;
    x=min(x,d);
  }else if(n>0) {
    if(memo[n]>0){
      x=min(x,memo[n]+d);
    }else{
      for(i=1;m[i]<=n;i++);
      i--;
      int b=x;
      for(j=i;j>0;j--){
	if(x>d+1&&d<5)
	  saiki(n-m[j],d+1);
      }
      if(x<b){
	memo[n]=x-d;
	cout << n << ":" << memo[n]<< endl;
      }
      //cout << n << ":" << memo[n]<< endl;
    }
  }
}
void saiki2(int n,int d){
  int i,j;
  //cout << n << ":" << d << endl;
  if(n==0) {
    y=min(y,d);
  }else if(n>0) {
    if(memo2[n]>0){
      y=min(y,memo2[n]+d);
    }else{
      for(i=0;odd[i]<=n;i++);
      i--;
      int b=y;
      //cout << i << ":" << n << ":" << odd[i] << endl;
      for(j=i;j>=0;j--){
	if(y>d+1){
	  saiki2(n-odd[j],d+1);
	}
      }
      if(y<b)
	memo2[n]=y-d;
    }
  }
}
int main(){
  int i,j,k;
  fill(memo,memo+1000005,-1);
  fill(memo2,memo2+1000005,-1);
  for(i=1;i<1000005;i++) {
    m[i]=i*(i+1)*(i+2)/6;
    if(m[i]%2==1) odd.push_back(m[i]);
  }
  int n;
  cin >> n;
  while(n!=0){
    x=1<<10;y=x;
    saiki(n,0);saiki2(n,0);
    cout << x << " " <<  y << endl;
    cin >> n;
  }
  return 0;
}
