#include<bits/stdc++.h>
using namespace std;
using Int = long long;
//BEGIN CUT HERE
vector<int> manacher(string s){
  int n=s.size();
  vector<int> v(n);
  for(int i=0,j=0;i<n;){
    while(i-j>=0&&i+j<n&&s[i-j]==s[i+j]) j++;
    v[i]=j;
    int k=1;
    while(i-k>=0&&i+k<n&&k+v[i-k]<j) v[i+k]=v[i-k],k++;
    i+=k;j-=k;
  }
  return v;
}
//END CUT HERE

template<typename T>
struct SparseTable{
  using F = function<T(T,T)>;
  vector<vector<T> > dat;
  vector<int> ht;
  const F f;

  SparseTable(){}
  SparseTable(F f):f(f){}

  void build(const vector<T> &v){
    int n=v.size(),h=1;
    while((1<<h)<=n) h++;
    dat.assign(h,vector<T>(n));
    ht.assign(n+1,0);
    for(int j=2;j<=n;j++) ht[j]=ht[j>>1]+1;

    for(int j=0;j<n;j++) dat[0][j]=v[j];
    for(int i=1,p=1;i<h;i++,p<<=1)
      for(int j=0;j<n;j++)
        dat[i][j]=f(dat[i-1][j],dat[i-1][min(j+p,n-1)]);
  };

  T query(int a,int b){
    int l=b-a;
    return f(dat[ht[l]][a],dat[ht[l]][b-(1<<ht[l])]);
  }
};

//INSERT ABOVE HERE
signed SPOJ_LPS(){
  int n;
  string s;
  cin>>n>>s;
  string t="$";
  for(int i=0;i<n;i++){
    t.push_back(s[i]);
    t.push_back('$');
  }
  vector<int> v=manacher(t);
  cout<<*max_element(v.begin(),v.end())-1<<endl;
  return 0;
}
/*
  verified on 2018/05/20
  http://www.spoj.com/problems/LPS/
*/

signed ukuku09_D(){
  int n,q;
  cin>>n>>q;
  string s;
  cin>>s;

  auto f=[](int a,int b){return max(a,b);};
  SparseTable<int> sp(f);
  sp.build(manacher(s));

  for(int i=0;i<q;i++){
    int l,r;
    cin>>l>>r;
    l--;
    int L=0,R=n;
    while(L+1<R){
      int M=(L+R)>>1;
      if(l+(M-1)<r-(M-1)&&sp.query(l+(M-1),r-(M-1))>=M) L=M;
      else R=M;
    }
    cout<<L*2-1<<endl;
  }
  return 0;
}
/*
  verified on 2019/10/08
  https://atcoder.jp/contests/ukuku09/tasks/ukuku09_d
*/

signed main(){
  //SPOJ_LPS();
  //ukuku09_D();
  return 0;
}
