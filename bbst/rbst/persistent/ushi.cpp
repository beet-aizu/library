#ifndef call_from_test

#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../basic/base.cpp"
#include "../basic/ushi.cpp"
#undef call_from_test

#endif
//BEGIN CUT HERE
template<typename Node, size_t LIM>
struct PersistentUshi : Ushi<Node, LIM>{
  using super = Ushi<Node, LIM>;
  using super::super;
  using T = typename Node::T;

  inline Node* clone(Node* t){
    if(t==nullptr) return t;
    return super::create(*t);
  }

  Node* eval(Node* t){
    t=clone(t);
    if(t->rev){
      t->l=clone(t->l);
      t->r=clone(t->r);
    }
    return super::eval(t);
  }

  T query(Node *a,size_t l,size_t r){
    auto s=super::split(a,l);
    auto t=super::split(s.second,r-l);
    return super::query(t.first);
  }

  Node* rebuild(Node* a){
    auto vs=super::dump(a);
    super::size=0;
    return super::build(vector<Node>(vs.begin(),vs.end()));
  }

  bool almost_full() const{
    return super::size>LIM*9/10;
  }
};
//END CUT HERE
//INSERT ABOVE HERE
#ifndef call_from_test
signed main(){
  return 0;
}
#endif
