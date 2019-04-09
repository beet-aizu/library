#include<bits/stdc++.h>
using namespace std;
using Int = long long;
//BEGIN CUT HERE
template<typename T> 
struct BIT2D{
  int n,m;
  T d;
  vector<vector<T> > bit;
  //1-indexed
  BIT2D():n(-1),m(-1){}
  BIT2D(int n_,int m_,T d_):n(n_),m(m_),d(d_),bit(n_+1,vector<T>(m+1,d_)){}
  T sum(int i,int j){
    T s=d;
    for(int x=i;x>0;x-=(x&-x))
      for(int y=j;y>0;y-=(y&-y))
        s+=bit[x][y];
    return s;
  }
  void add(int i,int j,T a){
    if(i==0||j==0) return;
    for(int x=i;x<=n;x+=(x&-x))
      for(int y=j;y<=m;y+=(y&-y))
        bit[x][y]+=a;
  }
  // (x1,x2] * (y1,y2];
  T sum(int x1,int y1,int x2,int y2){
    return sum(x1,y1)-sum(x1,y2)-sum(x2,y1)+sum(x2,y2);
  }
};
//END CUT HERE

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  int h,w,t,q;
  cin>>h>>w>>t>>q;
  BIT2D<int> beet(h+100,w+100,0);
  BIT2D<int> ushi(h+100,w+100,0);
  typedef pair<int,int> P;
  typedef pair<int,P> PP;
  queue<PP> qq; 
  for(int i=0;i<q;i++){
    int a,c,x1,y1;
    cin>>a>>c>>x1>>y1;
    while(!qq.empty()&&qq.front().first<=a){
      P p=qq.front().second;qq.pop();
      int x=p.first,y=p.second;
      assert(beet.sum(x-1,y-1,x,y)==1);
      beet.add(x,y,-1);
      assert(ushi.sum(x-1,y-1,x,y)==0);
      ushi.add(x,y,1);
    }
    if(c==0){
      assert(beet.sum(x1-1,y1-1,x1,y1)==0);
      beet.add(x1,y1,1);
      qq.push(PP(a+t,P(x1,y1)));
    }
    if(c==1){
      if(ushi.sum(x1-1,y1-1,x1,y1)==0) continue;
      ushi.add(x1,y1,-1);
    }
    if(c==2){
      int x2,y2;
      cin>>x2>>y2;
      x1--;y1--;
      cout<<ushi.sum(x1,y1,x2,y2)<<" "<<beet.sum(x1,y1,x2,y2)<<endl;
    }
  }
  return 0;
}

/*
  verified on 2017/10/29
  http://judge.u-aizu.ac.jp/onlinejudge/cdescription.jsp?cid=ACPC2017Day3&pid=E
*/
