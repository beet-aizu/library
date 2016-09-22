#include<iostream>
#include<vector>
using namespace std;
int main(){
  int h;
  cin >> h;
  while(h!=0){
    vector <int> lines[5];
    int b[10][5];
    int i,j,k;
    for(i=0;i<h;i++){
      for(j=0;j<5;j++){
	cin >> b[i][j];
      }
    }
    for(i=h-1;i>=0;i--){
      for(j=0;j<5;j++){
        lines[j].push_back(b[i][j]);
      }
    }
    
    int o=0;
    int f=0,ba,l;
    while(f==0){
      
      k=0;
      
      for(i=0;i<5;i++) k+=lines[i].size();
      
      for(i=h-1;i>=0;i--){
	l=0;
	ba=0;
	for(j=0;j<5;j++){
	  if(lines[j].size()>i){
	    if(ba==0){
	      ba=lines[j][i];
	      l=1;
	    }else if(ba==lines[j][i]){
	      l++;
	    }else{
	      if(l>=3){
		o+=ba*l;
		for(int a=1;a<=l;a++) lines[j-a].erase(lines[j-a].begin()+i);
	      }
	      ba=lines[j][i];
	      l=1;
	    }
	  }else{
	    ba=0;
	    l=0;
	  }
	}
	
	if(l>=3){
	  o+=ba*l;
	  for(int a=0;a<l;a++) lines[4-a].erase(lines[4-a].begin()+i);
	}	
	
      }
      for(i=0;i<5;i++) k-=lines[i].size();
      if(k==0) f=1;
    }
    
    cout << o << endl;
    cin >> h;
  }
  return 0;
}
