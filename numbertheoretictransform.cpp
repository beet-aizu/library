#include<bits/stdc++.h>
using namespace std;
using Int = long long;
//BEGIN CUT HERE
namespace NTT{
  using ull = unsigned long long;
  const int bmds[5]={1012924417,924844033,998244353,897581057,645922817};
  const int brts[5]={5,5,3,3,3};
  int md,rt;

  struct num{
    int v;
    num(){v=0;}
    num(int v):v(v){}
  };

  inline num operator+(num a,num b){
    return num((a.v+=b.v)>=md?a.v-md:a.v);
  }
  
  inline num operator-(num a,num b){
    return num((a.v+=md-b.v)>=md?a.v-md:a.v);
  }
  
  inline num operator*(num a,num b){
    return num(ull(a.v)*b.v%md);
  }

  inline num pow(num a,int b){
    //cout<<a.v<<" "<<b<<endl;
    num res=1;
    while(b){
      if(b&1) res=res*a;
      a=a*a;
      b>>=1;
    }
    //cout<<":"<<res.v<<endl;
    return res;
  }

  inline num inv(num x){
    return pow(x,md-2);
  }
  
  inline num operator/(num a,num b){
    return a*inv(b);
  }
  
  int base;
  vector<num> rts,rrts;
  vector<int> rev;

  void init(int k){
    md=bmds[k];
    rt=brts[k];
    base=1;
    rts={num(0),num(1)};
    rev={0,1};
    rrts.clear();
  }
  
  void ensure_base(int nbase){
    if(nbase<=base) return;
 
    rev.resize(1<<nbase);
    for(int i=0;i<(1<<nbase);i++)
      rev[i]=(rev[i>>1]>>1)+((i&1)<<(nbase-1));
 
    rts.resize(1<<nbase);
    while(base<nbase){
      num angle=pow(rt,(md-1)>>(base+1));
      for(int i=1<<(base-1);i<(1<<base);i++){
	rts[i<<1]=rts[i];
	rts[(i<<1)+1]=pow(angle,2*i+1-(1<<base));
      }
      base++;
    }

    rrts.resize(1<<nbase);
    for(int i=0;i<(1<<nbase);i++) rrts[i]=inv(rts[i]);
  }

  void ntt(vector<num> &a,bool f,int n=-1){
    if(n==-1) n=a.size();
    assert((n&(n-1))==0);
 
    int zeros=__builtin_ctz(n);
    ensure_base(zeros);
    int shift=base-zeros;
    for(int i=0;i<n;i++)
      if(i<(rev[i]>>shift))
	swap(a[i],a[rev[i]>>shift]);
 
    for(int k=1;k<n;k<<=1){
      for(int i=0;i<n;i+=2*k){
	for(int j=0;j<k;j++){
	  num z;
	  if(f) z=a[i+j+k]*rrts[j+k];
	  else  z=a[i+j+k]*rts[j+k];
	  a[i+j+k]=a[i+j]-z;
	  a[i+j]=a[i+j]+z;
	}
      }
    }
    if(f){
      num tmp=inv(n);
      for(Int i=0;i<n;i++) a[i]=a[i]*tmp;
    }
  }

  vector<int> multiply(vector<int> &a,vector<int> &b){
    int need=a.size()+b.size()-1;
    int nbase=0;
    while((1<<nbase)<need) nbase++;
    ensure_base(nbase);
    
    int sz=1<<nbase;
    
    vector<num> f(sz),g(sz);
    for(int i=0;i<(int)a.size();i++) f[i]=num(a[i]);
    for(int i=0;i<(int)b.size();i++) g[i]=num(b[i]);
    ntt(f,0);ntt(g,0);
    for(int i=0;i<sz;i++) f[i]=f[i]*g[i];
    ntt(f,1);
    
    vector<int> res(need,0);
    for(int i=0;i<need;i++) res[i]=f[i].v;
    return res;
  }
  
};
//END CUT HERE

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  int n;
  cin>>n;
  vector<int> a(n+1,0),b(n+1,0);
  for(int i=1;i<=n;i++) cin>>a[i]>>b[i];
  NTT::init(0);
  auto c=NTT::multiply(a,b);
  for(int i=1;i<=n*2;i++) cout<<c[i]<<endl;
  return 0;
}

/*
  verified on 2017/11/17
  http://atc001.contest.atcoder.jp/tasks/fft_c
*/
