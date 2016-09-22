#include<iostream>
#include<string>
#include<sstream>
using namespace std;
int main(){
  string s;
  int o=0,k;
  while(cin>>s){
    for(int i=0;i<s.size();i++) if(s[i]<'0'||s[i]>'9') s[i]=' ';
    stringstream ss(s);
    while(ss>>k) o+=k;
  }
  cout << o << endl;
  return 0;
}
