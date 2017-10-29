#include<bits/stdc++.h>
using namespace std;
using Int = long long;
//BEGIN CUT HERE
int lcs(string X,string Y){
  const int N=max(X.size(),Y.size())+1;
  vector<vector<int> > c(N,vector<int>(N,0));
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
//END CUT HERE
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
verified on 2017/06/29
http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_10_C
*/
