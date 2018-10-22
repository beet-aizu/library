#include<bits/stdc++.h>
using namespace std;
using Int = long long;

//BEGIN CUT HERE
namespace FFT{
  using dbl = double;
  
  struct num{
    dbl x,y;
    num(){x=y=0;}
    num(dbl x,dbl y):x(x),y(y){}
  };
  
  inline num operator+(num a,num b){
    return num(a.x+b.x,a.y+b.y);
  }
  inline num operator-(num a,num b){
    return num(a.x-b.x,a.y-b.y);
  }
  inline num operator*(num a,num b){
    return num(a.x*b.x-a.y*b.y,a.x*b.y+a.y*b.x);
  }
  inline num conj(num a){
    return num(a.x,-a.y);
  }
 
  int base=1;
  vector<num> rts={{0,0},{1,0}};
  vector<int> rev={0,1};
 
  const dbl PI=acosl(-1.0);
 
  void ensure_base(int nbase){
    if(nbase<=base) return;
 
    rev.resize(1<<nbase);
    for(int i=0;i<(1<<nbase);i++)
      rev[i]=(rev[i>>1]>>1)+((i&1)<<(nbase-1));
 
    rts.resize(1<<nbase);
    while(base<nbase){
      dbl angle=2*PI/(1<<(base+1));
      for(int i=1<<(base-1);i<(1<<base);i++){
        rts[i<<1]=rts[i];
        dbl angle_i=angle*(2*i+1-(1<<base));
        rts[(i<<1)+1]=num(cos(angle_i),sin(angle_i));
      }
      base++;
    }
  }
 
  void fft(vector<num> &a,int n=-1){
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
          num z=a[i+j+k]*rts[j+k];
          a[i+j+k]=a[i+j]-z;
          a[i+j]=a[i+j]+z;
        }
      }
    }
  }
 
  vector<num> fa;
 
  vector<Int> multiply(vector<int> &a,vector<int> &b){
    int need=a.size()+b.size()-1;
    int nbase=0;
    while((1<<nbase)<need) nbase++;
    ensure_base(nbase);
 
    int sz=1<<nbase;
    if(sz>(int)fa.size()) fa.resize(sz);
    for(int i=0;i<sz;i++){
      int x=(i<(int)a.size()?a[i]:0);
      int y=(i<(int)b.size()?b[i]:0);
      fa[i]=num(x,y);
    }
    fft(fa,sz);
 
    num r(0,-0.25/sz);
    for(int i=0;i<=(sz>>1);i++){
      int j=(sz-i)&(sz-1);
      num z=(fa[j]*fa[j]-conj(fa[i]*fa[i]))*r;
      if(i!=j)
        fa[j]=(fa[i]*fa[i]-conj(fa[j]*fa[j]))*r;
      fa[i]=z;
    }
    fft(fa,sz);
 
    vector<Int> res(need);
    for(int i=0;i<need;i++)
      res[i]=fa[i].x+0.5;
    
    return res;
  }
  
};
//END CUT HERE

signed main(){
  int n;
  scanf("%d",&n);
  vector<int> a(n+1,0),b(n+1,0);
  for(int i=1;i<=n;i++) scanf("%d %d",&a[i],&b[i]);
  auto c=FFT::multiply(a,b);
  for(int i=1;i<=n*2;i++) printf("%lld\n",c[i]);
  return 0;
}

/*
  verified on 2017/11/14
  http://atc001.contest.atcoder.jp/tasks/fft_c
*/
