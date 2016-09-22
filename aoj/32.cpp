#include<iostream>
#include<string>
#include<sstream>
using namespace std;
int s2i(string str){
  istringstream iss(str);
  int x;iss >> x;
  return x;
}
int main(){
  int r=0,q=0;
  string str;
  while(cin >> str){
    for(int i=0;i<str.size();i++) if(str[i]==',') str[i]=' ';
    stringstream ss(str);
    int a,b,c; ss >> a >> b >> c;
    if(a*a+b*b==c*c) r++;
    if(a==b) q++;

  }

  cout << r << endl << q << endl;
}
