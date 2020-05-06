#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0558"

#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../tools/gridbfs.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int h,w,n;
  cin>>h>>w>>n;

  vector<string> st(h);
  for(int i=0;i<h;i++) cin>>st[i];

  for(int i=0;i<h;i++)
    for(int j=0;j<w;j++)
      if(st[i][j]=='S') st[i][j]='0';

  vector<int> ys(n+1),xs(n+1);
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      if(!isdigit(st[i][j])) continue;
      int p=st[i][j]-'0';
      ys[p]=i;xs[p]=j;
    }
  }

  int ans=0;
  for(int k=0;k<n;k++)
    ans+=gridbfs(st,ys[k],xs[k],'X',4)[ys[k+1]][xs[k+1]];

  cout<<ans<<endl;
  return 0;
}
