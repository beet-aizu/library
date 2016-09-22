#include<iostream>
#include<string>
using namespace std;
int main(){
  long long a,b;cin >> a>>b;
  string s;
  if(a==b) s="==";
  if(a<b) s="<";
  if(a>b) s=">";
  cout << "a "<<s<<" b" <<endl;
  return 0;
}
