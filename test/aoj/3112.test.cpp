// verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=3112

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../tools/chminmax.cpp"
#include "../../string/suffixarray.cpp"
#include "../../string/longestcommonprefix.cpp"
#include "../../segtree/basic/dual.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  string s,t;
  cin>>s>>t;

  string b=s+'%'+t;
  LongestCommonPrefix lcp(b);

  int n=s.size(),m=t.size();

  set<int> ss;
  for(int i=0;i<=n+1+m;i++){
    if(!isalpha(b[lcp.sa[i]])) continue;
    if(n<lcp.sa[i]) ss.emplace(i);
  }

  vector<int> nx(n+1,-1);
  for(int i=0;i<=n+1+m;i++){
    if(!isalpha(b[lcp.sa[i]])) continue;
    int k=lcp.sa[i];
    if(k>=n) continue;

    auto it=ss.upper_bound(i);
    if(it!=ss.end()) chmax(nx[k],lcp.query(i,*it));
    if(it!=ss.begin()) it--;
    if(it!=ss.end()) chmax(nx[k],lcp.query(i,*it));
  }

  int len;
  cin>>len;

  auto h=[&](int a,int b){return a||b;};
  int ei=0;
  SegmentTree<int> seg(h,ei);
  seg.init(n+m+1000);

  seg.set_val(0,1);
  for(int i=0;i<n;i++){
    if(!seg.get_val(i)) continue;
    if(nx[i]<len) continue;
    int nl=i+len;
    int nr=i+nx[i]+1;
    seg.update(nl,nr,1);
  }

  cout<<(seg.get_val(n)?"Yes":"No")<<endl;
  return 0;
}
