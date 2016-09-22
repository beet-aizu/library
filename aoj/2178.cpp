#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  while(cin>>n,n){
    typedef pair<int,int> P;
    typedef pair<P,char> PP;
    map<PP,int> m;
    map<int,PP> r;
    set<PP> p;
    vector<PP> v;
    int i,j,k,x,y;
    char d;
    for(i=0;i<n;i++){
      cin>>x>>y>>d;
      p.insert(PP(P(x,y),d));
      m[PP(P(x,y),d)]=i;
      r[i]=PP(P(x,y),d);
      v.push_back(PP(P(x,y),d));
    }
    bool f=true;
    bool u[n];
    memset(u,0,sizeof(u));
    
    for(i=0;i<n;i++){

    }
    cout << (f?"Yes":"No") << endl;
  }
  return 0;
}
