#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;
#endif
//BEGIN CUT HERE
template<typename Node, size_t LIM>
struct BBSTBase{
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

  alignas(Node) static byte pool[sizeof(Node) * LIM];
  static Node* ptr;
  static size_t size;

  template<typename... Args>
  inline Node* create(Args&&... args){
    return new (ptr+size++) Node(std::forward<Args>(args)...);
  }

  size_t count(const Node *a){
    return a?a->cnt:0;
  }

  virtual void toggle(Node *a)=0;
  virtual Node* eval(Node* a)=0;
  virtual Node* recalc(Node* a)=0;

  Node* toggle(Node *a,size_t l,size_t r){
    auto s=split(a,l);
    auto t=split(s.second,r-l);
    auto u=eval(t.first);
    toggle(u);
    return merge(s.first,merge(u,t.second));
  }

  Node* merge(Node* a,Node* b){
    if(a==nullptr) return b;
    if(b==nullptr) return a;
    if(xor128()%(count(a)+count(b))<count(a)){
      a=eval(a);
      a->r=merge(a->r,b);
      a->r->p=a;
      return recalc(a);
    }
    b=eval(b);
    b->l=merge(a,b->l);
    b->l->p=b;
    return recalc(b);
  }

  pair<Node*, Node*> split(Node* a,size_t k){
    if(a==nullptr) return make_pair(a,a);
    a=eval(a);
    if(k<=count(a->l)){
      if(a->l) a->l->p=nullptr;
      auto s=split(a->l,k);
      a->l=s.second;
      if(a->l) a->l->p=a;
      return make_pair(s.first,recalc(a));
    }
    if(a->r) a->r->p=nullptr;
    auto s=split(a->r,k-(count(a->l)+1));
    a->r=s.first;
    if(a->r) a->r->p=a;
    return make_pair(recalc(a),s.second);
  }

  Node* insert(Node *a,size_t pos,Node v){
    Node* b=create(v);
    auto s=split(a,pos);
    return merge(merge(s.first,b),s.second);
  }

  Node* erase(Node *a,size_t pos){
    auto s=split(a,pos);
    auto t=split(s.second,1);
    return merge(s.first,t.second);
  }

  Node* find_by_order(Node *a,size_t k){
    assert(k<count(a));
    a=eval(a);
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
};
template<typename Node, size_t LIM>
alignas(Node) byte BBSTBase<Node, LIM>::pool[];
template<typename Node, size_t LIM>
Node* BBSTBase<Node, LIM>::ptr=(Node*)BBSTBase<Node, LIM>::pool;
template<typename Node, size_t LIM>
size_t BBSTBase<Node, LIM>::size=0;
//END CUT HERE
#ifndef call_from_test
//INSERT ABOVE HERE
signed main(){
  return 0;
}
#endif
