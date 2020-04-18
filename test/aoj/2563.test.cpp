#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2563"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../vector/zip.cpp"
#include "../../vector/fusion.cpp"
#include "../../vector/compress.cpp"
#include "../../algorithm/parallelbinarysearch.cpp"
#include "../../segtree/basic/chien.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  using ll = long long;

  int n,m,q;
  cin>>n>>m>>q;

  vector<int> as(m),bs(m),vs(m);
  for(int i=0;i<m;i++)
    cin>>as[i]>>bs[i]>>vs[i],as[i]--;

  {
    auto vt=zip(vs,as,bs);
    sort(vt.begin(),vt.end());
    for(int i=0;i<m;i++) tie(vs[i],as[i],bs[i])=vt[i];
  }

  vector<int> xs(q),ys(q);
  vector<ll> js(q);
  for(int i=0;i<q;i++)
    cin>>xs[i]>>ys[i]>>js[i],xs[i]--;

  auto ps=compress(fusion(as,bs,xs,ys,vector<int>({0,1000000007})));
  auto dc=dict(ps);

  using P = pair<ll, int>;
  auto f=[&](P a,P b){return P(a.first+b.first,a.second+b.second);};
  auto g=[&](P a,int b){return P(a.first+(ll)b*a.second,a.second);};
  auto h=[&](int a,int b){return a+b;};
  SegmentTree<P, int> seg(f,g,h,P(0,0),0);

  vector<P> vp(ps.size()-1);
  for(int i=0;i+1<(int)ps.size();i++) vp[i]=P(0,ps[i+1]-ps[i]);

  for(int &a:as) a=dc[a];
  for(int &b:bs) b=dc[b];
  for(int &x:xs) x=dc[x];
  for(int &y:ys) y=dc[y];

  auto init=[&](){
    seg.build(vp);
  };
  auto apply=[&](int i){
    seg.update(as[i],bs[i],1);
  };
  auto check=[&](int i){
    return seg.query(xs[i],ys[i]).first>=js[i];
  };

  auto ans=parallel_binary_search(q,m,init,apply,check);
  for(int i=0;i<q;i++) cout<<vs[ans[i]]<<"\n";
  cout<<flush;
  return 0;
}
