#include<iostream>
#include<string>
using namespace std;
int main(){
  string s;
  while(cin >> s){
    while(s.find("@")!=-1){
      int x=s.find("@");
      string buf;
      for(int i=0;i<s[x+1]-'0';i++) buf+=s[x+2];
      s.replace(x,3,buf);
    }
    cout << s << endl;
  }
}
