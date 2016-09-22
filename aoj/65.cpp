#include<iostream>
#include<sstream>
#include<string>
using namespace std;
int main(){
  string s;
  int id,k,i;
  int d[1005][2]={};
  while(getline(cin,s),s!=""){
    for(i=0;i<s.size();i++) if(s[i]==',') s[i]=' ';
    stringstream ss(s);
    ss>>id>>k;
    d[id][0]++;
  }
  while(getline(cin,s),s!=""){
    for(i=0;i<s.size();i++) if(s[i]==',') s[i]=' ';
    stringstream ss(s);
    ss>>id>>k;
    d[id][1]++;
  }
  for(i=0;i<1005;i++){
    if(d[i][0]>0&&d[i][1]>0) cout << i << " " << d[i][0]+d[i][1] << endl;
  }
}
