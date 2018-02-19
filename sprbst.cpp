#include<bits/stdc++.h>
using namespace std;
using Int = long long;
//BEGIN CUT HERE
template<typename T>
struct SPRBST{
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
  
  struct Node{
    Node *l,*r;
    size_t cnt;
    T val;
    Node():cnt(0){l=r=nullptr;}
    Node(T val):cnt(1),val(val){l=r=nullptr;}
  };

  const size_t LIM = 1e7;
  vector<Node> pool;
  size_t ptr;

  SPRBST():pool(LIM),ptr(0){}

  Node* build(size_t l,size_t r,vector<T> &v){
    if(l+1==r) return create(v[l]);
    size_t m=(l+r)>>1;
    return merge(build(l,m,v),build(m,r,v));
  }
  
  Node* build(vector<T> &v){
    return build(0,v.size(),v);
  }
  
  inline Node* create(){
    if(ptr>=LIM) exit(0);
    return &pool[ptr++];
  }
  
  inline Node* create(T v){
    if(ptr>=LIM) exit(0);
    return &(pool[ptr++]=Node(v));
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

  inline Node* update(Node* a){
    if(a==nullptr) return a;
    a->cnt=count(a->l)+count(a->r)+1;
    return a;
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
    if(xor128()%(count(a)+count(b))<count(a)){
      a=clone(update(a));
      a->r=merge(a->r,b);
      return update(a);
    }
    b=clone(update(b));
    b->l=merge(a,b->l);
    return update(b);
  }

  pair<Node*, Node*> split(Node* a,size_t k){
    if(a==nullptr) return make_pair(a,a);
    a=clone(update(a));
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
char buf[1123456];
signed main(){
  int m;
  scanf("%d",&m);
  scanf("%s",buf);
  vector<char> v(strlen(buf));
  for(int i=0;i<(int)v.size();i++) v[i]=buf[i];
  
  SPRBST<char> sprbst;
  auto root=sprbst.build(v);
  
  int n;
  scanf("%d",&n);
  for(int i=0;i<n;i++){
    int a,b,c;
    scanf("%d %d %d",&a,&b,&c);
    auto s=sprbst.split(root,a);
    auto t=sprbst.split(s.second,b-a);
    auto u=sprbst.split(root,c);
    root=sprbst.merge(sprbst.merge(u.first,t.first),u.second);
    
    if((int)sprbst.count(root)>m)
      root=sprbst.split(root,m).first;
    
    if(sprbst.ptr>sprbst.LIM*8/10)
      root=sprbst.rebuild(root);
  }
  auto d=sprbst.dump(root);
  for(int i=0;i<(int)d.size();i++) buf[i]=d[i];
  buf[d.size()]='\0';
  printf("%s\n",buf);
  return 0;
}
/*
  verified on 2018/02/17
  https://beta.atcoder.jp/contests/joisc2012/tasks/joisc2012_copypaste
*/
