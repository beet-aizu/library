#include<iostream>
#include<string>
#include<sstream>
#include<vector>
using namespace std;
struct node{
  int p;
  string s;
  vector<int> c;
  bool d;
};
int main(){
  int n,m;
  while(cin>>n>>m,n||m){
    vector<node> v;
    node no;
    no.p=-1;
    no.d=true;
    v.push_back(no);
    int i,j,k;
    string s,b;
    int p;
    k=1;
    for(i=0;i<n;i++){
      cin >> s;
      for(j=0;j<s.size();j++) {
	if(s[j]=='/') {
	  s[j]=' ';
	  
	}
      }
      stringstream ss(s);
      p=0;
      while(ss>>s){
	bool f =false;
	for(j=0;j<v[p].c.size();j++){
	  if(v[v[p].c[j]].s==s){
	    f=true;
	    v[p].d=true;
	    p=v[p].c[j];
	    break;
	  }
	}
	if(!f){
	  no.p=p;
	  no.s=s;
	  no.d=false;
	  v[p].d=true;
	  v[p].c.push_back(v.size());
	  p=v.size();
	  v.push_back(no);
	}
      }
    }
    
    //for(i=0;i<v.size();i++) cout <<i<< ":"<<(v[i].d?"d:":"f:")<<v[v[i].p].s<<"/"<<v[i].s<< endl;
    
    for(i=0;i<m;i++){
      string s1,s2;
      int id1=-1,id2=-1;
      cin >> s1 >> s2;
      
      bool d1=true,d2=true;;
      
      for(j=0;j<s1.size();j++){
	if(s1[j]=='/') {
	  s1[j]=' ';
	  if(j==s1.size()-1){
	    s1+="index.html";
	    d1=false;
	  }
	}
      }
      for(j=0;j<s2.size();j++) {
	if(s2[j]=='/'){
	  s2[j]=' ';
	  if(j==s2.size()-1){
	    s2+="index.html";
	    d2=false;
	  }
	}
      }
      bool nf=false;
      
      stringstream ss1(s1);
      p=0;
      while(ss1>>s1){
	nf=true;
	if(p==-1) break;
	if(s1==".") {
	  nf=false;
	  continue;
	}
	if(s1=="..") {
	  if(v[p].d){
	    nf=false;
	    p=v[p].p;
	    continue;
	  }else{
	    nf=true;
	    break;
	  }
	}
	for(j=0;j<v[p].c.size();j++){
	  if(v[v[p].c[j]].s==s1){
	    nf=false;
	    p=v[p].c[j];
	    break;
	  }
	}
	if(nf) break;
      }
      if(!nf) id1=p;

      stringstream ss2(s2);
      p=0;
      while(ss2>>s2){
	nf=true;
	if(p==-1) break;
	if(s2==".") {
	  nf=false;
	  continue;
	}
	if(s2=="..") {
	  if(v[p].d){
	    nf=false;
	    p=v[p].p;
	    continue;
	  }else{
	    nf=true;
	    break;
	  }
	}
	for(j=0;j<v[p].c.size();j++){
	  if(v[v[p].c[j]].s==s2){
	    nf=false;
	    p=v[p].c[j];
	    break;
	  }
	}
	if(nf) break;
      }
      
      if(!nf) id2=p;
      if(id1==-1||id2==-1) nf=true;
      else{
	if(!d1&&v[id1].d) nf=true;
	if(!d2&&v[id2].d) nf=true;

	if(v[id1].d){
	  bool ff=true;
	  for(j=0;j<v[id1].c.size();j++){
	    if(v[v[id1].c[j]].s=="index.html"&&!v[v[id1].c[j]].d) ff = false;
	  }
	  if(ff) nf=true;
	}
	
	if(v[id2].d){
	  bool ff=true;
	  for(j=0;j<v[id2].c.size();j++){
	    if(v[v[id2].c[j]].s=="index.html"&&!v[v[id2].c[j]].d) ff = false;
	  }
	  if(ff) nf=true;
	}
	
      }
      
      //cout << id1 << ":"<<id2 << endl;
      if(nf) cout << "not found" << endl;
      else if(id1==id2) cout << "yes" << endl;
      else if(d2&&v[id1].s=="index.html"&&v[id1].p==id2) cout << "yes" << endl;
      else if(d1&&v[id2].s=="index.html"&&v[id2].p==id1) cout << "yes" << endl;
      else cout << "no" << endl;
      
    }
  }
  return 0;
}
