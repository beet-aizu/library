#include<bits/stdc++.h>
using namespace std;
int main(){
  int i,j,k;
  while(cin>>k,k){
    string s,e;
    cin >> s>>e;
    typedef pair<string,int> P;
    set<string> m;
    P p;
    queue<P> q;
    q.push(P(s,0));
    int ans=k;
    while(!q.empty()){
      p=q.front();q.pop();
      s=p.first;
      if(s==e){
	ans=min(ans,p.second);
	break;
      }
      i=0;
      while(s[i]==e[i]) i++;
      int x=e[i]-s[i];
      bool f=false;
      for(j=i;j<k;j++){
	s[j]='0'+((s[j]-'0'+x+10)%10);
	if(m.find(s)==m.end()){
	  m.insert(s);
	  q.push(P(s,p.second+1));
	}
      }
    }
    cout << ans << endl;
  }
  return 0;
}
