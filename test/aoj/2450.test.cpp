#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2450"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../tree/heavylightdecomposition.cpp"
#include "../../segtree/basic/chien.cpp"
#undef call_from_test

signed main(){
  int n,q;
  scanf("%d %d",&n,&q);
  HLD hld(n);
  vector<int> w(n);
  for(int i=0;i<n;i++) scanf("%d",&w[i]);
  using P = pair<int, int>;
  for(int i=0;i+1<n;i++){
    int a,b;
    scanf("%d %d",&a,&b);
    a--;b--;
    hld.add_edge(a,b);
  }
  hld.build();

  using T = tuple<int, int, int, int, int, int, int>;

  T ti(-1,-1,-1,-1,-1,-1,-1);
  P ei(-1,-114514);

  auto &par=hld.par;
  auto &vid=hld.vid;;
  auto con=[&](int a,int b){
             return par[a]==b||par[b]==a;
           };

  auto f=[&](T a,T b){
           if(a>b) swap(a,b);

           if(get<0>(a)<0) return b;
           if(con(get<0>(a),get<1>(b))) swap(a,b);

           int al,ar,as,ava,avi,avl,avr;
           tie(al,ar,as,ava,avi,avl,avr)=a;
           int bl,br,bs,bva,bvi,bvl,bvr;
           tie(bl,br,bs,bva,bvi,bvl,bvr)=b;

           if(!con(ar,bl)){
             if(con(ar,br)){
               swap(bl,br);
               swap(bvl,bvr);
             }else if(con(al,bl)){
               swap(al,ar);
               swap(avl,avr);
             }else{
               return ti;
             }
           }
           int cl=al,cr=br,cs=as+bs;
           int cva=ava+bva,cvi=max(avi,bvi),cvl=avl,cvr=bvr;
           cvi=max(cvi,avr+bvl);
           cvl=max(cvl,ava+bvl);
           cvr=max(cvr,avr+bva);

           return T(cl,cr,cs,cva,cvi,cvl,cvr);
         };

  auto g=[&](T a,P p){
           if(p==ei) return a;
           int al,ar,as,ava,avi,avl,avr;
           tie(al,ar,as,ava,avi,avl,avr)=a;
           int v=p.first,b=p.second;
           if(~v) al=ar=v,as=1;
           if(b>=0) return T(al,ar,as,b*as,b*as,b*as,b*as);
           return T(al,ar,as,b*as,b,b,b);
         };

  auto h=[&](P a,P b){(void)a;return b;};


  SegmentTree<T, P> seg(f,g,h,ti,ei);

  vector<T> vt(n);
  for(int i=0;i<n;i++) vt[vid[i]]=g(ti,P(i,w[i]));
  seg.build(vt);

  while(q--){
    int t,a,b,c;
    scanf("%d %d %d %d",&t,&a,&b,&c);
    a--;b--;
    if(t==1){
      hld.for_each(a,b,[&](int l,int r){seg.update(l,r,P(-1,c));});
    }
    if(t==2){
      auto ask=[&](int l,int r){return seg.query(l,r);};
      T v=hld.for_each(a,b,seg.ti,ask,f);
      int vl,vr,vs,vva,vvi,vvl,vvr;
      tie(vl,vr,vs,vva,vvi,vvl,vvr)=v;
      printf("%d\n",max({vva,vvi,vvl,vvr}));
    }
  }
  return 0;
}
