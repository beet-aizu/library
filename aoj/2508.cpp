#include<iostream>
#include<string>
using namespace std;
int main(){
  int n;
  cin >> n;
  while(n!=0){
    int k[101]={},i,j;
    for(i=0;i<n;i++) cin >> k[i];
    string str;
    cin >> str;
    for(i=0;i<str.size();i++){
      for(j=0;j<k[i%n];j++){
	str[i]--;
      if(str[i]<'A') str[i]+=58;
      else if(str[i]>'Z'&&str[i]<'a') str[i]-=6;
      }
      cout << str[i];
    }
    cout << endl;
    cin>>n;
  }
  return 0;
}
