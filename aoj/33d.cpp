#include<iostream>
using namespace std;
int d[10]={};
bool f;
void dfs(int l,int r, int s){
  if(s==10) f=true;
  //cout << l << r << d[s] << endl;
  if(l<d[s]){
    dfs(d[s],r,s+1);
  }
  if(r<d[s]){
    dfs(l,d[s],s+1);
  }
}
int main(){
  int n;cin >> n;
  while(n--){
    int r=0,l=0;
    f=false;
    for(int i=0;i<10;i++){
      cin >> d[i];
      //cout << l << ":" << r << endl;
    }
    dfs(0,0,0);
    if(!f) cout << "NO" << endl;
    else cout << "YES" << endl;
  }  
}
