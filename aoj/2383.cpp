#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
ll MOD=1000000007;
int main(){
  ll n,t;
  cin >> n >> t;
  ll i,j,k;
  vector<ll> v;
  for(i=0;i<n;i++){
    cin >> k;
    v.push_back(k);
  }
  sort(v.begin(),v.end());
  ll ans=1;
  for(i=0;i<n;i++){
    ans*=(i-distance(v.begin(),lower_bound(v.begin(),v.end(),v[i]-t))+1);
    ans%=MOD;
  }
  cout << ans % MOD << endl;
  return 0;
}
