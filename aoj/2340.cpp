#include<iostream>
#include<string>
using namespace std;
typedef long long ll;
int main(){
  int q;
  cin >> q;
  int i,j,k;
  string str;
  ll op=0,en=0;
  for(i=0;i<q;i++){
    ll p,n;
    char c;
    cin >> p >> c >> n;
    if(c=='(') op+=n;
    else en+=n;
    if(op==en) cout << "Yes" <<endl;
    else cout << "No" <<endl;   
  }
  return 0;
}
