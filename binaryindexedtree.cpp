#include<bits/stdc++.h>
using namespace std;
const int MAX_N = 1 << 17;
struct BIT{
  int bit[MAX_N+1],n;
  //1-indexed
  BIT(){init();}
  BIT(int n):n(n){init();}
  void init(){
    memset(bit,0,sizeof(bit));
  }
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
  int sum0(int i){
    return sum(i+1);
  }
  void add0(int i,int x){
    add(i+1,x);
  }
};
int main(){
  
  return 0;
}
