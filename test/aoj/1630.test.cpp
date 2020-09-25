// verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1630

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../mod/mint.cpp"
#include "../../polynomial/hash.cpp"
#undef call_from_test

using M1 = Mint<int, int(1e9+7)>;
using M2 = Mint<int, int(1e9+9)>;
using M3 = Mint<int, int(1e8+7)>;
PolynomialHash<int, M1, M2, M3> ph(100);
using V = decltype(ph)::V;

vector<vector<V> > vs;
vector<vector<vector<V> > > vm;

V expr(string &s,int &p,int d);
V term(string &s,int &p,int d);
V factor(string &s,int &p,int d);
V number(string &s,int &p);

V expr(string &s,int &p,int d){
  V res=term(s,p,d);
  vs[d].emplace_back(res);
  while(p<(int)s.size()){
    if(s[p]=='+'){
      p++;
      V b=term(s,p,d);
      vs[d].emplace_back(b);
      res+=b;
      continue;
    }
    break;
  }
  vs[d].emplace_back(0);
  vm[d].emplace_back();
  return res;
}

V term(string &s,int &p,int d){
  V res=factor(s,p,d);
  vm[d].emplace_back();
  vm[d].back().emplace_back(res);
  while(p<(int)s.size()){
    if(s[p]=='*'){
      p++;
      V b=factor(s,p,d);
      vm[d].back().emplace_back(b);
      res*=b;
      continue;
    }
    break;
  }
  return res;
}

V factor(string &s,int &p,int d){
  if(s[p]=='('){
    p++;
    V res=expr(s,p,d+1);
    assert(s[p]==')');
    p++;
    return res;
  }
  return number(s,p);
}

V number(string &s,int &p){
  int k=s[p++]-'0';
  return V(k);
}

signed main(){
  using ll = long long;

  int n;
  while(cin>>n,n){
    string s;
    cin>>s;
    vs.assign(1010,vector<V>());
    vm.assign(1010,vector<vector<V> >());

    V nv((ll)n);

    int p=0;
    expr(s,p,0);
    ll ans=0;

    for(int i=0;i<1010;i++){
      auto &v=vs[i];
      if(v.empty()) continue;
      map<V, ll> dp;
      V uku(0);

      dp[uku]++;
      for(int j=0;j<(int)v.size();j++){
        if(v[j]==V(0)){
          dp.clear();
          uku=V(0);
          dp[uku]++;
          continue;
        }

        {
          V malta(1);
          for(int k=0;k<(int)vm[i][j].size();k++){
            malta*=vm[i][j][k];
            ans+=dp[uku+malta-nv];
          }
        }

        {
          V malta(1);
          map<V, ll> dp2;
          dp2[malta*nv]++;
          for(int k=1;k<(int)vm[i][j].size();k++){
            malta*=vm[i][j][k];
            ans+=dp2[malta];
            dp2[malta*nv]++;
          }
        }

        {
          V malta(1);
          uku+=v[j];
          for(int k=0;k+1<(int)vm[i][j].size();k++){
            malta*=vm[i][j][k];
            dp[uku-v[j]/malta]++;
          }
        }
        dp[uku]++;
      }
    }
    cout<<ans<<endl;
  }
  return 0;
}
