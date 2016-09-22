#include<iostream>
using namespace std;
typedef long long ll;
int main(){
  ll a,b,c;
  ll n;
  while(cin>>a>>b>>n){
    a-=(a/b)*b;
    ll o=0;
    ll i,j,k;
    for(i=0;i<n;i++){
      a*=10;
      //cout << a/b << ":";
      o+=a/b;
      a-=(a/b)*b;
      if(a==0) break;
    }
    cout << o << endl;
  }
  return 0;
}
