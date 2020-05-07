#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=3063"

#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../string/suffixarray.cpp"
#include "../../string/longestcommonprefix.cpp"
#include "../../datastructure/waveletmatrix.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n,q;
  cin>>n>>q;
  string s;
  cin>>s;

  LongestCommonPrefix lcp(s);
  auto vs=lcp.sa.sa;
  auto rev=lcp.sa.rev;
  using WM = WaveletMatrix<int, 18>;
  WM wm(vs);

  auto calc=
    [&](int a,int b)->int{
      auto check=
        [&](int x)->int{
          int p=b-x;
          int pos=rev[p];
          int ll=-1,rr=-1;
          {
            int l=-1,r=pos;
            while(l+1<r){
              int m=(l+r)>>1;
              if(vs[m]+x<=n&&lcp.lcp(vs[m],p)>=x) r=m;
              else l=m;
            }
            ll=r;
          }
          {
            int l=pos,r=n+1;
            while(l+1<r){
              int m=(l+r)>>1;
              if(vs[m]+x<=n&&lcp.lcp(vs[m],p)>=x) l=m;
              else r=m;
            }
            rr=r;
          }
          // [ll, rr)
          int q=wm.pred(ll,rr,p-x);
          if(q==WM::npos||q-x<0) return 0;
          int k=wm.pred(ll,rr,q-x);
          if(k==WM::npos) return 0;
          return a<k;
        };

      int l=0,r=(b-a+2)/3;
      while(l+1<r){
        int m=(l+r)>>1;
        if(check(m)) l=m;
        else r=m;
      }
      return l;
    };

  for(int i=0;i<q;i++){
    int a,b;
    cin>>a>>b;
    a--;
    cout<<calc(a,b)<<"\n";
  }
  cout<<flush;
  return 0;
}
