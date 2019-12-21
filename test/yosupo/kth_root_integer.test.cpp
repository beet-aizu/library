#define PROBLEM "https://judge.yosupo.jp/problem/kth_root_integer"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../tools/fastio.cpp"
#include "../../tools/int128.cpp"
#undef call_from_test

signed main(){
  int T;
  cin>>T;

  using ll = __int128_t;
  for(int t=0;t<T;t++){
    ll A,K;
    cin>>A>>K;

    ll L=0,R=A+1;
    while(L+1<R){
      ll M=(L+R)>>1;

      ll res=1;
      for(int i=0;i<K;i++){
        res*=M;
        if(res>A) break;
      }

      if(res<=A) L=M;
      else R=M;
    }

    cout<<L<<"\n";
  }
  cout<<flush;
  return 0;
}
