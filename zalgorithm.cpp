#include<bits/stdc++.h>
using namespace std;
using Int = long long;
//BEGIN CUT HERE
vector<int> zalgorithm(string s){
  int n=s.size();
  vector<int> a(n,0);
  a[0]=n;
  int i=1,j=0;
  while(i<n){
    while(i+j<n&&s[j]==s[i+j]) j++;
    a[i]=j;
    if(j==0){
      i++;
      continue;
    }
    int k=1;
    while(i+k<n&&k+a[k]<j) a[i+k]=a[k],k++;
    i+=k;
    j-=k;
  }
  return a;
}
//END CUT HERE

template<typename T> 
struct BIT{
  int n;
  vector<T> bit;
  //1-indexed
  BIT():n(-1){}
  BIT(int n_,T d):n(n_),bit(n_+1,d){}
  
  T sum(int i){
    T s=0;
    for(int x=i;x<=n;x+=(x&-x))
      s+=bit[x];
    return s;
  }
  void add(int i,T a){
    if(i==0) return;
    for(int x=i;x>0;x-=(x&-x))
      bit[x]+=a;
  }
  
  T sum0(int i){
    return sum(i+1);
  }
  void add0(int i,T a){
    add(i+1,a);
  }
};

//INSERT ABOVE HERE
signed CFR432_D(){
  string s;
  cin>>s;
  vector<int> a=zalgorithm(s);
  int n=s.size();
  set<int> ss;
  BIT<int> bit(n+100,0);
  for(int i=0;i<n;i++){
    //cout<<s[i]<<":"<<a[i]<<endl;
    bit.add0(a[i],1);
    if(i+a[i]!=n) continue;
    ss.emplace(a[i]);
  }
  cout<<ss.size()<<endl;
  for(auto x:ss) cout<<x<<" "<<bit.sum0(x)<<endl;
  return 0;
}
/*
  verified on 2018/05/01
  http://codeforces.com/problemset/problem/432/D
*/

signed main(){
  CFR432_D();
  return 0;
}
