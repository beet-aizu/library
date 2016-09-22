#include <iostream>
using namespace std;
int main(){
  int n,a,b,c,x;
  int y[101]={};
  int i,j,k;
  cin >> n >> a >> b >> c >> x;
  while(n!=0){
    for(i=0;i<n;i++) cin >> y[i];
    int s=-1,f=x,p=0;
    while(p!=n&&s<=10000){
      if(f==y[p]) p++;
      s++;
      f=(a*f+b)%c;
    }
    if(s>10000) cout << -1 << endl;
    else cout << s << endl;
    cin >> n >> a >> b >> c >> x;
  }
  return 0;
}
