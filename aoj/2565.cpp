#include<iostream>
#include<string>
#include<sstream>
using namespace std;
int s2i(string str){
  istringstream ss(str);
  int n;
  ss >> n;
  return n;
}
int main(){
  int n;
  cin >> n;
  int i,j,k;
  string str;
  while(n!=0){
    int b,c;
    int f=0;
    int o=0;
    int xmin=-1000000010,xmax=1000000010;
    cin >> str;
    if(str=="x"){
      f=1;
    }else{
      b=s2i(str);
    }
    for(i=1;i<n;i++){
      cin >> str;
      if(str=="x"){
	if(f==1) o=1;
	else {
	  if(i%2==0){
	    xmax=min(xmax,b-1);
	  }else{
	    xmin=max(xmin,b+1);
	  }
	  f=1;
	}
      }else{
	c=s2i(str);
	if(f==0){
	  if(i%2==0){
	    if(b<=c) o=1;
	  }else{
	    if(b>=c) o=1;
	  }
	  b=c;
	}else{
	  if(i%2==1){
	    xmax=min(xmax,c-1);
	  }else{
	    xmin=max(xmin,c+1);
	  }
	  f=0;
	  b=c;
	}
      }
    }
    //cout << xmax << ":" << xmin << endl;
    if(o==1){
      cout << "none" << endl;
    }else if(xmax-xmin>0){
      cout << "ambiguous" << endl;
    }else if(xmax-xmin==0){
      cout << xmax << endl;
    }else{
      cout << "none" << endl;
    }
    cin >> n;
  }
  return 0;
}
