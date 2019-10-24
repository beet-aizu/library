#include<bits/stdc++.h>
using namespace std;
using Int = long long;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

//BEGIN CUT HERE
signed main(){
  const int MOD = 1e9+7,B=1e8+7;
  long long res=0;
  string s;
  while(getline(cin,s)){
    for(char c:s){
      if(c==' ') continue;
      res=(res*B+c)%MOD;
    }
  }
  cout<<res<<endl;
  return 0;
}
//END CUT HERE
