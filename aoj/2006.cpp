#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;
int main(){
  int n,i,j,k,p;
  string str;
  cin>>n;
  for(j=0;j<n;j++){
    cin >> str;
    p=0;
    char c;
    for(i=0;i<str.size();i++){
      if(str[i]=='0'){
	if(p!=0){
	  if(c=='1'){
	    if(p%5==1) cout << '.';
	    if(p%5==2) cout << ',';
	    if(p%5==3) cout << '!';
	    if(p%5==4) cout << '?';
	    if(p%5==0) cout << " ";
	  }
	  if(c=='2'){
	    printf("%c", ('a'+(p-1)%3));
	  }
	  if(c=='3'){
	    printf("%c", ('d'+(p-1)%3));
	  }
	  if(c=='4'){
	    printf("%c", ('g'+(p-1)%3));
	  }
	  if(c=='5'){
	    printf("%c", ('j'+(p-1)%3));
	  }
	  if(c=='6'){
	   printf("%c", ('m'+(p-1)%3));
	  }
	  if(c=='7'){
	    printf("%c", ('p'+(p-1)%4));
	  }
	  if(c=='8'){
	    printf("%c", ('t'+(p-1)%3));
	  }
	  if(c=='9'){
	    printf("%c", ('w'+(p-1)%4));
	  }
	}
	p=0;
      }else{
	c=str[i];
	p++;
      }
      
    }
    cout << endl;
  }
  return 0;
}
