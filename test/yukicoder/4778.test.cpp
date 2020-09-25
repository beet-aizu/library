// verification-helper: PROBLEM https://yukicoder.me/problems/4778

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../vector/near.cpp"
#include "../../vector/compress.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  const char newl = '\n';

  int n;
  cin>>n;
  vector<int> xs(n),rs(n);
  for(int i=0;i<n;i++) cin>>xs[i]>>rs[i];
  xs=mul(xs,2);
  rs=mul(rs,2);

  auto vs=compress(near(near(xs,0,rs,mul(rs,-1)),-1,0,1));
  auto dc=dict(vs);

  vector<int> sm(vs.size(),0);
  for(int i=0;i<n;i++){
    sm[dc[xs[i]-rs[i]+1]]++;
    sm[dc[xs[i]+rs[i]]]--;
  }
  for(int i=1;i<(int)vs.size();i++) sm[i]+=sm[i-1];

  cout<<*max_element(sm.begin(),sm.end())<<newl;
  return 0;
}
