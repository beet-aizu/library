#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;
#endif
//BEGIN CUT HERE
template<typename Key>
struct SegmentTree{
  using P = pair<int, Key>;
  int n;
  vector< vector<Key> > dat;
  SegmentTree(int n,vector<P> vs):n(n){
    dat.assign(n<<1,vector<Key>());
    for(auto p:vs)
      dat[p.first+n].emplace_back(p.second);

    for(int i=0;i<n;i++)
      sort(dat[i+n].begin(),dat[i+n].end());

    for(int i=n-1;i;i--){
      merge(dat[(i<<1)|0].begin(),dat[(i<<1)|0].end(),
            dat[(i<<1)|1].begin(),dat[(i<<1)|1].end(),
            back_inserter(dat[i]));
    }
  }

  // [a, b) * [c, d)
  inline int query(int a,int b,Key c,Key d){
    int res=0;
    auto calc=[a,b,c,d](vector<Key> &xs){
      auto latte=lower_bound(xs.begin(),xs.end(),d);
      auto malta=lower_bound(xs.begin(),xs.end(),c);
      return int(latte-malta);
    };
    for(int l=a+n,r=b+n;l<r;l>>=1,r>>=1){
      if(l&1) res+=calc(dat[l++]);
      if(r&1) res+=calc(dat[--r]);
    }
    return res;
  }
};
//END CUT HERE
#ifndef call_from_test
signed main(){
  return 0;
}
#endif
