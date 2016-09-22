#include<iostream>
#include<string>
#include<sstream>
using namespace std;
int o;
int str;
int t,num;
int rej;
int s2i(string s){
  isstream ss(s);
  int x;
  ss >> x;
  return x;
}
void rec(int n,int s,int v){
  if(n==num.size()-1){
    if(v>o&&v<=t) {
      o=v;
      str=s;
      rej=0;
    }else if(o==v){
      rej=1;
    }
  }
  string buf;
  for(int i=n+1;i<num.size();i++){
    buf+=s[i];
    rec(i,s,v+s2i(buf));
  }
}
int main(){
  cin >> t >> num;
  while(num[0]!='0'){
    o=-1;
    rej=0;
    rec(0,0,0);
    
    cout << o << str;
    cin >> t >> num;
  }
}
