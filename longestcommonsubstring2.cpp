#include<bits/stdc++.h>
using namespace std;
using Int = long long;
//BEGIN CUT HERE
struct LongestCommonSubstring{
  struct node{
    int value;
    node *next;
    node(int value,node *next):value(value),next(next){}
  };
  const int INF=1<<28;
  string x,y;
  LongestCommonSubstring(){}
  LongestCommonSubstring(string x,string y):x(x),y(y){}
  string lcs(){
    int n=x.size(),m=y.size();
    map<char,vector<int> > M;
    for(int j=m-1;j>=0;j--) M[y[j]].push_back(j);
    vector<int> xs(n+1,INF);
    xs[0]=-INF;
    vector<node* > link(n+1);
    for(int i=0;i<n;i++){
      if(M.count(x[i])){
	vector<int> ys=M[x[i]];
	for(int j=0;j<(int)ys.size();j++){
	  int k=distance(xs.begin(),lower_bound(xs.begin(),xs.end(),ys[j]));
	  xs[k]=ys[j];
	  link[k]=new node(y[ys[j]],link[k-1]);
	}
      }
    }
    string res;
    int l=distance(xs.begin(),lower_bound(xs.begin(),xs.end(),INF-1))-1;
    for(node *p=link[l];p!=NULL;p=p->next)
      res.push_back(p->value);
    return res;
  }
};
//END CUT HERE
signed main(){
  int q;
  cin>>q;
  while(q--){
    string x,y;
    cin>>x>>y;
    LongestCommonSubstring lcs(x,y);
    cout<<lcs.lcs().size()<<endl;
  }
  return 0;
}
/*
verified on 2017/10/29
http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_10_C&lang=jp
*/
