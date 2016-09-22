#include<iostream>
#include<sstream>
using namespace std;
int main(){
  string s;
  while(cin >> s) {
    for(int i=0;i<s.size();i++) if(s[i]==',') s[i]=' ';
    stringstream ss(s);
    int id;double w,h;
    ss >> id >> w >> h;
    double bmi=w/(h*h);
    if(bmi>=25.0) cout << id << endl;
  }
}
