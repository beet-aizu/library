#include<bits/stdc++.h>
using namespace std;
using Int = long long;
//BEGIN CUT HERE
template<typename T,T MOD = 1000000007>
struct Mint{
  T v;
  Mint():v(0){}
  Mint(signed v):v(v){}
  Mint(long long t){v=t%MOD;if(v<0) v+=MOD;}

  Mint pow(int k){
    Mint res(1),tmp(v);
    while(k){
      if(k&1) res*=tmp;
      tmp*=tmp;
      k>>=1;
    }
    return res;
  }
  
  Mint inv(){return pow(MOD-2);}
  
  Mint& operator+=(Mint a){v+=a.v;if(v>=MOD)v-=MOD;return *this;}
  Mint& operator-=(Mint a){v+=MOD-a.v;if(v>=MOD)v-=MOD;return *this;}
  Mint& operator*=(Mint a){v=1LL*v*a.v%MOD;return *this;}
  Mint& operator/=(Mint a){return (*this)*=a.inv();}
  
  Mint operator+(Mint a){return Mint(v)+=a;};
  Mint operator-(Mint a){return Mint(v)-=a;};
  Mint operator*(Mint a){return Mint(v)*=a;};
  Mint operator/(Mint a){return Mint(v)/=a;};

  Mint operator-(){return v?MOD-v:v;}

  bool operator==(const Mint a)const{return v==a.v;}
  bool operator!=(const Mint a)const{return v!=a.v;}
  
  bool operator<(const Mint a)const{return v<a.v;}

  static vector<Mint> po,op;
  
  static void init(size_t n, T BASE){
    if(n+1<=po.size()) return;
    po.assign(n+1,1);
    op.assign(n+1,1);
    
    Mint x(BASE);
    Mint y=Mint(1)/x;
    for(int i=1;i<=(int)n;i++) po[i]=po[i-1]*x;
    for(int i=1;i<=(int)n;i++) op[i]=op[i-1]*y;
  }
};
template<typename T,T MOD>
vector<Mint<T, MOD> > Mint<T, MOD>::po = vector<Mint<T, MOD> >();
template<typename T,T MOD>
vector<Mint<T, MOD> > Mint<T, MOD>::op = vector<Mint<T, MOD> >();

template<typename T,typename M1,typename M2,typename M3>
struct PolynomialHash{
  using V = tuple<M1, M2, M3>;
  static const T BASE = 1777771;
  
  PolynomialHash(size_t n){
    M1::init(n, BASE);
    M2::init(n, BASE);
    M3::init(n, BASE);
  }

  V build(const vector<T> &v){
    int n=v.size();
    M1 r1;M2 r2;M3 r3;
    for(int i=0;i<n;i++){
      r1+=M1(v[i])*M1::po[i];
      r2+=M2(v[i])*M2::po[i];
      r3+=M3(v[i])*M3::po[i];
    }
    return V(r1,r2,r3);
  }

  V add(const V &a,const V &b){
    M1 a1=get<0>(a),b1=get<0>(b);
    M2 a2=get<1>(a),b2=get<1>(b);
    M3 a3=get<2>(a),b3=get<2>(b);
    return V(a1+b1,a2+b2,a3+b3);
  }
  
  V sub(const V &a,const V &b){
    M1 a1=get<0>(a),b1=get<0>(b);
    M2 a2=get<1>(a),b2=get<1>(b);
    M3 a3=get<2>(a),b3=get<2>(b);
    return V(a1-b1,a2-b2,a3-b3);
  }
  
  V mul(const V &a,const V &b){
    M1 a1=get<0>(a),b1=get<0>(b);
    M2 a2=get<1>(a),b2=get<1>(b);
    M3 a3=get<2>(a),b3=get<2>(b);
    return V(a1*b1,a2*b2,a3*b3);
  }
  
  V inv(const V &a){
    M1 a1;M2 a2;M3 a3;
    tie(a1,a2,a3)=a;
    return V(a1.inv(),a2.inv(),a3.inv());
  }

  V term(size_t x,T k){
    M1 a1=M1::po[x]*M1((long long)k);
    M2 a2=M2::po[x]*M2((long long)k);
    M3 a3=M3::po[x]*M3((long long)k);
    return V(a1,a2,a3);
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

  using M1 = Mint<int, int(1e9+7)>;
  using M2 = Mint<int, int(1e9+9)>;
  using M3 = Mint<int, int(1e8+7)>;
  
  PolynomialHash<int, M1, M2, M3> ph(MAX);
  using V = decltype(ph)::V;
  
  vector<V> vrs(h),vcs(w);
  vector<int> tmp(w,1);
  V ri=ph.build(tmp);
  tmp.assign(h,1);
  V ci=ph.build(tmp);
  
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
  
  map<V, set<int> > mrs, mcs;
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

//INSERT ABOVE HERE
signed main(){
  CODEFLYER2018_F();
  return 0;
}
