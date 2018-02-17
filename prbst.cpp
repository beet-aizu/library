#include<bits/stdc++.h>
using namespace std;
using Int = long long;
//BEGIN CUT HERE
template<typename T,typename E>
struct PRBST{
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

  const size_t LIM = 1e7;
  vector<Node> pool;
  size_t ptr;

  PRBST(F f,G g,H h,P p,T d1,E d0):
    f(f),g(g),h(h),p(p),d1(d1),d0(d0),pool(LIM),ptr(0){}

  Node* build(size_t l,size_t r,vector<T> &v){
    if(l+1==r) return create(v[l]);
    size_t m=(l+r)>>1;
    return merge(build(l,m,v),build(m,r,v));
  }
  
  Node* build(vector<T> &v){
    return build(0,v.size(),v);
  }
  
  Node* create(){
    return &pool[ptr++];
  }
  
  Node* create(T v){
    return &(pool[ptr++]=Node(v,d0));
  }

  Node* clone(Node* a){
    if(a==nullptr) return a;
    Node* b=create();
    *b=*a;
    return b;
  }
  
  size_t count(const Node* a){
    if(a==nullptr) return 0;
    return a->cnt;
  }

  Node* insert(Node* a,size_t pos,T v){
    Node* b=create(v);
    auto s=split(a,pos);
    return a=merge(merge(s.first,b),s.second);
  }

  Node* erase(Node* a,size_t pos){
    auto s=split(a,pos);
    auto t=split(s.second,1);
    return merge(s.first,t.second);
  }

  T query(const Node *a){
    if(a==nullptr) return d1;
    return f(g(a->val,p(a->laz,1)),
	     g(a->dat,p(a->laz,count(a)-1)));
  }

  Node* update(Node* a){
    if(a==nullptr) return a;
    Node *l=clone(a->l),*r=clone(a->r);
    if(a->laz!=d0){ 
      a->val=g(a->val,p(a->laz,1));
      if(l!=nullptr) l->laz=h(l->laz,a->laz);
      if(r!=nullptr) r->laz=h(r->laz,a->laz);
      a->laz=d0;
    }
    a->l=l;
    a->r=r;
    a->cnt=count(l)+count(r)+1;
    a->dat=f(query(l),query(r));
    return a;
  }

  T query(Node *&a,size_t l,size_t r){
    auto s=split(a,l);
    auto t=split(s.second,r-l);
    auto u=t.first;
    T res=query(u);
    a=merge(s.first,merge(t.first,t.second));
    return res;
  }
  
  void update(Node *&a,size_t l,size_t r,E v){
    auto s=split(a,l);
    auto t=split(s.second,r-l);
    auto u=clone(t.first);
    u->laz=h(u->laz,v);
    a=merge(merge(s.first,u),t.second);
  }

  void dump(Node* a,typename vector<T>::iterator it){
    if(!count(a)) return;
    update(a);
    dump(a->l,it);
    *(it+count(a->l))=a->val;
    dump(a->r,it+count(a->l)+1);
  }
  
  vector<T> dump(Node* a){
    vector<T> v(count(a));
    dump(a,v.begin());
    return v;
  }

  Node* rebuild(Node* a){
    auto v=dump(a);
    ptr=0;
    return build(v);
  }
  
  Node* merge(Node* a,Node* b){
    if(a==nullptr) return b;
    if(b==nullptr) return a;
    update(a);update(b);
    Node* na=clone(a);
    Node* nb=clone(b);
    if(xor128()%(count(na)+count(nb))<count(na)){
      na->r=merge(na->r,nb);
      return update(na);
    }
    nb->l=merge(na,nb->l);
    return update(nb);
  }

  pair<Node*, Node*> split(Node* a,size_t k){
    if(a==nullptr) return make_pair(a,a);
    update(a);
    Node* na=clone(a);
    if(k<=count(na->l)){
      auto s=split(na->l,k);
      na->l=s.second;
      return make_pair(s.first,update(na));
    }
    auto s=split(a->r,k-(count(a->l)+1));
    na->r=s.first;
    return make_pair(update(na),s.second);
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
signed ARC030_D(){
  int n,q;
  cin>>n>>q;
  vector<Int> v(n);
  for(int i=0;i<n;i++) cin>>v[i];
  
  PRBST<Int, Int>::F f=[](Int a,Int b){return a+b;};
  PRBST<Int, Int>::G g=[](Int a,Int b){return a+b;};
  PRBST<Int, Int>::H h=[](Int a,Int b){return a+b;};
  PRBST<Int, size_t>::P p=[](Int a,size_t b){return a*b;};
  PRBST<Int, Int> prbst(f,g,h,p,0,0);
  auto root=prbst.build(v);
  
  for(int i=0;i<q;i++){
    int t;
    cin>>t;
    if(t==1){
      int a,b,v;
      cin>>a>>b>>v;
      prbst.update(root,a-1,b,v);
    }
    if(t==2){
      int a,b,c,d;
      cin>>a>>b>>c>>d;
      a--;c--;
      auto s=prbst.split(root,a);
      auto t=prbst.split(s.second,b-a);
      auto u=prbst.split(root,c);
      auto v=prbst.split(u.second,d-c);
      
      root=prbst.merge(prbst.merge(s.first,v.first),t.second);
    }
    if(t==3){
      int a,b;
      cin>>a>>b;
      cout<<prbst.query(root,a-1,b)<<endl;
    }
    
    if(prbst.ptr>prbst.LIM*95/100)
      root=prbst.rebuild(root);
    
  }
  return 0;
}

/*
  verified on 2018/02/17
  http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_G
*/

signed main(){
  ARC030_D();
  return 0;
}
