#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "zalgorithm.cpp"
#undef call_from_test

#endif
//BEGIN CUT HERE
namespace Run{
  using T = tuple<int, int, int>;
  using P = pair<int, int>;
  vector<vector<P>> run;

  template<typename C>
  vector<T> sub(const vector<C> &xs,const vector<C> &ys){
    auto ps=xs;
    auto qs=ys;
    reverse(ps.begin(),ps.end());
    qs.insert(qs.end(),xs.begin(),xs.end());
    qs.insert(qs.end(),ys.begin(),ys.end());
    auto zp=zalgorithm(ps);
    auto zq=zalgorithm(qs);
    vector<T> res;
    for(int i=0;i<(int)xs.size();i++){
      int a=xs.size()-i;
      int b=i-zp[a];
      int c=max(0,(int)ys.size()-zq[ys.size()+i]);
      if((int)(xs.size()+ys.size())-b-c>=2*a)
        res.emplace_back(a,b,c);
    }
    return res;
  }

  template<typename C>
  void dfs(int l,int r,const vector<C> &cs){
    if(l+1>=r) return;
    int m=(l+r)>>1;
    vector<C> xs(cs.begin()+l,cs.begin()+m);
    vector<C> ys(cs.begin()+m,cs.begin()+r);
    {
      auto zs=sub(xs,ys);
      for(auto w:zs){
        int a,b,c;
        tie(a,b,c)=w;
        run[a].emplace_back(l+b,r-c);
      }
    }
    reverse(xs.begin(),xs.end());
    reverse(ys.begin(),ys.end());
    {
      auto zs=sub(ys,xs);
      for(auto w:zs){
        int a,b,c;
        tie(a,b,c)=w;
        run[a].emplace_back(l+c,r-b);
      }
    }
    dfs(l,m,cs);
    dfs(m,r,cs);
  }

  // return all t (not only minimal)
  template<typename C>
  vector<vector<P>> enumerate(const vector<C> &cs){
    int n=cs.size();
    run.clear();
    run.resize(n+1);
    dfs(0,n,cs);

    auto cmp=[&](P a,P b){return P(a.first,-a.second)<P(b.first,-b.second);};
    for(int i=1;i<=n;i++){
      auto &rs=run[i];
      sort(rs.begin(),rs.end(),cmp);
      int mx=-1;
      vector<P> tmp;
      for(auto p:rs){
        if(mx<p.second){
          tmp.emplace_back(p);
          mx=p.second;
        }
      }
      rs=tmp;
    }
    return run;
  }

  vector<vector<P>> enumerate(string ss){
    return enumerate(vector<char>(ss.begin(),ss.end()));
  }
};
//END CUT HERE
#ifndef call_from_test
signed main(){
  return 0;
}
#endif
