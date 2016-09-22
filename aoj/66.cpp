#include<iostream>
#include<string>
using namespace std;
int main(){
  string s;
  while(cin>>s){
    char c='d';
    if(s[0]=='o'&&s[1]=='o'&&s[2]=='o') c='o';
    if(s[3]=='o'&&s[4]=='o'&&s[5]=='o') c='o';
    if(s[6]=='o'&&s[7]=='o'&&s[8]=='o') c='o';
    if(s[0]=='o'&&s[3]=='o'&&s[6]=='o') c='o';
    if(s[1]=='o'&&s[4]=='o'&&s[7]=='o') c='o';
    if(s[2]=='o'&&s[5]=='o'&&s[8]=='o') c='o';
    if(s[0]=='o'&&s[4]=='o'&&s[8]=='o') c='o';
    if(s[2]=='o'&&s[4]=='o'&&s[6]=='o') c='o';
    
    if(s[0]=='x'&&s[1]=='x'&&s[2]=='x') c='x';
    if(s[3]=='x'&&s[4]=='x'&&s[5]=='x') c='x';
    if(s[6]=='x'&&s[7]=='x'&&s[8]=='x') c='x';
    if(s[0]=='x'&&s[3]=='x'&&s[6]=='x') c='x';
    if(s[1]=='x'&&s[4]=='x'&&s[7]=='x') c='x';
    if(s[2]=='x'&&s[5]=='x'&&s[8]=='x') c='x';
    if(s[0]=='x'&&s[4]=='x'&&s[8]=='x') c='x';
    if(s[2]=='x'&&s[4]=='x'&&s[6]=='x') c='x';
    
    cout << c << endl;
  }
  return 0;
}
