#include<iostream>
#include<string>
using namespace std;
int main(){
  string s,p;
  cin >> s >> p;
  s=s+s;
  if(s.find(p)!=-1) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}
