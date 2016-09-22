#include<iostream>
#include<string>
#include<sstream>
#include<vector>
using namespace std;
int main(){
  string s;
  getline(cin,s);
  int i,j,k;
  vector<string> v;
  for(i=0;i<s.size();i++) if(s[i]==','||s[i]=='.') s[i]=' ';
  stringstream ss(s);
  while(ss>>s) v.push_back(s);
  bool f=true;
  for(i=0;i<v.size();i++){
    if(2<v[i].size()&&v[i].size()<7){
      if(f){ cout << v[i];f=false;}
      else cout << " " << v[i];
    }
  }
  cout << endl;
  return 0;
}
