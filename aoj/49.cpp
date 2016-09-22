#include<iostream>
#include<sstream>
#include<map>
using namespace std;
int main(){
  string b;
  map<string,int> m;
  m["A"]=0;
  m["B"]=0;
  m["AB"]=0;
  m["O"]=0;
  while(cin >> b){
    for(int i=0;i<b.size();i++) if(b[i]==',') b[i]=' ';
    stringstream ss(b);
    int n;
    ss >> n >> b;
    m[b]++;
  }
  cout << m["A"] << endl;
  cout << m["B"] << endl;
  cout << m["AB"] << endl;
  cout << m["O"] << endl;
  
}
