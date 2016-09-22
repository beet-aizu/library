#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#define mp(a,b) make_pair(a,b)
using namespace std;
int o;
int n;
int s2i(string str){
  stringstream ss(str);
  int x;
  ss >> x;
  return x;
}
void rec(string str[12]){
  bool f=false;
  bool used[10];
  char y;
  for(int i=0;i<10;i++) used[i]=false;
  vector<pair<int,int> > v;

  for(int j=0;j<=8;j++){
    for(int i=0;i<n;i++){
    //cout << str[i] << endl;
      int l=str[i].size()-1;
      if(j>l) continue;
      if(!f){
	if(str[i][l-j]<'0'||'9'<str[i][l-j]){
	  //cout << str[i][j]-'A' << endl;
	  y=str[i][l-j];
	  v.push_back(mp(i,l-j));
	  f=true;
	}else used[str[i][l-j]-'0']=true;
      }else{
	if(str[i][l-j]>='0'&&'9'>=str[i][l-j]) used[str[i][l-j]-'0']=true;
	if(str[i][l-j]==y) v.push_back(mp(i,l-j));
      }
    }
  }
  
  int sum=0;
  
  bool z=false;
  
  for(int i=0;i<n;i++){
    if(str[i][str[i].size()-1]<'0'||'9'<str[i][str[i].size()-1]) z=true;
    else sum+=str[i][str[i].size()-1]-'0';
  }
  
  if(!z){
    if((sum-2*(str[n-1][str[n-1].size()-1]-'0'))%10!=0) return;
  }
  
  
  string buf[12];
  for(int j=0;j<12;j++) buf[j]=str[j];
  if(f){
    for(int k=0;k<=9;k++){
      if(used[k]) continue;
      bool x=false;
      for(int j=0;j<v.size();j++){
	buf[v[j].first][v[j].second]='0'+k;
	if(k==0&&v[j].second==0&&str[v[j].first].size()>1) {
	  x=true;
	}
      }
      if(!x) rec(buf); 
    }
  }else{
    sum=0;
    for(int i=0;i<n-1;i++) sum+=s2i(str[i]);
    if(sum==s2i(str[n-1])) {
      o++;
      //for(int i=0;i<n;i++) cout << str[i] << endl;
    }
  }
  
}
int main(){
  cin >> n;
  while(n!=0){
    string str[12];
    for(int i=0;i<n;i++) cin >> str[i];
    o=0;
    rec(str);
    cout << o << endl;
    cin >> n;
  }
}
/*
  for(int i=0;i<n;i++){
    //cout << str[i] << endl;
    for(int j=str[i].size()-1;j>=0;j--){
      if(!f){
	if(str[i][j]<'0'||'9'<str[i][j]){
	  //cout << str[i][j]-'A' << endl;
	  y=str[i][j];
	  v.push_back(mp(i,j));
	  f=true;
	}else used[str[i][j]-'0']=true;
      }else{
	if(str[i][j]>='0'&&'9'>=str[i][j]) used[str[i][j]-'0']=true;
	if(str[i][j]==y) v.push_back(mp(i,j));
      }
    }
  }
  */
