#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;
#endif
//BEGIN CUT HERE
vector<int> manacher(string s){
  int n=s.size();
  vector<int> vs(n);
  for(int i=0,j=0;i<n;){
    while(i-j>=0&&i+j<n&&s[i-j]==s[i+j]) j++;
    vs[i]=j;
    int k=1;
    while(i-k>=0&&i+k<n&&k+vs[i-k]<j) vs[i+k]=vs[i-k],k++;
    i+=k;j-=k;
  }
  return vs;
}
//END CUT HERE
#ifndef call_from_test

//INSERT ABOVE HERE
// verify even palindrome
signed SPOJ_LPS(){
  int n;
  string s;
  cin>>n>>s;
  string t="$";
  for(int i=0;i<n;i++){
    t.push_back(s[i]);
    t.push_back('$');
  }
  auto vs=manacher(t);
  cout<<*max_element(vs.begin(),vs.end())-1<<endl;
  return 0;
}
/*
  verified on 2019/10/29
  http://www.spoj.com/problems/LPS/
*/

signed main(){
  //SPOJ_LPS();
  return 0;
}
#endif
