#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;
#endif
//BEGIN CUT HERE
template<typename Key,typename T>
struct RangeCount{
  struct BIT{
    vector<T> dat;
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
  vector< vector<Key> > val;
  vector<BIT> dat;
  RangeCount(int n):n(n){
    val.assign(n<<1,vector<Key>());
    dat.reserve(n<<1);
  }
  void preupdate(int a,Key x){
    a+=n;
    while(a){
      val[a].emplace_back(x);
      a>>=1;
    }
  }
  void build(){
    for(int i=0;i<n*2;i++){
      auto &vs=val[i];
      sort(vs.begin(),vs.end());
      vs.erase(unique(vs.begin(),vs.end()),vs.end());
      dat.emplace_back(vs.size());
    }
  }
  void update(int a,Key x,T z){
    a+=n;
    while(a){
      auto &vs=val[a];
      int k=lower_bound(vs.begin(),vs.end(),x)-vs.begin();
      dat[a].add(k,z);
      a>>=1;
    }
  }
  T calc(int k,Key x,Key y){
    auto &vs=val[k];
    int p=lower_bound(vs.begin(),vs.end(),x)-vs.begin();
    int q=lower_bound(vs.begin(),vs.end(),y)-vs.begin();
    return dat[k].sum(q)-dat[k].sum(p);
  }
  // [a, b) * [x, y)
  T query(int a,int b,Key x,Key y){
    T res=0;
    for(int l=a+n,r=b+n;l<r;l>>=1,r>>=1){
      if(l&1) res+=calc(l++,x,y);
      if(r&1) res+=calc(--r,x,y);
    }
    return res;
  }
};
//END CUT HERE
#ifndef call_from_test
//INSERT ABOVE HERE
//END CUT HERE
signed main(){
  return 0;
}
#endif
