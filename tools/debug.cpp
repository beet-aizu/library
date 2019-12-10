#include<bits/stdc++.h>
using namespace std;

#define IGNORE

//BEGIN CUT HERE
const int DEBUG = 1;
template<typename ...Ts>
void debug(Ts... ts){
  if(!DEBUG) return;
  cout<<"#:";
  auto print=[](auto v){cout<<v<<" ";};
  initializer_list<int>{(void(print(ts)),0)...};
  cout<<endl;
}
//END CUT HERE
//INSERT ABOVE HERE
signed main(){
  int a=42;
  string s="UKU";
  char c='$';
  debug(a,100,s,c);
  return 0;
}
