#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;
#endif
//BEGIN CUT HERE
template<typename Impl, typename Data, typename Node, size_t LIM>
struct RBST{
  using u32 = uint32_t;
  u32 xor128(){
    static u32 x = 123456789;
    static u32 y = 362436069;
    static u32 z = 521288629;
    static u32 w = 88675123;

    u32 t = x ^ (x << 11);
    x = y; y = z; z = w;
    return w = (w ^ (w >> 19)) ^ (t ^ (t >> 8));
  }

  alignas(Node) static inline char pool[sizeof(Node)*LIM];
  static inline Node* ptr = (Node*)pool;
  static inline size_t size;

  template<typename... Args>
  inline Node* create(Args&&... args){
    return new (ptr+size++) Node(std::forward<Args>(args)...);
  }

  inline size_t count(const Node *t){return Data::count(t);}

  inline Node* touch(Node *t){
    return static_cast<Impl*>(this)->touch(t);
  }

  inline void toggle(Node *t){
    return static_cast<Impl*>(this)->toggle(t);
  }

  inline Node* pushup(Node *t){
    return static_cast<Impl*>(this)->pushup(t);
  }

  Node* toggle(Node *a,size_t l,size_t r){
    auto s=split(a,l);
    auto t=split(s.second,r-l);
    auto u=touch(t.first);
    toggle(u);
    return merge(s.first,merge(u,t.second));
  }

  Node* merge(Node* a,Node* b){
    if(a==nullptr) return b;
    if(b==nullptr) return a;
    if(xor128()%(count(a)+count(b))<count(a)){
      a=touch(a);
      a->r=merge(a->r,b);
      a->r->p=a;
      return pushup(a);
    }
    b=touch(b);
    b->l=merge(a,b->l);
    b->l->p=b;
    return pushup(b);
  }

  pair<Node*, Node*> split(Node* a,size_t k){
    if(a==nullptr) return make_pair(a,a);
    a=touch(a);
    if(k<=count(a->l)){
      if(a->l) a->l->p=nullptr;
      auto s=split(a->l,k);
      a->l=s.second;
      if(a->l) a->l->p=a;
      return make_pair(s.first,pushup(a));
    }
    if(a->r) a->r->p=nullptr;
    auto s=split(a->r,k-(count(a->l)+1));
    a->r=s.first;
    if(a->r) a->r->p=a;
    return make_pair(pushup(a),s.second);
  }

  Node* insert(Node *a,size_t k,Node v){
    Node* b=create(v);
    auto s=split(a,k);
    return merge(merge(s.first,b),s.second);
  }

  Node* erase(Node *a,size_t k){
    assert(k<count(a));
    auto s=split(a,k);
    auto t=split(s.second,1);
    return merge(s.first,t.second);
  }

  Node* find_by_order(Node *a,size_t k){
    assert(k<count(a));
    a=touch(a);
    size_t num=count(a->l);
    if(k<num) return find_by_order(a->l,k);
    if(k>num) return find_by_order(a->r,k-(num+1));
    return a;
  }

  inline bool is_right(Node* a){
    return a->p and a->p->r==a;
  }

  size_t order_of_key(Node* a){
    size_t res=count(a->l);
    while(a){
      if(is_right(a)) res+=count(a->p->l)+1;
      a=a->p;
    }
    return res;
  }

  Node* build(size_t l,size_t r,const vector<Node> &vs){
    if(l+1==r) return create(vs[l]);
    size_t m=(l+r)>>1;
    return merge(build(l,m,vs),build(m,r,vs));
  }

  Node* build(const vector<Node> &vs){
    return build(0,vs.size(),vs);
  }

  template<typename T>
  Node* set_val(Node *a,size_t k,T val){
    assert(k<count(a));
    a=touch(a);
    size_t num=count(a->l);
    if(k<num) a->l=set_val(a->l,k,val);
    if(k>num) a->r=set_val(a->r,k-(num+1),val);
    if(k==num) a->val=val;
    return pushup(a);
  }

  Node* get_val(Node *a,size_t k){
    assert(k<count(a));
    a=touch(a);
    size_t num=count(a->l);
    if(k<num) return get_val(a->l,k);
    if(k>num) return get_val(a->r,k-(num+1));
    return a;
  }

  template<typename E>
  Node* update(Node *a,size_t l,size_t r,E v){
    auto s=split(a,l);
    auto t=split(s.second,r-l);
    auto u=touch(t.first);
    static_cast<Impl*>(this)->propagate(u,v);
    return merge(s.first,merge(u,t.second));
  }

  decltype(auto) query(Node *&a,size_t l,size_t r){
    auto s=split(a,l);
    auto t=split(s.second,r-l);
    auto u=t.first;
    auto res=static_cast<Impl*>(this)->query(u);
    a=merge(s.first,merge(u,t.second));
    return res;
  }
};
//END CUT HERE
#ifndef call_from_test
//INSERT ABOVE HERE
signed main(){
  return 0;
}
#endif
