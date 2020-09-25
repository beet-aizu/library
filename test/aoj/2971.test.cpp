// verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2971

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../tools/drop.cpp"
#include "../../mod/mint.cpp"
#include "../../polynomial/hash.cpp"
#undef call_from_test

const int MOD1 = 1e9+7;
const int MOD2 = 1e9+9;
const int MOD3 = 1e9+21;

using M1 = Mint<int, MOD1>;
using M2 = Mint<int, MOD2>;
using M3 = Mint<int, MOD3>;

using PH = PolynomialHash<int, M1, M2, M3>;
PH ph(1);

const int MAX = 1e5+100;
int used[MAX]={};
PH::V vs[MAX];

using P = pair<int, int>;
vector<P> G[MAX],R[MAX];

template<typename T> void check(T x,T y){if(x!=y) drop("No");};

void dfs(int v){
  for(auto e:G[v]){
    int u=e.first,x=e.second;
    if(used[u]) continue;
    used[u]=1;
    vs[u]=vs[v]*PH::V(x);
    dfs(u);
  }
  for(auto e:R[v]){
    int u=e.first,x=e.second;
    if(used[u]) continue;
    used[u]=1;
    vs[u]=vs[v]/PH::V(x);
    dfs(u);
  }

  for(auto e:G[v]){
    int u=e.first,x=e.second;
    check(vs[u],vs[v]*PH::V(x));
  }
  for(auto e:R[v]){
    int u=e.first,x=e.second;
    check(vs[u],vs[v]/PH::V(x));
  }
}

signed main(){
  int n,m;
  cin>>n>>m;

  for(int i=0;i<m;i++){
    int a,b,x;
    cin>>a>>b>>x;
    a--;b--;
    G[a].emplace_back(b,x);
    R[b].emplace_back(a,x);
  }

  for(int i=0;i<n;i++){
    if(used[i]) continue;
    vs[i]=PH::V(1);
    dfs(i);
  }

  cout<<"Yes"<<endl;
  return 0;
}
