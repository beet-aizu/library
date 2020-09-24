#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2679"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../mincostflow/primaldual.cpp"
#undef call_from_test

const int MAX = 52;
struct ARR{
  array<int, MAX> val;
  ARR(){fill(val.begin(),val.end(),0);}
  ARR(int x){fill(val.begin(),val.end(),x);}
  int& operator[](int k){return val[k];};
  int operator[](int k)const{return val[k];};
  ARR operator+(const ARR &oth) const{
    ARR res;
    for(int i=0;i<MAX;i++)
      res[i]=val[i]+oth[i];
    return res;
  }
  ARR operator-(const ARR &oth) const{
    ARR res;
    for(int i=0;i<MAX;i++)
      res[i]=val[i]-oth[i];
    return res;
  }
  ARR operator-() const{
    ARR res;
    for(int i=0;i<MAX;i++)
      res[i]=-val[i];
    return res;
  }
  ARR operator*(const int &k) const{
    ARR res;
    for(int i=0;i<MAX;i++)
      res[i]=val[i]*k;
    return res;
  }
  ARR operator/(const int &k) const{
    ARR res;
    for(int i=0;i<MAX;i++)
      res[i]=val[i]/k;
    return res;
  }
  bool operator< (const ARR &oth) const{
    return val< oth.val;
  }
  bool operator> (const ARR &oth) const{
    return val< oth.val;
  }
  bool operator==(const ARR &oth) const{
    return val==oth.val;
  }
};

namespace std {
  template<> class numeric_limits<ARR> {
  public:
    static ARR max() {return ARR(numeric_limits<int>::max());};
  };
}

int main(){
  int n;
  cin>>n;
  vector<string> vs(n);
  for(int i=0;i<n;i++) cin>>vs[i];

  auto enc=[&](char c){
    if(isupper(c)) return c-'A';
    return 26+c-'a';
  };
  auto dec=[&](int d){
    if(d<26) return 'A'+d;
    return 'a'+d-26;
  };

  int S=n*2,T=n*2+1;
  PrimalDual<int, ARR> G(n*2+2);
  for(int i=0;i<n;i++){
    G.add_edge(S,i,1,ARR());
    G.add_edge(n+i,T,1,ARR());
  }

  const int INF = 1e5;
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      ARR cost(INF);
      cost[enc(vs[i][j])]=INF-1;
      G.add_edge(i,n+j,1,cost);
    }
  }

  assert(G.build(S,T,n));
  auto res=G.get_cost();

  string ans;
  for(int i=0;i<MAX;i++)
    for(int j=0;j<n*INF-res[i];j++)
      ans+=dec(i);

  cout<<ans<<endl;
  return 0;
}
