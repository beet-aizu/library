#include<iostream>
#include<vector>
#include<map>
#include<queue>
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
#define MAX 100005
int main(){
  int n,m,s,t,di;
  cin >> n >> m >> s >> t;
  int i,j,k;
  vector<int> v[MAX];
  ll d[MAX]={},d2[MAX]={};
  for(i=0;i<m;i++){
    cin >> j >> k;
    v[j].push_back(k);
    v[k].push_back(j);
  }

  bool used[MAX]={},used2[MAX]={};
  queue<P> q;
  P p,b;
  p.first=s;
  p.second=0;
  q.push(p);
  while(!q.empty()){
    p=q.front();q.pop();
    if(used[p.first]) continue;
    //cout << p.first << ":" << p.second << endl;
    if(p.first==t) di=p.second;
    used[p.first]=true;
    d[p.second]++;
    b.second=p.second+1;
    for(i=0;i<v[p.first].size();i++){
      b.first=v[p.first][i];
      q.push(b);
    }
  }
  p.first=t;
  p.second=0;
  q.push(p);
  while(!q.empty()){
    p=q.front();q.pop();
    if(used2[p.first]) continue;
    //cout << p.first << ":" << p.second << endl;
    used2[p.first]=true;
    d2[p.second]++;
    b.second=p.second+1;
    for(i=0;i<v[p.first].size();i++){
      b.first=v[p.first][i];
      q.push(b);
    }
  }
  
  //cout << di << endl;
  ll o=0;
  
  for(i=0;i<di-1;i++){
    o+=d[i]*d2[di-2-i];
  }
  
  cout << o << endl;
  return 0;
}
