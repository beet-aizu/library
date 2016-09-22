#include<iostream>
#include<string>
#include<sstream>
#include<vector>
using namespace std;
typedef long long ll;
ll ans;
void solve(vector<ll> v,ll a,ll b,ll c){
  ll cnt=0,m=0;
  ll i,j,k;
  for(i=0;i<v.size();i++){
    if(v[i]==-1) cnt++;
    if(v[i]==-2) cnt--;
    m=max(m,cnt);
  }
  cnt=0;
  bool f=true;
  while(f){
    f=false;
    for(i=0;i<v.size();i++){
      cout << i << v.size() << endl;
      for(j=0;j<v.size();j++) cout << j << ":" << v[j]<<endl;
      if(v[i]==-1) cnt++;
      if(v[i]==-2) cnt--;
      if(cnt==m){
	if(a==b){
	  if(b==c){
	    if(v[i]==-3){
	      v[i-1]+=v[i+1];
	      v.erase(v.begin()+i);v.erase(v.begin()+i);
	      i-=2;
	      f=true;
	    }
	    if(v[i]==-4){
	      v[i-1]-=v[i+1];
	      v.erase(v.begin()+i);v.erase(v.begin()+i);
	      i-=2;
	      f=true;
	    }
	    if(v[i]==-5){
	      v[i-1]*=v[i+1];
	      v.erase(v.begin()+i);v.erase(v.begin()+i);
	      i-=2;
	      f=true;
	    }
	  }
	}
      }
    }
  }
  cout << v[0] << endl;
}
int main(){
  string s;
  cin >> s;
  vector<ll> v;
  ll i,j,k;
  for(i=0;i<s.size();i++){
    if(s[i]=='(') {
      s.replace(i,1," -1 ");
      i+=3;
    }
    if(s[i]==')') {
      s.replace(i,1," -2 ");
      i+=3;
    }
    if(s[i]=='+'){
      s.replace(i,1," -3 ");
      i+=3;
    }
    if(s[i]=='-'){
      s.replace(i,1," -4 ");
      i+=3;
    }
    if(s[i]=='*') {
      s.replace(i,1," -5 ");
      i+=3;
    }
  }
  stringstream ss(s);
  ll x;
  while(ss>>x) v.push_back(x);
  //for(i=0;i<v.size();i++) cout << v[i] << endl;
  ans=-(1<<30);
  
  for(i=0;i<3;i++){
    for(j=0;j<3;j++){
      for(k=0;k<3;k++){
	solve(v,i,j,k);
      }
    }
  }
  cout << ans << endl;
}
