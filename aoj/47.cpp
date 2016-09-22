#include<iostream>
#include<string>
using namespace std;
int main(){
  int d[3]={};
  d[0]=1;
  string s;
  while(cin>>s){
    swap(d[s[0]-'A'],d[s[2]-'A']);
  }
  for(int i=0;i<3;i++) if(d[i]) cout << (char)('A'+i) << endl;
  return 0;
}
