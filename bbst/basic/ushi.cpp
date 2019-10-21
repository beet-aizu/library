#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;
using Int = long long;
#endif
//BEGIN CUT HERE
template<typename T>
struct SRBST{
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

  SRBST(F f,T ti):f(f),ti(ti),pool(LIM),ptr(0){
    flip=[](T a){return a;};
  }

  SRBST(F f,S flip,T ti):
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
#ifndef call_from_test
//INSERT ABOVE HERE
signed HAPPYQUERY_C(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n;
  cin>>n;
  vector<int> vs(n);
  for(int i=0;i<n;i++) cin>>vs[i];

  int q;
  cin>>q;
  vector<int> ts(q);
  vector<int> ls(q),rs(q);
  vector<int> ps(q),xs(q);
  vector<int> as(q),bs(q),cs(q),ds(q);
  for(int i=0;i<q;i++){
    cin>>ts[i];
    if(ts[i]==1) cin>>ls[i]>>rs[i],ls[i]--;
    if(ts[i]==2) cin>>ps[i]>>xs[i],ps[i]--;
    if(ts[i]==3){
      cin>>as[i]>>bs[i]>>cs[i]>>ds[i];
      as[i]--;cs[i]--;
    }
  }

  using ll = long long;
  auto f=[](ll a,ll b){return a+b;};
  ll ti=0;
  SRBST<ll> srbst(f,ti);

  unordered_map<int, ll> memo;
  auto hs=
    [&](int x){
      if(!memo.count(x))
        memo[x]=srbst.xor128();
      return memo[x];
    };

  vector<ll> ws(n);
  for(int i=0;i<n;i++) ws[i]=hs(vs[i]);
  auto rt=srbst.build(ws);

  for(int i=0;i<q;i++){
    if(ts[i]==1) rt=srbst.toggle(rt,ls[i],rs[i]);
    if(ts[i]==2) rt=srbst.set_val(rt,ps[i],hs(xs[i]));
    if(ts[i]==3){
      ll x=srbst.query(rt,as[i],bs[i]);
      ll y=srbst.query(rt,cs[i],ds[i]);
      cout<<(x==y?"Yes":"No")<<"\n";
    }
  }
  cout<<flush;
  return 0;
}
/*
  verified on 2019/06/24
  https://www.hackerrank.com/contests/happy-query-contest/challenges/range-sorting-query
*/

signed main(){
  HAPPYQUERY_C();
  return 0;
}
#endif
