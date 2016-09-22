#include<iostream>
#include<string>
using namespace std;
typedef long long ll;
int main(){
  string s;
  while(cin>>s,s!="0"){
    if(s.size()==1){
      cout << 0 << endl;
      s="";
      continue;
    }
    ll d[80005]={};
    ll i,j,k,ans=0;
    for(i=0;i<s.size();i++){
      d[i+2]=(d[i]+s[i]-'0')%11;
    }
    for(i=0;i<s.size();i++){
      if(s[i]=='0') continue;
      for(j=i+1;j<s.size();j++){
	if((j-i)%2==0){
	  if(((d[j+2]-d[i])-(d[j+1]-d[i+1]))%11==0) ans++;
	}else{
	  if(((d[j+1]-d[i])-(d[j+2]-d[i+1]))%11==0) ans++;
	}
      }
    }
    cout << ans << endl;
    s="";
  }
  return 0;
}
