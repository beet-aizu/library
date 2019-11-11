#include<bits/stdc++.h>
using namespace std;

//BEGIN CUT HERE
signed main(){
  const int MOD = 1e9+7,B=1e8+7;
  long long res=0;
  string s;
  while(getline(cin,s)){
    if(s.find("//")!=string::npos)
      s=s.substr(0,s.find("//"));
    for(char c:s){
      if(c==' ') continue;
      res=(res*B+c)%MOD;
    }
  }
  cout<<res<<endl;
  return 0;
}
//END CUT HERE
