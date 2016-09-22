#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main(){
  string s;
  int i,j,k;
  while(cin>>s){
    vector<int> v;
    for(i=0;i<13;i++) v.push_back(s[i]-'0');
    bool fi =true;
    for(i=1;i<10;i++){
      bool f=true;
      vector<int> c(v);
      c.push_back(i);
      int d[10]={};
      for(j=0;j<14;j++) d[c[j]]++;
      for(j=0;j<10;j++) {
	//cout << j+1 <<":"<<d[j]<<endl;
	if(d[j]>4) f=false;
      }
      bool r=true;
      while(r){
	r=false;
	for(j=1;j<8;j++) {
	  if(d[j]==1){
	    if(d[j+1]>0&&d[j+2]>0){
	      d[j]--;d[j+1]--;d[j+2]--;
	      r=true;
	    }
	  }
	}
	for(j=2;j<9;j++) {
	  if(d[j]==1){
	    if(d[j-1]>0&&d[j+1]>0){
	      d[j]--;d[j+1]--;d[j-1]--;
	      r=true;
	    }
	  }
	}
	for(j=3;j<10;j++) {
	  if(d[j]==1){
	    if(d[j-1]>0&&d[j-2]>0){
	      d[j]--;d[j-1]--;d[j-2]--;
	      r=true;
	    }
	  }
	}
      }
      for(j=1;j<10;j++) {
	if(d[j]==3) d[j]=0;
      }
      cout << i << endl;
      for(j=1;j<10;j++) cout << j <<":"<<d[j]<<endl;
      k=0;
      for(j=1;j<10;j++)k+=d[j];
      if(k!=2) f=false;
      
      if(f) {
	if(fi){
	  cout << i;
	  fi=false;
	}else cout << " " << i;
      }
      
    }
    cout << endl;
  }
  return 0;
}
