#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;
#endif

//BEGIN CUT HERE
struct BoolPrinter{
  const string a,b;
  BoolPrinter(string a_,string b_):a(a_),b(b_){}
  string operator[](int k){return k?a:b;}
};
BoolPrinter yesno("yes","no");
BoolPrinter YesNo("Yes","No");
BoolPrinter YESNO("YES","NO");
//END CUT HERE
#ifndef call_from_test
signed main(){
  return 0;
}
#endif
