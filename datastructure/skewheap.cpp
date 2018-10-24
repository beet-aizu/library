#include<bits/stdc++.h>
using namespace std;
using Int = long long;
//BEGIN CUT HERE
template<typename T, typename E>
struct SkewHeap{
  using G = function<T(T,E)>;
  using H = function<E(E,E)>;
  using C = function<bool(T,T)>;
  G g;
  H h;
  C c;
  T INF;
  E ei;
  SkewHeap(G g,H h,C c,T INF,E ei):g(g),h(h),c(c),INF(INF),ei(ei){}
  
  struct Node{
    Node *l,*r;
    T val;
    E add;
    Node(T val,E add):val(val),add(add){l=r=nullptr;}
  };

  void eval(Node *a){
    if(a==nullptr) return;
    if(a->add==ei) return;
    if(a->l) a->l->add=h(a->l->add,a->add);
    if(a->r) a->r->add=h(a->r->add,a->add);
    a->val=g(a->val,a->add);
    a->add=ei;
  }
  
  T top(Node *a){
    return a!=nullptr?g(a->val,a->add):INF;
  }

  T snd(Node *a){
    eval(a);
    return a!=nullptr?min(top(a->l),top(a->r)):INF;
  }

  Node* add(Node *a,E d){
    if(a!=nullptr) a->add=h(a->add,d);
    return a;
  }
  
  Node* push(T v){
    return new Node(v,ei);
  }
  
  Node* meld(Node *a,Node *b){
    if(!a||!b) return a?a:b;
    if(c(top(a),top(b))) swap(a,b);
    eval(a);
    a->r=meld(a->r,b);
    swap(a->l,a->r);
    return a;
  }
  
  Node* pop(Node* a){
    eval(a);
    auto res=meld(a->l,a->r);
    delete a;
    return res;
  }
  
};
//END CUT HERE
struct ALDS1_9_C{
  signed solve(){
    cin.tie(0);
    ios::sync_with_stdio(0);

    using Heap=SkewHeap<int, int>;
    auto g=[](int a,int b){return a+b;};
    auto h=[](int a,int b){return a+b;};
    auto c=[](int a,int b){return a<b;};
    int INF = -1;
    Heap heap(g,h,c,INF,0);
    auto base=heap.push(0);
  
    string s;
    while(cin>>s,s!="end"){
      int x;
      if(s=="insert"){
        cin>>x;
        base=heap.meld(base,heap.push(x));
      }
      if(s=="extract"){
        x=heap.top(base);
        base=heap.pop(base);
        cout<<x<<endl;
      }
    }
    return 0;
  }
  /*
    verified on 2018/03/04
    http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_9_C&lang=jp
  */
};

struct APC001_D{
  struct UnionFind{
    int n;
    vector<int> r,p;
    UnionFind(){}
    UnionFind(int sz):n(sz),r(sz,1),p(sz,0){iota(p.begin(),p.end(),0);}
    int find(int x){
      return (x==p[x]?x:p[x]=find(p[x]));
    }
    bool same(int x,int y){
      return find(x)==find(y);
    }
    void unite(int x,int y){
      x=find(x);y=find(y);
      if(x==y) return;
      if(r[x]<r[y]) swap(x,y);
      r[x]+=r[y];
      p[y]=x;
    }
  };
  
  signed solve(){
    using Heap = SkewHeap<Int, Int>;
    Int n,m;
    cin>>n>>m;
    vector<Int> a(n);
    for(Int i=0;i<n;i++) cin>>a[i];
    
    auto g=[](Int a,Int b){return a+b;};
    auto h=[](Int a,Int b){return a+b;};
    auto c=[](Int a,Int b){return a>b;};

    const Int INF = 1e16;
    Heap heap(g,h,c,INF,0);
    vector<Heap::Node*> v(n);
    for(Int i=0;i<n;i++) v[i]=heap.push(a[i]);
    
    UnionFind uf(n);
    for(Int i=0;i<m;i++){
      Int x,y;
      cin>>x>>y;
      x=uf.find(x);y=uf.find(y);
      uf.unite(x,y);
      if(uf.find(x)!=x) swap(x,y);
      v[x]=heap.meld(v[x],v[y]);
      v[y]=NULL;
    }
    
    if(m==n-1){
      cout<<0<<endl;
      return 0;
    }
    
    Heap::Node* base=NULL;
    
    Int ans=0,cnt=0;
    for(Int i=0;i<n;i++){
      if(uf.find(i)==i){
        ans+=heap.top(v[i]);
        v[i]=heap.pop(v[i]);
        base=heap.meld(base,v[i]);
        cnt++;
      }
    }
    
    while(m*2+cnt<(n-1)*2){
      if(base==NULL){
        cout<<"Impossible"<<endl;
        return 0;
      }
      ans+=heap.top(base);
      base=heap.pop(base);
      cnt++;
    }
  
    cout<<ans<<endl;
    return 0;
  }
  /*
    verified on 2018/03/04
    https://beta.atcoder.jp/contests/apc001/tasks/apc001_d
  */
};

signed main(){
  //ALDS1_9_C ans;
  APC001_D ans;
  
  ans.solve();
}
