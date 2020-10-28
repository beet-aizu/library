#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#include "base.cpp"
#undef call_from_test

#endif
//BEGIN CUT HERE
template<typename Tp, typename Ep>
struct NodeBase{
  using T = Tp;
  using E = Ep;
  NodeBase *l,*r,*p;
  size_t cnt;
  bool rev;
  T val,dat;
  E laz;
  NodeBase(T val,E laz):
    cnt(1),rev(0),val(val),dat(val),laz(laz){l=r=p=nullptr;}
};

template<typename Node, size_t LIM>
struct Lazy : BBSTBase<Node, LIM, Lazy<Node, LIM>>{
  using super = BBSTBase<Node, LIM, Lazy>;

  using T = typename Node::T;
  using E = typename Node::E;

  using F = function<T(T, T)>;
  using G = function<T(T, E)>;
  using H = function<E(E, E)>;
  using S = function<T(T)>;

  F f;
  G g;
  H h;
  S flip;
  T ti;
  E ei;

  Lazy(F f,G g,H h,S flip,T ti,E ei):
    f(f),g(g),h(h),flip(flip),ti(ti),ei(ei){}

  Lazy(F f,G g,H h,T ti,E ei):
    Lazy(f,g,h,[](T a){return a;},ti,ei){}

  inline void propagate(Node *t,E v){
    t->laz=h(t->laz,v);
    t->val=g(t->val,v);
    t->dat=g(t->dat,v);
  }

  inline void toggle(Node *t){
    swap(t->l,t->r);
    t->val=flip(t->val);
    t->dat=flip(t->dat);
    t->rev^=1;
  }

  inline Node* eval(Node* t){
    if(t->laz!=ei){
      if(t->l) propagate(t->l,t->laz);
      if(t->r) propagate(t->r,t->laz);
      t->laz=ei;
    }
    if(t->rev){
      if(t->l) toggle(t->l);
      if(t->r) toggle(t->r);
      t->rev=false;
    }
    return t;
  }

  using super::count;
  inline Node* pushup(Node *t){
    t->cnt=count(t->l)+1+count(t->r);
    t->dat=t->val;
    if(t->l) t->dat=f(t->l->dat,t->dat);
    if(t->r) t->dat=f(t->dat,t->r->dat);
    return t;
  }

  using super::merge;
  using super::split;

  T query(const Node *a){
    return a?a->dat:ti;
  }

  T query(Node *&a,size_t l,size_t r){
    auto s=split(a,l);
    auto t=split(s.second,r-l);
    auto u=t.first;
    T res=query(u);
    a=merge(s.first,merge(u,t.second));
    return res;
  }

  Node* update(Node *a,size_t l,size_t r,E v){
    auto s=split(a,l);
    auto t=split(s.second,r-l);
    auto u=eval(t.first);
    propagate(u,v);
    return merge(s.first,merge(u,t.second));
  }

  T get_val(Node *a,size_t k){
    assert(k<count(a));
    a=eval(a);
    size_t num=count(a->l);
    if(k<num) return get_val(a->l,k);
    if(k>num) return get_val(a->r,k-(num+1));
    return a->val;
  }

  Node* set_val(Node *a,size_t k,T val){
    assert(k<count(a));
    a=eval(a);
    size_t num=count(a->l);
    if(k<num) a->l=set_val(a->l,k,val);
    if(k>num) a->r=set_val(a->r,k-(num+1),val);
    if(k==num) a->val=val;
    return pushup(a);
  }
};
//END CUT HERE
#ifndef call_from_test
//INSERT ABOVE HERE

// test insert, erase
signed CODEFESTIVAL2014EXHIBITION_B(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int Q;
  cin>>Q;

  string S;
  cin>>S;

  using T = tuple<int, int, int>;
  using P = pair<int, int>;
  auto f=[](T a,T b){
    return T(min(get<0>(a),get<0>(b)),min(get<1>(a),get<1>(b)),0);
  };
  auto g=[](T a,P b){
    return T(get<0>(a)+b.first,get<1>(a)+b.second,get<2>(a));
  };
  auto h=[](P a,P b){
    return P(a.first+b.first,a.second+b.second);
  };
  const int INF = 1e9;

  using Node = NodeBase<T, P>;
  constexpr size_t LIM = 1e6;
  Lazy<Node, LIM> G(f,g,h,T(INF,INF,0),P(0,0));

  vector<Node> vs((int)S.size()+2,Node(T(0,0,0),G.ei));
  auto rt=G.build(vs);

  for(int i=0;i<(int)S.size();i++)
    rt=G.set_val(rt,i+1,T(0,0,S[i]=='('?+1:-1));

  for(int i=1;i<=(int)S.size();i++){
    int z=get<2>(G.get_val(rt,i));
    rt=G.update(rt,i,G.count(rt),P(+z,0));
    rt=G.update(rt,0,i+1,P(0,-z));
  }

  for(int i=0;i<Q;i++){
    char x;
    int y,z;
    cin>>x>>y>>z;

    z++;
    if(x=='(' or x==')'){
      z=(x=='('?+1:-1);
      T prv=G.get_val(rt,y-1);
      T nxt=G.get_val(rt,y);
      T cur(get<0>(prv),get<1>(nxt),z);
      rt=G.insert(rt,y,Node(cur,P(0,0)));
      rt=G.update(rt,y,G.count(rt),P(z,0));
      rt=G.update(rt,0,y+1,P(0,-z));
    }

    if(x=='D'){
      z=get<2>(G.get_val(rt,y));
      rt=G.erase(rt,y);
      rt=G.update(rt,y,G.count(rt),P(-z,0));
      rt=G.update(rt,0,y,P(0,z));
    }

    if(x=='Q'){
      T prv=G.get_val(rt,y-1);
      T cur=G.query(rt,y,z);
      T nxt=G.get_val(rt,z);
      int ans=0;
      if(get<0>(prv)>get<0>(cur)) ans+=get<0>(prv)-get<0>(cur);
      if(get<1>(nxt)>get<1>(cur)) ans+=get<1>(nxt)-get<1>(cur);
      cout<<ans<<'\n';
    }
  }

  return 0;
}
/*
  verified on 2020/10/28
  https://atcoder.jp/contests/code-festival-2014-exhibition-open/tasks/code_festival_exhibition_b
*/

signed main(){
  CODEFESTIVAL2014EXHIBITION_B();
  return 0;
}
#endif
