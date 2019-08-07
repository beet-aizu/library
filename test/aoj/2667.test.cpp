#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2667"

#define main moin
#define SegmentTree SegmentUkunichiakun
#include "../../tree/heavylightdecomposition.cpp"
#undef SegmentTree
#undef main

#define main mpin
#include "../../segtree/basic/chien.cpp"
#undef main

signed main(){
  using ll = long long;

  int n,q;
  scanf("%d %d",&n,&q);
  HLD hld(n);
  for(int i=1;i<n;i++){
    int a,b;
    scanf("%d %d",&a,&b);
    hld.add_edge(a,b);
  }
  hld.build();

  using P = pair<ll, ll>;
  auto f=[](P a,P b){return P(a.first+b.first,a.second+b.second);};
  auto g=[](P a,ll b){return P(a.first+b*a.second,a.second);};
  auto h=[](ll a,ll b){return a+b;};
  SegmentTree<P, ll> seg(f,g,h,P(0,0),0);
  seg.build(vector<P>(n,P(0,1)));

  for(int i=0;i<q;i++){
    int t;
    scanf("%d",&t);
    if(t==0){
      int u,v;
      scanf("%d %d",&u,&v);
      ll ans=0;
      hld.for_each_edge(u,v,[&](int l,int r){ans+=seg.query(l,r).first;});
      printf("%lld\n",ans);
    }
    if(t==1){
      int v,x;
      scanf("%d %d",&v,&x);
      seg.update(hld.vid[v]+1,hld.vid[v]+hld.sub[v],x);
    }
  }
  return 0;
}
