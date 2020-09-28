// verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=3073

#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../string/trie.cpp"
#include "../../string/ahocorasick.cpp"
#include "../../segtree/basic/lazy.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  string s;
  cin>>s;
  int n,q;
  cin>>n>>q;

  auto conv=[](char c){return c-'a';};
  AhoCorasick<26> aho(conv);
  aho.add(s,0);
  aho.build(false);

  using A = array<int, 32>;
  A ti,ei;
  fill(ti.begin(),ti.end(),0);
  iota(ei.begin(),ei.end(),0);
  auto f=[&](A a,A b){
           A c;
           for(int i=0;i<(int)a.size();i++) c[i]=a[i]+b[i];
           return c;
         };
  auto g=[&](A a,A b){
           A c(ti);
           for(int i=0;i<(int)a.size();i++) c[b[i]]+=a[i];
           return c;
         };
  auto h=[&](A a,A b){
           A c;
           for(int i=0;i<(int)a.size();i++) c[i]=b[a[i]];
           return c;
         };

  SegmentTree<A, A> seg(f,g,h,ti,ei);
  vector<A> va(n,ti);
  for(int i=0;i<n;i++) va[i][0]=1;
  seg.build(va);

  vector<A> mv(26);
  for(int x=0;x<26;x++){
    for(int i=0;i<(int)mv[x].size();i++)
      mv[x][i]=(i<(int)aho.size()?aho.move(i,char('a'+x)):i);
  }

  for(int i=0;i<q;i++){
    int t;
    cin>>t;
    if(t==1){
      int l,r;
      string c;
      cin>>l>>r>>c;
      l--;
      A a=ei;
      for(char x:c) a=h(a,mv[x-'a']);
      seg.update(l,r,a);
    }
    if(t==2){
      int l,r;
      cin>>l>>r;
      l--;
      A res=seg.query(l,r);
      int ans=0;
      for(int j=0;j<(int)res.size();j++)
        if(j<(int)aho.size()&&aho.count(j)) ans+=res[j];
      cout<<ans<<"\n";
    }
  }
  cout<<flush;
  return 0;
}
