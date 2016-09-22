#include<iostream>
#include<string>
#include <sstream>
using namespace std;
string i2s(int number)
{
  stringstream ss;
  ss << number;
  return ss.str();
}
int main(){
  int n,i,j,k,b;
  string str;
  char c;
  cin >> n;
  for(i=0;i<n;i++){
    cin >> c;
    str+=c;
  }
  k=0;
  while(str.find(i2s(k))!=-1){
    k++;
  }
  cout << k << endl;
  return 0;
}
