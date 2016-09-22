#include<iostream>
using namespace std;
int main(){
  int a,b;
  while(cin>>a>>b){
    int d[105]={};
    int i;
    d[a]++;d[b]++;
    if(a==0&&b==0) {
      cout << "OK" << endl;
      continue;
    }
    while(cin>>a>>b,a||b){
      d[a]++;d[b]++;
    }
    bool f=true;
    for(i=3;i<105;i++){
      if(d[i]%2!=0) f=false;
    }
    if(d[1]%2==1&&d[2]%2==1&&f) cout << "OK" << endl;
    else cout << "NG" << endl;
  }
  return 0;
}
