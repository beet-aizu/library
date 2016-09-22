#include<iostream>
#include<string>
using namespace std;
struct Dice{
  int s[6];
  void roll(char c){
    int b;
    if(c=='E'){
      b=s[0];
      s[0]=s[3];
      s[3]=s[5];
      s[5]=s[2];
      s[2]=b;
    }
    if(c=='W'){
      b=s[0];
      s[0]=s[2];
      s[2]=s[5];
      s[5]=s[3];
      s[3]=b;
    }
    if(c=='N'){
      b=s[0];
      s[0]=s[1];
      s[1]=s[5];
      s[5]=s[4];
      s[4]=b;
    }
    if(c=='S'){
      b=s[0];
      s[0]=s[4];
      s[4]=s[5];
      s[5]=s[1];
      s[1]=b;
    }
    if(c=='R'){
      b=s[1];
      s[1]=s[2];
      s[2]=s[4];
      s[4]=s[3];
      s[3]=b;
    }    
  }
  int top() {
    return s[0];
  }
  int right(){
    return s[2];
  }
  int left(){
    return s[3];
  }
  int front(){
    return s[1];
  }
};
bool same(Dice a,Dice b){
  for(int i=0;i<6;i++) if(a.s[i]!=b.s[i]) return false;
  return true;
}
int main(){
  Dice d[2];
  for(int j=0;j<2;j++) 
    for(int i=0;i<6;i++)
      cin >> d[j].s[i];
  bool f=false;
  
  
  for(int i=0;i<4;i++){
    d[1].roll('R');
    for(int j=0;j<4;j++){
      d[1].roll('N');
      if(same(d[0],d[1])) f=true;
    }
  }
  d[1].roll('E');
  for(int j=0;j<4;j++){
    d[1].roll('N');
    if(same(d[0],d[1])) f=true;
  }

  d[1].roll('W');
  d[1].roll('W');
  for(int j=0;j<4;j++){
    d[1].roll('N');
    if(same(d[0],d[1])) f=true;
  }
  
  cout << (f?"Yes":"No") << endl;
  return 0;
}
