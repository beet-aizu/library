#include<bits/stdc++.h>
using namespace std;
using Int = long long;
//BEGIN CUT HERE
constexpr int bmds(int x){
  const int v[] = {1012924417, 924844033, 998244353,
                   897581057, 645922817};
  return v[x];
}
constexpr int brts(int x){
  const int v[] = {5, 5, 3, 3, 3};
  return v[x];
}


template<int X>
struct NTT{
  static constexpr int md = bmds(X);
  static constexpr int rt = brts(X);

  inline int add(int a,int b){
    a+=b;
    if(a>=md) a-=md;
    return a;
  }
  
  inline int mul(int a,int b){
    return 1LL*a*b%md;
  }
  
  inline int pow(int a,int b){
    int res=1;
    while(b){
      if(b&1) res=mul(res,a);
      a=mul(a,a);
      b>>=1;
    }
    return res;
  }

  inline int inv(int x){
    return pow(x,md-2);
  }
  
  vector<vector<int> > rts,rrts;
  
  void ensure_base(int n){
    if((int)rts.size()>=n) return;
    rts.resize(n);rrts.resize(n);
    for(int i=1;i<n;i<<=1){
      if(!rts[i].empty()) continue;
      int w=pow(rt,(md-1)/(i<<1));
      int rw=inv(w);
      rts[i].resize(i);rrts[i].resize(i);
      rts[i][0]=1;rrts[i][0]=1;
      for(int k=1;k<i;k++){
        rts[i][k]=mul(rts[i][k-1],w);
        rrts[i][k]=mul(rrts[i][k-1],rw);
      }
    }
  }

  void ntt(vector<int> &a,bool f,int n=-1){
    if(n==-1) n=a.size();
    assert((n&(n-1))==0);
    
    for(int i=0,j=1;j+1<n;j++){
      for(int k=n>>1;k>(i^=k);k>>=1);
      if(i>j) swap(a[i],a[j]);
    }

    for(int i=1;i<n;i<<=1){
      for(int j=0;j<n;j+=i*2){
        for(int k=0;k<i;k++){
          int z=mul(a[i+j+k],f?rrts[i][k]:rts[i][k]);
          a[i+j+k]=add(a[j+k],md-z);
          a[j+k]=add(a[j+k],z);
        }
      }
    }
    
    if(f){
      int tmp=inv(n);
      for(Int i=0;i<n;i++) a[i]=mul(a[i],tmp);
    }
  }

  vector<int> multiply(vector<int> &a,vector<int> &b){
    int need=a.size()+b.size()-1;
    int sz=1;
    while(sz<need) sz<<=1;
    ensure_base(sz);
    
    vector<int> f(sz),g(sz);
    for(int i=0;i<(int)a.size();i++) f[i]=a[i];
    for(int i=0;i<(int)b.size();i++) g[i]=b[i];
    ntt(f,0);ntt(g,0);
    for(int i=0;i<sz;i++) f[i]=mul(f[i],g[i]);
    ntt(f,1);

    f.resize(need);
    return f;
  }
  
};
//END CUT HERE

signed main(){
  int n;
  scanf("%d",&n);
  vector<int> a(n+1,0),b(n+1,0);
  for(int i=1;i<=n;i++) scanf("%d %d",&a[i],&b[i]);
  NTT<0> ntt;
  auto c=ntt.multiply(a,b);
  for(int i=1;i<=n*2;i++) printf("%d\n",c[i]);
  return 0;
}

/*
  verified on 2017/11/17
  http://atc001.contest.atcoder.jp/tasks/fft_c
*/
