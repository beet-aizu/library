#include<bits/stdc++.h>
using namespace std;
using Int = long long;
//BEGIN CUT HERE
template<typename T>
struct RangeCount{
  struct BIT{
    vector<T> dat;
    BIT(){}
    BIT(int n){dat.assign(++n,0);}
    T sum(int k){
      T res=0;
      for(;k;k-=k&-k) res+=dat[k];
      return res;
    }
    void add(int k,T v){
      for(++k;k<(int)dat.size();k+=k&-k) dat[k]+=v;
    }    
  };
  int n;
  vector<vector<int> > val;
  vector<BIT> dat;
  RangeCount(){}
  RangeCount(int n_){
    n=1;
    while(n<n_) n<<=1;
    val.assign(n<<1,vector<int>());
    dat.reserve(n<<1);    
  }
  void preupdate(int a,int x){
    a+=n;
    while(a){
      val[a].emplace_back(x);
      a>>=1;
    }
  }
  void build(){    
    for(int i=0;i<n*2;i++){
      auto &v=val[i];
      sort(v.begin(),v.end());
      v.erase(unique(v.begin(),v.end()),v.end());
      dat.emplace_back(v.size());
    }
  }
  void update(int a,int x,int z){
    a+=n;
    while(a){
      auto &v=val[a];
      int k=lower_bound(v.begin(),v.end(),x)-v.begin();
      dat[a].add(k,z);
      a>>=1;
    }    
  }
  T calc(int k,int x,int y){
    auto &v=val[k];
    int p=lower_bound(v.begin(),v.end(),x)-v.begin();
    int q=lower_bound(v.begin(),v.end(),y)-v.begin();
    return dat[k].sum(q)-dat[k].sum(p);
  }
  // [a, b) * [x, y)
  T query(int a,int b,int x,int y){
    T res=0;
    for(int l=a+n,r=b+n;l<r;l>>=1,r>>=1){
      if(l&1) res+=calc(l++,x,y);
      if(r&1) res+=calc(--r,x,y); 
    }
    return res;
  }
};
//END CUT HERE

//INSERT ABOVE HERE
signed YUKI_743(){  
  int n,m;
  scanf("%d %d",&n,&m);
  vector<int> a(n),b(n);
  for(int i=0;i<n;i++) scanf("%d %d",&a[i],&b[i]);

  RangeCount<int> seg(m);
  
  for(int i=0;i<n;i++){
    if(a[i]>b[i]) swap(a[i],b[i]);
    seg.preupdate(a[i],b[i]);
  }

  seg.build();
  
  long long ans=0;
  for(int i=0;i<n;i++){
    ans+=seg.query(0,a[i],a[i],b[i]);
    ans+=seg.query(a[i],b[i],b[i],m);
    seg.update(a[i],b[i],1);
  }

  printf("%lld\n",ans);
  return 0;
}

signed ABC106_D(){
  int n,m,q;
  scanf("%d %d %d",&n,&m,&q);
  vector<int> x(m),y(m);
  for(int i=0;i<m;i++) scanf("%d %d",&x[i],&y[i]);
  
  RangeCount<int> seg(n+1);
  for(int i=0;i<m;i++) seg.preupdate(x[i],y[i]);
  seg.build();
  for(int i=0;i<m;i++) seg.update(x[i],y[i],1);
  
  for(int i=0;i<q;i++){
    int a,b;
    scanf("%d %d",&a,&b);
    printf("%d\n",seg.query(a,b+1,a,b+1));    
  }
  return 0;
}

//END CUT HERE
signed main(){
  ABC106_D();
  return 0;
}
