#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2995"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../tree/sack.cpp"
#undef call_from_test

struct UnionFind{
  vector<int> rs,ps;
  UnionFind(){}
  UnionFind(int n):rs(n,1),ps(n,0){iota(ps.begin(),ps.end(),0);}
  int find(int x) const{
    return (x==ps[x]?x:find(ps[x]));
  }
  bool same(int x,int y) const{
    return find(x)==find(y);
  }
  using P = pair<int, int>;
  stack<P> st;
  void rollback(){
    int x,y;
    tie(x,y)=st.top();st.pop();
    if(x!=y){
      rs[x]-=rs[y];
      ps[y]=y;
    }
  }
  void unite(int x,int y){
    x=find(x);y=find(y);
    if(rs[x]<rs[y]) swap(x,y);
    if(x!=y){
      rs[x]+=rs[y];
      ps[y]=x;
    }
    st.emplace(x,y);
  }
  int size(int x) const{
    return rs[find(x)];
  }
};

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
    int c=(cs[v]=uf.find(cs[v]));
    int d=(ds[v]=uf.find(ds[v]));
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
    uf.rollback();
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
