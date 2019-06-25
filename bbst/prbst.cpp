#include<bits/stdc++.h>
using namespace std;
using Int = long long;
template<typename T, typename E>
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
    E laz;
    Node():cnt(0),rev(0){l=r=nullptr;}
    Node(T val,E laz):
      cnt(1),rev(0),val(val),dat(val),laz(laz){l=r=nullptr;}
  };

  using F = function<T(T,T)>;
  using G = function<T(T,E)>;
  using H = function<E(E,E)>;
  using S = function<T(T)>;

  F f;
  G g;
  H h;
  S flip;
  T ti;
  E ei;

  const size_t LIM = 1.3e7;
  vector<Node> pool;
  size_t ptr;

  RBST(F f,G g,H h,T ti,E ei):
    f(f),g(g),h(h),ti(ti),ei(ei),pool(LIM),ptr(0){
    flip=[](T a){return a;};
  }

  RBST(F f,G g,H h,S flip,T ti,E ei):
    f(f),g(g),h(h),flip(flip),ti(ti),ei(ei),pool(LIM),ptr(0){}

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
    return &(pool[ptr++]=Node(v,ei));
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

  void propagate(Node *a,E v){
    a->laz=h(a->laz,v);
    a->val=g(a->val,v);
    a->dat=g(a->dat,v);
  }

  void toggle(Node *a){
    swap(a->l,a->r);
    a->dat=flip(a->dat);
    a->rev^=1;
  }

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

  Node* update(Node *a,size_t l,size_t r,E x){
    auto s=split(a,l);
    auto t=split(s.second,r-l);
    auto u=eval(t.first);
    propagate(u,x);
    return merge(s.first,merge(u,t.second));
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

//BEGIN CUT HERE
template<typename T, typename E>
struct PRBST : RBST<T, E>{
  using super = RBST<T, E>;
  using super::RBST;
  using typename super::Node;

  inline Node* clone(Node* a){
    if(a==nullptr) return a;
    Node* b=super::create();
    *b=*a;
    return b;
  }

  Node* eval(Node* a){
    a=clone(a);
    a->l=clone(a->l);
    a->r=clone(a->r);
    return super::eval(a);
  }

  T query(Node *a,size_t l,size_t r){
    auto s=super::split(a,l);
    auto t=super::split(s.second,r-l);
    return super::query(t.first);
  }

  Node* rebuild(Node* a){
    auto v=super::dump(a);
    super::ptr=0;
    return super::build(v);
  }

  bool almost_full() const{
    return super::ptr>super::LIM*95/100;
  }
};
//END CUT HERE
//INSERT ABOVE HERE
signed ARC030_D(){
  int n,q;
  scanf("%d %d",&n,&q);
  using P = pair<Int, Int>;
  vector<P> v(n,P(0,1));
  for(int i=0;i<n;i++) scanf("%lld",&v[i].first);

  auto f=[](P a,P b){return P(a.first+b.first,a.second+b.second);};
  auto g=[](P a,Int b){return P(a.first+b*a.second,a.second);};
  auto h=[](Int a,Int b){return a+b;};

  PRBST<P, Int> prbst(f,g,h,P(0,0),0);
  auto rt=prbst.build(v);

  for(int i=0;i<q;i++){
    int t;
    scanf("%d",&t);
    if(t==1){
      int a,b,v;
      scanf("%d %d %d",&a,&b,&v);
      a--;
      rt=prbst.update(rt,a,b,v);
    }
    if(t==2){
      int a,b,c,d;
      scanf("%d %d %d %d",&a,&b,&c,&d);
      a--;c--;
      auto s=prbst.split(rt,a);
      auto t=prbst.split(s.second,b-a);
      auto u=prbst.split(rt,c);
      auto v=prbst.split(u.second,d-c);

      rt=prbst.merge(prbst.merge(s.first,v.first),t.second);
    }
    if(t==3){
      int a,b;
      scanf("%d %d",&a,&b);
      a--;
      printf("%lld\n",prbst.query(rt,a,b).first);
    }

    if(prbst.almost_full()) rt=prbst.rebuild(rt);
  }
  return 0;
}
/*
  verified on 2019/06/12
  https://beta.atcoder.jp/contests/arc030/tasks/arc030_4
*/

signed main(){
  ARC030_D();
  return 0;
}
