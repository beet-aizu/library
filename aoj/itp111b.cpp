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
int main(){
  Dice d;
  for(int i=0;i<6;i++) cin >> d.s[i];
  int n;cin >> n;
  while(n--){
    int a,b;cin >> a >> b;
    if(d.left()==a) d.roll('E');
    if(d.right()==a) d.roll('W');
    while(d.top()!=a) d.roll('N');
    while(d.front()!=b) d.roll('R');
    cout << d.right() << endl;
  }
  return 0;
}
