#include<iostream>
#include<string>
#include<cstring>
using namespace std;
typedef long long ll;
int main(){
  string s;
  while(cin>>s,s!="0"){
    if(s.size()<2){
      cout << 0 << endl;
      continue;
    }
    ll d[80005][11]={{}};
    ll w[80005]={};
    ll i,j,k,ans=0;
    for(i=0;i<s.size();i++){
      w[i+2]=(w[i]+s[i]-'0')%11;
    }
    for(i=0;i+1<s.size();i+=2){
      k=(11+s[i]-s[i+1])%11;
      for(j=0;j<11;j++){
	d[i+2][(j+k)%11]=d[i][j];
      }
      if(s[i]!='0') d[i+2][k]++;
      //for(j=0;j<11;j++) cout << d[i+2][j] << " ";
      //cout << endl;
      ans+=d[i+2][0];
      //cout << ans << "/";
      if(i+2<s.size()){
	k=s[i+2]-'0';
	ans+=d[i+2][(11-k)%11];
      }
      //cout << ans << " ";
    }
    //cout << endl;
    for(i=1;i+1<s.size();i+=2){
      k=(11+s[i]-s[i+1])%11;
      for(j=0;j<11;j++){
	d[i+2][(j+k)%11]=d[i][j];
      }
      if(s[i]!='0') d[i+2][k]++;
      //for(j=0;j<11;j++) cout << d[i+2][j] << " ";
      //cout << endl;
      ans+=d[i+2][0];
      //cout << ans << "/";
      if(i+2<s.size()){
	k=s[i+2]-'0';
	ans+=d[i+2][(11-k)%11];
      }
      //cout << ans << " ";
    }
    //cout << endl;
    cout << ans << endl;
    //cout <<endl;
    s="";
  }
  return 0;
}
