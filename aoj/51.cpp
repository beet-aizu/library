#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
  int n;cin >> n;
  while(n--){
    string s;cin >> s;
    vector<int> v;
    for(int i=0;i<s.size();i++){
      v.push_back(s[i]-'0');
    }
    int a=0,x=0;
    sort(v.begin(),v.end());
    for(int i=0;i<v.size();i++){
      x*=10;
      x+=v[i];
    }
    sort(v.begin(),v.end(),greater<int>());
    for(int i=0;i<v.size();i++){
      a*=10;
      a+=v[i];
    }
    cout << a-x << endl;
  }
}
