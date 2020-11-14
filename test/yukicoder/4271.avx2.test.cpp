// verification-helper: PROBLEM https://yukicoder.me/problems/4271

#define call_from_test
#include "../../tools/avx2.cpp"
#undef call_from_test

#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e5;
const int MOD = 1e9+7;
using uint = unsigned int;

inline uint add_mod(uint a, uint b) {
  return (a += b) >= MOD ? a - MOD : a;
}

uint mul(uint x,uint y){
  return 1ULL*x*y%MOD;
}

uint xs[MAX]={};
uint as[MAX]={};
uint cs[MAX]={};

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  const char newl = '\n';

  int k,n,m;
  cin>>k>>n>>m;
  for(int i=0;i<k;i++) cin>>as[i];
  for(int i=0;i<k;i++) cin>>cs[i];

  for(int i=k;i<n;i++)
    for(int j=0;j<k;j++)
      as[i]=add_mod(as[i],mul(cs[j],as[i-(j+1)]));

  for(int i=0;i<m;i++){
    int l,r;
    cin>>l>>r;
    for(int k=l;k<r;k++) xs[k]=add_mod(xs[k],as[k-l]);
  }

  for(int i=0;i<n;i++) cout<<xs[i]<<newl;
  return 0;
}
