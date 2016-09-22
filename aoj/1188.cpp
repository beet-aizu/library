#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int o=0;
string i2s(int k){
  stringstream ss;
  ss << k;
  return ss.str();
}
int s2i(string s){
  istringstream iss(s);
  int x;
  iss >> x;
  return x;
}
void rec(string str){
  //cout << str << endl;
  int i=0,op=0,f=0;
  string buf,next,num;
  vector <int> v;
  while(i<str.size()){
    if(str[i]=='['){
      op++;
      if(str[i+1]=='[') next+="[";
    }else if(str[i]==']'){
      if(f==1){
	//cout << (s2i(num)+1)/2 <<endl;
	v.push_back((s2i(num)+1)/2);
	//cout << v.size() << endl;
	num="";
	f=0;
      }else{
	int k=0;
	sort(v.begin(),v.end());
	//cout << v.size() << endl;
	for(int i=0;i<(v.size()+1)/2;i++){
	  k+=v[i];
	  //cout << k << ":";
	}
	k*=2;
	//cout << i2s(k) << endl;
	if(k!=0)
	  next+=i2s(k);
	next+="]";
	v.clear();
      }
    }else{
      num+=str[i];
      f=1;
    }
    i++;
  }
  //cout << next << endl;
  if(op==1) o=s2i(str.substr(1,str.size()-2))/2;
  else rec(next);
}

int main(){
  int n,i;
  cin >> n;
  for(i=0;i<n;i++){
    string str;
    cin >> str;
    rec(str);
    cout << o << endl;
  }
}
