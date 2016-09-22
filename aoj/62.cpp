#include<iostream>
#include<string>
using namespace std;
int main(){
  string s;
  while(cin >> s){
    int i,j,k;
    int d[10][10]={};
    for(i=0;i<10;i++) d[0][i]=s[i]-'0';
    for(i=1;i<10;i++){
      for(j=0;j<10-i;j++){
	d[i][j]=(d[i-1][j]+d[i-1][j+1])%10;
      }
    }
    cout << d[9][0] << endl;
  }
}
