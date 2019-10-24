#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1508"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../bbst/basic/base.cpp"
#include "../../bbst/basic/ushi.cpp"
#undef call_from_test

signed main(){
  int n,q;
  scanf("%d %d",&n,&q);
  vector<int> vs(n);
  for(int i=0;i<n;i++) scanf("%d",&vs[i]);

  auto f=[](int a,int b){return min(a,b);};
  const int INF = 1e9;

  using Node = NodeBase<int>;
  constexpr size_t LIM = 1e6;
  Ushi<Node, LIM> G(f,INF);

  auto rt=G.build(vector<Node>(vs.begin(),vs.end()));

  for(int i=0;i<q;i++){
    int x,y,z;
    scanf("%d %d %d",&x,&y,&z);
    if(x==0){
      int l=y,r=z+1;
      rt=G.toggle(rt,l,r);
      rt=G.toggle(rt,l+1,r);
    }
    if(x==1){
      int l=y,r=z+1;
      printf("%d\n",G.query(rt,l,r));
    }
    if(x==2){
      rt=G.set_val(rt,y,z);
    }
  }

  return 0;
}
