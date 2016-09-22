#include<iostream>
#include<string>
using namespace std;
int main(){
  string str;
  cin >> str;
  while(str[0]!='#'){
    int i=0,a=0,k=1;
    i=str.size()-1;k=1;
    while(str[i]!='n'&&str[i]!='w'){
      i--;
    }
    if(str[i]=='n'){
      a=0;
    }else if(str[i]=='w'){
      a=90;
    }
    if(i>0) i--;
    while(i!=0){
      i--;
      if(str[i]=='n'){
	a*=2;
        a-=90;
	k*=2;
      }else if(str[i]=='w'){
	a*=2;
	a+=90;
	k*=2;
      }
      
    }
    while(a%2==0&&k%2==0){
      a/=2;k/=2;
    }
    if(k==1) cout << a << endl;
    else cout << a << "/" << k << endl;
    cin >> str;
  }
  return 0;
}
