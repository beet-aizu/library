#include<bits/stdc++.h>
using namespace std;
/*
  multiprecision:
  #include <boost/multiprecision/cpp_int.hpp>
  using Int = boost::multiprecision::cpp_int;
*/
//BEGIN CUT HERE
using ll = __int128_t;
ll abs128(ll val){return val<0?-val:val;}

ostream &operator<<(ostream &os,ll val){
  if(ostream::sentry(os)){
    __uint128_t tmp=abs128(val);
    char buf[64];
    char *d=end(buf);
    do{
      --d;
      *d=char(tmp%10+'0');
      tmp/=10;
    }while(tmp);
    if(val<0) *--d='-';
    int len=end(buf)-d;
    if(os.rdbuf()->sputn(d,len)!=len){
      os.setstate(ios_base::badbit);
    }
  }
  return os;
}

istream &operator>>(istream &is,ll &val){
  string s;
  is>>s;
  val=0;
  for(int i=0;i<(int)s.size();i++)
    if(isdigit(s[i])) val=val*10+s[i]-'0';
  if(s[0]=='-') val*=-1;
  return is;
}
//END CUT HERE
template<typename T>
T extgcd(T a,T b,T& x,T& y){
  T d=a;
  if(b!=0){
    d=extgcd(b,a%b,y,x);
    y-=(a/b)*x;
  }else{
    x=1;y=0;
  }
  return d;
}

template<typename T>
T mod_inverse(T a,T mod){
  T x,y;
  extgcd(a,mod,x,y);
  return (x%mod+mod)%mod;
}

//INSERT ABOVE HERE
signed main(){
  ll n,R;
  ll cnt=0;
  while(cin>>n>>R,n){
    cout<<"Case #"<<++cnt<<":";
    ll r=R;
    vector<ll> v(n);
    for(ll i=0;i<n;i++){
      ll k;
      cin>>k;
      v[i]=k;
    }
    ll g=v[0];
    for(ll i=0;i<n;i++) g=__gcd(g,v[i]);
    if(abs128(r)%g){
      cout<<" Stupid keypad!"<<endl;
      continue;
    }
    vector<ll> ans(n,0);
    auto print=
      [&](){
        ll tmp=0;
        for(ll i=0;i<n;i++) tmp+=v[i]*ans[i];
        assert(tmp==r);
        for(ll i=0;i<n;i++) cout<<" "<<ans[i];
        cout<<endl;
      };

    bool f=0;
    for(ll i=0;i<n;i++){
      if(abs128(r)%v[i]==0){
        ans[i]=r/v[i];
        f=1;
        break;
      }
    }

    if(f){
      print();
      continue;
    }

    ll res=v[0];
    ans[0]=1;
    for(ll i=1;i<n;i++){
      ll k=__gcd(res,v[i]);
      if(k==res) continue;
      ll x,y;
      extgcd(res,v[i],x,y);
      for(ll j=0;j<i;j++) ans[j]*=x;
      ans[i]=y;
      res=k;
    }
    for(ll i=0;i<n;i++) ans[i]*=(r/res);
    print();
  }

  return 0;
}

/*
  verified on 2019/10/22
  https://vjudge.net/problem/UVA-12980
*/
