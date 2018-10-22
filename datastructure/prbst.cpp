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
  using F = function<T(T,T)>;
  using G = function<T(T,E)>;
  using H = function<E(E,E)>;

  F f;
  G g;
  H h;
  T ti;
  E ei;
  
  struct Node{
    Node *l,*r;
    size_t cnt;
    T val,dat;
    E laz;
    Node():cnt(0){}
    Node(T val,E laz):
      cnt(1),val(val),dat(val),laz(laz){l=r=nullptr;}
  };

  const size_t LIM = 1e7;
  vector<Node> pool;
  size_t ptr;

  PRBST(F f,G g,H h,T ti,E ei):
    f(f),g(g),h(h),ti(ti),ei(ei),pool(LIM),ptr(0){}

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

  inline Node* clone(Node* a){
    if(a==nullptr) return a;
    Node* b=create();
    *b=*a;
    return b;
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
    if(a==nullptr) return ti;
    return a->dat;
  }

  Node* eval(Node* a){
    a=clone(a);
    if(a->laz!=ei){ 
      a->val=g(a->val,a->laz);
      if(a->l!=nullptr){
        a->l=clone(a->l);
        a->l->laz=h(a->l->laz,a->laz);
        a->l->dat=g(a->l->dat,a->laz);
      }
      if(a->r!=nullptr){
        a->r=clone(a->r);
        a->r->laz=h(a->r->laz,a->laz);
        a->r->dat=g(a->r->dat,a->laz);
      }
      a->laz=ei;
    }
    return update(a);
  }
  
  inline Node* update(Node* a){
    if(a==nullptr) return a;
    a->cnt=count(a->l)+count(a->r)+1;
    a->dat=f(query(a->l),f(a->val,query(a->r)));
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
    auto u=clone(t.first);
    u->laz=h(u->laz,v);
    a=merge(merge(s.first,eval(u)),t.second);
  }

  inline T get(Node *&a,size_t p){
    auto s=split(a,p);
    auto t=split(s.second,1);
    T res=t.first->val;
    a=merge(s.first,merge(t.first,t.second));
    return res;
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

  Node* rebuild(Node* a){
    auto v=dump(a);
    ptr=0;
    return build(v);
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
  auto root=prbst.build(v);
  
  for(int i=0;i<q;i++){
    int t;
    scanf("%d",&t);
    if(t==1){
      int a,b,v;
      scanf("%d %d %d",&a,&b,&v);
      prbst.update(root,a-1,b,v);
    }
    if(t==2){
      int a,b,c,d;
      scanf("%d %d %d %d",&a,&b,&c,&d);
      a--;c--;
      auto s=prbst.split(root,a);
      auto t=prbst.split(s.second,b-a);
      auto u=prbst.split(root,c);
      auto v=prbst.split(u.second,d-c);
      
      root=prbst.merge(prbst.merge(s.first,v.first),t.second);
    }
    if(t==3){
      int a,b;
      scanf("%d %d",&a,&b);
      printf("%lld\n",prbst.query(root,a-1,b).first);
    }
    
    if(prbst.ptr>prbst.LIM*95/100)
      root=prbst.rebuild(root);
    
  }
  return 0;
}

/*
  verified on 2018/03/04
  https://beta.atcoder.jp/contests/arc030/tasks/arc030_4
*/

signed main(){
  ARC030_D();
  return 0;
}
