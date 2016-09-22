#include<iostream>
#include<string>
using namespace std;
int main(){
  string str;
  while(cin >> str){
    string st[8];
    st[0]=str;
    int i,j;
    for(i=1;i<8;i++) cin >> st[i];

    //for(i=0;i<8;i++) cout << st[i] << endl;
    //cout << endl;
    char o='0';
    for(i=0;i<8;i++){
      for(j=0;j<8;j++){
	if(st[i][j]=='1'){
	  if(j<7&&i<7){
	    if(st[i][j]=='1'&&
	       st[i+1][j]=='1'&&
	       st[i][j+1]=='1'&&
	       st[i+1][j+1]=='1'){
	      o='A';
	      break;
	    }
	  }
	  if(i<5){
	    if(st[i][j]=='1'&&
	       st[i+1][j]=='1'&&
	       st[i+2][j]=='1'&&
	       st[i+3][j]=='1'){
	      o='B';
	      break;
	    }  
	  }
	  if(j<5){
	    if(st[i][j]=='1'&&
	       st[i][j+1]=='1'&&
	       st[i][j+2]=='1'&&
	       st[i][j+3]=='1'){
	      o='C';
	      break;
	    }
	  }
	  if(0<j&&i<6){
	    if(st[i][j]=='1'&&
	       st[i+1][j]=='1'&&
	       st[i+1][j-1]=='1'&&
	       st[i+2][j-1]=='1'){
	      o='D';
	      break;
	    }
	  }
	  if(j<6&&i<7){
	    if(st[i][j]=='1'&&
	       st[i][j+1]=='1'&&
	       st[i+1][j+1]=='1'&&
	       st[i+1][j+2]=='1'){
	      o='E';
	      break;
	    }
	  }
	  if(j<8&&i<6){
	    if(st[i][j]=='1'&&
	       st[i+1][j]=='1'&&
	       st[i+1][j+1]=='1'&&
	       st[i+2][j+1]=='1'){
	      o='F';
	      break;
	    }
	  
	  }
	  if(j<8&&i<8){
	    if(st[i][j]=='1'&&
	       st[i][j+1]=='1'&&
	       st[i+1][j]=='1'&&
	       st[i+1][j-1]=='1'){
	      o='G';
	      break;
	    }
	  }
	}	
      }
    }
    cout << o << endl;
    //cin >> str;
  }
  return 0;
}
