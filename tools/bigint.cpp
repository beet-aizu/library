#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../convolution/fastfouriertransform.cpp"
#undef call_from_test

#endif
//BEGIN CUT HERE
struct bigint {
  using ll = long long;
  using vll = vector<ll>;

  inline static constexpr ll base_digits = 9;
  inline static constexpr ll base = 1000000000;

  vll a;
  ll sign;

  bigint():sign(1){}

  bigint(ll v){*this=v;}

  bigint(const string &s){read(s);}

  static bigint add_identity(){return bigint(0);}
  static bigint mul_identity(){return bigint(1);}

  void operator=(ll v){
    sign=1;
    if(v<0) sign=-1,v=-v;
    for(;v>0;v=v/base) a.emplace_back(v%base);
  }

  bigint operator+(const bigint &v) const{
    if(sign==v.sign){
      bigint res=v;
      for(ll i=0,carry=0;i<(ll)max(a.size(),v.a.size()) or carry;++i){
        if(i==(ll)res.a.size()) res.a.emplace_back(0);
        res.a[i]+=carry+(i<(ll)a.size()?a[i]:0);
        carry=res.a[i]>=base;
        if(carry) res.a[i]-=base;
      }
      return res;
    }
    return *this-(-v);
  }

  bigint operator-(const bigint &v) const{
    if(sign==v.sign){
      if(abs()>=v.abs()){
        bigint res=*this;
        for(ll i=0,carry=0;i<(ll)v.a.size() or carry;++i){
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
    for(ll i=0,carry=0;i<(ll)a.size() or  carry;++i){
      if(i ==(ll)a.size()) a.emplace_back(0);
      ll cur=a[i] *(ll)v+carry;
      carry=(ll)(cur/base);
      a[i]=(ll)(cur%base);
      // asm("divl %%ecx" : "=a"(carry),"=d"(a[i]) : "A"(cur),"c"(base));
    }
    trim();
  }

  bigint operator*(ll v) const{
    bigint res=*this;
    res*=v;
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
    for(ll i=a.size()-1;i>=0;--i) m=(a[i]+m*(ll)base)%v;
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
    return !(*this<v) and !(v<*this);
  }

  bool operator!=(const bigint &v) const{
    return *this<v or v<*this;
  }

  void trim(){
    while(!a.empty() and !a.back()) a.pop_back();
    if(a.empty()) sign=1;
  }

  bool isZero() const{
    return a.empty() or (a.size()==1 and !a[0]);
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
    return b.isZero()?a:gcd(b,a%b);
  }

  friend bigint lcm(const bigint &a,const bigint &b){
    return a/gcd(a,b)*b;
  }

  void read(const string &s){
    sign=1;
    a.clear();
    ll pos=0;
    while(pos<(ll)s.size() and (s[pos]=='-' or s[pos]=='+')){
      if(s[pos]=='-') sign=-sign;
      ++pos;
    }
    for(ll i=s.size()-1;i>=pos;i-=base_digits){
      ll x=0;
      for(ll j=max(pos,i-base_digits+1);j<=i;j++) x=x*10+s[j]-'0';
      a.emplace_back(x);
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
        res.emplace_back(signed(cur%p[new_digits]));
        cur/=p[new_digits];
        cur_digits-=new_digits;
      }
    }
    res.emplace_back((signed)cur);
    while(!res.empty() and !res.back()) res.pop_back();
    return res;
  }

  static vll karatsubaMultiply(vll &a,vll &b){
    {
      while(a.size()<b.size()) a.emplace_back(0);
      while(b.size()<a.size()) b.emplace_back(0);
      while(a.size()&(a.size()-1)) a.emplace_back(0),b.emplace_back(0);
    }

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

    if(a.empty() or b.empty()) return bigint(0);

    vll c=karatsubaMultiply(a,b);
    // vll c=FFT::multiply(a,b);

    bigint res;
    res.sign=sign*v.sign;
    for(ll i=0,carry=0;i<(ll)c.size();i++){
      ll cur=c[i]+carry;
      res.a.emplace_back((ll)(cur%nbase));
      carry=(ll)(cur/nbase);
      if(i+1==(int)c.size() and carry>0) c.emplace_back(0);
    }

    res.a=convert_base(res.a,nbase_digits,base_digits);
    res.trim();
    return res;
  }
};
//END CUT HERE
#ifndef call_from_test
//INSERT ABOVE HERE
signed main(){
  return 0;
}
#endif
