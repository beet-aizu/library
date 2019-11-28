#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2711"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../tools/fastio.cpp"
#include "../../string/suffixarray.cpp"
#include "../../string/longestcommonprefix.cpp"
#undef call_from_test

signed main(){
  string s;
  cin>>s;
  LongestCommonPrefix lcp(s);
  int q;
  cin>>q;
  for(int i=0;i<q;i++){
    int l,r,t;
    cin>>l>>r>>t;
    l--;
    int x=lcp.lcp(l,l+t);
    if(l+t+x+1>=r){
      cout<<"Yes\n";
      continue;
    }
    int y=lcp.lcp(l+x+1,l+t+x+1);
    if(l+t+x+1+y>=r){
      cout<<"Yes\n";
      continue;
    }
    if(l+x+1+y<l+t){
      cout<<"No\n";
      continue;
    }
    int z=lcp.lcp(l+x+1+y+1,l+t+x+1+y+1);
    if(l+t+x+1+y+1+z<r){
      cout<<"No\n";
      continue;
    }
    if(x+t==x+1+y&&s[l+x]==s[l+x+t+t]) cout<<"Yes\n";
    else cout<<"No\n";
  }
  cout<<flush;
  return 0;
}
