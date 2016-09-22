#include<iostream>
#include<map>
using namespace std;
typedef pair<int,int> P;
#define X first
#define Y second
int main(){
  int n;cin>>n;
  map<P,int> m;
  P p;
  int i,j,k;
  int w;
  for(i=0;i<n;i++){
    cin >> p.X >> p.Y >> w;
    m[p]+=w;
  }
  int o=0;
  for(map<P,int>::iterator it=m.begin();it!=m.end();++it){
    p=it->first;
    w=it->second;
    //cout << p.X << p.Y << w << endl;
    k=0;
    k+=w;
    p.X++;
    if(m.find(p)!=m.end())
       k+=m[p];
    p.Y++;
    if(m.find(p)!=m.end())
      k+=m[p];
    p.X--;
    if(m.find(p)!=m.end())
      k+=m[p];
    o=max(o,k);
    p=it->first;
    k=0;
    k+=w;
    p.X--;
    if(m.find(p)!=m.end())
       k+=m[p];
    p.Y++;
    if(m.find(p)!=m.end())
      k+=m[p];
    p.X++;
    if(m.find(p)!=m.end())
      k+=m[p];
    o=max(o,k);
    p=it->first;
    k=0;
    k+=w;
    p.X++;
    if(m.find(p)!=m.end())
       k+=m[p];
    p.Y--;
    if(m.find(p)!=m.end())
      k+=m[p];
    p.X--;
    if(m.find(p)!=m.end())
      k+=m[p];
    o=max(o,k);
  }
  cout << o << " / 1" << endl;
  return 0;
}
