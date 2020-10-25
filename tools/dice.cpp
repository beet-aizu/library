#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;
#endif
//BEGIN CUT HERE
template<typename T=int>
struct Die{
  array<T, 6> fs;
  int &top()   {return fs[0];}
  int &south() {return fs[1];}
  int &east()  {return fs[2];}
  int &west()  {return fs[3];}
  int &north() {return fs[4];}
  int &bottom(){return fs[5];}
  void roll(char c){
    //the view from above
    // N
    //W E
    // S
    string b("EWNSRL");
    int v[6][4]={{0,3,5,2},
                 {0,2,5,3},
                 {0,1,5,4},
                 {0,4,5,1},
                 {1,2,4,3},
                 {1,3,4,2}};
    for(int k=0;k<6;k++){
      if(b[k]!=c) continue;
      int t=fs[v[k][0]];
      fs[v[k][0]]=fs[v[k][1]];
      fs[v[k][1]]=fs[v[k][2]];
      fs[v[k][2]]=fs[v[k][3]];
      fs[v[k][3]]=t;
    }
  }
  using ll = long long;
  ll hash(){
    ll res=0;
    for(int i=0;i<6;i++) res=res*256+fs[i];
    return res;
  }
  bool operator==(const Die &d) const{
    for(int i=0;i<6;i++) if(fs[i]!=d.fs[i]) return 0;
    return 1;
  }
};

template<typename T>
vector<Die<T>> makeDice(Die<T> d){
  vector<Die<T>> res;
  for(int i=0;i<6;i++){
    Die t(d);
    if(i==1) t.roll('N');
    if(i==2) t.roll('S');
    if(i==3) t.roll('S'),t.roll('S');
    if(i==4) t.roll('L');
    if(i==5) t.roll('R');
    for(int k=0;k<4;k++){
      res.emplace_back(t);
      t.roll('E');
    }
  }
  return res;
}
//END CUT HERE
#ifndef call_from_test
signed main(){
  return 0;
}
#endif
