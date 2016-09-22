#include<iostream>
#include<string>
#include<sstream>
using namespace std;
typedef unsigned long long ll;
int main(){
  ll inf=1;
  inf = inf << 32;
  ll n;
  cin >> n;
  ll i,j,k;
  for(i=0;i<n;i++){
    string strs[9];
    ll is[9];
    for(j=0;j<9;j++){
      cin >> hex >> is[j];
    }
    ll o=0;
    for(j=0;j<32;j++){
      ll c=0;
      for(k=0;k<8;k++) {
	c+=is[k]^o;
	c%=inf;
      }
      if(((is[8]>>j)&1)^((c>>j)&1)) {
	o+=1<<j;
	o%=inf;
      }
    }
    o%=inf;
    cout <<hex << o << endl;
  }
  return 0;
}
