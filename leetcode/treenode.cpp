#include<bits/stdc++.h>
using namespace std;
using Int = long long;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
//BEGIN CUT HERE

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int dfs(TreeNode* v,int &k,vector<vector<int> > &G,vector<int> &x){
  if(!v) return -1;
  int s=k++;
  x.emplace_back(v->val);
  G.emplace_back(vector<int>());
  int a=dfs(v->left,k,G,x);
  int b=dfs(v->right,k,G,x);    
  if(~a){
    G[s].emplace_back(a);
    G[a].emplace_back(s);
  }
  if(~b){
    G[s].emplace_back(b);
    G[b].emplace_back(s);
  } 
  return s;
}

void build(TreeNode* v,vector<vector<int> > &G,vector<int> &x){
  assert(G.empty());
  int k=0;
  dfs(v,k,G,x);
}

//END CUT HERE

//INSERT ABOVE HERE
signed main(){
  return 0;
}
