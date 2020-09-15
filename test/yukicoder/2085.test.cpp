#define PROBLEM "https://yukicoder.me/problems/2085"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../tree/rerooting.cpp"
#undef call_from_test

#ifdef SANITIZE
#define IGNORE
#endif

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n;
  cin>>n;
  auto fold=[](int a,int b){return max(a,0)+max(b,0);};
  auto lift=[](int a,int d){return d-a;};
  ReRooting<int, int> G(n,fold,lift,0);
  for(int i=1;i<n;i++){
    int a,b;
    cin>>a>>b;
    a--;b--;
    G.add_edge(a,b,1);
  }
  auto res=G.build();

  vector<int> ans;
  for(int i=0;i<n;i++)
    if(1-res[i]>0) ans.emplace_back(i);

  cout<<ans.size()<<"\n";
  for(int x:ans) cout<<x+1<<"\n";
  cout<<flush;
  return 0;
}
