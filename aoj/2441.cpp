#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string l2s(ll x){
  stringstream ss;
  ss<<x;
  return ss.str();
}
int main(){
  string s;
  ll c=0;
  for(ll i=1;i<=10000000;i++){
    if(i%15==0) s+="FizzBuzz";
    else if(i%3==0) s+="Fizz";
    else if(i%5==0) s+="Buzz";
    else s+=l2s(i),c+=l2s(i).size();

    if(i==1) cout << c << endl;
    if(i==10) cout << c << endl;
    if(i==100) cout << c << endl;
    if(i==1000) cout << c << endl;
    if(i==10000) cout << c << endl;
    if(i==100000) cout << c << endl;
    if(i==1000000) cout << c << endl;
    if(i==10000000) cout << c << endl;
    if(i%30000==0) {
      //cout << s.size() << endl;
      s="";
    }
  }
  return 0;
}
