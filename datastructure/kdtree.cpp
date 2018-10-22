#include<bits/stdc++.h>
using namespace std;
using Int = long long;
//BEGIN CUT HERE
struct KDTree{
  class Node{
  public:
    int location;
    int p,l,r;
    Node(){}
  };
  class Point{
  public:
    int id,x,y;
    Point(){}
    Point(int id,int x,int y): id(id),x(x),y(y){}
    bool operator<(const Point &p)const{
      return id<p.id;
    }
    void print(){
      printf("%d\n",id);
    }
  };
  
  static const int NIL = -1;

  int N;
  vector<Point> P;
  vector<Node> T;
  int np;

  KDTree(){}
  KDTree(int N){init(N);}

  void init(int N_){
    N=N_;
    P.clear();
    T.clear();
    P.resize(N);
    T.resize(N);
  }
  
  static bool lessX(const Point &p1,const Point &p2){return p1.x<p2.x;}
  static bool lessY(const Point &p1,const Point &p2){return p1.y<p2.y;}
  
  int makeKDTree(int l,int r,int depth){
    if(!(l<r)) return NIL;
    int mid=(l+r)/2;
    int t = np++;
    if(depth%2==0){
      sort(P.begin()+l,P.begin()+r,lessX);
    }else{
      sort(P.begin()+l,P.begin()+r,lessY);
    }
    T[t].location=mid;
    T[t].l=makeKDTree(l,mid,depth+1);
    T[t].r=makeKDTree(mid+1,r,depth+1);
    return t;
  }
  
  void find(int v,int sx,int tx,int sy,int ty,int depth,vector<Point> &ans){
    int x=P[T[v].location].x;
    int y=P[T[v].location].y;
    if(sx<=x&&x<=tx&&sy<=y&&y<=ty){
      ans.push_back(P[T[v].location]);
    }
    if(depth%2==0){
      if(T[v].l!=NIL){
        if(sx<=x) find(T[v].l,sx,tx,sy,ty,depth+1,ans);
      }
      if(T[v].r!=NIL){
        if(x<=tx) find(T[v].r,sx,tx,sy,ty,depth+1,ans);
      }
    }else{
      if(T[v].l!=NIL){
        if(sy<=y) find(T[v].l,sx,tx,sy,ty,depth+1,ans);
      }
      if(T[v].r!=NIL){
        if(y<=ty) find(T[v].r,sx,tx,sy,ty,depth+1,ans);
      }
    }
  } 
};
//END CUT HERE

signed main(){
  int x,y;
  int N;
  scanf("%d",&N);
  KDTree kd(N);
  for(int i=0;i<N;i++) {
    scanf("%d %d",&x,&y);
    kd.P[i]=KDTree::Point(i,x,y);
    kd.T[i].l = kd.T[i].r = kd.T[i].p = kd.NIL;
  }
  kd.np=0;
  int root=kd.makeKDTree(0,N,0);

  int q;
  scanf("%d",&q);
  int sx,tx,sy,ty;
  vector<KDTree::Point> ans;
  for(int i=0;i<q;i++){
    scanf("%d %d %d %d",&sx,&tx,&sy,&ty);
    ans.clear();
    kd.find(root,sx,tx,sy,ty,0,ans);
    sort(ans.begin(),ans.end());
    for(int j=0;j<(int)ans.size();j++){
      ans[j].print();
    }
    printf("\n");
  }
  
  return 0;
}

/*
  verified on 2017/10/29
  http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_C&lang=jp
*/
