#include<bits/stdc++.h>
using namespace std;
using Int = long long;
//BEGIN CUT HERE
template<typename T,typename E>
struct RBST{
  int xor128(){
    static int x = 123456789;
    static int y = 362436069;
    static int z = 521288629;
    static int w = 88675123; 
    int t;
   
    t = x ^ (x << 11);
    x = y; y = z; z = w;
    return w = (w ^ (w >> 19)) ^ (t ^ (t >> 8));
  }
  typedef function<T(T,T)> F;
  typedef function<T(T,E)> G;
  typedef function<E(E,E)> H;
  typedef function<E(E,size_t)> P;

  F f;
  G g;
  H h;
  P p;
  T d1;
  E d0;
  
  struct Node{
    Node *l,*r;
    size_t cnt;
    T val,dat;
    E laz;
    Node():cnt(0){l=r=nullptr;}
    Node(T val,E laz):
      cnt(1),val(val),dat(val),laz(laz){l=r=nullptr;}
  };

  const size_t LIM = 1e6;
  vector<Node> pool;
  size_t ptr;

  RBST(F f,G g,H h,P p,T d1,E d0):
    f(f),g(g),h(h),p(p),d1(d1),d0(d0),pool(LIM),ptr(0){}

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
    return &(pool[ptr++]=Node(v,d0));
  }
  
  inline size_t count(const Node* a){
    if(a==nullptr) return 0;
    return a->cnt;
  }

  inline Node* insert(Node* a,size_t pos,T v){
    Node* b=create(v);
    auto s=split(a,pos);
    return a=merge(merge(s.first,b),s.second);
  }

  inline Node* erase(Node* a,size_t pos){
    auto s=split(a,pos);
    auto t=split(s.second,1);
    return merge(s.first,t.second);
  }

  inline T query(const Node *a){
    if(a==nullptr) return d1;
    return a->dat;
  }
  
  Node* eval(Node* a){
    if(a->laz!=d0){ 
      a->val=g(a->val,p(a->laz,1));
      if(a->l!=nullptr){
	a->l->laz=h(a->l->laz,a->laz);
	a->l->dat=g(a->l->dat,p(a->laz,count(a->l)));
      }
      if(a->r!=nullptr){
	a->r->laz=h(a->r->laz,a->laz);
	a->r->dat=g(a->r->dat,p(a->laz,count(a->r)));
      }
      a->laz=d0;
    }
    return update(a);
  }
  
  inline Node* update(Node* a){
    if(a==nullptr) return a;
    a->cnt=count(a->l)+count(a->r)+1;
    a->dat=f(a->val,f(query(a->l),query(a->r)));
    return a;
  }

  inline T query(Node *&a,size_t l,size_t r){
    auto s=split(a,l);
    auto t=split(s.second,r-l);
    auto u=t.first;
    T res=query(u);
    a=merge(s.first,merge(t.first,t.second));
    return res;
  }
  
  inline void update(Node *&a,size_t l,size_t r,E v){
    auto s=split(a,l);
    auto t=split(s.second,r-l);
    auto u=t.first;
    u->laz=h(u->laz,v);
    a=merge(merge(s.first,eval(u)),t.second);
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

  Node* merge(Node* a,Node* b){
    if(a==nullptr) return b;
    if(b==nullptr) return a;
    if(xor128()%(count(a)+count(b))<count(a)){
      a=eval(a);
      a->r=merge(a->r,b);
      return update(a);
    }
    b=eval(b);
    b->l=merge(a,b->l);
    return update(b);
  }

  pair<Node*, Node*> split(Node* a,size_t k){
    if(a==nullptr) return make_pair(a,a);
    a=eval(a);
    if(k<=count(a->l)){
      auto s=split(a->l,k);
      a->l=s.second;
      return make_pair(s.first,update(a));
    }
    auto s=split(a->r,k-(count(a->l)+1));
    a->r=s.first;
    return make_pair(update(a),s.second);
  } 
  
};
//END CUT HERE

struct FastIO{
  FastIO(){
    cin.tie(0);
    ios::sync_with_stdio(0);
  }
}fastio_beet;

//INSERT ABOVE HERE
signed AOJ_1508(){
  int n,q;
  cin>>n>>q;
  vector<int> v(n);
  for(int i=0;i<n;i++) cin>>v[i];
  
  RBST<int, int>::F f=[](int a,int b){return min(a,b);};
  RBST<int, int>::G g=[](int a,int b){return b<0?a:b;};
  RBST<int, int>::H h=[](int a,int b){return b<0?a:b;};
  RBST<int, size_t>::P p=[](int a,size_t b){++b;return a;};
  const int INF = 1e9;
  RBST<int, int> rbst(f,g,h,p,INF,-1);

  auto root=rbst.build(v);
  
  for(int i=0;i<q;i++){
    int x,y,z;
    cin>>x>>y>>z;
    if(x==0){
      int v=rbst.query(root,z,z+1);
      root=rbst.erase(root,z);
      root=rbst.insert(root,y,v);
    }
    if(x==1){
      cout<<rbst.query(root,y,z+1)<<endl;
    }
    if(x==2){
      rbst.update(root,y,y+1,z);
    }
  }
  
  return 0;
}
/*
  verified on 2018/02/17
  judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1508
*/

signed DSL_2_F(){
  int n,q;
  cin>>n>>q;
  RBST<Int, Int>::F f=[](Int a,Int b){return min(a,b);};
  RBST<Int, Int>::G g=[](Int a,Int b){return b<0?a:b;};
  RBST<Int, Int>::H h=[](Int a,Int b){return b<0?a:b;};
  RBST<Int, size_t>::P p=[](Int a,size_t b){++b;return a;};
  RBST<Int, Int> rbst(f,g,h,p,INT_MAX,-1);
  vector<Int> v(n,INT_MAX);
  auto root=rbst.build(v);
  
  for(int i=0;i<q;i++){
    int c,s,t,x;
    cin>>c;
    if(c){
      cin>>s>>t;
      cout<<rbst.query(root,s,t+1)<<endl;
    }else{
      cin>>s>>t>>x;
      rbst.update(root,s,t+1,x);
    }
  }
  return 0;
}
/*
  verified on 2018/02/17
  http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_F
*/

signed DSL_2_G(){
  int n,q;
  cin>>n>>q;
  RBST<Int, Int>::F f=[](Int a,Int b){return a+b;};
  RBST<Int, Int>::G g=[](Int a,Int b){return a+b;};
  RBST<Int, Int>::H h=[](Int a,Int b){return a+b;};
  RBST<Int, size_t>::P p=[](Int a,size_t b){return a*b;};
  RBST<Int, Int> rbst(f,g,h,p,0,0);
  vector<Int> v(n,0);
  auto root=rbst.build(v);
  
  for(int i=0;i<q;i++){
    int c,s,t,x;
    cin>>c;
    if(c){
      cin>>s>>t;
      cout<<rbst.query(root,s-1,t)<<endl;
    }else{
      cin>>s>>t>>x;
      rbst.update(root,s-1,t,x);
    }
  }
  return 0;
}
/*
  verified on 2018/02/17
  http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_G
*/

signed main(){
  //AOJ_1508();
  DSL_2_F();
  //DSL_2_G();
  return 0;
}

