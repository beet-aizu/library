#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../basic/base.cpp"
#include "base.cpp"
#undef call_from_test

#endif
//BEGIN CUT HERE
template<typename Tp>
struct NodeBase{
  using T = Tp;
  NodeBase *l,*r,*p;
  size_t cnt;
  bool rev;
  T val;
  NodeBase(T val):
    cnt(1),rev(0),val(val){l=r=p=nullptr;}
};

template<typename Node, size_t LIM>
struct PersistentArray :
  PersistentBase<Node, LIM, PersistentArray<Node, LIM>>{
  using super = PersistentBase<Node, LIM, PersistentArray>;
  using T = typename Node::T;

  inline void toggle(Node *t){
    swap(t->l,t->r);
    t->rev^=1;
  }

  using super::clone;
  inline Node* eval(Node* t){
    t=clone(t);
    if(t->rev){
      t->l=clone(t->l);
      t->r=clone(t->r);

      if(t->l) toggle(t->l);
      if(t->r) toggle(t->r);
      t->rev=false;
    }
    return t;
  }

  using super::count;
  inline Node* pushup(Node *t){
    t->cnt=count(t->l)+1+count(t->r);
    return t;
  }

  void dump_impl(typename vector<Node>::iterator it,
                 Node* const t,bool rev){
    if(!count(t)) return;

    Node *l=t->l,*r=t->r;
    if(rev) swap(l,r);
    rev^=t->rev;

    dump_impl(it,l,rev);
    *(it+count(l))=Node(t->val);
    dump_impl(it+count(l)+1,r,rev);
  }

  using super::dump;
  void dump(typename vector<Node>::iterator it,Node* t){
    dump_impl(it,t,false);
  }

  using super::find_by_order;

  Node* set_val(Node *a,size_t k,T val){
    auto b=find_by_order(a,k);
    b->val=val;
    return b;
  }

  T get_val(Node *a,size_t k){
    return find_by_order(a,k)->val;
  }
};
//END CUT HERE
#ifndef call_from_test
//INSERT ABOVE HERE
signed JOISC2012_COPYPASTE(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  int m;
  string buf;
  cin>>m>>buf;

  using Node = NodeBase<char>;
  const size_t LIM = 1e7;
  PersistentArray<Node, LIM> pa;

  vector<Node> vs(buf.begin(),buf.end());
  auto rt=pa.build(vs);

  int n;
  cin>>n;
  for(int i=0;i<n;i++){
    int a,b,c;
    cin>>a>>b>>c;
    auto s=pa.split(rt,a);
    auto t=pa.split(s.second,b-a);
    auto u=pa.split(rt,c);
    rt=pa.merge(pa.merge(u.first,t.first),u.second);

    if((int)pa.count(rt)>m)
      rt=pa.split(rt,m).first;

    if(pa.almost_full()) rt=pa.rebuild(rt);
  }

  auto ds=pa.dump(rt);
  buf.resize(ds.size());
  for(int i=0;i<(int)ds.size();i++) buf[i]=ds[i].val;
  cout<<buf<<endl;
  return 0;
}
/*
  verified on 2020/10/28
  https://atcoder.jp/contests/joisc2012/tasks/joisc2012_copypaste
*/

signed main(){
  JOISC2012_COPYPASTE();
  return 0;
}
#endif
