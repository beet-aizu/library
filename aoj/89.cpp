#include<iostream>
#include<string>
#include<sstream>
#include<vector>
using namespace std;
int main(){
  vector<vector<int> > vv;
  vector<int>v;
  string str;
  int i,j,k;
  while(getline(cin,str)){
    v.clear();
    for(i=0;i<str.size();i++) if(str[i]==',') str[i]=' ';
    stringstream ss(str);
    while(ss>>k) v.push_back(k);
    vv.push_back(v);
  }
  int dp[100][100]={{}};
  dp[0][0]=vv[0][0];
  for(i=0;i<vv.size()-1;i++){
    for(j=0;j<vv[i].size();j++){
      dp[i+1][j]=max(dp[i+1][j],dp[i][j]+vv[i][j]);
      dp[i+1][j+1]=max(dp[i+1][j],dp[i][j]+vv[i][j]);
    }
  }
  return 0;
}
