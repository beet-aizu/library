#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main(){
  int o=0;
  string s,ss;
  while(cin >> s){
    ss=s;
    reverse(ss.begin(),ss.end());
    if(s==ss) o++;
  }
  cout << o << endl;
}
