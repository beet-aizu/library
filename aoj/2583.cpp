#include<iostream>
#include<string>
using namespace std;
int main(){
  int n;
  cin >> n;
  int i,j,k;
  while(n!=0){
    string str[1000];
    int d[1000]={};
    for(i=0;i<n;i++){
      cin >> str[i];
      j=0;
      while(str[i][j]=='.') j++;
      if(j==1) str[i][0]='+';
      else if(j!=0){
	str[i][j-1]='+';
      }
      d[i]=j;
      
    }
    for(i=0;i<n;i++){
      if(d[i]==0) continue;
      if(d[i+1]<=d[i]) continue;
      for(j=i+2;j<n;j++){
	
	if(d[i]==d[j]){
	  for(k=i+1;k<j;k++){
	    str[k][d[i]-1]='|';
	  }
	}
	if(d[i]>=d[j]) break;
      }
    }
    for(i=0;i<n;i++){
      for(j=0;j<str[i].size();j++) {
	if(str[i][j]=='.') str[i][j]=' ';
      }
      cout  <<str[i] << endl;
    }
    cin >> n;
  }

  return 0;
}
