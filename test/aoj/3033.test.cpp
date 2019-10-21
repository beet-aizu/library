#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=3033"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../tools/fastio.cpp"
#include "../../string/suffixarray.cpp"
#undef call_from_test

signed main(){
  using ll = long long;
  int n;
  ll k;
  string s;
  cin>>n>>k>>s;

  auto calc=[](ll x){return x*(x+1)/2;};
  ll zs=0;
  vector<ll> cnt(n+1,1);
  for(int i=0;i<n;i++){
    if(s[i]=='0'){
      if(i+1>=n||s[i+1]!='0') zs+=calc(cnt[i]);
      if(i+1<n) cnt[i+1]+=cnt[i];
      cnt[i]=0;
    }
  }

  if(k<=zs){
    cout<<0<<endl;
    return 0;
  }
  k-=zs+1;

  vector<ll> sum(n+1,0);
  for(int i=0;i<n;i++) sum[i+1]=sum[i]+cnt[i];

  int len=1;
  while(k>=sum[n+1-len]&&len<n) k-=sum[n+1-(len++)];

  SuffixArray sa(s);
  int pos=0;
  for(int i=1;i<=n;i++){
    if(s[sa.sa[i]]=='0'||sa.sa[i]+len>n) continue;
    if(k>=0) pos=sa.sa[i];
    k-=cnt[sa.sa[i]];
  }

  cout<<s.substr(pos,len)<<endl;
  return 0;
}
