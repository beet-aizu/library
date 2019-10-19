#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2959"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../mod/mint.cpp"
#include "../../convolution/numbertheoretictransform.cpp"
#undef call_from_test

NTT<2> ntt;
using M = Mint<int, ntt.md>;
vector<M> res;

void dfs(vector<int> &as,vector<int> &bs,int l,int r){
  if(r-l==1) return;
  int m=(l+r)>>1;
  vector<int> cs(m-l);
  vector<int> ds(r-m);
  for(int i=l;i<m;i++) cs[i-l]=as[i];
  for(int i=m;i<r;i++) ds[i-m]=bs[i];
  auto es=ntt.multiply(cs,ds);
  for(int i=0;i<(int)es.size();i++)
    res[l+m+i]+=M(es[i]);
  dfs(as,bs,l,m);
  dfs(as,bs,m,r);
}

signed main(){
  string s;
  cin>>s;
  int n=s.size();
  vector<int> us(n),gs(n),qs(n);
  int num=0;
  for(int i=0;i<n;i++){
    us[i]=s[i]=='U';
    gs[i]=s[i]=='G';
    qs[i]=s[i]=='?';

    num+=qs[i];
  }

  M ans{0};
  // U (M / ?) G
  {
    res.assign(2*n,0);
    dfs(us,gs,0,n);
    for(int i=0;i<n;i++){
      if(s[i]=='M'){
        ans+=res[i*2]*M(3).pow(num);
      }
      if(s[i]=='?'){
        ans+=res[i*2]*M(3).pow(num-1);
      }
    }
  }
  // ? (M / ?) G
  {
    res.assign(2*n,0);
    dfs(qs,gs,0,n);
    for(int i=0;i<n;i++){
      if(s[i]=='M'){
        if(num>=1)
          ans+=res[i*2]*M(3).pow(num-1);
      }
      if(s[i]=='?'){
        if(num>=2)
          ans+=res[i*2]*M(3).pow(num-2);
      }
    }
  }

  // U (M / ?) ?
  {
    res.assign(2*n,0);
    dfs(us,qs,0,n);
    for(int i=0;i<n;i++){
      if(s[i]=='M'){
        if(num>=1)
          ans+=res[i*2]*M(3).pow(num-1);
      }
      if(s[i]=='?'){
        if(num>=2)
          ans+=res[i*2]*M(3).pow(num-2);
      }
    }
  }

  // ? (M / ?) ?
  {
    res.assign(2*n,0);
    dfs(qs,qs,0,n);
    for(int i=0;i<n;i++){
      if(s[i]=='M'){
        if(num>=2)
          ans+=res[i*2]*M(3).pow(num-2);
      }
      if(s[i]=='?'){
        if(num>=3)
          ans+=res[i*2]*M(3).pow(num-3);
      }
    }
  }

  cout<<ans<<endl;
  return 0;
}
