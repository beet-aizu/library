#include<iostream>
using namespace std;
int main(){
  double d;
  while(cin >> d){
    string s;
    if(d<=48.0) s="light fly";
    else if(d<=51.0) s="fly";
    else if(d<=54.0) s="bantam";
    else if(d<=57.0) s="feather";
    else if(d<=60.0) s="light";
    else if(d<=64.0) s="light welter";
    else if(d<=69.0) s="welter";
    else if(d<=75.0) s="light middle";
    else if(d<=81.0) s="middle";
    else if(d<=91.0) s="light heavy";
    else s="heavy";
    cout << s << endl;
  }
  return 0;
}
