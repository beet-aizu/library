#include <iostream>
#include <string>
#include <vector>
using namespace std;
string r(string s);
int main(){
  int n,i,j,k,l,f[8]={};
  cin >> n;
  string str,s1,s2;
  for(i=0;i<n;i++){
    cin >> str;
    int si = str.size();
    vector <string> v;
    for(j=1;j<si;j++){
      string s[8];
      s1=str.substr(0,j);
      s2=str.substr(j,si-j);
      f[0]=0;f[1]=0;f[2]=0;f[3]=0;
      f[4]=0;f[5]=0;f[6]=0;f[7]=0;
      s[0]=s1+s2;s[1]=s2+s1;
      s[2]=r(s2)+s1;s[3]=s2+r(s1);
      s[4]=s1+r(s2);s[5]=r(s1)+s2;
      s[6]=r(s1)+r(s2);s[7]=r(s2)+r(s1);
      for(k=0;k<v.size();k++){
	for(l=0;l<8;l++)
	  if(s[l] == v[k]) f[l]=1;
      }
      for(k=1;k<8;k++)
	for(l=0;l<k;l++)
	  if(s[k]==s[l]) f[k]=1;
      
      for(l=0;l<8;l++)
	if(f[l]==0) v.push_back(s[l]);
    }
    cout << v.size() << endl;
  }
  return 0;
}
string r(string s){
  string b="";
  int i;
  for(i=0;i<s.size();i++) b += s[s.size()-i-1];
  return b;
}
