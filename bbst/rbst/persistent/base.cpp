#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../basic/base.cpp"
#undef call_from_test

#endif
//BEGIN CUT HERE
template<typename Node, size_t LIM, typename Impl>
struct PersistentBase : BBSTBase<Node, LIM, PersistentBase<Node, LIM, Impl>>{
  using super = BBSTBase<Node, LIM, PersistentBase>;
  using super::super;
  using T = typename Node::T;

  inline Node* clone(Node* a){
    if(a==nullptr) return a;
    return super::create(*a);
  }

  inline void toggle(Node *t){
    ((Impl*)(this))->toggle(t);
  }

  inline Node* eval(Node* a){
    a=clone(a);
    if(a->rev){
      a->l=clone(a->l);
      a->r=clone(a->r);
    }
    return ((Impl*)(this))->eval(a);
  }

  inline Node* pushup(Node *t){
    return ((Impl*)(this))->pushup(t);
  }

  bool almost_full() const{
    return super::size>LIM*9/10;
  }

  Node* rebuild(Node* a){
    auto vs=super::template dump<T>(a);
    super::size=0;
    return super::build(vector<Node>(vs.begin(),vs.end()));
  }
};
//END CUT HERE
#ifndef call_from_test
signed main(){
  return 0;
}
#endif
