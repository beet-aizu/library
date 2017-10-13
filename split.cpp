#include<bits/stdc++.h>
using namespace std;
using Int = long long;
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
signed main(){
  return 0;
}
