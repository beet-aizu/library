#include<iostream>
#include<string>
#include<sstream>
#include<cmath>
using namespace std;
int main(){
  string b;
  int sum=0,num=0,s=0;
  while(cin >> b){
    for(int i=0;i<b.size();i++) if(b[i]==',') b[i]=' ';
    stringstream ss(b);
    int a,c;
    ss >> a >> c;
    sum+=a*c;num+=c;s++;
  }
  cout << sum << endl;
  cout << round((double) num/s) << endl;
}
