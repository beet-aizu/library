#include<iostream>
#include<string>
using namespace std;
int main(){
  string str;
  while(getline(cin,str)){
    while(str.find("the")==-1&&
	  str.find("this")==-1&&
	  str.find("that")==-1){
      int i;
      for(i=0;i<str.size();i++){
	if('a'<=str[i]&&str[i]<'z') str[i]++;
	else if(str[i]=='z') str[i]='a';
      }
    }
    cout << str << endl;
  }
  return 0;
}
