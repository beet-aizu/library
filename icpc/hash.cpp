#include<bits/stdc++.h>
using namespace std;
/**
 * @ignore
 */
//BEGIN CUT HERE
signed main(){
  const int MOD = 1e9+7,B=1e8+7;
  long long res=0;
  string s;
  while(getline(cin,s)){
    string t=s;
    if(s.find("//")!=string::npos)
      t=s.substr(0,s.find("//"));
    for(char c:t){
      if(c==' ') continue;
      res=(res*B+c)%MOD;
    }
    cout<<s;
    if(s=="  }") cout<<" // "<<res;
    cout<<endl;
  }
  cout<<res<<endl;
  return 0;
}
//END CUT HERE
