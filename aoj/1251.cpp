#include<iostream>
#include<string>
#include<sstream>
#include<map>
#include<vector>
using namespace std;
struct node{
  int id;
  string p,v;
  vector<string> c;
};
int main(){
  int n,m;
  while(cin>>n>>m,n||m){
    map<string,node> ma;
    node no;
    no.p="-2";
    no.v="-1";
    ma["-1"]=no;
    int i,j,k;
    string s,b;
    k=0;
    for(i=0;i<n;i++){
      cin >> s;
      for(j=0;j<s.size();j++) if(s[j]=='/') s[j]=' ';
      stringstream ss(s);
      b="-1";
      while(ss>>s){
	if(b!="-1"){
	  ma[b].c.push_back(s);
	}else{
	  ma["-1"].c.push_back(s);
	}
	
	if(ma.find(s)==ma.end()){
	  no.p=b;
	  no.v=s;
	  no.id=k;
	  k++;
	  ma[s]=no;
	}
	cout << s << ":"<<ma[s].id<<"/";
	b=s;
      }
      cout << endl;
    }
    
    for(i=0;i<m;i++){
      string s1,s2;
      int id1=-1,id2=-1;
      cin >> s1 >> s2;
      for(j=0;j<s1.size();j++) if(s1[j]=='/') s1[j]=' ';
      for(j=0;j<s2.size();j++) if(s2[j]=='/') s2[j]=' ';
      bool nf=false;
      stringstream ss1(s1);
      node now;
      string b="-1";
      while(ss1>>s1){
	nf=true;
	for(j=0;j<ma[b].c.size();j++){
	  if(ma[b].c[j]==s1){
	    nf=false;
	    break;
	  }
	}
	if(nf) break;
	b=s1;
      }
      if(!nf) id1=ma[s1].id;
      b="-1";
      stringstream ss2(s2);
      while(ss2>>s2){
	nf=true;
	for(j=0;j<ma[b].c.size();j++){
	  if(ma[b].c[j]==s2){
	    nf=false;
	    break;
	  }
	}
	if(nf) break;
	b=s2;
      }
      if(!nf) id2=ma[s2].id;
      cout << id1 << ":"<<id2 << endl;
      if(nf) cout << "not found" << endl;
      else cout << "found" << endl;
    }
  }
  return 0;
}
