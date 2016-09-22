#include<iostream>
#include<vector>
using namespace std;

int main(){
  int i,j,k;
  int x,y;
  int inf = 1 << 10;
  int m[200]={};
  int memo[1000005]={};
  int memo2[1000005]={};
  vector <int>  odd;
  fill(memo,memo+1000005,inf);
  fill(memo2,memo2+1000005,inf);
  for(i=1;i<201;i++) {
    m[i-1]=i*(i+1)*(i+2)/6;
    if(m[i-1]%2==1) odd.push_back(m[i-1]);
  }
  memo[0]=0;
  for(i=0;i<200;i++) {
    for(j=m[i];j<1000005;j++){
      memo[j]=min(memo[j],memo[j-m[i]]+1);
    }
  }
  memo2[0]=0;
  for(i=0;i<odd.size();i++) {
    for(j=odd[i];j<1000005;j++){
      memo2[j]=min(memo2[j],memo2[j-odd[i]]+1);
    }
  }
  int n;
  cin >> n;
  while(n!=0){
    cout << memo[n] << " " <<  memo2[n] << endl;
    cin >> n;
  }
  return 0;
}
