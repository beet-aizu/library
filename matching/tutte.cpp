#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../mod/mint.cpp"
#undef call_from_test

#endif
//BEGIN CUT HERE
int maximal_matching(vector< vector<int> > G){
  int n=G.size();

  random_device rd;
  mt19937 mt(rd());
  using M = Mint<int>;
  uniform_int_distribution<int> ud(1,M::mod-1);

  vector< vector<M> > H(n,vector<M>(n,0));
  for(int v=0;v<n;v++){
    for(int u:G[v]){
      if(u>=v) continue;
      M val(ud(mt));
      H[u][v]= val;
      H[v][u]=-val;
    }
  }

  int res=0;
  for(int i=0,j=0;i<n;i++){
    while(j<n and H[i][j]==M(0)){
      int p=i;
      for(int k=i+1;k<n;k++)
        if(H[k][j]!=M(0)) p=k;
      if(i!=p) swap(H[i],H[p]);
      else j++;
    }
    if(j==n) break;
    M tmp=H[i][j].inv();
    for(int s=j;s<n;s++) H[i][s]*=tmp;
    for(int k=i+1;k<n;k++)
      for(int s=n-1;s>=j;s--)
        H[k][s]-=H[k][j]*H[i][s];

    j++;res++;
  }
  return (res+1)/2;
}
//END CUT HERE
#ifndef call_from_test
//INSERT ABOVE HERE
signed main(){
  return 0;
}
#endif
