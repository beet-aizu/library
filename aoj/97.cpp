#include<iostream>
using namespace std;
typedef long long ll;
ll n,s,o;
void rec(int d,int p,int su){
  if(d==n) {
    if(su==s) o++;
    return;
  }
  for(int i=p;i<=100;i++){
    if(su+i<=s) rec(d+1,i+1,su+i);
  }
}
int main(){
  while(cin >> n >> s,n||s) {
    o=0;
    rec(0,0,0);
    cout << o << endl;
  }
  return 0;
}
