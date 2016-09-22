#include<iostream>
#include<string>
#include<sstream>
using namespace std;
int o;
string str;
int t;
string num;
int rej;
int s2i(string s){
  istringstream ss(s);
  int x;
  ss >> x;
  return x;
}
void rec(int n,string s,int v){
  //cout << n << ":"<<v <<endl;
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
  //buf+=num[n];
  for(int i=n+1;i<num.size();i++){
    buf+=num[i];
    //cout << s2i(buf) <<endl;
    rec(i,s+" "+buf,v+s2i(buf));
  }
}
int main(){
  cin >> t >> num;
  while(num[0]!='0'){
    o=-1;
    rej=0;
    string buf;
    for(int i=0;i<num.size();i++){
      buf+=num[i];
      //cout << s2i(buf) <<endl;
      rec(i," "+buf,s2i(buf));
    }
    //rec(0,0,num[0]-'0');

    if(o==-1) cout << "error" << endl;
    else if(rej==1) cout << "rejected" <<endl;
    else cout << o << str << endl;
    cin >> t >> num;
  }
}
