#include<iostream>
using namespace std;
int ans,n,s;
int memo[1050][1000][10];
int rec(int bit,int x,int d){
  int res=0;
  if(memo[bit][x][d]!=-1) return memo[bit][x][d];
  if(d==n){
    if(x==s) return 1;
    return 0;
  }
  if(x>s) return 0;
  for(int i=0;i<10;i++){
    if(bit>>i&1) continue;
    res+=rec(bit+(1<<i),x+i*(d+1),d+1);
  }
  return memo[bit][x][d]=res;;
}
int main(){
  while(cin>>n>>s){
    fill(memo[0][0],memo[1049][999],-1);
    cout << rec(0,0,0) << endl;
  }
  return 0;
}
