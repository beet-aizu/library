#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../basic/base.cpp"
#undef call_from_test

#endif
//BEGIN CUT HERE
template<typename Node, size_t LIM, typename Impl>
struct PersistentBase : BBSTBase<Node, LIM, PersistentBase<Node, LIM, Impl>>{
  using super = BBSTBase<Node, LIM, PersistentBase>;
  using T = typename Node::T;

  static bool exist;
  PersistentBase(){
    // rebuild destroys all elements in the pool
    assert(!exchange(exist,true));
  }

  inline Node* clone(Node* a){
    if(a==nullptr) return a;
    return super::create(*a);
  }

  inline void toggle(Node *t){
    static_cast<Impl*>(this)->toggle(t);
  }

  inline Node* eval(Node *t){
    return static_cast<Impl*>(this)->eval(t);
  }

  inline Node* pushup(Node *t){
    return static_cast<Impl*>(this)->pushup(t);
  }

  using super::count;
  void dump(Node* a,typename vector<Node>::iterator it){
    if(!count(a)) return;
    a=eval(a);
    auto cur=it+count(a->l);
    dump(a->l,it);
    dump(a->r,it+count(a->l)+1);
    a->l=a->r=nullptr;
    *cur=*pushup(a);
  }

  vector<Node> dump(Node* a){
    assert(a!=nullptr);
    vector<Node> vs(count(a),*a);
    dump(a,vs.begin());
    return vs;
  }

  Node* rebuild(Node* a){
    auto vs=dump(a);
    super::size=0;
    return super::build(vs);
  }

  bool almost_full(double d=0.8) const{
    return super::size>LIM*d;
  }
};
template<typename Node, size_t LIM, typename Impl>
bool PersistentBase<Node, LIM, Impl>::exist = false;
//END CUT HERE
#ifndef call_from_test
//INSERT ABOVE HERE
signed main(){
  return 0;
}
#endif
