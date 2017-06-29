#include<bits/stdc++.h>
using namespace std;
#define int long long
//BEGIN CUT HERE
int lis(int n,vector<int>& A){
  vector<int> L(A.size()+1,0);
  L[0]=A[0];
  int length=1;
  for(int i=1;i<n;i++){
    if(L[length-1]<A[i]){
      L[length++]=A[i];
    }else{
      *lower_bound(L.begin(),L.begin()+length,A[i])=A[i];
    }
  }
  return length;
}
//END CUT HERE
signed main(){
  int n;
  cin>>n;
  vector<int> A(n);
  for(int i=0;i<n;i++) cin>>A[i];
  cout<<lis(n,A)<<endl;
  return 0;
}
/*
verified on 2017/06/29
http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_D&lang=jp
*/
