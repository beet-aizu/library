#include<bits/stdc++.h>
using namespace std;
using Int = long long;
//BEGIN CUT HERE
using P = pair<int, int>;
struct SegmentTree{
  int n;
  vector<P> v;
  vector<vector<int> > dat;
  SegmentTree(){};
  SegmentTree(int n,vector<P> v):v(v){init(n);build();};
  
  void init(int n_){
    n=1;
    while(n<n_) n*=2;
    dat.clear();
    dat.resize(2*n-1);
  }
  
  void build(){
    for(int i=0;i<(int)v.size();i++)
      dat[v[i].first+(n-1)].emplace_back(v[i].second);
    
    for(int i=0;i<n;i++)
      sort(dat[i+n-1].begin(),dat[i+n-1].end());
    
    for(int i=n-2;i>=0;i--){
      merge(dat[i*2+1].begin(),dat[i*2+1].end(),
	    dat[i*2+2].begin(),dat[i*2+2].end(),
	    back_inserter(dat[i]));
    }
  }
  // [a,b) * [c,d)
  inline int query(int a,int b,int c,int d){
    int res=0;
    auto calc=[a,b,c,d](vector<int> &x){
      auto latte=lower_bound(x.begin(),x.end(),d);
      auto malta=lower_bound(x.begin(),x.end(),c);
      return int(latte-malta);
    };
    for(int l=a+n,r=b+n;l<r;l>>=1,r>>=1) {
      if(l&1) res+=calc(dat[(l++)-1]);
      if(r&1) res+=calc(dat[(--r)-1]);
    }
    return res;
  }
  
};


//END CUT HERE
signed main(){
  return 0;
}
