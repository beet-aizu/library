#include<iostream>
#include<string>
#include<vector>
#include<sstream>
using namespace std;
string s="true";
string i2s(int n){
  stringstream x;
  x<<n;
  return x.str();
}
bool calc(int a,int b){
  if(a+b==10) {
    s+="+";
    return true;
  }
  if(a-b==10){
    s+="-";
    return true;
  }
  if(a*b==10) {
    s+="*";
    return true;
  }
  return false;
}
bool calc(int a,int b, int c){
  if(calc(a+b,c)) {
    s+="0+";
    return true;
  }
  if(calc(a-b,c)) {
    s+="0-";
    return true;
  }
  if(calc(a*b,c)) {
    s+="0*";
    return true;
  }
  if(calc(a,b+c)) {
    s+="1+";
    return true;
  }
  if(calc(a,b-c)) {
    s+="1-";
    return true;
  }if(calc(a,b*c)) {
    s+="1*";
    return true;
  }
  
  return false;
}

bool calc(int a,int b, int c, int d){
  
  if(calc(a+b,c,d)) {
    s+="0+";
    return true;
  }
  if(calc(a-b,c,d)) {
    s+="0-";
    return true;
  }
  if(calc(a*b,c,d)) {
    s+="0*";
    return true;
  }
  if(calc(a,b+c,d)) {
    s+="1+";
    return true;
  }
  if(calc(a,b-c,d)){
    s+="1-";
    return true;
  }
  if(calc(a,b*c,d)) {
    s+="1*";
    return true;
  }
  if(calc(a,b,c+d)) {
    s+="2+";
    return true;
  }
  if(calc(a,b,c-d)) {
    s+="2-";
    return true;
  }
  if(calc(a,b,c*d)){
    s+="2*";
    return true;
  }
  
  return false;
}
int main(){
  int a[4];
  while(cin>>a[0]>>a[1]>>a[2]>>a[3],a[0]||a[1]||a[2]||a[3]){
    int i,j,k,l;
    int bi,bj,bk,bl;
    bool f=false;
    s="";
    for(i=0;i<4;i++){
      for(j=0;j<4;j++){
	for(k=0;k<4;k++){
	  for(l=0;l<4;l++){
	    if(i==j||i==k||i==l||j==k||j==l||k==l) continue;
	    if(calc(a[i],a[j],a[k],a[l])){
	      bi=i;bj=j;bk=k;bl=l;
	      f=true;
	      break;
	    }
	  }
	  if(f) break;
	}
	if(f) break;
      }
      if(f) break;
    }
    if(f){
      //cout << s << endl;
      //cout << a[bi] << a[bj] << a[bk] << a[bl] << endl;
      vector<string> b;
      b.push_back(i2s(a[bi]));b.push_back(i2s(a[bj]));
      b.push_back(i2s(a[bk]));b.push_back(i2s(a[bl]));
      
      string o="";
      o+="(";
      o+=(b[s[3]-'0']);
      o+=s[4];
      o+=(b[s[3]-'0'+1]);
      o+=")";
      b[s[3]-'0']=o;
      b.erase(b.begin()+(s[3]-'0')+1);
      o="";
      o+="(";
      o+=(b[s[1]-'0']);
      o+=s[2];
      o+=(b[s[1]-'0'+1]);
      o+=")";
      b[s[1]-'0']=o;
      b.erase(b.begin()+(s[1]-'0')+1);
      o="";
      o+="(";
      o+=(b[0]);
      o+=s[0];
      o+=(b[1]);
      o+=")";
      b[0]=o;
      b.erase(b.begin()+1);
      cout << b[0] << endl;
    }
    else cout << 0 << endl;
  }
  return 0;
}
