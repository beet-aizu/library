#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2995"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../datastructure/unionfind.cpp"
#include "../../tree/sack.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  const char newl = '\n';

  int n,k;
  cin>>n>>k;

  vector<int> us(n),vs(n),cs(n),ds(n);
  for(int i=1;i<n;i++) cin>>us[i]>>vs[i];
  for(int i=0;i<n;i++) cin>>cs[i]>>ds[i];

  int num=0;
  vector<int> cnt(k,0);
  UnionFind uf(k);

  auto calc=[&](int c){return min(cnt[c],uf.size(c));};
  auto expand=[&](int v){
    int c=uf.find(cs[v]);
    int d=uf.find(ds[v]);
    int flg=uf.same(c,d);
    if(flg){
      num-=calc(c);

      uf.unite(c,d);
      cnt[c]++;

      num+=calc(c);
    }else{
      num-=calc(c)+calc(d);

      uf.unite(c,d);
      if(uf.find(c)!=c) swap(c,d);
      cnt[c]+=cnt[d]+1;

      num+=calc(c);
    }
  };

  auto shrink=[&](int v){
    cnt[cs[v]]=cnt[ds[v]]=0;
    uf.ps[cs[v]]=cs[v];
    uf.ps[ds[v]]=ds[v];
    uf.rs[cs[v]]=uf.rs[ds[v]]=1;
  };

  vector<int> ans(n);
  auto query=[&](int v){ans[v]=num;};
  auto reset=[&](int){num=0;};
  Sack S(n,expand,shrink,query,reset);

  for(int i=1;i<n;i++){
    us[i]--;vs[i]--;
    S.add_edge(us[i],vs[i]);
  }

  for(int i=0;i<n;i++){
    cs[i]--,ds[i]--;
    S.add_query(i,i);
  }

  S.build();
  for(int i=0;i<n;i++) cout<<ans[i]<<newl;
  return 0;
}
