#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;
using Int = long long;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
#endif
//BEGIN CUT HERE
template<typename E>
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

  struct Node{
    Node *l,*r;
    size_t cnt;
    bool rev;
    E dat,laz;
    Node(){}
    Node(E dat,E laz):
      cnt(1),rev(0),dat(dat),laz(laz){l=r=nullptr;}
  };

  using H = function<E(E,E)>;

  H h;
  E ei;

  const size_t LIM = 1e6;
  vector<Node> pool;
  size_t ptr;

  RBST(H h,E ei):h(h),ei(ei),pool(LIM),ptr(0){}

  inline Node* create(){
    return &(pool[ptr++]=Node(ei,ei));
  }

  Node* build(size_t l,size_t r){
    if(l+1==r) return create();
    size_t m=(l+r)>>1;
    return merge(build(l,m),build(m,r));
  }

  Node* init(int n){
    return build(0,n);
  }

  size_t count(const Node *a){
    return a?a->cnt:0;
  }

  Node* recalc(Node *a){
    a->cnt=count(a->l)+1+count(a->r);
    return a;
  }

  void propagate(Node *a,E x){
    a->dat=h(a->dat,x);
    a->laz=h(a->laz,x);
  }

  void toggle(Node *a){
    swap(a->l,a->r);
    a->rev^=1;
  }

  // remove "virtual" for optimization
  virtual Node* eval(Node* a){
    if(a->laz!=ei){
      if(a->l) propagate(a->l,a->laz);
      if(a->r) propagate(a->r,a->laz);
      a->laz=ei;
    }
    if(a->rev){
      if(a->l) toggle(a->l);
      if(a->r) toggle(a->r);
      a->rev=false;
    }
    return recalc(a);
  }

  pair<Node*, Node*> split(Node* a,size_t k){
    if(a==nullptr) return make_pair(a,a);
    a=eval(a);
    if(k<=count(a->l)){
      auto s=split(a->l,k);
      a->l=s.second;
      return make_pair(s.first,recalc(a));
    }
    auto s=split(a->r,k-(count(a->l)+1));
    a->r=s.first;
    return make_pair(recalc(a),s.second);
  }

  Node* merge(Node* a,Node* b){
    if(a==nullptr) return b;
    if(b==nullptr) return a;
    if(xor128()%(count(a)+count(b))<count(a)){
      a=eval(a);
      a->r=merge(a->r,b);
      return recalc(a);
    }
    b=eval(b);
    b->l=merge(a,b->l);
    return recalc(b);
  }

  Node* insert(Node *a,size_t pos){
    Node* b=create();
    auto s=split(a,pos);
    return a=merge(merge(s.first,b),s.second);
  }

  Node* erase(Node *a,size_t pos){
    auto s=split(a,pos);
    auto t=split(s.second,1);
    return merge(s.first,t.second);
  }

  Node* toggle(Node *a,size_t l,size_t r){
    auto s=split(a,l);
    auto t=split(s.second,r-l);
    auto u=eval(t.first);
    toggle(u);
    return merge(s.first,merge(u,t.second));
  }

  Node* update(Node *a,size_t l,size_t r,E x){
    auto s=split(a,l);
    auto t=split(s.second,r-l);
    auto u=eval(t.first);
    propagate(u,x);
    return merge(s.first,merge(u,t.second));
  }

  Node* set_val(Node *a,size_t k,E x){
    assert(k<count(a));
    a=eval(a);
    size_t num=count(a->l);
    if(k<num) a->l=set_val(a->l,k,x);
    if(k>num) a->r=set_val(a->r,k-(num+1),x);
    if(k==num) a->dat=x;
    return recalc(a);
  }

  E get_val(Node *a,size_t k){
    assert(k<count(a));
    a=eval(a);
    size_t num=count(a->l);
    if(k<num) return get_val(a->l,k);
    if(k>num) return get_val(a->r,k-(num+1));
    return a->dat;
  }

  void dump(Node* a,typename vector<E>::iterator it){
    if(!count(a)) return;
    a=eval(a);
    dump(a->l,it);
    *(it+count(a->l))=a->dat;
    dump(a->r,it+count(a->l)+1);
  }

  vector<E> dump(Node* a){
    vector<E> v(count(a));
    dump(a,v.begin());
    return v;
  }
};
//END CUT HERE
//INSERT ABOVE HERE
#ifndef call_from_test
signed main(){
  return 0;
}
#endif
