#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;
#endif
//BEGIN CUT HERE
vector<string> split(string& s,char c){
  int n=s.size();
  vector<string> res;
  for(int i=0;i<n;i++){
    if(s[i]==c) continue;
    res.emplace_back();
    while(i<n and s[i]!=c) res.back()+=s[i++];
  }
  return res;
}
//END CUT HERE
#ifndef call_from_test
signed main(){
  return 0;
}
#endif
