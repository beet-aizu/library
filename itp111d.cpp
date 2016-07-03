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
  Dice d[100];
  int n;cin >> n;
  for(int j=0;j<n;j++) 
    for(int i=0;i<6;i++)
      cin >> d[j].s[i];
  
  bool ff = true;
  for(int k=0;k<n-1;k++){
    for(int l=k+1;l<n;l++){
      bool f=false;
      for(int i=0;i<4;i++){
	d[l].roll('R');
	for(int j=0;j<4;j++){
	  d[l].roll('N');
	  if(same(d[k],d[l])) f=true;
	}
      }
      d[l].roll('E');
      for(int j=0;j<4;j++){
	d[l].roll('N');
	if(same(d[k],d[l])) f=true;
      }
      
      d[l].roll('W');
      d[l].roll('W');
      for(int j=0;j<4;j++){
	d[l].roll('N');
	if(same(d[k],d[l])) f=true;
      }
      if(f) ff=false;
    }
  }
  
  cout << (ff?"Yes":"No") << endl;
  return 0;
}
