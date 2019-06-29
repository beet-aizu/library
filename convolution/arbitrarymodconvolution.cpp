#include<bits/stdc++.h>
using namespace std;
using Int = long long;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
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
};

struct ArbitraryModConvolution{
  using ll = long long;
  static NTT<0> ntt0;
  static NTT<1> ntt1;
  static NTT<2> ntt2;

  static constexpr int pow(int a,int b,int md){
    int res=1;
    a=a%md;
    while(b){
      if(b&1) res=(ll)res*a%md;
      a=(ll)a*a%md;
      b>>=1;
    }
    return res;
  }

  static constexpr int inv(int x,int md){
    return pow(x,md-2,md);
  }

  inline void garner(vector< vector<int> > &cs,int MOD){
    static constexpr int r01=inv(ntt0.md,ntt1.md);
    static constexpr int r02=inv(ntt0.md,ntt2.md);
    static constexpr int r12=inv(ntt1.md,ntt2.md);

    int m01 =(ll)ntt0.md*ntt1.md%MOD;
    size_t sz=cs[0].size();
    for(size_t i=0;i<sz;i++){
      cs[1][i]=(ll)(cs[1][i]-cs[0][i])*r01%ntt1.md;
      if(cs[1][i]<0) cs[1][i]+=ntt1.md;

      cs[2][i]=(ll)(cs[2][i]-cs[0][i])*r02%ntt2.md;
      cs[2][i]=(ll)(cs[2][i]-cs[1][i])*r12%ntt2.md;
      if(cs[2][i]<0) cs[2][i]+=ntt2.md;

      cs[0][i]+=(ll)cs[1][i]*ntt0.md%MOD;
      if(cs[0][i]>=MOD) cs[0][i]-=MOD;
      cs[0][i]+=(ll)cs[2][i]*m01%MOD;
      if(cs[0][i]>=MOD) cs[0][i]-=MOD;
    }
  }

  inline int add(int a,int b,int MOD){
    a+=b;
    if(a>=MOD) a-=MOD;
    return a;
  }

  vector<int> add(vector<int> as,vector<int> bs,int MOD){
    int sz=max(as.size(),bs.size());
    vector<int> cs(sz,0);
    for(int i=0;i<(int)as.size();i++) cs[i]=add(cs[i],as[i],MOD);
    for(int i=0;i<(int)bs.size();i++) cs[i]=add(cs[i],bs[i],MOD);
    return cs;
  }

  vector<int> sub(vector<int> as,vector<int> bs,int MOD){
    int sz=max(as.size(),bs.size());
    vector<int> cs(sz,0);
    for(int i=0;i<(int)as.size();i++) cs[i]=add(cs[i],as[i],MOD);
    for(int i=0;i<(int)bs.size();i++) cs[i]=add(cs[i],MOD-bs[i],MOD);
    return cs;
  }

  vector<int> multiply(vector<int> as,vector<int> bs,int MOD){
    for(int& x:as) x%=MOD;
    for(int& x:bs) x%=MOD;
    vector< vector<int> > cs(3);
    cs[0]=ntt0.multiply(as,bs);
    cs[1]=ntt1.multiply(as,bs);
    cs[2]=ntt2.multiply(as,bs);
    size_t sz=as.size()+bs.size()-1;
    for(auto& v:cs) v.resize(sz);
    garner(cs,MOD);
    return cs[0];
  }

  vector<int> divide(vector<int> as,vector<int> bs,int MOD){
    assert(bs!=vector<int>(bs.size(),0));
    if(as==vector<int>(as.size(),0)) return {0};
    assert(as.size()>=bs.size());

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

    int need=as.size()-bs.size()+1;
    as.resize(need);

    int sz=1;
    vector<int> rs({inv(bs[0],MOD)});
    while(sz<need){
      sz<<=1;
      vector<int> ts(min(sz,(int)bs.size()));
      for(int i=0;i<(int)ts.size();i++) ts[i]=bs[i];
      rs=sub(add(rs,rs,MOD),multiply(multiply(rs,rs,MOD),ts,MOD),MOD);
      rs.resize(sz);
    }

    while(as.back()==0) as.pop_back();
    while(rs.back()==0) rs.pop_back();
    auto cs=multiply(as,rs,MOD);
    cs.resize(need,0);
    return cs;
  }
};
NTT<0> ArbitraryModConvolution::ntt0;
NTT<1> ArbitraryModConvolution::ntt1;
NTT<2> ArbitraryModConvolution::ntt2;
//END CUT HERE

template<typename T,T MOD = 1000000007>
struct Mint{
  T v;
  Mint():v(0){}
  Mint(signed v):v(v){}
  Mint(long long t){v=t%MOD;if(v<0) v+=MOD;}

  Mint pow(long long k){
    Mint res(1),tmp(v);
    while(k){
      if(k&1) res*=tmp;
      tmp*=tmp;
      k>>=1;
    }
    return res;
  }

  static Mint add_identity(){return Mint(0);}
  static Mint mul_identity(){return Mint(1);}

  Mint inv(){return pow(MOD-2);}

  Mint& operator+=(Mint a){v+=a.v;if(v>=MOD)v-=MOD;return *this;}
  Mint& operator-=(Mint a){v+=MOD-a.v;if(v>=MOD)v-=MOD;return *this;}
  Mint& operator*=(Mint a){v=1LL*v*a.v%MOD;return *this;}
  Mint& operator/=(Mint a){return (*this)*=a.inv();}

  Mint operator+(Mint a) const{return Mint(v)+=a;};
  Mint operator-(Mint a) const{return Mint(v)-=a;};
  Mint operator*(Mint a) const{return Mint(v)*=a;};
  Mint operator/(Mint a) const{return Mint(v)/=a;};

  Mint operator-() const{return v?Mint(MOD-v):Mint(v);}

  bool operator==(const Mint a)const{return v==a.v;}
  bool operator!=(const Mint a)const{return v!=a.v;}
  bool operator <(const Mint a)const{return v <a.v;}

  static vector<Mint> fact,finv,invs;

  static void init(int n){
    int m=fact.size();
    if(n<m) return;

    fact.resize(n+1,1);
    finv.resize(n+1,1);
    invs.resize(n+1,1);

    if(m==0) m=1;
    for(int i=m;i<=n;i++) fact[i]=fact[i-1]*Mint(i);
    finv[n]=Mint(1)/fact[n];
    for(int i=n;i>=m;i--) finv[i-1]=finv[i]*Mint(i);
    for(int i=m;i<=n;i++) invs[i]=finv[i]*fact[i-1];
  }

  static Mint C(int n,int k){
    if(n<k||k<0) return Mint(0);
    init(n);
    return fact[n]*finv[n-k]*finv[k];
  }

  static Mint H(int n,int k){
    if(n<0||k<0) return Mint(0);
    if(!n&&!k) return Mint(1);
    init(n+k-1);
    return C(n+k-1,k);
  }
};
template<typename T,T MOD>
vector<Mint<T, MOD> > Mint<T, MOD>::fact = vector<Mint<T, MOD> >();
template<typename T,T MOD>
vector<Mint<T, MOD> > Mint<T, MOD>::finv = vector<Mint<T, MOD> >();
template<typename T,T MOD>
vector<Mint<T, MOD> > Mint<T, MOD>::invs = vector<Mint<T, MOD> >();

//INSERT ABOVE HERE
signed  YUKI_829(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  using ll = long long;
  int n,b;
  cin>>n>>b;
  vector<int> s(n);
  for(Int i=0;i<n;i++) cin>>s[i];
  using M = Mint<int>;
  M::init(3e5);

  vector<int> cnt(n,0);
  for(int i=0;i<n;i++) cnt[s[i]]++;

  using P = pair<int, vector<int> > ;
  priority_queue<P> pq;
  pq.emplace(-1,vector<int>(1,1));

  int sum=0;
  for(int i=n-1;i>=0;i--){
    if(cnt[i]==0) continue;
    M x=M::H(sum,cnt[i]);
    M y=M::H(sum+1,cnt[i])-x;
    x*=M::fact[cnt[i]];
    y*=M::fact[cnt[i]];

    pq.emplace(-2,vector<int>({x.v,y.v}));
    sum+=cnt[i];
  }

  const int MOD = 1e9+7;
  ArbitraryModConvolution arb;
  while(pq.size()>1u){
    auto a=pq.top().second;pq.pop();
    auto b=pq.top().second;pq.pop();
    auto c=arb.multiply(a,b,MOD);
    pq.emplace(-(int)c.size(),c);
  }

  auto dp=pq.top().second;
  M ans(0),res(1);
  for(int j=0;j<(int)dp.size();j++){
    ans+=M((ll)j*(ll)dp[j])*res;
    res*=M(b);
  }
  cout<<ans.v<<endl;
  return 0;
}
/*
  verified on 2019/06/29
  https://yukicoder.me/problems/no/829
*/

signed YUKI_3046(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int k,n;
  cin>>k>>n;
  vector<int> xs(n);
  for(int i=0;i<n;i++) cin>>xs[i];
  const int MOD = 1e9+7;
  ArbitraryModConvolution arb;
  vector<int> as((1<<17)+k),bs(1<<17);
  as[0]=bs[0]=1;
  for(int x:xs) bs[x]=MOD-1;
  cout<<arb.divide(as,bs,MOD)[k]<<endl;
  return 0;
}
/*
  verified on 2019/06/29
  https://yukicoder.me/problems/no/3046
*/
signed main(){
  //YUKI_829();
  //YUKI_3046();
  return 0;
}
