#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1549"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../tools/fastio.cpp"
#include "../../tools/chminmax.cpp"
#include "../../datastructure/waveletmatrix.cpp"
#undef call_from_test

signed main(){
  int n;
  cin>>n;

  const int OFS = 1e6;
  vector<int> as(n);
  for(int i=0;i<n;i++) cin>>as[i],as[i]+=OFS;
  WaveletMatrix<int, 21> wm(as);

  int q;
  cin>>q;
  for(int i=0;i<q;i++){
    int l,r,d;
    cin>>l>>r>>d;
    r++;
    d+=OFS;
    int ans=OFS*2;
    if(wm.rank(d,l)<wm.rank(d,r)) ans=0;
    else{
      int succ=wm.succ(l,r,d);
      if(~succ) chmin(ans,abs(succ-d));
      int pred=wm.pred(l,r,d);
      if(~pred) chmin(ans,abs(pred-d));
    }
    cout<<ans<<"\n";
  }
  cout<<flush;
  return 0;
}
