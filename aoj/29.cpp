#include<iostream>
#include<vector>
#include<sstream>
#include<string>
using namespace std;
int main(){
  string str;
  getline(cin,str);
  stringstream ss(str);
  vector<string> v;
  vector<int> n;
  while(ss >> str){
    bool f=false;
    for(int i=0;i<v.size();i++){
      if(str==v[i]) {
	n[i]++;
	f=true;
      }
    }
    if(!f){
      v.push_back(str);
      n.push_back(1);
    }
  }
  str="";
  int c=0;
  for(int i=0;i<v.size();i++){
    if(c<n[i]) c=n[i];
  }
  for(int i=0;i<v.size();i++){
    if(n[i]==c) cout << v[i];
    if(str.size()<v[i].size()) str=v[i];
  }
  cout << " " << str << endl;
}
