// verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1197

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../tools/dice.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  vector<int> ts(6);
  do{
    for(int i=0;i<6;i++) cin>>ts[i];
    int sum=0;
    for(int t:ts) sum+=t;
    if(sum==0) break;

    auto check=
      [&](Die<int> d)->int{
        for(int i=0;i<6;i++)
          if(d.s[i]<0) return 0;
        int a=d.top()+d.bottom();
        int b=d.east()+d.west();
        int c=d.south()+d.north();
        if(a>b+c) return 0;
        if(b>(a+1)+c) return 0;
        if(c>(a+1)+b) return 0;
        return 1;
      };

    string ans(sum,'Z');
    sort(ts.begin(),ts.end());
    do{
      Die d;
      for(int i=0;i<6;i++) d.fs[i]=ts[i];
      if(!check(d)) continue;

      string res(sum,'Z');
      int flg=0;
      for(int i=0;i<sum;i++){
        string B="ENSW";
        string R="WSNE";
        for(int j=0;j<4;j++){
          d.roll(B[j]);
          d.bottom()--;
          if(check(d)){
            res[i]=B[j];
            break;;
          }
          d.bottom()++;
          d.roll(R[j]);
        }
        flg|=res[i]<ans[i];
        if(flg) continue;
        if(res[i]>ans[i]) break;
      }

      if(flg) ans=res;
    }while(next_permutation(ts.begin(),ts.end()));

    int p,q;
    cin>>p>>q;
    p--;
    if(ans[0]!='Z') cout<<ans.substr(p,q-p)<<endl;
    else cout<<"impossible"<<endl;
  }while(1);

  return 0;
}
