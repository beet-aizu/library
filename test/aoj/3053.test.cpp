#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=3053"

#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../tools/all_permutations.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n;
  string s;
  cin>>n>>s;

  int c[10][10]={};
  for(int i=0;i+1<n;i++){
    int a=s[i]-'0',b=s[i+1]-'0';
    c[a][b]++;
  }

  int ans=n*100;
  vector<int> us;
  auto f=
    [&](auto vs){
      int x[10],y[10];
      for(int i=0;i<9;i++){
        x[vs[i]+1]=i%3;
        y[vs[i]+1]=i/3;
      }

      int res=0;
      for(int i=1;i<=9;i++)
        for(int j=1;j<=9;j++)
          res+=c[i][j]*(abs(x[i]-x[j])+abs(y[i]-y[j]));

      if(res<ans) ans=res,us=vs;
    };
  all_permutations(9,f);

  for(int i=0;i<9;i++){
    cout<<us[i]+1;
    if(i%3==2) cout<<endl;
  }
  return 0;
}
