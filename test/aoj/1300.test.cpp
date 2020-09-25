// verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1300

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../string/split.cpp"
#include "../../vector/compress.cpp"
#include "../../mod/mint.cpp"
#undef call_from_test

using S = map<string, int>;
S add(S x,S y){
  for(auto p:y)
    x[p.first]+=p.second;
  return x;
}
S mul(S x,int k){
  for(auto &p:x)
    p.second*=k;
  return x;
}

S term(string s){
  S res;
  int n=s.size();
  for(int i=0;i<n;){
    if(s[i]=='('){
      int j=s.find(')',i);
      string t=s.substr(i+1,j-(i+1));
      auto tmp=term(t);
      i=j+1;
      if(i==n) continue;
      if(isdigit(s[i])){
        int num=0;
        while(i<n&&isdigit(s[i]))
          num=num*10+(s[i]-'0'),i++;
        tmp=mul(tmp,num);
      }
      res=add(res,tmp);
      continue;
    }
    assert(isupper(s[i]));
    string c;
    c+=s[i],i++;
    while(i<n&&islower(s[i])) c+=s[i],i++;
    int num=0;
    while(i<n&&isdigit(s[i]))
      num=num*10+(s[i]-'0'),i++;
    if(num==0) num=1;
    res[c]+=num;
  }
  return res;
}

vector<S> conv(string s){
  vector<S> res;
  for(auto t:split(s,'+'))
    res.emplace_back(term(t));
  return res;
}

signed solve(string s){
  s.pop_back();
  string x=s.substr(0,s.find("->"));
  string y=s.substr(s.find("->")+2);
  auto t1=conv(x);
  auto t2=conv(y);

  vector<string> ms;
  for(auto rs:t1)
    for(auto p:rs)
      ms.emplace_back(p.first);
  for(auto rs:t2)
    for(auto p:rs)
      ms.emplace_back(p.first);
  ms=compress(ms);
  auto dc=dict(ms);

  int n=ms.size();
  int m=t1.size()+t2.size();

  using M = Mint<int>;
  vector< vector<M> > mat(n,vector<M>(m));
  for(int i=0;i<(int)t1.size();i++)
    for(auto p:t1[i])
      mat[dc[p.first]][i]=M(p.second);

  for(int i=0;i<(int)t2.size();i++)
    for(auto p:t2[i])
      mat[dc[p.first]][t1.size()+i]=-M(p.second);

  for(int j=0;j+1<m;j++){
    {
      int k=-1;
      for(int i=j;i<n;i++)
        if(mat[i][j]!=M(0)) k=i;
      assert(~k);
      swap(mat[j],mat[k]);
    }
    for(int k=m-1;k>=j;k--)
      mat[j][k]/=mat[j][j];

    for(int i=j+1;i<n;i++){
      M cof=mat[i][j];
      for(int k=0;k<m;k++)
        mat[i][k]-=cof*mat[j][k];
    }
  }

  for(int j=m-2;j>=0;j--){
    for(int i=0;i<j;i++){
      M cof=mat[i][j];
      for(int k=0;k<m;k++)
        mat[i][k]-=cof*mat[j][k];
    }
  }

  using ll = long long;
  auto check=
    [&](vector<ll> cof)->int{
      map<string, ll> res;
      for(int i=0;i<(int)t1.size();i++)
        for(auto p:t1[i])
          res[p.first]+=p.second*cof[i];
      for(int i=0;i<(int)t2.size();i++)
        for(auto p:t2[i])
          res[p.first]-=p.second*cof[t1.size()+i];
      for(auto p:res)
        if(p.second!=0) return 0;
      return 1;
    };

  const int MAX = 40000;
  for(ll l=1;l<=MAX;l++){
    vector<ll> cof(m,0);
    cof[m-1]=l;
    for(int i=0;i+1<m;i++)
      cof[i]=(-M(l)*mat[i][m-1]).v;
    if(*max_element(cof.begin(),cof.end())>MAX) continue;

    if(check(cof)){
      for(int i=0;i<m;i++){
        if(i) cout<<" ";
        cout<<cof[i];
      }
      cout<<endl;
      break;
    }
  }
  return 0;
}

signed main(){
  string s;
  while(cin>>s,s!=".") solve(s);
  return 0;
}
