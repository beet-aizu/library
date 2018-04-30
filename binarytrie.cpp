#include<bits/stdc++.h>
using namespace std;
using Int = long long;
//BEGIN CUT HERE
template<typename T,Int X>
struct BinaryTrie{
  struct Node{
    bool f;
    T laz;
    int par,cnt,nxt[2];
    Node(){}
    Node(bool f,int par):
      f(f),laz(0),par(par),cnt(0){nxt[0]=nxt[1]=-1;}
  };

  vector<Node> v;
  queue<int> q;
  BinaryTrie(){v.reserve(int(6e6));v.emplace_back(0,-1);}
  
  void emplace(bool f,int par){
    if(q.empty()){
      v[par].nxt[f]=v.size();
      v.emplace_back(f,par);
    }else{
      v[par].nxt[f]=q.front();
      v[q.front()]=Node(f,par);
      q.pop();
    }
  }

  inline int count(int x){
    return x<0?0:v[x].cnt;
  }

  inline void eval(int x,int i){
    if((v[x].laz>>i)&1){
      swap(v[x].nxt[0],v[x].nxt[1]);
      v[x].laz^=T(1)<<i;
    }
    for(int k=0;k<2;k++){
      if(!~v[x].nxt[k]) continue;
      v[v[x].nxt[k]].laz^=v[x].laz;
      v[v[x].nxt[k]].f=k;
    }
    v[x].laz=0;
  }
  
  void add(const T b){
    int pos=0;
    for(int i=X-1;i>=0;i--){
      eval(pos,i);
      bool f=(b>>i)&1;
      if(v[pos].nxt[f]<0) emplace(f,pos);
      pos=v[pos].nxt[f];
    }
    v[pos].cnt++;
    for(int i=0;i<X;i++){
      pos=v[pos].par;
      v[pos].cnt=count(v[pos].nxt[0])+count(v[pos].nxt[1]);
    }
  }

  void update(const T b){
    v[0].laz^=b;
  }

  int find(const T b){
    int pos=0;
    for(int i=X-1;i>=0;i--){
      eval(pos,i);
      bool f=(b>>i)&1;
      if(~v[pos].nxt[f]) pos=v[pos].nxt[f];
      else return -1;
    }
    return pos;
  }

  void erase(int pos){
    v[pos].cnt--;
    for(int i=0;i<X;i++){
      pos=v[pos].par;
      v[pos].cnt=count(v[pos].nxt[0])+count(v[pos].nxt[1]);
      for(int k=0;k<2;k++){
	if(!count(v[pos].nxt[k])){
	  if(~v[pos].nxt[k])
	    q.emplace(v[pos].nxt[k]);
	  v[pos].nxt[k]=-1;
	}
      }
    }
  }
  
  int xmax(const T b){
    int pos=0;
    for(int i=X-1;i>=0;i--){
      eval(pos,i);
      bool f=(~b>>i)&1;
      f^=!~v[pos].nxt[f];
      pos=v[pos].nxt[f];
    }
    return pos;
  }

  int xmin(const T b){
    return xmax(~b&((T(1)<<X)-1));
  }

  int lower_bound(T b){
    int pos=0;
    for(int i=X-1;i>=0;i--){
      eval(pos,i);
      bool f=(b>>i)&1;
      if(~v[pos].nxt[f]){
	pos=v[pos].nxt[f];
	continue;
      }
      if(f) return next(pos,i);
      return fmin(v[pos].nxt[!f],i-1);
    }
    return pos;
  }

  int upper_bound(T b){
    return lower_bound(b+1);
  }
  
  int next(int pos,int i=-1){
    for(;i<X;i++){
      int par=v[pos].par;
      if(v[pos].f==0&&~v[par].nxt[1])
	return fmin(v[par].nxt[1],i);
      pos=par;
    }
    return -1;
  }

  int fmin(int pos,int i){
    if(i==-1) return pos;
    eval(pos,i);
    return fmin(v[pos].nxt[v[pos].nxt[0]==-1],i-1);
  }

  T val(int pos){
    T res=0;
    for(int i=0;i<X;i++){
      res|=T(v[pos].f)<<i;
      pos=v[pos].par;
    }
    return res;
  }

  void show(){
    vector<T> vs;
    T a=val(xmin(0));
    vs.emplace_back(a);
    int pos=find(a);
    while(val(xmax(0))!=a){
      pos=next(pos);
      a=val(pos);
      vs.emplace_back(a);
    }
    cout<<"#######"<<endl;
    for(T x:vs) cout<<x<<" ";
    cout<<endl;
  }
  
};
//END CUT HERE

//INSERT ABOVE HERE
signed JAG2013SUMMERWARMINGUP_F(){
  int n;
  cin>>n;
  vector<int> a(n);
  for(int i=0;i<n;i++) cin>>a[i];
  vector<int> s(n+1,0);
  for(int i=0;i<n;i++) s[i+1]=s[i]^a[i];
  map<int, int> r;
  BinaryTrie<int, 30> bt;
  bt.add(0);
  r[bt.find(0)]=0;
  int ans=-1,idx=-1,idy=-1;
  for(int i=0;i<n;i++){
    int k=r[bt.xmax(a[i])];
    int res=s[i+1]^s[k];
    if(ans<res||(ans==res&&idx>k)){
      ans=res;
      idx=k;
      idy=i;
    }
    bt.update(a[i]);
    bt.add(0);
    if(!r.count(bt.find(0))) r[bt.find(0)]=i+1;
  }
  cout<<ans<<" "<<idx+1<<" "<<idy+1<<endl;
  return 0;
}
/*
  verified on 2018/04/30
  https://beta.atcoder.jp/contests/jag2013summer-warmingup/tasks/icpc2013summer_warmingUp_f
*/
signed CFR470_C(){
  int n;
  scanf("%d",&n);
  vector<int> a(n),p(n);
  for(Int i=0;i<n;i++) scanf("%d",&a[i]);
  for(Int i=0;i<n;i++) scanf("%d",&p[i]);

  BinaryTrie<int, 30> bt;
  for(int i=0;i<n;i++) bt.add(p[i]);
  
  for(Int i=0;i<n;i++){
    if(i) printf(" ");
    int k=bt.xmin(a[i]);
    printf("%d",a[i]^bt.val(k));
    bt.erase(k);
  }
  puts("");
  return 0;
}
/*
  verified on 2018/04/30
  http://codeforces.com/contest/947/problem/C
*/

signed CFR477_C(){
  Int n;
  scanf("%lld",&n);
  vector<Int> b(n);
  for(Int i=0;i<n;i++) scanf("%lld",&b[i]);
  
  BinaryTrie<Int, 60> bt;
  for(Int i=0;i<n;i++) bt.add(b[i]);
  
  Int z=0;
  auto apply=[&](Int a){
    z^=a;
    bt.update(a);
  };

  vector<Int> ans;
  Int x=bt.val(bt.xmin(0));
  
  ans.emplace_back(x);
  bt.erase(bt.find(x));
  apply(x);

  for(Int i=1;i<n;i++){
    if(bt.val(bt.xmax(0))<=x){
      printf("No\n");
      return 0; 
    }
    
    Int nxt=bt.upper_bound(x);
    Int y=bt.val(nxt);
    
    ans.emplace_back(y^z);
    bt.erase(nxt);
    apply(x^y);
    x=y;
    
  }
  
  printf("Yes\n");
  for(Int i=0;i<n;i++){
    if(i) printf(" ");
    printf("%lld",ans[i]);
  }
  printf("\n");
  
  return 0;
}
/*
  verified on 2018/04/30
  http://codeforces.com/contest/966/problem/C
*/

signed main(){
  //JAG2013SUMMERWARMINGUP_F();
  CFR470_C();
  //CFR477_C();
  return 0;
}
