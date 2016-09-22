#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main(){
  string str;
  while(cin >> str){
    vector <int> v;
    int i,j,k;
    for(i=0;i<str.size();i++){
      if(str[i]=='I') k=1;
      else if(str[i]=='V') k=5;
      else if(str[i]=='X') k=10;
      else if(str[i]=='L') k=50;
      else if(str[i]=='C') k=100;
      else if(str[i]=='D') k=500;
      else if(str[i]=='M') k=1000;
      v.push_back(k);
    }
    int o=0;
    for(i=0;i<v.size()-1;i++){
      if(v[i]<v[i+1]) o-=v[i];
      else o+=v[i];
    }
    o+=v[v.size()-1];
    cout << o << endl;
  }
}
