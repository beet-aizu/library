#include<iostream>
using namespace std;
typedef long long ll;
#define MOD 1000000007
ll calc(ll a,ll b){
  ll res=1;
  for(int i=0;(1<<i)<=b;i++){
    if(b>>i&1) res=(res*a)%MOD;
    a=(a*a)%MOD;
  }
  return res % MOD;
}
int main(){
  ll m,n;
  cin >> m >> n;
  cout << calc(m,n) << endl;
  return 0;
}
