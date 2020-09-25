// verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2448
// verification-helper: ERROR 1e-6

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../../geometry/geometry.cpp"
#include "../../../tools/fixpoint.cpp"
#undef call_from_test

signed main(){
  int n;
  cin>>n;
  Polygon ps(n);
  cin>>ps;
  vector<Segment> ss(n-1);
  for(int i=0;i+1<n;i++){
    ss[i].p1=ps[i];
    ss[i].p2=ps[i+1];
  }
  Polygon qs;
  auto G=segmentArrangement(ss,qs);

  int m=qs.size();
  int s=0;
  for(int i=0;i<m;i++)
    if(qs[i]<qs[s]) s=i;


  auto calc=[&](Vector a,Vector b){
              double th=acos(max(-1.0,min(1.0,dot(a,b)/abs(a)/abs(b))));
              if(cross(a,b)<-EPS) th=2*PI-th;
              return th;
            };
  double ans=0;
  for(int t:G[s]){

    Polygon res;
    res.emplace_back(qs[s]);

    MFP([&](auto dfs,int v,int p)->void{
          if(v==s) return;
          int z=G[v][0];
          for(int u:G[v]){
            double a1=calc(qs[p]-qs[v],qs[z]-qs[v]);
            if(z==p) a1=8;
            double a2=calc(qs[p]-qs[v],qs[u]-qs[v]);
            if(u==p) a2=8;
            if(a1>a2) z=u;
          }
          res.emplace_back(qs[v]);
          dfs(z,v);
        })(t,s);

    ans+=max(0.0,area(res));
  }
  cout<<fixed<<setprecision(12)<<ans<<endl;
  return 0;
}
