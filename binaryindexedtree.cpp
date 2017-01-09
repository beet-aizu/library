#include<bits/stdc++.h>
using namespace std;
const int MAX_N = 1 << 17;
int bit[MAX_N+1],n;
//1-indexed
int sum(int i){
  int s=0;
  while(i>0){
    s+=bit[i];
    i-=i&-i;
  }
  return s;
}
void add(int i,int x){
  while(i<=n){
    bit[i]+=x;
    i+=i&-i;
  }
}
int main(){
  memset(bit,0,sizeof(bit));
  return 0;
}
