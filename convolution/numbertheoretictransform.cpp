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

  // assume md % 4 = 1
  // if md % 4 == 3, then x = a^{(md+1)/4}
  inline int sqrt(int a){
    if(a==0) return 0;
    if(pow(a,(md-1)/2)!=1) return -1;
    int q=md-1,m=0;
    while(~q&1) q>>=1,m++;
    mt19937 mt;
    int z=mt()%md;
    while(pow(z,(md-1)/2)!=md-1) z=mt()%md;
    int c=pow(z,q),t=pow(a,q),r=pow(a,(q+1)/2);
    while(m>1){
      if(pow(t,1<<(m-2))!=1)
        r=mul(r,c),t=mul(t,mul(c,c));
      c=mul(c,c);
      m--;
    }
    return r;
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

  vector<int> add(vector<int> as,vector<int> bs){
    int sz=max(as.size(),bs.size());
    vector<int> cs(sz,0);
    for(int i=0;i<(int)as.size();i++) cs[i]=add(cs[i],as[i]);
    for(int i=0;i<(int)bs.size();i++) cs[i]=add(cs[i],bs[i]);
    return cs;
  }

  vector<int> sub(vector<int> as,vector<int> bs){
    int sz=max(as.size(),bs.size());
    vector<int> cs(sz,0);
    for(int i=0;i<(int)as.size();i++) cs[i]=add(cs[i],as[i]);
    for(int i=0;i<(int)bs.size();i++) cs[i]=add(cs[i],md-bs[i]);
    return cs;
  }

  vector<int> multiply(vector<int> as,vector<int> bs){
    int need=as.size()+bs.size()-1;
    int sz=1;
    while(sz<need) sz<<=1;
    ensure_base(sz);

    vector<int> f(sz),g(sz);
    for(int i=0;i<(int)as.size();i++) f[i]=as[i];
    for(int i=0;i<(int)bs.size();i++) g[i]=bs[i];
    ntt(f,0);ntt(g,0);
    for(int i=0;i<sz;i++) f[i]=mul(f[i],g[i]);
    ntt(f,1);

    f.resize(need);
    return f;
  }

  vector<int> divide(vector<int> as,vector<int> bs){
    assert(bs!=vector<int>(bs.size(),0));
    if(as==vector<int>(as.size(),0)) return {0};

    assert(as.size()>=bs.size());
    int need=as.size()-bs.size()+1;
    as.resize(need);

    if(bs[0]==0){
      reverse(as.begin(),as.end());
      reverse(bs.begin(),bs.end());
      while(bs.back()==0){
        assert(as.back()==0);
        as.pop_back();
        bs.pop_back();
      }
      reverse(as.begin(),as.end());
      reverse(bs.begin(),bs.end());
    }
    int sz=1;
    vector<int> rs({inv(bs[0])});
    while(sz<need){
      sz<<=1;
      rs=sub(add(rs,rs),multiply(multiply(rs,rs),bs));
      rs.resize(sz);
    }

    while(as.back()==0) as.pop_back();
    while(rs.back()==0) rs.pop_back();
    auto cs=multiply(as,rs);
    cs.resize(need,0);
    return cs;
  }

  vector<int> sqrt(vector<int> as){
    if(as==vector<int>(as.size(),0)) return {0};

    int dg=0;
    if(as[0]==0){
      reverse(as.begin(),as.end());
      while(as.back()==0){
        dg++;
        as.pop_back();
        assert(as.back()==0);
        as.pop_back();
      }
      reverse(as.begin(),as.end());
    }

    int sz=1,inv2=inv(2);
    vector<int> ss({sqrt(as[0])});
    while(sz<(int)as.size()){
      sz<<=1;
      vector<int> ts(as);
      if((sz+sz/2-1)<(int)ts.size()) ts.resize(sz+sz/2-1);
      ss=add(ss,divide(ts,ss));
      ss.resize(sz);
      for(int &x:ss) x=mul(x,inv2);
    }

    if(dg){
      reverse(ss.begin(),ss.end());
      for(int i=0;i<dg;i++) ss.emplace_back(0);
      reverse(ss.begin(),ss.end());
    }
    return ss;
  }
};
//END CUT HERE

signed ATC001_C(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n;
  cin>>n;
  vector<int> as(n+1,0),bs(n+1,0);
  for(int i=1;i<=n;i++) cin>>as[i]>>bs[i];
  NTT<0> ntt;
  auto cs=ntt.multiply(as,bs);
  for(int i=1;i<=n*2;i++) cout<<cs[i]<<"\n";
  cout<<flush;
  return 0;
}
/*
  verified on 2019/06/28
  https://atcoder.jp/contests/atc001/tasks/fft_c
*/

signed HAPPYQUERY_E(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n,m,q;
  cin>>n>>m>>q;
  vector<int> ls(q),rs(q);
  for(int i=0;i<q;i++) cin>>ls[i]>>rs[i],ls[i]--;

  vector<int> as(n);
  for(int i=0;i<n;i++) cin>>as[i];

  vector<int> cnt(n-m+1,0);
  for(int l:ls) cnt[l]++;

  NTT<0> ntt;
  auto bs=ntt.divide(as,cnt);

  assert((int)bs.size()==m);
  for(int i=0;i<m;i++){
    if(i) cout<<" ";
    cout<<bs[i];
  }
  cout<<endl;
  return 0;
}
/*
  verified on 2019/06/28
  https://www.hackerrank.com/contests/happy-query-contest/challenges/array-restoring
*/

signed CFR250_E(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n,m;
  cin>>n>>m;
  vector<int> cs(n);
  for(int i=0;i<n;i++) cin>>cs[i];

  NTT<2> ntt;
  vector<int> as(1<<18,0);
  as[0]=1;
  for(int c:cs) as[c]=ntt.add(as[c],ntt.md-4);

  vector<int> bs=ntt.sqrt(as);
  bs[0]=ntt.add(bs[0],1);
  while(bs.back()==0) bs.pop_back();

  vector<int> vs(bs.size()+m,0);
  vs[0]=2;

  vector<int> ans=ntt.divide(vs,bs);
  for(int i=1;i<=m;i++) cout<<ans[i]<<"\n";
  cout<<flush;
  return 0;
}
/*
  verified on 2019/06/28
  https://codeforces.com/contest/438/problem/E
*/

signed main(){
  //ATC001_C();
  //HAPPYQUERY_E();
  //CFR250_E();
  return 0;
}
