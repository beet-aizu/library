#include<iostream>
#include<vector>
#include<map>
#include<queue>
using namespace std;
typedef pair<int,int> P;
int n;
int p[100005];
int m[100005];
/*
vector<int> v;
int dfs(int x){
  for(int i=0;i<v.size();i++) if(v[i]==x) return -2;
  v.push_back(x);
  if(p[x]==0) return (m[x]=x);
  if(m[x]!=-1) return m[x];
  return (m[x]=dfs(x+p[x]));
}
*/
int main(){
  cin >> n;
  int i,j,k;
  fill(p,p+100005,0);
  for(i=0;i<n;i++) cin >> p[i];

  /*
  fill(m,m+100005,-1);
  for(i=0;i<n;i++){
    if(m[i]==-1){
      v.clear();
      m[i]=dfs(i);
    }
  }
  */
  
  int d[100005];
  int inf = 1 << 20;
  fill(d,d+100005,inf);

  queue<P> q;
  P a;
  q.push(P(0,0));
  while(!q.empty()){
    a=q.front();q.pop();
    if(a.first<0) continue;
    //cout << a.first << ":" << a.second << endl;
    if(d[a.first]<=a.second) continue;
    d[a.first]=a.second;
    if(p[a.first]==0){
      if(a.first+6>n) {
	d[n-1]=min(d[n-1],a.second+1);
	continue;
      }
      for(i=1;i<=6;i++){
	q.push(P(a.first+i,a.second+1));
      }
    }else{
      q.push(P(a.first+p[a.first],a.second));
    }
    
  }

  cout << d[n-1] << endl;
  //for(i=1;i<=n;i++) cout << m[i] << endl;

  return 0;
}
