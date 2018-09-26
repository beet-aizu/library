#include<bits/stdc++.h>
using namespace std;
using Int = long long;
//BEGIN CUT HERE
vector<int> manacher(string s){
  int n=s.size();
  vector<int> v(n);
  for(int i=0,j=0;i<n;){
    while(i-j>=0&&i+j<n&&s[i-j]==s[i+j]) j++;
    v[i]=j;
    int k=1;
    while(i-k>=0&&i+k<n&&k+v[i-k]<j) v[i+k]=v[i-k],k++;
    i+=k;j-=k;
  }
  return v;
}
//END CUT HERE

//INSERT ABOVE HERE
signed SPOJ_LPS(){
  int n;
  string s;
  cin>>n>>s;
  string t="$";
  for(int i=0;i<n;i++){
    t.push_back(s[i]);
    t.push_back('$');
  }
  vector<int> v=manacher(t);
  cout<<*max_element(v.begin(),v.end())-1<<endl;
  return 0;
}
/*
  verified on 2018/05/20
  http://www.spoj.com/problems/LPS/
*/

signed main(){
  SPOJ_LPS();
  return 0;
}
