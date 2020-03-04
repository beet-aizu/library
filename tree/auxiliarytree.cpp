#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "eulertourforvertex.cpp"
#include "lowestcommonancestor.cpp"
#undef call_from_test

#endif
/**
 * @see https://smijake3.hatenablog.com/entry/2019/09/15/200200
 */
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
  return 0;
}
#endif
