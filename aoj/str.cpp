#include<iostream>
#include<string>
using namespace std;
int main(){
  string str[256];
  int n,i;
  cin >> n;
  for(i=0;i<n;i++){
  cin >> str[i];
  reverse(str[i].begin(),str[i].end());
  }
  for(i=0;i<n;i++){
  cout << str[i] << endl;
  }
}
