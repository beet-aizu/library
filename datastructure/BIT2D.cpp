#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;
#endif
//BEGIN CUT HERE
template<typename T>
struct BIT2D{
  int n,m;
  T d;
  vector< vector<T> > bit;
  //1-indexed
  BIT2D():n(-1),m(-1){}
  BIT2D(int n_,int m_):n(n_),m(m_),bit(n_+1,vector<T>(m+1,0)){}
  T sum(int i,int j){
    T s(0);
    for(int x=i;x>0;x-=(x&-x))
      for(int y=j;y>0;y-=(y&-y))
        s+=bit[x][y];
    return s;
  }
  void add(int i,int j,T a){
    if(i==0 or j==0) return;
    for(int x=i;x<=n;x+=(x&-x))
      for(int y=j;y<=m;y+=(y&-y))
        bit[x][y]+=a;
  }
  // (x1,x2] * (y1,y2];
  T sum(int x1,int y1,int x2,int y2){
    return sum(x1,y1)-sum(x1,y2)-sum(x2,y1)+sum(x2,y2);
  }
};
//END CUT HERE
#ifndef call_from_test
signed main(){
  return 0;
}
#endif
