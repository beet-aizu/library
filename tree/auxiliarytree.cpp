#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "eulertourforvertex.cpp"
#include "lowestcommonancestor.cpp"
#undef call_from_test

#endif
//BEGIN CUT HERE
struct AuxiliaryTree : EulerTourForVertex{
  using super = EulerTourForVertex;
  LowestCommonAncestor lca;
  AuxiliaryTree(){}
  AuxiliaryTree(int n):super(n),lca(n){}

  void build(int r=0){
    super::build(r);
    lca.G=super::G;
    lca.build(r);
  }

  using super::idx;
  decltype(auto) query(vector<int> &vs){
    assert(!vs.empty());
    sort(vs.begin(),vs.end(),
         [&](int a,int b){return idx(a)<idx(b);});

    map<int, vector<int>> H;

    int k=vs.size();
    stack<int> st;
    st.emplace(vs[0]);
    H[vs[0]];
    for(int i=0;i+1<k;i++){
      int w=lca.lca(vs[i],vs[i+1]);
      if(w!=vs[i]){
        int l=st.top();st.pop();
        while(!st.empty()&&lca.dep[w]<lca.dep[st.top()]){
          H[st.top()].emplace_back(l);
          l=st.top();st.pop();
        }
        if(st.empty()||st.top()!=w){
          st.emplace(w);
          vs.emplace_back(w);
        }
        H[w].emplace_back(l);
      }
      st.emplace(vs[i+1]);
      H[vs[i+1]];
    }

    while(st.size()>1){
      int c=st.top();st.pop();
      H[st.top()].emplace_back(c);
    }

    return make_pair(st.top(),H);
  }
};
//END CUT HERE
#ifndef call_from_test

signed main(){
  int n;
  cin>>n;

  AuxiliaryTree G(n);
  vector<map<int, int>> ws(n);
  for(int i=1;i<n;i++){
    int u,v,w;
    cin>>u>>v>>w;
    G.add_edge(u,v);
    ws[u][v]=ws[v][u]=w;
  }
  G.build();

  using ll = long long;
  vector<ll> dep(n,-1);
  queue<int> que;
  dep[0]=0;
  que.emplace(0);
  while(!que.empty()){
    int v=que.front();que.pop();
    for(int u:G.G[v]){
      if(~dep[u]) continue;
      dep[u]=dep[v]+ws[v][u];
      que.emplace(u);
    }
  }

  int q;
  cin>>q;
  for(int i=0;i<q;i++){
    int k;
    cin>>k;
    vector<int> vs(k);
    for(int j=0;j<k;j++) cin>>vs[j];

    auto H=G.query(vs).second;
    ll ans=0;
    for(int v:vs)
      for(int u:H[v])
        ans+=dep[u]-dep[v];

    cout<<ans<<"\n";
  }
  cout<<flush;
  return 0;
}
#endif
