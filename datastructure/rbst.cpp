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
    Node():cnt(0){l=r=nullptr;}
    Node(T val,E laz):
      cnt(1),val(val),dat(val),laz(laz){l=r=nullptr;}
  };

  const size_t LIM = 1e6;
  vector<Node> pool;
  size_t ptr;

  RBST(F f,G g,H h,T ti,E ei):
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
    if(a->laz!=ei){ 
      a->val=g(a->val,a->laz);
      if(a->l!=nullptr){
        a->l->laz=h(a->l->laz,a->laz);
        a->l->dat=g(a->l->dat,a->laz);
      }
      if(a->r!=nullptr){
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
    auto u=t.first;
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
signed AOJ_1508(){
  int n,q;
  scanf("%d %d",&n,&q);
  vector<int> v(n);
  for(int i=0;i<n;i++) scanf("%d",&v[i]);
  
  auto f=[](int a,int b){return min(a,b);};
  auto g=[](int a,int b){return b<0?a:b;};
  auto h=[](int a,int b){return b<0?a:b;};
  const int INF = 1e9;
  RBST<int, int> rbst(f,g,h,INF,-1);

  auto root=rbst.build(v);
  
  for(int i=0;i<q;i++){
    int x,y,z;
    scanf("%d %d %d",&x,&y,&z);
    if(x==0){
      int v=rbst.query(root,z,z+1);
      root=rbst.erase(root,z);
      root=rbst.insert(root,y,v);
    }
    if(x==1){
      printf("%d\n",rbst.query(root,y,z+1));
    }
    if(x==2){
      rbst.update(root,y,y+1,z);
    }
  }
  
  return 0;
}
/*
  verified on 2018/08/21
  judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1508
*/

signed DSL_2_F(){
  int n,q;
  scanf("%d %d",&n,&q);
  auto f=[](Int a,Int b){return min(a,b);};
  auto g=[](Int a,Int b){return b<0?a:b;};
  auto h=[](Int a,Int b){return b<0?a:b;};
  RBST<Int, Int> rbst(f,g,h,INT_MAX,-1);
  vector<Int> v(n,INT_MAX);
  auto root=rbst.build(v);
  
  for(int i=0;i<q;i++){
    int c,s,t,x;    
    scanf("%d",&c);
    if(c){      
      scanf("%d %d",&s,&t);
      printf("%lld\n",rbst.query(root,s,t+1));
    }else{
      scanf("%d %d %d",&s,&t,&x);
      rbst.update(root,s,t+1,x);
    }
  }
  return 0;
}
/*
  verified on 2018/02/17
  https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_F
*/

signed DSL_2_G(){
  int n,q;
  scanf("%d %d",&n,&q);
  using P = pair<Int, Int>;
  auto f=[](P a,P b){return P(a.first+b.first,a.second+b.second);};
  auto g=[](P a,Int b){return P(a.first+b*a.second,a.second);};
  auto h=[](Int a,Int b){return a+b;};
  RBST<P, Int> rbst(f,g,h,P(0,0),0);
  vector<P> v(n,P(0,1));
  auto root=rbst.build(v);
  
  for(int i=0;i<q;i++){
    int c,s,t,x;
    scanf("%d",&c);
    if(c){
      scanf("%d %d",&s,&t);
      printf("%lld\n",rbst.query(root,s-1,t).first);
    }else{
      scanf("%d %d %d",&s,&t,&x);
      rbst.update(root,s-1,t,x);
    }
  }
  return 0;
}
/*
  verified on 2018/02/17
  https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_G
*/

char buf[114514];
inline signed CODEFESTIVAL2014EXHIBITION_B(){
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
  
  auto root=rbst.build(v);
  for(int i=1;i<=(int)S.size();i++){
    int z=get<2>(rbst.get(root,i));
    P q=P(z,-z);
     
    q.second=0;
    rbst.update(root,i,rbst.count(root),q);
    q.second=-z;
    q.first=0;
    rbst.update(root,0,i+1,q);      
    q.first=z;
  }

  for(int i=0;i<Q;i++){
    char x;
    int y,z;
    scanf("%c %d %d\n",&x,&y,&z);
    z++;
    if(x=='('||x==')'){
      T prev=rbst.query(root,y-1,y);
      T next=rbst.query(root,y,y+1);
      z=(x=='('?1:-1);
      P q=P(z,-z);
      T curr(get<0>(prev),get<1>(next),z);
      root=rbst.insert(root,y,curr);
      
      q.second=0;
      rbst.update(root,y,rbst.count(root),q);
      q.second=-z;
      q.first=0;
      rbst.update(root,0,y+1,q);      
      q.first=z;
    }
    
    if(x=='D'){
      z=get<2>(rbst.get(root,y));
      P q=P(-z,z);
      root=rbst.erase(root,y);
      
      q.second=0;
      rbst.update(root,y,rbst.count(root),q);
      q.second=z;
      q.first=0;
      rbst.update(root,0,y,q);      
      q.first=-z;
    }
    
    if(x=='Q'){
      T prev=rbst.query(root,y-1,y);
      T curr=rbst.query(root,y,z);
      T next=rbst.query(root,z,z+1);
      int ans=0;
      if(get<0>(prev)>get<0>(curr)) ans+=get<0>(prev)-get<0>(curr);
      if(get<1>(next)>get<1>(curr)) ans+=get<1>(next)-get<1>(curr);
      printf("%d\n",ans);
    }
  }
  
  return 0;
}
/*
  verified on 2018/03/04
  https://beta.atcoder.jp/contests/code-festival-2014-exhibition-open/tasks/code_festival_exhibition_b
*/

signed main(){
  //AOJ_1508();
  //DSL_2_F();
  //DSL_2_G();
  CODEFESTIVAL2014EXHIBITION_B();
  return 0;
}

