#include<bits/stdc++.h>
using namespace std;
using Int = long long;
//BEGIN CUT HERE
template<Int MOD = 1e9+7>
struct Mint{
  int v;
  Mint():v(0){}
  Mint(int v):v(v){}
  Mint(int v,bool f):v(v){if(f) v%=MOD;}

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
  Mint& operator/=(Mint a){return v*=a.inv();}
  
  Mint operator+(Mint a){return Mint(v)+=a;};
  Mint operator-(Mint a){return Mint(v)-=a;};
  Mint operator*(Mint a){return Mint(v)*=a;};
  Mint operator/(Mint a){return Mint(v)/=a;};

  Mint operator-(){return v?MOD-v:v;}

  Mint operator==(Mint a){return v==a.v;}
  Mint operator!=(Mint a){return v!=a.v;}
  
  vector<Mint> fact(int n){
    vector<Mint> res(n+1,1);
    for(int i=1;i<=n;i++) res[i]=res[i-1]*Mint(i);
    return res;
  }
  
  vector<Mint> finv(int n){
    vector<Mint> res(n+1,1);
    for(int i=1;i<=n;i++) res[i]=res[i-1]*Mint(i);
    res[n]=Mint(1)/res[n];
    for(int i=n;i>=1;i--) res[i-1]=res[i]*Mint(i);
    return res;
  }

  vector<Mint> invs(vector<Mint> &a,vector<Mint> &b){
    int n=a.size()-1;
    vector<Mint> res(n+1,0);
    for(int i=1;i<=n;i++) res[i]=b[i]*a[i-1];
    return res;
  }
};

template<Int MOD>
istream& operator>>(istream &is, Mint<MOD>& a){
  is>>a.v;
  return is;
} 
template<Int MOD>
ostream& operator<<(ostream &os, Mint<MOD>& a){
  os<<a.v;
  return os;
} 
//END CUT HERE
//INSERT ABOVE HERE
signed main(){
  return 0;
}
