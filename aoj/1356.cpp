#include<iostream>
#include<string>
#include<map>
using namespace std;
int main(){
  map<string,int> m;
  int n,i,j;
  int d[1001]={};
  cin >> n;
  for(i=0;i<n;i++) cin >> d[i];
  string str;
  for(i=0;i<n;i++){
    int b=0;
    for(j=i;j<n;j++){
      b=b*10+d[j];
      str = to_string(b);
      m[str]=1;
    }
  }
  long long k=0;
  str=to_string(k);
  while(m.find(str)!=m.end()){
    k++;
    str=to_string(k);
  }
  cout << k << endl;
  return 0;
}
