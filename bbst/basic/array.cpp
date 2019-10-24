#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;
using Int = long long;

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

  static array<Node, LIM> pool;
  size_t ptr;
  BBSTBase():ptr(0){}

  size_t count(const Node *a){
    return a?a->cnt:0;
  }

  inline Node* create(){
    return &pool[ptr++];
  }

  template<typename T>
  inline Node* create(T v){
    return &(pool[ptr++]=Node(v));
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

  template<typename T>
  Node* insert(Node *a,size_t pos,T v){
    Node* b=create(v);
    auto s=split(a,pos);
    return a=merge(merge(s.first,b),s.second);
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
    return a->p&&a->p->r==a;
  }

  size_t order_of_key(Node* a){
    size_t res=count(a->l);
    while(a){
      if(is_right(a)) res+=count(a->p->l)+1;
      a=a->p;
    }
    return res;
  }

  template<typename T>
  Node* build(size_t l,size_t r,const vector<T> &vs){
    if(l+1==r) return create(vs[l]);
    size_t m=(l+r)>>1;
    return merge(build(l,m,vs),build(m,r,vs));
  }

  template<typename T>
  Node* build(const vector<T> &vs){
    return build(0,vs.size(),vs);
  }
};
template<typename Node, size_t LIM>
array<Node, LIM> BBSTBase<Node, LIM>::pool;
#endif
//BEGIN CUT HERE
template<typename Tp>
struct NodeBase{
  using T = Tp;
  NodeBase *p,*l,*r;
  size_t cnt;
  bool rev;
  T val;
  NodeBase():cnt(0),rev(0){p=l=r=nullptr;}
  NodeBase(T val):
    cnt(1),rev(0),val(val){p=l=r=nullptr;}
};

template<typename Node, size_t LIM>
struct Array : BBSTBase<Node, LIM>{
  using T = typename Node::T;
  using super = BBSTBase<Node, LIM>;

  Array():super(){}

  using super::count;

  Node* recalc(Node *a){
    a->cnt=count(a->l)+1+count(a->r);
    return a;
  }

  void toggle(Node *a){
    swap(a->l,a->r);
    a->rev^=1;
  }

  // remove "virtual" for optimization
  virtual Node* eval(Node* a){
    if(a->rev){
      if(a->l) toggle(a->l);
      if(a->r) toggle(a->r);
      a->rev=false;
    }
    return recalc(a);
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

  void dump(Node* a,typename vector<T>::iterator it){
    if(!count(a)) return;
    if(a->rev){
      if(a->l) toggle(a->l);
      if(a->r) toggle(a->r);
      a->rev=false;
    }
    dump(a->l,it);
    *(it+count(a->l))=a->val;
    dump(a->r,it+count(a->l)+1);
  }

  vector<T> dump(Node* a){
    vector<T> vs(count(a));
    dump(a,vs.begin());
    return vs;
  }
};
//END CUT HERE
#ifndef call_from_test
//INSERT ABOVE HERE
signed main(){
  return 0;
}
#endif
