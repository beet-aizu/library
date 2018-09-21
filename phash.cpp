#include<bits/stdc++.h>
using namespace std;
using Int = long long;
//BEGIN CUT HERE
template<typename T, T... Ts> struct PACK{};
template<typename T> struct PHash{};

template<typename T, T... MODS>
struct PHash<PACK<T, MODS...> >{
  using type = T;
  static constexpr T BASE = 1777771;
  static constexpr size_t N = sizeof...(MODS);
  
  valarray<T> val;
  
  PHash(valarray<T> tmp):val(N){
    int k=0;
    for(const auto &e:{MODS...})
      val[k]=(tmp[k]%e+e)%e,k++;
  }
  
  PHash(T a=0):val(N){
    int k=0;
    for(const auto &e:{MODS...}) val[k]=(a%e+e)%e,k++;
  }

  T pow(T a,T n,const T MOD){
    T res=1;
    while(n){
      if(n&1) res=1LL*res*a%MOD;
      a=1LL*a*a%MOD;
      n>>=1;
    }
    return res;
  }
  
  PHash inv(){
    valarray<T> res(N);
    int k=0;
    for(const auto &e:{MODS...}) res[k]=pow(val[k],e-2,e),k++;
    return PHash(res);
  }
  
  PHash operator+(PHash a){return PHash(val+a.val);}
  PHash operator-(PHash a){return PHash(val-a.val);}
  PHash operator*(PHash a){return PHash(val*a.val);}
  PHash operator/(PHash a){return PHash(val*a.inv().val);}

  PHash& operator=(PHash a){val=a.val;return *this;};
  
  //PHash operator<<(size_t k){return PHash(val*po[k]);}
  //PHash operator>>(size_t k){return PHash(val*op[k]);}
  //PHash mv(int k){return k<0?PHash(val)>>(-k):PHash(val)<<k;}
  
  bool operator==(PHash a)const{
    for(size_t k=0;k<N;k++) if(val[k]!=a.val[k]) return false;
    return true;
  }
  
  bool operator!=(PHash a)const{
    for(size_t k=0;k<N;k++) if(val[k]!=a.val[k]) return true;
    return false;
  }

  bool operator<(PHash a)const{
    for(size_t k=0;k<N;k++) if(val[k]!=a.val[k]) return val[k]<a.val[k];
    return false;
  }
  
  void print(){
    int k=0;
    for(const auto &e:{MODS...}) cout<<val[k++]%e<<endl;
  }
};
//END CUT HERE

//INSERT ABOVE HERE
signed JAG2018_SUMMER_DAY2_F(){
  static constexpr Int MOD1 = 1e9+7;
  static constexpr Int MOD2 = 1e9+9;
  static constexpr Int MOD3 = 1e8+7;
  using V = PHash<PACK<Int, MOD1, MOD2, MOD3> >;

  struct Point{
    V x,y;
    Point(){}
    Point(Int x,Int y):x(x),y(y){}
    Point(V x,V y):x(x),y(y){}
    Point operator+(const Point a){return Point(x+a.x,y+a.y);}
    Point operator-(const Point a){return Point(x-a.x,y-a.y);}
  };

  auto getP=[&](){int x,y;cin>>x>>y;return Point(x,y);};
  Int n;
  cin>>n;
  
  vector<Point> a(n),b(n),c(n),d(n);
  d[0]=getP();
  for(Int i=0;i<n;i++){
    a[i]=getP();
    b[i]=getP();
    c[i]=getP();
  }

  for(Int i=0;i<n;i++){
    if(c[i].x==d[i].x&&c[i].y==d[i].y){
      cout<<i<<endl;
      return 0;
    }
    
    if(a[i].x==b[i].x&&c[i].x==d[i].x){
      cout<<i<<endl;
      return 0;
    }

    if(a[i].x==b[i].x){
      V nx=a[i].x;
      V ny=c[i].y+((nx-c[i].x)/(d[i].x-c[i].x))*(d[i].y-c[i].y);
      d[i+1]=Point(nx,ny);
      continue;
    }

    if(c[i].x==d[i].x){
      V nx=c[i].x;
      V ny=a[i].y+((nx-a[i].x)/(b[i].x-a[i].x))*(b[i].y-a[i].y);
      d[i+1]=Point(nx,ny);
      continue;	 
    }

    
    V al=(b[i].y-a[i].y)/(b[i].x-a[i].x);
    V bt=(d[i].y-c[i].y)/(d[i].x-c[i].x);

    if(al==bt){
      cout<<i<<endl;
      return 0;
    }
    
    V nx=((al*a[i].x)-(bt*c[i].x)-a[i].y+c[i].y)/(al-bt);
    V ny=(al*nx)-(al*a[i].x)+a[i].y;

    d[i+1]=Point(nx,ny);
  }
  cout<<n<<endl;
  
  return 0;
}

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
  

  static constexpr Int MOD1 = 1e9+7;
  static constexpr Int MOD2 = 1e9+9;
  static constexpr Int MOD3 = 1e8+7;
  using T = PHash<PACK<Int, MOD1, MOD2, MOD3> >;
  
  vector<valarray<Int> > po,op;
  auto init=
    [&](int n){
      po.assign(n+1,valarray<T::type>(T::N));
      op.assign(n+1,valarray<T::type>(T::N));
      po[0]=op[0]=T(1).val;
      for(int i=0;i<n;i++) po[i+1]=T(po[i]*T::BASE).val;
      for(int i=0;i<n;i++) op[i+1]=T(op[i]*T(T::BASE).inv().val).val;
    };
  auto term=[&](T::type a,size_t k){return T(po[k]*a);};
  
  init(MAX);
  vector<T> vrs(h),vcs(w);

  auto build=
    [&](vector<int> v)->T{
      int n=v.size();
      T r(0);
      for(int i=0;i<n;i++) r=r+term(v[i],i);
      return r;
    };
  vector<int> tmp;
  tmp.assign(w,1);
  T ri=build(tmp);
  tmp.assign(h,1);
  T ci=build(tmp);
  
  for(int i=0;i<h;i++){
    auto v=conv(rs[i],w);
    vrs[i]=build(v);
    if(rs[i][0]) vrs[i]=ri-vrs[i];
  }

  for(int j=0;j<w;j++){
    auto v=conv(cs[j],h);
    vcs[j]=build(v);
    if(cs[j][0]) vcs[j]=ci-vcs[j];
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

    if(rs[r][0]) vrs[r]=(ri-vrs[r]);
    if(cs[c][0]) vcs[c]=(ci-vcs[c]);
    
    if(rs[r][c]){
      vrs[r]=(vrs[r]-term(1,c));
      vcs[c]=(vcs[c]-term(1,r));
    }else{
      vrs[r]=(vrs[r]+term(1,c));
      vcs[c]=(vcs[c]+term(1,r));
    }
    
    rs[r][c].flip();
    cs[c][r].flip();
    
    if(rs[r][0]) vrs[r]=(ri-vrs[r]);
    if(cs[c][0]) vcs[c]=(ci-vcs[c]);
        
    mrs[vrs[r]].emplace(r);
    mcs[vcs[c]].emplace(c);

    calc();
  }
  
  return 0;
}

signed main(){
  //JAG2018_SUMMER_DAY2_F();
  CODEFLYER2018_F();
  return 0;
}
