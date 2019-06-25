#include<bits/stdc++.h>
using namespace std;
using Int = long long;
//BEGIN CUT HERE
template<typename T>
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
    T val,dat;
    Node():cnt(0),rev(0){l=r=nullptr;}
    Node(T val):
      cnt(1),rev(0),val(val),dat(val){l=r=nullptr;}
  };

  using F = function<T(T,T)>;
  using S = function<T(T)>;

  F f;
  S flip;
  T ti;

  const size_t LIM = 1e6;
  vector<Node> pool;
  size_t ptr;

  RBST(F f,T ti):f(f),ti(ti),pool(LIM),ptr(0){
    flip=[](T a){return a;};
  }

  RBST(F f,S flip,T ti):
    f(f),flip(flip),ti(ti),pool(LIM),ptr(0){}

  Node* build(size_t l,size_t r,vector<T> &v){
    if(l+1==r) return create(v[l]);
    size_t m=(l+r)>>1;
    return merge(build(l,m,v),build(m,r,v));
  }

  Node* build(vector<T> &v){
    return build(0,v.size(),v);
  }

  inline Node* create(){
    return &pool[ptr++];
  }

  inline Node* create(T v){
    return &(pool[ptr++]=Node(v));
  }

  size_t count(const Node *a){
    return a?a->cnt:0;
  }

  T query(const Node *a){
    return a?a->dat:ti;
  }

  Node* recalc(Node *a){
    a->cnt=count(a->l)+1+count(a->r);
    a->dat=a->val;
    if(a->l) a->dat=f(a->l->dat,a->dat);
    if(a->r) a->dat=f(a->dat,a->r->dat);
    return a;
  }

  void toggle(Node *a){
    swap(a->l,a->r);
    a->dat=flip(a->dat);
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

  Node* toggle(Node *a,size_t l,size_t r){
    auto s=split(a,l);
    auto t=split(s.second,r-l);
    auto u=eval(t.first);
    toggle(u);
    return merge(s.first,merge(u,t.second));
  }

  T query(Node *&a,size_t l,size_t r){
    auto s=split(a,l);
    auto t=split(s.second,r-l);
    auto u=t.first;
    T res=query(u);
    a=merge(s.first,merge(u,t.second));
    return res;
  }

  Node* set_val(Node *a,size_t k,T val){
    assert(k<count(a));
    a=eval(a);
    size_t num=count(a->l);
    if(k<num) a->l=set_val(a->l,k,val);
    if(k>num) a->r=set_val(a->r,k-(num+1),val);
    if(k==num) a->val=val;
    return recalc(a);
  }

  T get_val(Node *a,size_t k){
    assert(k<count(a));
    a=eval(a);
    size_t num=count(a->l);
    if(k<num) return get_val(a->l,k);
    if(k>num) return get_val(a->r,k-(num+1));
    return a->val;
  }

  void dump(Node* a,typename vector<T>::iterator it){
    if(!count(a)) return;
    a=eval(a);
    dump(a->l,it);
    *(it+count(a->l))=a->val;
    dump(a->r,it+count(a->l)+1);
  }

  vector<T> dump(Node* a){
    vector<T> v(count(a));
    dump(a,v.begin());
    return v;
  }
};
//END CUT HERE
//INSERT ABOVE HERE
signed DSL_2_A(){
  int n,q;
  scanf("%d %d",&n,&q);
  auto f=[](int a,int b){return min(a,b);};
  RBST<int> rbst(f,INT_MAX);
  vector<int> v(n,INT_MAX);
  auto rt=rbst.build(v);

  for(int i=0;i<q;i++){
    int c,s,t;
    scanf("%d %d %d",&c,&s,&t);
    if(c){
      printf("%d\n",rbst.query(rt,s,t+1));
    }else{
      rt=rbst.set_val(rt,s,t);
    }
  }
  return 0;
}
/*
  verified on 2019/06/24
  http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A&lang=jp
*/

signed main(){
  DSL_2_A();
  return 0;
}
