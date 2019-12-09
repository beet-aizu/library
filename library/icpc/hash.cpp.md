<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    TeX: { equationNumbers: { autoNumber: "AMS" }},
    tex2jax: {
      inlineMath: [ ['$','$'] ],
      processEscapes: true
    },
    "HTML-CSS": { matchFontHeight: false },
    displayAlign: "left",
    displayIndent: "2em"
  });
</script>

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/jquery-balloon-js@1.1.2/jquery.balloon.min.js" integrity="sha256-ZEYs9VrgAeNuPvs15E39OsyOJaIkXEEt10fzxJ20+2I=" crossorigin="anonymous"></script>
<script type="text/javascript" src="../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../assets/css/copy-button.css" />


# :warning: icpc/hash.cpp
* category: icpc


[Back to top page](../../index.html)



## Code
```cpp
#include<bits/stdc++.h>
using namespace std;

//BEGIN CUT HERE
signed main(){
  const int MOD = 1e9+7,B=1e8+7;
  long long res=0;
  string s;
  while(getline(cin,s)){
    string t=s;
    if(s.find("//")!=string::npos)
      t=s.substr(0,s.find("//"));
    for(char c:t){
      if(c==' ') continue;
      res=(res*B+c)%MOD;
    }
    cout<<s;
    if(s=="  }") cout<<" // "<<res;
    cout<<endl;
  }
  cout<<res<<endl;
  return 0;
}
//END CUT HERE

```

[Back to top page](../../index.html)

