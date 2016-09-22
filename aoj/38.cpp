#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<algorithm>
using namespace std;
bool st(vector<int> v){
  if(
     v[1]+1==v[2]&&
     v[2]+1==v[3]&&
     v[3]+1==v[4]){
    if(v[0]+1==v[1]) return true;
    if(v[0]==1&&v[4]==13) return true;
  }
  return false;
}
int main(){
  string buf;
  int i,j,k;
  while(cin >> buf){
    vector<int> v,p;
    for(i=0;i<buf.size();i++) if(buf[i]==',') buf[i]=' ';
    stringstream ss(buf);
    for(i=0;i<5;i++){
      ss >> k;
      v.push_back(k);
    }
    sort(v.begin(),v.end());
    k=1;
    for(i=1;i<5;i++){
      //cout << v[i] << endl;
      if(v[i-1]==v[i]) k++;
      else {
	p.push_back(k);
	k=1;
      }
    }
    if(k!=1) p.push_back(k);
    sort(p.begin(),p.end(),greater<int>());
    //for(i=0;i<p.size();i++) cout << p[i] << endl;
    if(p[0]==4) cout << "four card" << endl;
    else if(p[0]==3&&p[1]==2) cout << "full house" << endl;
    else if(p[0]==3) cout << "three card" << endl;
    else if(p[0]==2&&p[1]==2) cout << "two pair" << endl;
    else if(p[0]==2) cout << "one pair" << endl;
    else if(st(v)) cout << "straight" << endl;
    else cout << "null" << endl;
  }

}
