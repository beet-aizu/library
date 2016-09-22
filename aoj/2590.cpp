#include<iostream>
#include<string>
using namespace std;
int main(){
  int n,m,q;
  cin >> n >> m >> q;
  int i,j,k;
  string s,b;
  while((n+m+q)!=0){
    int table[1001][40]={{}};
    fill(table[0],table[1001],1);
    int onoff[40]={};
    
    for(i=0;i<q;i++){
      cin >> s >> b;
      for(j=0;j<n;j++){
	if(s[j]=='1') {
	  if(onoff[j]==0) onoff[j]=1;
	  else onoff[j]=0;
	}
      }
      int c=0,x;
      /*
      for(j=0;j<n;j++){
	c+=onoff[j];
	if(onoff[j]==1) x=j;
      }
      if(c==1){
	for(j=0;j<m;j++){
	  if(b[j]=='1'){
	    for(k=0;k<n;k++){
	      if(k!=x) table[j][k]=1;
	    }
	  }
	}
      }
      */
      for(j=0;j<m;j++){
	if(b[j]=='1'){
	  for(k=0;k<n;k++){
	    /*
	    if(table[j][k]==0){
	      if(onoff[k]==1)
		table[j][k]=1;
	    }
	    */
	    table[j][k]*=onoff[k];
	  }
	}else{
	  for(k=0;k<n;k++){
	    //cout << j << " " << k << endl;
	    if(onoff[k]==1)
	    table[j][k]=0;
	  }
	}
      }
      /*
      int ch[1001]={},id[40]={};
      for(j=0;j<m;j++){
	for(k=0;k<n;k++){
	  if(table[j][k]==1) ch[j]++;
	  if(table[j][k]==0) id[j]=k;
	}
      }
      for(j=0;j<m;j++){
	if(ch[j]+1==n){
	  //cout <<"a"<< endl;
	  for(k=0;k<m;k++){
	    if(ch[k]+1!=n){
	      table[k][id[j]]=1;
	    }
	  }
	}
      }
      */
      
    }

    for(j=0;j<m;j++){
      /*
	int c=0,id;
	for(k=0;k<n;k++){
	  if(table[j][k]==1) c++;
	  if(table[j][k]==0) id=k;
	}
	char buf;
	if(c+1==n){
	  if(id<10) buf=id+'0';
	  else buf='A'+id-10;
	}else{
	  buf='?';
	}
	cout << buf;
      */
      int c=0,id;
      for(k=0;k<n;k++){
	c+=table[j][k];
	if(table[j][k]==1) id=k;
      }
      char buf;
      if(c==1){
	if(id<10) buf=id+'0';
	else buf='A'+id-10;
      }else{
	buf='?';
      }
      cout << buf;
    }
    cout << endl;
    cin >> n >> m >> q;
  }
  return 0;
}
