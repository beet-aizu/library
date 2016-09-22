#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main(){
  int h,w,n;
  int i,j,k;
  cin>>n;
  while(n--){
    cin >> h >> w;
    string st[60];
    for(i=0;i<h;i++) cin >> st[i];
    bool f=true;
    while(f){
      f=false;
      vector<char> v;
      for(i=0;i<h;i++){
	for(j=0;j<w;j++){
	  if(st[i][j]!='.'&&st[i][j]!='?') v.push_back(st[i][j]);
	}
      }
      for(k=0;k<v.size();k++){
	int r=0,l=w,u=h,d=0;
	for(i=0;i<h;i++){
	  for(j=0;j<w;j++){
	    if(st[i][j]==v[k]){
	      r=max(r,j);
	      l=min(l,j);
	      u=min(u,i);
	      d=max(d,i);
	    }
	  }
	}
	bool e = true;
	for(i=u;i<=d;i++){
	  for(j=l;j<=r;j++){
	    if(st[i][j]!=v[k]&&st[i][j]!='?') e =false;
	  }
	}
	if(!e) continue;
	f=true;
	for(i=u;i<=d;i++){
	  for(j=l;j<=r;j++){
	    st[i][j]='?';
	  }
	}
      }
      //for(i=0;i<h;i++) cout << st[i] << endl;
    }
    vector<char> v;
    for(i=0;i<h;i++){
      for(j=0;j<w;j++){
	if(st[i][j]!='.'&&st[i][j]!='?') v.push_back(st[i][j]);
      }
    }
    if(v.size()==0) cout << "SAFE" << endl;
    else cout << "SUSPICIOUS" << endl;
  }
  return 0;
}
