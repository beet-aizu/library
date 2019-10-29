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

#define call_from_test
#include "../datastructure/sparsetable.cpp"
#undef call_from_test

signed ukuku09_D(){
  int n,q;
  cin>>n>>q;
  string s;
  cin>>s;

  auto f=[](int a,int b){return max(a,b);};
  SparseTable<int> sp(f);
  sp.build(manacher(s));

  for(int i=0;i<q;i++){
    int l,r;
    cin>>l>>r;
    l--;
    int L=0,R=n;
    while(L+1<R){
      int M=(L+R)>>1;
      if(l+(M-1)<r-(M-1)&&sp.query(l+(M-1),r-(M-1))>=M) L=M;
      else R=M;
    }
    cout<<L*2-1<<endl;
  }
  return 0;
}
/*
  verified on 2019/10/29
  https://atcoder.jp/contests/ukuku09/tasks/ukuku09_d
*/

signed main(){
  //SPOJ_LPS();
  //ukuku09_D();
  return 0;
}
#endif
