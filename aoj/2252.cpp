#include <iostream>
#include <string>
using namespace std;
int main(){
  string str;
  cin >> str;
  int i,j,k,o,r,b;
  char right[]={'y','u','i','o','p','h','j','k','l','n','m'};
  while(str[0]!='#'){
    o=0;
    r=0;
    for(j=0;j<11;j++){
      if(str[0]==right[j]) r=1;
    }
    b=r;
    for(i=0;i<str.size();i++){
      r=0;
      for(j=0;j<11;j++){
	if(str[i]==right[j]) r=1;
      }
      if(b!=r){
	o++;
	
      }
      b=r;
    }
    cout << o << endl;
    cin >> str;
  }
  return 0;
}
