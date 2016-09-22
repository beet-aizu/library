#include<iostream>
#include<string>
using namespace std;
int main(){
  string str;
  getline(cin,str);
  while(str.find("apple")!=-1) str.replace(str.find("apple"),5,"00000");
  while(str.find("peach")!=-1) str.replace(str.find("peach"),5,"11111");
  while(str.find("00000")!=-1) str.replace(str.find("00000"),5,"peach");
  while(str.find("11111")!=-1) str.replace(str.find("11111"),5,"apple");
  cout << str << endl;
  return 0;
}
