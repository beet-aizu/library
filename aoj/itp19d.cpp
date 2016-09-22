#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main(){
  string str;
  cin >> str;
  int q,i;
  cin >> q;
  string s1,s2;
  int a,b;
  for(i=0;i<q;i++){
    //cout << str << endl;
    cin >> s1 >> a >> b;
    if(s1=="print"){
      cout << str.substr(a,b-a+1) << endl;
    }else if(s1=="reverse"){
      string s3=str.substr(a,b-a+1);
      reverse(s3.begin(),s3.end());
      str=str.substr(0,a)+s3+str.substr(b+1,str.size()-a-1);
    }else{
      cin >> s2;
      str=str.substr(0,a)+s2+str.substr(b+1,str.size()-a-1);
    }
  }
}
