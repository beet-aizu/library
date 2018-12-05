#include<bits/stdc++.h>
using namespace std;
using Int = long long;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
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

  template<typename T>
  vector<Int> multiply(const vector<T> &a,const vector<T> &b){
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

struct bigint {  
  using ll = long long; 
  using vll = vector<ll>;
  
  constexpr static ll base = 1000000000;
  constexpr static ll base_digits = 9;

  vll a;
  ll sign;

  bigint():sign(1){}

  bigint(ll v){*this=v;}

  bigint(const string &s){read(s);}

  void operator=(const bigint &v){
    sign=v.sign;
    a=v.a;
  }

  void operator=(ll v){
    sign=1;
    if(v<0) sign=-1,v=-v;
    for(;v>0;v=v/base) a.push_back(v%base);
  }

  bigint operator+(const bigint &v) const{
    if(sign==v.sign){
      bigint res=v;

      for(ll i=0,carry=0;i<(ll)max(a.size(),v.a.size())||carry;++i){
        if(i==(ll)res.a.size()) res.a.push_back(0);
        res.a[i]+=carry+(i<(ll)a.size()?a[i]:0);
        carry=res.a[i]>=base;
        if(carry) res.a[i]-=base;
      }
      return res;
    }
    return *this -(-v);
  }

  bigint operator-(const bigint &v) const{
    if(sign==v.sign){
      if(abs()>=v.abs()){
        bigint res=*this;
        for(ll i=0,carry=0;i<(ll)v.a.size()||carry;++i){
          res.a[i]-=carry+(i<(ll)v.a.size()?v.a[i]:0);
          carry=res.a[i]<0;
          if(carry) res.a[i]+=base;
        }
        res.trim();
        return res;
      }
      return -(v-*this);
    }
    return *this+(-v);
  }

  void operator*=(ll v){
    if(v<0) sign=-sign,v=-v;
    for(ll i=0,carry=0;i<(ll)a.size()|| carry;++i){
      if(i ==(ll)a.size()) a.push_back(0);
      ll cur=a[i] *(ll)v+carry;
      carry=(ll)(cur/base);
      a[i]=(ll)(cur%base);
      // asm("divl %%ecx" : "=a"(carry),"=d"(a[i]) : "A"(cur),"c"(base));
    }
    trim();
  }

  bigint operator*(ll v) const{
    bigint res=*this;
    res *=v;
    return res;
  }

  friend pair<bigint,bigint> divmod(const bigint &a1,const bigint &b1){
    ll norm=base/(b1.a.back()+1);   
    bigint a=a1.abs()*norm;
    bigint b=b1.abs()*norm;
    bigint q,r;
    q.a.resize(a.a.size());

    for(ll i=a.a.size()-1;i>=0;i--){
      r *=base;
      r+=a.a[i];
      ll s1=r.a.size()<=b.a.size() ? 0 : r.a[b.a.size()];
      ll s2=r.a.size()<=b.a.size()-1 ? 0 : r.a[b.a.size()-1];
      ll d=((ll)base*s1+s2)/b.a.back();
      r-=b*d;
      while(r<0) r+=b,--d;
      q.a[i]=d;
    }

    q.sign=a1.sign*b1.sign;
    r.sign=a1.sign;
    q.trim();
    r.trim();
    return make_pair(q,r/norm);
  }

  bigint operator/(const bigint &v) const{
    return divmod(*this,v).first;
  }

  bigint operator%(const bigint &v) const{
    return divmod(*this,v).second;
  }

  void operator/=(ll v){
    if(v<0) sign=-sign,v=-v;
    for(ll i=(ll)a.size()-1,rem=0;i>=0;--i){
      ll cur=a[i]+rem *(ll)base;
      a[i]=(ll)(cur/v);
      rem=(ll)(cur%v);
    }
    trim();
  }

  bigint operator/(ll v) const{
    bigint res=*this;
    res/=v;
    return res;
  }

  ll operator%(ll v) const{
    if(v<0) v=-v;
    ll m=0;
    for(ll i=a.size()-1;i>=0;--i) m=(a[i]+m *(ll)base)%v;
    return m*sign;
  }

  void operator+=(const bigint &v){
    *this=*this+v;
  }

  void operator-=(const bigint &v){
    *this=*this-v;
  }

  void operator*=(const bigint &v){
    *this=*this*v;
  }

  void operator/=(const bigint &v){
    *this=*this/v;
  }

  bool operator<(const bigint &v) const{
    if(sign!=v.sign) return sign<v.sign;
    if(a.size()!=v.a.size()) return a.size()*sign<v.a.size()*v.sign;
    for(ll i=a.size()-1;i>=0;i--)
      if(a[i]!=v.a[i]) return a[i]*sign<v.a[i]*sign;
    return false;
  }

  bool operator>(const bigint &v) const{
    return v<*this;
  }

  bool operator<=(const bigint &v) const{
    return !(v<*this);
  }

  bool operator>=(const bigint &v) const{
    return !(*this<v);
  }

  bool operator==(const bigint &v) const{
    return !(*this<v)&&!(v<*this);
  }

  bool operator!=(const bigint &v) const{
    return *this<v|| v<*this;
  }

  void trim(){
    while(!a.empty()&&!a.back()) a.pop_back();
    if(a.empty()) sign=1;
  }

  bool isZero() const{
    return a.empty()||(a.size()==1&&!a[0]);
  }

  bigint operator-() const{
    bigint res=*this;
    res.sign=-sign;
    return res;
  }

  bigint abs() const{
    bigint res=*this;
    res.sign*=res.sign;
    return res;
  }

  ll longValue() const{
    ll res=0;
    for(ll i=a.size()-1;i>=0;i--) res=res*base+a[i];
    return res*sign;
  }

  friend bigint gcd(const bigint &a,const bigint &b){
    return b.isZero() ? a : gcd(b,a%b);
  }

  friend bigint lcm(const bigint &a,const bigint &b){
    return a/gcd(a,b)*b;
  }

  void read(const string &s){
    sign=1;
    a.clear();
    ll pos=0;
    while(pos<(ll)s.size()&&(s[pos]=='-'|| s[pos]=='+')){
      if(s[pos]=='-') sign=-sign;
      ++pos;
    }
    for(ll i=s.size()-1;i>=pos;i-=base_digits){
      ll x=0;
      for(ll j=max(pos,i-base_digits+1);j<=i;j++) x=x*10+s[j]-'0';
      a.push_back(x);
    }
    trim();
  }

  friend istream &operator>>(istream &stream,bigint &v){
    string s;
    stream>>s;
    v.read(s);
    return stream;
  }

  friend ostream &operator<<(ostream &stream,const bigint &v){
    if(v.sign==-1) stream<<'-';
    stream<<(v.a.empty()?0:v.a.back());
    for(ll i=(ll)v.a.size()-2;i>=0;--i)
      stream<<setw(base_digits)<<setfill('0')<<v.a[i];
    return stream;
  }

  static vll convert_base(const vll &a,ll old_digits,ll new_digits){
    vll p(max(old_digits,new_digits)+1);
    p[0]=1;
    for(ll i=1;i<(ll)p.size();i++) p[i]=p[i-1]*10;
    vll res;
    ll cur=0;
    ll cur_digits=0;
    for(ll i=0;i<(ll)a.size();i++){
      cur+=a[i]*p[cur_digits];
      cur_digits+=old_digits;
      while(cur_digits>=new_digits){
        res.push_back(signed(cur%p[new_digits]));
        cur/=p[new_digits];
        cur_digits-=new_digits;
      }
    }
    res.push_back((signed)cur);
    while(!res.empty()&&!res.back()) res.pop_back();
    return res;
  }
  
  static vll karatsubaMultiply(const vll &a,const vll &b){
    ll n=a.size();
    vll res(n+n);
    if(n<=32){
      for(ll i=0;i<n;i++)
        for(ll j=0;j<n;j++)
          res[i+j]+=a[i]*b[j];
      return res;
    }

    ll k=n>>1;
    vll a1(a.begin(),a.begin()+k);
    vll a2(a.begin()+k,a.end());
    vll b1(b.begin(),b.begin()+k);
    vll b2(b.begin()+k,b.end());

    vll a1b1=karatsubaMultiply(a1,b1);
    vll a2b2=karatsubaMultiply(a2,b2);

    for(ll i=0;i<k;i++) a2[i]+=a1[i];
    for(ll i=0;i<k;i++) b2[i]+=b1[i];

    vll r=karatsubaMultiply(a2,b2);
    for(ll i=0;i<(ll)a1b1.size();i++) r[i]-=a1b1[i];
    for(ll i=0;i<(ll)a2b2.size();i++) r[i]-=a2b2[i];

    for(ll i=0;i<(ll)r.size();i++) res[i+k]+=r[i];
    for(ll i=0;i<(ll)a1b1.size();i++) res[i]+=a1b1[i];
    for(ll i=0;i<(ll)a2b2.size();i++) res[i+n]+=a2b2[i];
    return res;
  }
  
  bigint operator*(const bigint &v) const{
    constexpr static ll nbase = 10000;
    constexpr static ll nbase_digits = 4;
    
    vll a=convert_base(this->a,base_digits,nbase_digits);
    vll b=convert_base(v.a,base_digits,nbase_digits);

    /*
      while(a.size()<b.size()) a.push_back(0);
      while(b.size()<a.size()) b.push_back(0);
      while(a.size() &(a.size()-1)) a.push_back(0),b.push_back(0);
      vll c=karatsubaMultiply(a,b);
    */    

    if(a.empty()) a.push_back(0);
    if(b.empty()) b.push_back(0);    
    vll c=FFT::multiply(a,b);
    bigint res;
    res.sign=sign*v.sign;
    for(ll i=0,carry=0;i<(ll)c.size();i++){
      ll cur=c[i]+carry;
      res.a.push_back((ll)(cur%nbase));
      carry=(ll)(cur/nbase);
      if(i+1==(int)c.size()&&carry>0) c.push_back(0);
    }
    
    res.a=convert_base(res.a,nbase_digits,base_digits);
    res.trim();
    return res;
  }
};
//END CUT HERE

template<typename T> 
struct BIT{
  int n;
  vector<T> bit;
  //1-indexed
  BIT():n(-1){}
  BIT(int n_,T d):n(n_),bit(n_+1,d){}
  
  T sum(int i){
    T s=bit[0];
    for(int x=i;x>0;x-=(x&-x))
      s+=bit[x];
    return s;
  }
  void add(int i,T a){
    if(i==0) return;
    for(int x=i;x<=n;x+=(x&-x))
      bit[x]+=a;
  }
};

//INSERT ABOVE HERE
const int MAX = 1e5+100;
Int dp[MAX];
pair<bigint, bigint> dfs(int l,int r){
  if(l+1>=r) return make_pair(bigint(dp[l]),bigint(l+1));
  int m=(l+r)>>1;
  auto v=dfs(l,m);
  auto t=dfs(m,r);
  t.first*=v.second;
  t.first+=v.first;
  t.second*=v.second;
  return t;
}
signed main(){
  int n;
  cin>>n;
  vector<int> p(n);
  for(int i=0;i<n;i++) cin>>p[i];  
  BIT<Int> bit(n+1,0);
  for(int i=0;i<n;i++) bit.add(p[i],1);
  for(int i=0;i<n;i++){
    dp[n-(i+1)]=bit.sum(p[i]-1);
    bit.add(p[i],-1);
  }
  cout<<bigint(dfs(0,n).first+1)<<endl;
  return 0;
}
