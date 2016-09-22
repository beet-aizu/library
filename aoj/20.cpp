#include<iostream>
#include<string>
using namespace std;
int main(){
  string str;
  getline(cin,str);
  int i=0;
  for(i=0;i<str.size();i++){
    if(str[i]>='a'&&str[i]<='z') str[i]+='A'-'a';
  }
  cout << str << endl;
}
