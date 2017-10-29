#include<bits/stdc++.h>
using namespace std;
using Int = long long;
//BEGIN CUT HERE
template <typename T> 
struct WeightedUnionFind{
  int n;
  T d;
  vector<int> r,p;
  vector<T> ws;
  WeightedUnionFind(){}
  WeightedUnionFind(int sz,T d_):
    n(sz),d(d_),r(n,1),p(n),ws(n,d){iota(p.begin(),p.end(),0);}
  int find(int x){
    if(x==p[x]){
      return x;
    }else{
      int t=find(p[x]);
      ws[x]+=ws[p[x]];
      return p[x]=t;
    }
  }
  T weight(int x){
    find(x);
    return ws[x];
  }
  bool same(int x,int y){
    return find(x)==find(y);
  }
  void unite(int x,int y,T w){
    w+=weight(x);
    w-=weight(y);
    x=find(x);y=find(y);
    if(x==y) return;
    if(r[x]<r[y]) swap(x,y),w=-w;
    r[x]+=r[y];
    p[y]=x;
    ws[y]=w;
  }
  T diff(int x,int y){
    return weight(y)-weight(x);
  }
};
//END CUT HERE
signed main(){
  int n,m;
  while(cin>>n>>m,n||m){
    WeightedUnionFind<Int> u(n,0);
    for(int i=0;i<m;i++){
      int a,b;
      char c;
      cin>>c>>a>>b;
      a--;b--;
      if(c=='!'){
	Int w;
	cin>>w;
	u.unite(a,b,w);
      }else{
	if(!u.same(a,b)) cout<<"UNKNOWN"<<endl;
	else cout<<u.diff(a,b)<<endl;
      }
    }
  }
  return 0;
}
/*
  verified on 2017/10/29
  http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1330
*/
