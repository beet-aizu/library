#include<bits/stdc++.h>
using namespace std;
map<string,int> m;
int s2i(string s){
  stringstream ss(s);
  int x;ss>>x;
  return x;
}
string i2s(int x){
  stringstream ss;
  ss<<x;
  return ss.str();
}
int calc(string s){
  //cout << s << endl;
  int res=0,j;
  string key,n;
  for(int i=0;i<s.size();i++){
    //cout << i << endl;
    if(isdigit(s[i])){
      n=s[i];
      i++;
      while(i<s.size()&&isdigit(s[i])){
	n+=s[i];
	i++;
      }
      if(i<s.size()&&s[i]==','){
	//cout << n << endl;
	res+=s2i(n);
      }
      i--;
    }else if('A'<=s[i]&&s[i]<='Z'){
      key=s[i];
      j=i+1;
      if(j<s.size()&&'a'<=s[j]&&s[j]<='z'){
	key+=s[j];
	j++;
      }
      
      if(m[key]==0) return -1;
      //cout << key << ":" << m[key] << endl;;
      n="";
      while(j<s.size()&&isdigit(s[j])){
	n+=s[j];
	j++;
      }
      if(j<s.size()&&s[j]==','){
	res+=m[key];
      }else{
	if(n=="") res+=m[key];
	else res+=m[key]*s2i(n);
      }
    }
    //cout << res << endl;
  }
  return res;
}
int main(){
  string s,b,n;
  int x;
  int i,j,k;
  while(cin>>s,s!="END_OF_FIRST_PART"){
    cin >> x;
    m[s]=x;
  }
  while(cin>>s,s!="0"){
    //cout << s << endl;
    bool f=true;
    int ans=0;
    bool ff=true;
    while(ff){
      
      ff=false;
      int o=0,m=0;
      for(i=0;i<s.size();i++){
	if(s[i]=='(') o++;
	if(s[i]==')') o--;
	m=max(m,o);
      }
      if(m==0){
	ans=calc(s);
	f=true;
	break;
      }
      for(i=0;i<s.size();i++){
	if(s[i]=='(') o++;
	if(s[i]==')') o--;
	if(o==m){
	  b="";
	  j=i;
	  i++;
	  while(s[i]!=')'){
	    b+=s[i];
	    i++;
	  }
	  x=calc(b);
	  if(x==-1) {
	    f=false;
	    break;
	  }
	  //s.replace(j+1,i-j-1,i2s(calc(b)));
	  o--;
	  n="";
	  if(i+1<s.size()&&isdigit(s[i+1])) i++;
	  while(i<s.size()&&isdigit(s[i])){
	    n+=s[i];
	    i++;
	  }
	  //cout << calc(b) << endl;
	  //cout << x << endl;
	  if(n=="") s.replace(j,i-j,"."+i2s(x)+",");
	  else s.replace(j,i-j,"."+i2s(x*s2i(n))+",");
	  ff=true;
	  break;
	}
	if(!f) break;
      }
      //cout << s << endl;
      if(!f) break;
    }
    if(f&&ans>0) cout << ans << endl;
    else cout << "UNKNOWN" << endl;
  }
  return 0;
}
