#include<iostream>
using namespace std;
int bit[100000+1],n;
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
  int q;
  cin >> n>>q;
  fill(bit,bit+100000+1,0);
  int a,b,c;
  while(q--){
    cin >> a >> b >> c;
    if(a==0) add(b,c);
    else{
      if(b==0) cout << sum(c) << endl;
      else cout << sum(c)-sum(b-1)<<endl;
    }
  }
}
