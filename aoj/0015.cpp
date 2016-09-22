#include <iostream>
#include <string>
using namespace std;


int main(){
  int n,i,j;
  
  
  int up = 0;
  cin >> n;
  for(i=0;i<n;i++){
    int sum[110]={};
    string a,b;
    up = 0;
    cin >> a >> b;
    int sa=a.size(),sb=b.size();
    int flag=0;
    if(max(sa,sb)>80) flag =1;
    else 
    for(j=0;j<max(sa,sb);j++){
      if(sa>j&&sb>j){
	sum[j] = (a[sa-j-1]-'0') + (b[sb-j-1]-'0') + up;
      }else if(sa>j){
	sum[j] = (a[sa-j-1]-'0') + up;
      }else if(sb>j){
	sum[j] = (b[sb-j-1]-'0') + up;
      }
      up=0;
      if(sum[j]>9){
	up=1;
	sum[j]-=10;
      }
    }
    sum[max(sa,sb)]=up;
    int k=max(sa,sb);
    while(sum[k]==0&&k>0) k--;
    if(k>=80||flag==1) cout << "overflow";
    else
    for(j=k;j>=0;j--)
      cout << sum[j];
    cout << endl;
  }
}
