#include<iostream>
#include<queue>
#include<map>
#define S second
#define F first
using namespace std;
typedef pair<int,pair<int,pair<int,int> > > P;
int main(){
  int inf = 1<<20;
  int n,m,l,k,a,h;
  cin >> n >> m >> l >> k >> a >> h;
  while(n!=0){
    int i,j;
    int ma[105][105]={{}};
    fill(ma[0],ma[104],inf);
    int aa,b,c;
    bool ref[105];
    for(i=0;i<n;i++) ref[i]=false;
    for(i=0;i<l;i++){
      cin >> aa;
      ref[aa]=true;
    }
    for(i=0;i<k;i++){
      cin >> aa >> b >> c;
      ma[aa][b]=c;
      ma[b][aa]=c;
    }
    int d[105][105]={};
    fill(d[0],d[104],inf);
    P p,r;
    priority_queue <P,vector<P>,greater<P> > q;
    d[a][m]=0;
    p.F=0;p.S.F=a;p.S.S.F=m;p.S.S.S=0;
    q.push(p);
    int o=inf;;
    while(!q.empty()){
      p=q.top();q.pop();
      //cout << p.F<<":"<<p.S.F<<":"<<p.S.S<<endl;
      if(d[p.S.F][p.S.S.F]<p.F) continue;
      if(p.S.F==h) {
	o=min(o,p.F);
	if(p.S.S.S>0) o=min(o,p.F-min(p.S.S.F,p.S.S.S));
	continue;
      }
      for(i=0;i<n;i++){
	if(p.S.S.F>=ma[p.S.F][i]){
	  if(d[p.S.F][p.S.S.F]+ma[p.S.F][i]<d[i][p.S.S.F-ma[p.S.F][i]]){
	    d[i][p.S.S.F-ma[p.S.F][i]]=d[p.S.F][p.S.S.F]+ma[p.S.F][i];
	    r.F=d[i][p.S.S.F-ma[p.S.F][i]];
	    r.S.F=i;
	    r.S.S.F=p.S.S.F-ma[p.S.F][i];
	    r.S.S.S=p.S.S.S;
	    q.push(r);
	  }
	}
	if(ref[p.S.F]){
	  //cout << i << endl;
	  //for(j=1;p.S.S+j<=m;j++){
	  j=m-p.S.S.F;
	    if(p.S.S.F+j>=ma[p.S.F][i]){
	      if(d[p.S.F][p.S.S.F]+j+ma[p.S.F][i]<d[i][p.S.S.F+j-ma[p.S.F][i]]){
		d[i][p.S.S.F+j-ma[p.S.F][i]]=d[p.S.F][p.S.S.F]+j+ma[p.S.F][i];
		r.F=d[i][p.S.S.F+j-ma[p.S.F][i]];
		r.S.F=i;
		r.S.S.F=p.S.S.F+j-ma[p.S.F][i];
		r.S.S.S=p.S.S.S+j;
		q.push(r);
	      }
	    }
	    //} 
	}
      }
    }
    
    if(o==inf) cout << "Help!" << endl;
    else cout << o << endl;
    cin >> n >> m >> l >> k >> a >> h;
  }
  return 0;
}
