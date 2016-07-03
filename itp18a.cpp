#include<iostream>
#include<string>
using namespace std;
int main(){
  string str;
  getline(cin,str);
  int i;
  for(i=0;i<str.size();i++){
    if(str[i]>='a'&&str[i]<='z') str[i]+='A'-'a';
    else if(str[i]>='A'&&str[i]<='Z') str[i]+='a'-'A';
  }
    cout << str << endl;
  return 0;
}
