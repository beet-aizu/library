#include<bits/stdc++.h>
using namespace std;
using Int = long long;
//BEGIN CUT HERE
struct SparseTable{
  int n,h;
  vector<vector<int> > dat;
  vector<int> ht;
  SparseTable(){}
  SparseTable(int n_,int *arr){init(n_,arr);}
  void init(int n_,int *arr){
    n=1;h=1;
    while(n<n_) n*=2,h++;
    dat.clear();
    dat.resize(h,vector<int>(n_));
    for(int j=0;j<n_;j++) dat[0][j]=arr[j];
    for(int i=1,p=1;i<h;i++){
      for(int j=0;j<n_;j++){
	dat[i][j]=dat[i-1][j];
	if(j+p<n_) dat[i][j]=min(dat[i][j],dat[i-1][j+p]);
      }
      p*=2;
    }
    ht.resize(n_+1);
    ht[0]=ht[1]=0;
    for(int j=2;j<=n_;j++)
      ht[j]=ht[j>>1]+1;
  }
  int query(int a,int b){
    b--;//[a,b)->[a,b-1]
    int l=b-a+1;
    return min(dat[ht[l]][a],dat[ht[l]][b-(1<<ht[l])+1]);
  }
};
//END CUT HERE

signed main(){
  return 0;
}
