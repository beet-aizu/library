// verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0502

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../tools/dice.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n;
  while(cin>>n,n){
    Die d;
    for(int i=0;i<6;i++) d.fs[i]=i+1;

    int ans=d.top();
    for(int i=0;i<n;i++){
      string s;
      cin>>s;
      d.roll(s[0]);
      ans+=d.top();
    }
    cout<<ans<<endl;
  }
  return 0;
}
