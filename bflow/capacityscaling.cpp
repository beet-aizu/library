#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;
#endif
//BEGIN CUT HERE
// O(m^2 \log m \log U)
// U: maximum capacity
enum Objective{
  MINIMIZE = +1,
  MAXIMIZE = -1,
};
template<typename Flow, typename Cost,
         Objective objective = Objective::MINIMIZE>
struct MinCostFlow{
  template<typename T> inline void chmin(T &x,T y){x=min(x,y);}

  struct Edge{
    int src,dst;
    Flow flow,cap;
    Cost cost;
    int rev;
    Edge(int src,int dst,Flow cap,Cost cost,int rev):
      src(src),dst(dst),flow(0),cap(cap),cost(cost),rev(rev){}
    Flow residual_cap()const{return cap-flow;}
  };

  struct EdgePtr{
    int v,e;
    EdgePtr(int v,int e):v(v),e(e){}
  };

  int n;
  vector<vector<Edge>> G;
  vector<Flow> b;
  vector<Cost> p;

  MinCostFlow(int n):n(n),G(n),b(n,0){}

  EdgePtr add_edge(int src,int dst,Flow lower,Flow upper,Cost cost){
    int e=G[src].size();
    int r=(src==dst?e+1:G[dst].size());
    assert(lower<=upper);
    G[src].emplace_back(src,dst,+upper,+cost*objective,r);
    G[dst].emplace_back(dst,src,-lower,-cost*objective,e);
    return EdgePtr(src,e);
  }

  const Edge &get_edge(EdgePtr ep)const{return G[ep.v][ep.e];}

  void push(Edge &e,Flow amount){
    e.flow+=amount;
    G[e.dst][e.rev].flow-=amount;
  }

  void add_supply(int v,Flow amount){b[v]+=amount;}
  void add_demand(int v,Flow amount){b[v]-=amount;}

  Cost residual_cost(const Edge &e){
    return e.cost+p[e.src]-p[e.dst];
  }

  vector<int> excess_vs,deficit_vs;
  void saturate_negative(const Flow delta){
    for(auto &es:G){
      for(auto &e:es){
        Flow cap=e.residual_cap();
        cap-=cap%delta;
        if(cap<0 or residual_cost(e)<0){
          push(e,cap);
          b[e.src]-=cap;
          b[e.dst]+=cap;
        }
      }
    }

    excess_vs.clear();
    deficit_vs.clear();
    for(int v=0;v<n;v++){
      if(b[v]>0) excess_vs.emplace_back(v);
      if(b[v]<0) deficit_vs.emplace_back(v);
    }
  }

  const Cost unreachable = std::numeric_limits<Cost>::max();
  Cost farthest;
  vector<Cost> dist;
  vector<Edge*> parent;

  struct P{
    Cost first;
    int second;
    P(Cost first,int second):first(first),second(second){}
    bool operator<(const P o)const{return first>o.first;}
  };

  priority_queue<P> pq;

  template<typename Predicate>
  void eliminate(vector<int> &vs,Predicate predicate){
    vs.erase(remove_if(begin(vs),end(vs),predicate),end(vs));
  }

  bool dual(const Flow delta){
    eliminate(excess_vs, [&](int v){return b[v]<+delta;});
    eliminate(deficit_vs,[&](int v){return b[v]>-delta;});

    dist.assign(n,unreachable);
    for(int v:excess_vs) pq.emplace(dist[v]=0,v);

    parent.assign(n,nullptr);
    auto emplace=[&](Edge& e){
      if(e.residual_cap()<delta) return;
      Cost nxt=dist[e.src]+residual_cost(e);
      if(nxt>=dist[e.dst]) return;
      pq.emplace(dist[e.dst]=nxt,e.dst);
      parent[e.dst]=&e;
    };

    farthest=0;
    int deficit_count=0;
    while(!pq.empty()){
      Cost d=pq.top().first;
      int v=pq.top().second;
      pq.pop();
      if(dist[v]<d) continue;
      farthest=d;

      if(b[v]<=-delta) deficit_count++;
      if(deficit_count>=(int)deficit_vs.size()) break;

      for(auto &e:G[v]) emplace(e);
    }
    pq=decltype(pq)();

    for(int v=0;v<n;v++)
      p[v]+=min(dist[v],farthest);

    return deficit_count>0;
  }

  void primal(const Flow delta){
    for(int t:deficit_vs){
      if(dist[t]>farthest) continue;
      Flow f=-b[t];
      int v;
      for(v=t;parent[v];v=parent[v]->src)
        chmin(f,parent[v]->residual_cap());
      chmin(f,b[v]);

      f-=f%delta;
      if(f<=0) continue;

      for(v=t;parent[v];){
        auto &e=*parent[v];
        push(e,f);
        int u=parent[v]->src;
        if(e.residual_cap()<=0) parent[v]=nullptr;
        v=u;
      }
      b[t]+=f;
      b[v]-=f;
    }
  }

  template<Flow SCALING_FACTOR=2>
  bool build(){
    p.resize(n);
    Flow max_flow=1;
    for(auto t:b) max_flow=max({max_flow,t,-t});
    for(auto &es:G)
      for(auto &e:es)
        max_flow=max({max_flow,e.residual_cap(),-e.residual_cap()});

    Flow delta=1;
    while(delta<max_flow) delta*=SCALING_FACTOR;
    for(;delta;delta/=SCALING_FACTOR){
      saturate_negative(delta);
      while(dual(delta)) primal(delta);
    }

    return excess_vs.empty() and deficit_vs.empty();
  }

  template<typename T=Cost>
  T get_cost(){
    T res=0;
    for(auto &es:G)
      for(auto &e:es)
        res+=T(e.flow)*T(e.cost)/T(objective);
    return res/T(2);
  }
  template<typename T=Cost> T get_gain(){return get_cost();}

  vector<Cost> get_potential(){
    fill(p.begin(),p.end(),0);
    for(int i=0;i<n;i++)
      for(auto &es:G)
        for(auto &e:es)
          if(e.residual_cap()>0)
            chmin(p[e.dst],p[e.src]+e.cost);
    return p;
  }
};

template<typename Flow, typename Cost>
using MaxGainFlow = MinCostFlow<Flow, Cost, Objective::MAXIMIZE>;
//END CUT HERE
#ifndef call_from_test
//INSERT ABOVE HERE
signed main(){
  return 0;
}
#endif
