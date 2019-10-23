#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2674"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../tools/fastio.cpp"
#include "../../datastructure/waveletmatrix.cpp"
#undef call_from_test

signed main(){
  int d;
  cin>>d;
  vector<int> xs(d);
  for(int i=0;i<d;i++) cin>>xs[i];

  const int ofs = 2e8;
  for(int &x:xs) x+=ofs;
  WaveletMatrix<int, 30> wm(xs);

  int q;
  cin>>q;
  for(int i=0;i<q;i++){
    int l,r,e;
    cin>>l>>r>>e;
    l--;
    int a=min(xs[l],xs[r-1]);
    int b=max(xs[l],xs[r-1]);
    cout<<(r-l)-wm.rangefreq(l,r,a-e,b+e+1)<<"\n";
  }
  cout<<flush;
  return 0;
}
