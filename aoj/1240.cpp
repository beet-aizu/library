#include<iostream>
#include<string>
using namespace std;
int main(){
  int n;
  cin >> n;
  for(int k=0;k<n;k++){
    string order,str,buf;
    cin >> order >> str;
    for(int i=order.size()-1;i>=0;i--){
      
      int s=str.size();
      switch(order[i]) {
      case 'J' :
	buf=str;
	for(int j=0;j<s;j++)
	  str[j+1]=buf[j];
	str[0]=buf[s-1];
	break;
      case 'C' : 
	buf=str;
	for(int j=0;j<s;j++)
	  str[j]=buf[j+1];
	str[s-1]=buf[0];
	break;
      case 'E' :
	buf=str;
	for(int j=0;j<s/2;j++){
	  str[j]=buf[j+s-s/2];
	}
	for(int j=s-s/2;j<s;j++){
	  str[j]=buf[j-s+s/2];  
	}
	
	break;
      case 'A' :
	buf=str;
	for(int j=0;j<s/2;j++){
	  str[j]=buf[s-1-j];
	  str[s-1-j]=buf[j];
	}
	break;
      case 'P' :
	for(int j=0;j<s;j++){
	  if(str[j]=='0') str[j]='9';
	  else if('0'<str[j]&&str[j]<='9') str[j]--;
	}
	break;
      case 'M' :
	for(int j=0;j<s;j++){
	  if(str[j]=='9') str[j]='0';
	  else if('0'<=str[j]&&str[j]<'9') str[j]++;
	}
	break;
      }
    }
    cout << str << endl;
  }
  return 0;
}
