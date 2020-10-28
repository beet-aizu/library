#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../basic/base.cpp"
#include "../basic/lazy.cpp"
#undef call_from_test

#endif
//BEGIN CUT HERE
template<typename Node, size_t LIM>
struct PersistentLazy : Lazy<Node, LIM>{
  using super = Lazy<Node, LIM>;
  using super::super;
  using T = typename Node::T;

  inline Node* clone(Node* a){
    if(a==nullptr) return a;
    return super::create(*a);
  }

  Node* eval(Node* a){
    a=clone(a);
    a->l=clone(a->l);
    a->r=clone(a->r);
    return super::eval(a);
  }

  T query(Node *a,size_t l,size_t r){
    auto s=super::split(a,l);
    auto t=super::split(s.second,r-l);
    return super::query(t.first);
  }

  Node* rebuild(Node* a){
    auto vs=super::dump<T>(a);
    vector<Node> nx;
    nx.reserve(vs.size());
    for(auto v:vs)
      nx.emplace_back(v,super::ei);
    super::size=0;
    return super::build(nx);
  }

  bool almost_full() const{
    return super::size>LIM*9/10;
  }
};
//END CUT HERE
//INSERT ABOVE HERE
signed ARC030_D(){
  int n,q;
  scanf("%d %d",&n,&q);

  using ll = long long;
  using P = pair<ll, ll>;
  vector<P> vp(n,P(0,1));
  for(int i=0;i<n;i++) scanf("%lld",&vp[i].first);

  auto f=[](P a,P b){return P(a.first+b.first,a.second+b.second);};
  auto g=[](P a,ll b){return P(a.first+b*a.second,a.second);};
  auto h=[](ll a,ll b){return a+b;};

  using Node = NodeBase<P, ll>;
  constexpr size_t LIM = 6e6;
  PersistentLazy<Node, LIM> G(f,g,h,P(0,0),0);

  vector<Node> vs;
  for(auto v:vp) vs.emplace_back(v,0);
  auto rt=G.build(vs);

  for(int i=0;i<q;i++){
    int t;
    scanf("%d",&t);
    if(t==1){
      int a,b,v;
      scanf("%d %d %d",&a,&b,&v);
      a--;
      rt=G.update(rt,a,b,v);
    }
    if(t==2){
      int a,b,c,d;
      scanf("%d %d %d %d",&a,&b,&c,&d);
      a--;c--;
      auto s=G.split(rt,a);
      auto t=G.split(s.second,b-a);
      auto u=G.split(rt,c);
      auto v=G.split(u.second,d-c);

      rt=G.merge(G.merge(s.first,v.first),t.second);
    }
    if(t==3){
      int a,b;
      scanf("%d %d",&a,&b);
      a--;
      printf("%lld\n",G.query(rt,a,b).first);
    }

    if(G.almost_full()) rt=G.rebuild(rt);
  }
  return 0;
}
/*
  verified on 2020/10/27
  https://atcoder.jp/contests/arc030/tasks/arc030_4
*/

signed main(){
  ARC030_D();
  return 0;
}
