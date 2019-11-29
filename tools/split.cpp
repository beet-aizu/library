#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;
#endif
//BEGIN CUT HERE
vector<string> split(string& s,char c){
  int n=s.size();
  vector<string> res;
  for(int i=0;i<n;i++){
    if(s[i]==c) continue;
    string t;
    while(i<n&&s[i]!=c) t.push_back(s[i++]);
    res.push_back(t);
  }
  return res;
}
//END CUT HERE
#ifndef call_from_test
signed YUKI_932(){
  string s;
  cin>>s;
  auto ss=split(s,',');
  cout<<(ss==vector<string>(ss.size(),"AC")?"Done!":"Failed...")<<endl;
  return 0;
}
/*
  verified 2019/11/30
  https://yukicoder.me/problems/no/932
*/

signed main(){
  YUKI_932();
  return 0;
}
#endif
