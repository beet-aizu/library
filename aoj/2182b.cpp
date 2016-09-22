#include<iostream>
#include<string>
using namespace std;
typedef long long ll;
int main(){
  string s;
  while(cin>>s,s!="0"){
    ll d[80005][11]={{}};
    ll i,j,k,ans=0;
    for(i=0;i<s.size();i++){
      cout << ans << endl;
      k=s[i]-'0';
      if(k!=0)
	d[i+2][k]=1;
      for(j=0;j<11;j++){
	d[i+2][(j+k)%11]+=d[i][j];
      }
      for(j=0;j<11;j++){
	cout << d[i+2][j] << " ";
	ans+=d[i+2][j]*d[i+1][j];
      }
      cout << endl;
    }
    cout << ans << endl;
    cout <<endl;
    s="";
  }
  return 0;
}
