#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#include "lowestcommonancestor.cpp"
#undef call_from_test

#endif

//BEGIN CUT HERE
struct AuxiliaryTree : LowestCommonAncestor{
  using super = LowestCommonAncestor;

  vector<int> idx;
  vector<vector<int>> T;
  AuxiliaryTree(int n):super(n),idx(n),T(n){}

  void dfs(int v,int p,int &pos){
    idx[v]=pos++;
    for(int u:G[v])
      if(u!=p) dfs(u,v,pos);
  }

  void build(int r=0){
    super::build(r);
    int pos=0;
    dfs(r,-1,pos);
  }

  void add_aux_edge(int u,int v){
    T[u].emplace_back(v);
    T[v].emplace_back(u);
  }

  using super::lca, super::dep;
  void query(vector<int> &vs){
    assert(!vs.empty());
    sort(vs.begin(),vs.end(),
         [&](int a,int b){return idx[a]<idx[b];});
    vs.erase(unique(vs.begin(),vs.end()),vs.end());

    int k=vs.size();
    stack<int> st;
    st.emplace(vs[0]);
    for(int i=0;i+1<k;i++){
      int w=lca(vs[i],vs[i+1]);
      if(w!=vs[i]){
        int l=st.top();st.pop();
        while(!st.empty() and dep[w]<dep[st.top()]){
          add_aux_edge(st.top(),l);
          l=st.top();st.pop();
        }
        if(st.empty() or st.top()!=w){
          st.emplace(w);
          vs.emplace_back(w);
        }
        add_aux_edge(w,l);
      }
      st.emplace(vs[i+1]);
    }

    while(st.size()>1){
      int c=st.top();st.pop();
      add_aux_edge(st.top(),c);
    }
  }

  void clear(const vector<int> &ws){
    for(int w:ws) T[w].clear();
  }
};
//END CUT HERE
#ifndef call_from_test
signed main(){
  return 0;
}
#endif
