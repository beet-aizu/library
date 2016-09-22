#include <iostream>
#include <string>
using namespace std;
int main(){
  int n,o,i,j;
  int l,r,s;
  string str;
  cin >> n;
  while(n!=0){
    o=0;
    l=0;r=0;s=0;
    for(i=0;i<n;i++){
      cin >> str;
      if(str[0]=='l'){
	if(str[1]=='u') l=1;
	else l=0;
      }else{
	if(str[1]=='u') r=1;
	else r=0;
      }
      if(l==1&&r==1&&s==0){
	o++;
	s=1;
      }
      if(l==0&&r==0&&s==1){
	o++;
	s=0;
      } 
    }
    cout << o << endl;
    cin >> n;
  }
  
}
