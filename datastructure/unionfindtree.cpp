#include<bits/stdc++.h>
using namespace std;
using Int = long long;
//BEGIN CUT HERE
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
  int size(int x){
    return r[find(x)];
  }
};
//END CUT HERE

struct FastIO{
  FastIO(){
    cin.tie(0);
    ios::sync_with_stdio(0);
  }
}fastio_beet;

//INSERT ABOVE HERE

signed DSL_1_A(){
  int n,q;
  cin>>n>>q;
  UnionFind uf(n);
  for(int i=0;i<q;i++){
    int c,x,y;
    cin>>c>>x>>y;
    if(c) cout<<uf.same(x,y)<<"\n";
    else uf.unite(x,y);
  }
  cout<<flush;
  return 0;
}
/*
  verified on 2019/03/03
  http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_A&lang=jp
*/

signed ABC120_D(){
  int n,m;
  cin>>n>>m;
  vector<int> a(m),b(m);
  for(int i=0;i<m;i++) cin>>a[i]>>b[i];

  UnionFind uf(n);
  vector<Int> ans(m+1,0);
  ans[m]=(Int)n*(n-1)/2;
  for(int i=m-1;i>=0;i--){
    a[i]--;b[i]--;
    ans[i]=ans[i+1];
    if(uf.same(a[i],b[i])) continue;
    
    Int x=uf.size(a[i]),y=uf.size(b[i]);
    ans[i]-=x*y;
    
    uf.unite(a[i],b[i]);
  }
  ans.erase(ans.begin());
  for(Int x:ans) cout<<x<<"\n";
  cout<<flush;
  return 0;
}

/*
  verified on 2019/03/03
  https://atcoder.jp/contests/abc120/tasks/abc120_d
*/

signed main(){
  //DSL_1_A();
  //ABC120_D();
  return 0; 
}
