#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef vector<P> D;
typedef map<ll,D> M;
typedef priority_queue<P,vector<P>,greater<P> > Q;
int main(){
  ll n,l,s,x,e;
  while(cin>>n,n){
    char c;
    M m;
    Q em;
    e=0;
    while(n--){
      D d;
      P p;
      cin >> c;
      if(c=='W'){
	cin >> l >> s;
	while(!em.empty()&&s>0){
	  p=em.top();em.pop();
	  x=p.second-p.first+1;
	  if(x<=s){
	    s-=x;
	    m[l].push_back(p);
	  }else{
	    m[l].push_back(P(p.first,p.first+s-1));
	    p.first+=s;
	    em.push(p);
	    s=0;
	  }
	}
	if(s>0){
	  p.first=e;p.second=p.first+s-1;
	  m[l].push_back(p);
	  e=p.second+1;
	}
      }
      if(c=='D'){
	cin>>l;
	for(int i=m[l].size()-1;i>=0;i--){
	  em.push(m[l][i]);
	}
	m[l].clear();
      }
      if(c=='R'){
	cin >> x;
	bool f=true;
	for(M::iterator it=m.begin();it!=m.end();++it){
	  l=it->first;d=it->second;
	  for(int i=0;i<d.size();i++){
	    p=d[i];
	    if(p.first<=x&&x<=p.second){
	      cout << l << endl;
	      f=false;
	      break;
	    }
	  }
	  if(!f) break;
	}
	if(f) cout << -1 << endl;
      }
    }
    cout << endl;
  }
  return 0;
}
