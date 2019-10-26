#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "base.cpp"
#undef call_from_test

#endif
//BEGIN CUT HERE
template<typename Tp>
struct NodeBase{
  using T = Tp;
  NodeBase *l,*r,*p;
  int idx;
  bool rev;
  T val,ld,rd,smd;
  multiset<T> td;
  NodeBase(){}
  NodeBase(int idx,T val):
    idx(idx),rev(0),val(val){
    l=r=p=nullptr;
    ld=rd=smd=val;
    td.emplace(0);
  }
};
template<typename Np, size_t LIM>
struct Farthest : LinkCutTreeBase<Np, LIM>{
  using super = LinkCutTreeBase<Np, LIM>;
  using Node = Np;
  using T = typename Node::T;

  Farthest():super(){}

  Node* create(int idx,T val){
    return super::create(Node(idx,val));
  }

  inline void toggle(Node *t){
    swap(t->l,t->r);
    swap(t->ld,t->rd);
    t->rev^=1;
  }

  inline void eval(Node *t){
    if(t->rev){
      if(t->l) toggle(t->l);
      if(t->r) toggle(t->r);
      t->rev=false;
    }
  }

  inline void pushup(Node *t){
    if(t==nullptr) return;
    t->smd=t->val;
    if(t->l) t->smd+=t->l->smd;
    if(t->r) t->smd+=t->r->smd;

    T lld=t->l?t->l->ld:0;
    T rrd=t->r?t->r->rd:0;

    T lsmd=t->l?t->l->smd:0;
    T rsmd=t->r?t->r->smd:0;

    t->ld=max(lld,lsmd+t->val+*(t->td).rbegin());
    if(t->r) t->ld=max(t->ld,lsmd+t->val+t->r->ld);

    t->rd=max(rrd,rsmd+t->val+*(t->td).rbegin());
    if(t->l) t->rd=max(t->rd,rsmd+t->val+t->l->rd);
  }

  using super::splay;

  Node* expose(Node *t){
    Node *rp=nullptr;
    for(Node *c=t;c;c=c->p){
      splay(c);
      if(c->r) c->td.emplace(c->r->ld);
      c->r=rp;
      if(c->r) c->td.erase(c->td.find(c->r->ld));
      pushup(c);
      rp=c;
    }
    splay(t);
    return rp;
  }
};
//END CUT HERE
//INSERT ABOVE HERE
signed TKPPC2015_J(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  using ll = long long;
  using Node = NodeBase<ll>;
  constexpr size_t LIM = 1e6;
  using LCT = Farthest<Node, LIM>;
  LCT lct;

  vector<LCT::Node*> vs;
  vector<LCT::Node*> es;
  vs.reserve(5e5+100);
  es.reserve(5e5+100);

  int num=0;
  vs.emplace_back(lct.create(num,0));
  es.emplace_back(lct.create(num,0));
  num++;

  int q;
  cin>>q;
  for(int i=0;i<q;i++){
    int t,a,c;
    cin>>t>>a>>c;
    if(t==1){
      vs.emplace_back(lct.create(num,0));
      es.emplace_back(lct.create(num,c));
      lct.link(vs[a],es[num]);
      lct.link(es[num],vs[num]);
      num++;
    }
    if(t==2){
      lct.expose(es[a]);
      es[a]->val=c;
      lct.pushup(es[a]);
    }
    if(t==3){
      lct.evert(vs[a]);
      cout<<(vs[a]->ld)<<"\n";
    }
  }
  cout<<flush;
  return 0;
}
/*
  verified on 2019/10/25
  https://atcoder.jp/contests/tkppc/tasks/tkppc2015_j
*/

signed main(){
  TKPPC2015_J();
  return 0;
}
