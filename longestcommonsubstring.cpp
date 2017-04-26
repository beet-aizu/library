#include<bits/stdc++.h>
using namespace std;
#define N 1050
int c[N+1][N+1];
int lcs(string X,string Y){
  memset(c,0,sizeof(0));
  int m = X.size();
  int n = Y.size();
  int maxl = 0;
  X = ' ' + X;
  Y = ' ' + Y;
  for(int i=1;i<=m;i++){
    for(int j=1;j<=n;j++){
      if(X[i]==Y[j]) c[i][j]=c[i-1][j-1]+1;
      else c[i][j]=max(c[i-1][j],c[i][j-1]);
      maxl=max(maxl,c[i][j]);
    }
  }
  return maxl;
}
int main(){
  int q;
  cin>>q;
  while(q--){
    string s,t;
    cin>>s>>t;
    cout<<lcs(s,t)<<endl;
  }
  return 0;
}
/*
verified on 2017/04/26
http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_10_C
*/
