#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../rbst.cpp"
#undef call_from_test

#endif
//BEGIN CUT HERE
template<typename Data, size_t LIM>
struct Persistent : RBST<Persistent<Data, LIM>, Data, typename Data::Node, LIM>{
  using super = RBST<Persistent, Data, typename Data::Node, LIM>;
  using Node = typename Data::Node;

  Data data;

  template<class... Args>
  Persistent(Args... args):data(forward<Args>(args)...){}

  inline Node* clone(Node *t){
    if(t==nullptr) return t;
    return super::create(*t);
  }

  inline Node* touch(Node *t){
    if(t==nullptr) return t;
    t=clone(t);
    if(data.dirty(t)){
      t->l=clone(t->l);
      t->l=clone(t->r);
    }
    return data.eval(t);
  }

  using super::toggle;
  inline void toggle(Node *t){return data.toggle(t);}
  template<typename E>
  inline void propagate(Node *t,E x){return data.propagate(t,x);}
  inline Node* pushup(Node *t){return data.pushup(t);}

  inline decltype(auto) get_val(Node *a,size_t k){
    return data.reflect(super::get_val(a,k));
  }

  using super::query;
  inline decltype(auto) query(Node *a){
    return data.reflect(a);
  }

  bool almost_full() const{
    return super::size+1000>LIM;
  }

  Node* rebuild(Node* a){
    auto vs=data.dump(a);
    super::size=0;
    return super::build(vs);
  }
};
//END CUT HERE
#ifndef call_from_test
//INSERT ABOVE HERE
signed main(){
  return 0;
}
#endif
