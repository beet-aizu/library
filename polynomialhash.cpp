#include<bits/stdc++.h>
using namespace std;
using Int = long long;
//BEGIN CUT HERE
template<typename T>
struct PolynomialHash{
  using V = tuple<T, T, T>;
  static const T MOD1 = 1e9+7;
  static const T MOD2 = 1e9+9;
  static const T MOD3 = 1e8+7;
  static const T BASE = 1777771;
  vector<T> po1,po2,po3;
  vector<T> op1,op2,op3;

  inline T add1(T a,T b){
    a+=b;
    if(a>=MOD1) a-=MOD1;
    return a;
  }
  inline T add2(T a,T b){
    a+=b;
    if(a>=MOD2) a-=MOD2;
    return a;
  }
  inline T add3(T a,T b){
    a+=b;
    if(a>=MOD3) a-=MOD3;
    return a;
  }
  
  inline T sub1(T a,T b){
    return add1(a,MOD1-b);
  }
  inline T sub2(T a,T b){
    return add2(a,MOD2-b);
  }
  inline T sub3(T a,T b){
    return add3(a,MOD3-b);
  }

  inline T mul1(T a,T b){
    return (1LL*a*b)%MOD1;
  }

  inline T mul2(T a,T b){
    return (1LL*a*b)%MOD2;
  }

  inline T mul3(T a,T b){
    return (1LL*a*b)%MOD3;
  }

  static inline constexpr T pow(T a,int n,const T MOD){
    T res=1;
    while(n){
      if(n&1) res=1LL*res*a%MOD;
      a=1LL*a*a%MOD;
      n>>=1;
    }
    return res;
  }
  
  static inline constexpr T inv(T a,T MOD){
    return pow(a,MOD-2,MOD);
  }
  
  static constexpr T INV1 = inv(BASE,MOD1);
  static constexpr T INV2 = inv(BASE,MOD2);
  static constexpr T INV3 = inv(BASE,MOD3);
  
  PolynomialHash(const int MAX){
    po1.resize(MAX);
    po2.resize(MAX);
    po3.resize(MAX);
    po1[0]=po2[0]=po3[0]=1;
    for(int i=1;i<MAX;i++){
      po1[i]=mul1(po1[i-1],BASE);
      po2[i]=mul2(po2[i-1],BASE);
      po3[i]=mul3(po3[i-1],BASE);
    }
    
    op1.resize(MAX);
    op2.resize(MAX);
    op3.resize(MAX);
    op1[0]=op2[0]=op3[0]=1;
    for(int i=1;i<MAX;i++){
      op1[i]=mul1(op1[i-1],INV1);
      op2[i]=mul2(op2[i-1],INV2);
      op3[i]=mul3(op3[i-1],INV3);
    }
  }

  V build(const vector<T> &v){
    int n=v.size();
    T r1=0,r2=0,r3=0;
    for(int i=0;i<n;i++){
      r1=add1(r1,mul1(v[i],po1[i]));
      r2=add2(r2,mul2(v[i],po2[i]));
      r3=add3(r3,mul3(v[i],po3[i]));
    }
    return V(r1,r2,r3);
  }
  
  V add(const V &a,const V &b){
    T a1,a2,a3,b1,b2,b3;
    tie(a1,a2,a3)=a;
    tie(b1,b2,b3)=b;
    T r1=add1(a1,b1);
    T r2=add2(a2,b2);
    T r3=add3(a3,b3);
    return V(r1,r2,r3);
  }
  
  V sub(const V &a,const V &b){
    T a1,a2,a3,b1,b2,b3;
    tie(a1,a2,a3)=a;
    tie(b1,b2,b3)=b;
    T r1=sub1(a1,b1);
    T r2=sub2(a2,b2);
    T r3=sub3(a3,b3);
    return V(r1,r2,r3);
  }

  V term(int x,T k){
    T a1=mul1(po1[x],k);
    T a2=mul2(po2[x],k);
    T a3=mul3(po3[x],k);
    return V(a1,a2,a3);
  }

  V shl(const V &a,int k){
    T a1,a2,a3;
    tie(a1,a2,a3)=a;
    a1=mul(a1,op1[k]);
    a2=mul(a2,op2[k]);
    a3=mul(a3,op3[k]);
    return V(a1,a2,a3);
  }
  
  V shr(const V &a,int k){
    T a1,a2,a3;
    tie(a1,a2,a3)=a;
    a1=mul(a1,po1[k]);
    a2=mul(a2,po2[k]);
    a3=mul(a3,po3[k]);
    return V(a1,a2,a3);
  }

  V mv(const V &a,int k){
    if(k<0) return shl(a,-k);
    return shr(a,k);
  }
};

//END CUT HERE

signed CODEFLYER2018_F(){
  const int MAX = 2020;
  using BS = bitset<MAX>;
  
  int h,w,q;
  scanf("%d %d %d",&h,&w,&q);
  vector<string> s(h);
  char buf[MAX];
  for(int i=0;i<h;i++){
    scanf("%s",buf);
    s[i]=string(buf);
  }
  
  vector<BS> rs(h),cs(w);
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      rs[i][j]=(s[i][j]=='#');
      cs[j][i]=(s[i][j]=='#');
    }
  }

  auto conv=
    [&](BS &v,int k){
      vector<int> a(k);
      for(int i=0;i<k;i++) a[i]=v[i];
      return a;
    };
  
  PolynomialHash<int> ph(MAX);
  using T = PolynomialHash<int>::V;
  vector<T> vrs(h),vcs(w);
  vector<int> tmp(w,1);
  T ri=ph.build(tmp);
  tmp.assign(h,1);
  T ci=ph.build(tmp);
  
  for(int i=0;i<h;i++){
    auto v=conv(rs[i],w);
    vrs[i]=ph.build(v);
    if(rs[i][0]) vrs[i]=ph.sub(ri,vrs[i]);
  }

  for(int j=0;j<w;j++){
    auto v=conv(cs[j],h);
    vcs[j]=ph.build(v);
    if(cs[j][0]) vcs[j]=ph.sub(ci,vcs[j]);
  }
  
  map<T, set<int> > mrs, mcs;
  for(int i=0;i<h;i++) mrs[vrs[i]].emplace(i);
  for(int j=0;j<w;j++) mcs[vcs[j]].emplace(j);

  auto check=
    [&](){
      int a1=-1,b1=-1,c1=-1,d1=-1;
      int a2=-1,b2=-1,c2=-1,d2=-1;

      int A,B,C,D;
      
      {
	auto latte=mrs.begin();
	set<int> &s=latte->second;
	latte++;
	set<int> &t=latte->second;
	if(*--s.end()-*s.begin()+1==(int)s.size()){
	  a1=*s.begin();
	  b1=*--s.end();
	}
	if(*--t.end()-*t.begin()+1==(int)t.size()){
	  a2=*t.begin();
	  b2=*--t.end(); 
	}
	A=*s.begin();
	B=*t.begin();
      }
      if(a1<0&&a2<0){
	puts("No");
	return;
      }
      
      {
	auto latte=mcs.begin();
	set<int> &s=latte->second;
	latte++;
	set<int> &t=latte->second;
	if(*--s.end()-*s.begin()+1==(int)s.size()){
	  c1=*s.begin();
	  d1=*--s.end();
	}
	if(*--t.end()-*t.begin()+1==(int)t.size()){
	  c2=*t.begin();
	  d2=*--t.end(); 
	}
	C=*s.begin();
	D=*t.begin();
      }
      
      if(c1<0&&c2<0){
	puts("No");
	return;
      }

      {
	int flg=0;
	if(~c1){
	  BS r=rs[A]^rs[B];
	  r>>=c1;
	  int k=r.count();
	  r>>=(d1-c1+1);
	  k-=r.count();
	  flg|=(d1-c1+1)==k;
	}
	if(~c1){
	  BS r=rs[A]^~rs[B];
	  r>>=c1;
	  int k=r.count();
	  r>>=(d1-c1+1);
	  k-=r.count();
	  flg|=(d1-c1+1)==k;
	}
	if(~c2){
	  BS r=rs[A]^rs[B];
	  r>>=c2;
	  int k=r.count();
	  r>>=(d2-c2+1);
	  k-=r.count();
	  flg|=(d2-c2+1)==k;
	}
	if(~c2){
	  BS r=rs[A]^~rs[B];
	  r>>=c2;
	  int k=r.count();
	  r>>=(d2-c2+1);
	  k-=r.count();
	  flg|=(d2-c2+1)==k;
	}
	if(!flg){
	  puts("No");
	  return;
	}
      }
      
      {
	int flg=0;
	if(~a1){
	  BS r=cs[C]^cs[D];
	  r>>=a1;
	  int k=r.count();
	  r>>=(b1-a1+1);
	  k-=r.count();
	  flg|=(b1-a1+1)==k;
	}
	if(~a1){
	  BS r=cs[C]^~cs[D];
	  r>>=a1;
	  int k=r.count();
	  r>>=(b1-a1+1);
	  k-=r.count();
	  flg|=(b1-a1+1)==k;
	}
	if(~a2){
	  BS r=cs[C]^cs[D];
	  r>>=a2;
	  int k=r.count();
	  r>>=(b2-a2+1);
	  k-=r.count();
	  flg|=(b2-a2+1)==k;
	}
	if(~a2){
	  BS r=cs[C]^~cs[D];
	  r>>=a2;
	  int k=r.count();
	  r>>=(b2-a2+1);
	  k-=r.count();
	  flg|=(b2-a2+1)==k;
	}
	if(!flg){
	  puts("No");
	  return;
	}
      }
      
      puts("Yes");
    };

  auto calc=
    [&](){
      if(mrs.size()>2u||mcs.size()>2u){
	puts("No");
	return;
      }
      if(mrs.size()==1u||mcs.size()==1u){
	puts("Yes");
	return;
      }

      if(mrs.size()==2u||mcs.size()==2u){
	check();
	return;
      }
      puts("No");
    };
  
  calc();

  for(int i=1;i<q;i++){
    int r,c;
    scanf("%d %d",&r,&c);
    r--;c--;
    
    mrs[vrs[r]].erase(r);
    if(mrs[vrs[r]].empty()) mrs.erase(vrs[r]);
    mcs[vcs[c]].erase(c);
    if(mcs[vcs[c]].empty()) mcs.erase(vcs[c]);

    if(rs[r][0]) vrs[r]=ph.sub(ri,vrs[r]);
    if(cs[c][0]) vcs[c]=ph.sub(ci,vcs[c]);
    
    if(rs[r][c]){
      vrs[r]=ph.sub(vrs[r],ph.term(c,1));
      vcs[c]=ph.sub(vcs[c],ph.term(r,1));
    }else{
      vrs[r]=ph.add(vrs[r],ph.term(c,1));
      vcs[c]=ph.add(vcs[c],ph.term(r,1));
    }
    
    rs[r][c].flip();
    cs[c][r].flip();
    
    if(rs[r][0]) vrs[r]=ph.sub(ri,vrs[r]);
    if(cs[c][0]) vcs[c]=ph.sub(ci,vcs[c]);
        
    mrs[vrs[r]].emplace(r);
    mcs[vcs[c]].emplace(c);

    calc();
  }
  
  return 0;
}

signed ARC099_F(){
  int n;
  string s;
  cin>>n>>s;
}

//INSERT ABOVE HERE
signed main(){
  CODEFLYER2018_F();
  return 0;
}
