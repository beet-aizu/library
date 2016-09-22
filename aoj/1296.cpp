#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<queue>
using namespace std;
typedef pair<string,string> P;
typedef pair<int,string> C;
#define F first
#define S second
int main(){
  int n;
  int i,j,k;
  while(cin >> n,n){
    vector<P> v;
    P p;
    for(i=0;i<n;i++) {
      cin >> p.F >> p.S;
      v.push_back(p);
    }
    queue<C> q;
    C c,b;
    int o=-1;
    c.F=0;cin >> c.S;
    string s,g;cin >> g;
    q.push(c);
    while(!q.empty()){
      c=q.front();q.pop();
      //cout << c.F << c.S << endl;
      if(c.S==g){
	o=c.F;
	break;
      }
      if(c.S.size()>=g.size()) continue;
      for(i=0;i<n;i++){
	b.F=c.F+1;b.S=c.S;
	if(b.S.find(v[i].F)==-1) continue;
	int pos = b.S.find(v[i].F);
	while(pos != -1){
	  b.S.replace(pos, v[i].F.size(), v[i].S);
	  pos = b.S.find(v[i].F, pos + v[i].S.size());
	}
	q.push(b);
      }
    }
    cout << o << endl;
  }
  return 0;
}
