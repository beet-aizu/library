#include <iostream>
#include<vector>
#include<math.h>
using namespace std;
typedef long long ll;
bool isPrime(ll n){
  for(ll i=2;i*i<=n;i++) if(n%i==0) return false;
  return true;
}
int main(){
  ll ans = 2;
  ll n;
  vector<ll> p;
  vector<ll> v;
  for(ll i=2;i<1000000;i++) if(isPrime(i)) p.push_back(i);
  //cout << p.size() << endl;
  while(1){
    ans=2;
    v.clear();
    cin >> n;
    if(n == 0)break;
    if(n==1) {
      cout << 1 << endl;
      continue;
    }
    //cout << n << endl;
    for(ll i = 0;p[i] <= n;i++){
      //cout << i << n << endl;
      if(i==p.size()) break;
      if(n%p[i] == 0){
        ll c=0;
        while(n%p[i]==0) {
          n/=p[i];
          c++;
        }
        //cout << p[i] << ":" << c << endl;
        v.push_back(c);
	
	if(n==1) break;
      }
       
    }
    if(n!=1) v.push_back(1);
    ll m = 0;
    ans = 1;
    for(ll i=0;i<v.size();i++){
      ans*=2*v[i]+1;
    }
    cout << (1+ans)/2 <<endl;
  }
  return 0;
}
