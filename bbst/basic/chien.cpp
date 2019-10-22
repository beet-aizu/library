#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;
using Int = long long;
#endif
//BEGIN CUT HERE
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

  const size_t LIM = 1e6;
  vector<Node> pool;
  size_t ptr;

  RBST(F f,G g,H h,T ti,E ei):
    f(f),g(g),h(h),ti(ti),ei(ei),pool(LIM),ptr(0){
    flip=[](T a){return a;};
  }

  RBST(F f,G g,H h,S flip,T ti,E ei):
    f(f),g(g),h(h),flip(flip),ti(ti),ei(ei),pool(LIM),ptr(0){}

  Node* build(size_t l,size_t r,const vector<T> &vs){
    if(l+1==r) return create(vs[l]);
    size_t m=(l+r)>>1;
    return merge(build(l,m,vs),build(m,r,vs));
  }

  Node* build(const vector<T> &vs){
    return build(0,vs.size(),vs);
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
//END CUT HERE
#ifndef call_from_test
//INSERT ABOVE HERE
char buf[114514];
signed CODEFESTIVAL2014EXHIBITION_B(){
  int Q;
  scanf("%d",&Q);
  scanf("%s\n",buf);
  string S(buf);
  using T = tuple<int, int, int>;
  using P = pair<int, int>;
  auto f=[](T a,T b){
           return T(min(get<0>(a),get<0>(b)),min(get<1>(a),get<1>(b)),0);
         };
  auto g=[](T a,P b){
           return T(get<0>(a)+b.first,get<1>(a)+b.second,get<2>(a));
         };
  auto h=[](P a,P b){
           return P(a.first+b.first,a.second+b.second);
         };
  const int INF = 1e9;
  RBST<T, P> rbst(f,g,h,T(INF,INF,0),P(0,0));

  vector<T> v(S.size()+2,T(0,0,0));
  for(int i=0;i<(int)S.size();i++)
    get<2>(v[i+1])=(S[i]=='('?1:-1);

  auto rt=rbst.build(v);
  for(int i=1;i<=(int)S.size();i++){
    int z=get<2>(rbst.get_val(rt,i));
    rt=rbst.update(rt,i,rbst.count(rt),P(z,0));
    rt=rbst.update(rt,0,i+1,P(0,-z));
  }

  for(int i=0;i<Q;i++){
    char x;
    int y,z;
    scanf("%c %d %d\n",&x,&y,&z);
    z++;
    if(x=='('||x==')'){
      z=(x=='('?1:-1);
      T prev=rbst.get_val(rt,y-1);
      T next=rbst.get_val(rt,y);
      T curr(get<0>(prev),get<1>(next),z);
      rt=rbst.insert(rt,y,curr);
      rt=rbst.update(rt,y,rbst.count(rt),P(z,0));
      rt=rbst.update(rt,0,y+1,P(0,-z));
    }

    if(x=='D'){
      z=get<2>(rbst.get_val(rt,y));
      rt=rbst.erase(rt,y);
      rt=rbst.update(rt,y,rbst.count(rt),P(-z,0));
      rt=rbst.update(rt,0,y,P(0,z));
    }

    if(x=='Q'){
      T prev=rbst.get_val(rt,y-1);
      T curr=rbst.query(rt,y,z);
      T next=rbst.get_val(rt,z);
      int ans=0;
      if(get<0>(prev)>get<0>(curr)) ans+=get<0>(prev)-get<0>(curr);
      if(get<1>(next)>get<1>(curr)) ans+=get<1>(next)-get<1>(curr);
      printf("%d\n",ans);
    }
  }

  return 0;
}
/*
  verified on 2019/06/24
  https://atcoder.jp/contests/code-festival-2014-exhibition-open/tasks/code_festival_exhibition_b
*/

signed main(){
  //DSL_2_F();
  //DSL_2_G();
  //CODEFESTIVAL2014EXHIBITION_B();
  return 0;
}
#endif
