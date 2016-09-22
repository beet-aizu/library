#include <iostream>
using namespace std;

int main(){
  int w,n,i,j;
  int f,t;
  int value[31];
  for(i=1;i<31;i++){
    value[i]=i;
  }
  string str;
  cin >> w >> n;
  for(i=0;i<n;i++){
    cin >> str;
    if(str[1]==','){
      f = str[0] - '0';
      if(str.size()==3) t = str[2] - '0';
      else t = (str[2] - '0') * 10 + str[3] - '0';
    }else{
      f = (str[0] - '0') * 10 +  str[1] - '0';
      if(str.size()==4) t = str[3] - '0';
      else t = (str[3] - '0') * 10 + str[4] - '0';
    }
    int buf=value[f];
    value[f]=value[t];
    value[t]=buf;
  }
  for(i=1;i<w+1;i++){
    cout << value[i] << endl;
  }
}
