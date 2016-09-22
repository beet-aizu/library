#include<iostream>
using namespace std;
int n,s,o;
void rec(int d,int k,int x){
  if(d>n) return;
  else if(d==n){
    if(x==s) o++;
  }else{
    for(int i=k+1;i<=9;i++){
      rec(d+1,i,x+i);
    }
  }
}
int main(){
  cin >> n >> s;
  while(n!=0){
    o=0;
    rec(0,-1,0);
    cout << o << endl;
    cin >> n >> s;
  }
  return 0;
}
