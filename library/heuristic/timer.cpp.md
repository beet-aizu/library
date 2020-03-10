---
layout: default
---

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


# :warning: heuristic/timer.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#4163cf922db5cac4b933c8e333ba09ef">heuristic</a>
* <a href="{{ site.github.repository_url }}/blob/master/heuristic/timer.cpp">View this file on GitHub</a>
    - Last commit date: 2019-12-10 13:55:14+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include<bits/stdc++.h>
using namespace std;

#define IGNORE

//BEGIN CUT HERE
using i16 = int16_t;
using i32 = int32_t;
using i64 = int64_t;

using u16 = uint16_t;
using u32 = uint32_t;
using u64 = uint64_t;

// AtCoder
const i64 CYCLES_PER_SEC = 2800000000;

struct Timer {
	i64 start;
	Timer(){reset();}
	void reset(){start=getCycle();}
	inline double get(){return (double)(getCycle()-start)/CYCLES_PER_SEC;}
	inline i64 getCycle(){
		u32 low,high;
		__asm__ volatile ("rdtsc" : "=a" (low), "=d" (high));
		return ((i64)low)|((i64)high<<32);
	}
};

Timer timer;
//END CUT HERE

//INSERT ABOVE HERE
void nxt(){
  static i64 x = 0;
  static i64 y = 1;
  x=(x<<10)+y;
  y=x/3;
}

signed main(){
  cout<<fixed<<setprecision(12);
  auto start1=clock(),stop1=clock();
  for(int i=0;i<1000000;i++) stop1=clock();

  double d=0;
  auto start2=clock();
  for(int i=0;i<1000000;i++) d+=timer.get();
  auto stop2=clock();

  cout<<(double)(stop1-start1)/CLOCKS_PER_SEC<<endl;
  cout<<(double)(stop2-start2)/CLOCKS_PER_SEC<<endl;
  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "heuristic/timer.cpp"
#include<bits/stdc++.h>
using namespace std;

#define IGNORE

//BEGIN CUT HERE
using i16 = int16_t;
using i32 = int32_t;
using i64 = int64_t;

using u16 = uint16_t;
using u32 = uint32_t;
using u64 = uint64_t;

// AtCoder
const i64 CYCLES_PER_SEC = 2800000000;

struct Timer {
	i64 start;
	Timer(){reset();}
	void reset(){start=getCycle();}
	inline double get(){return (double)(getCycle()-start)/CYCLES_PER_SEC;}
	inline i64 getCycle(){
		u32 low,high;
		__asm__ volatile ("rdtsc" : "=a" (low), "=d" (high));
		return ((i64)low)|((i64)high<<32);
	}
};

Timer timer;
//END CUT HERE

//INSERT ABOVE HERE
void nxt(){
  static i64 x = 0;
  static i64 y = 1;
  x=(x<<10)+y;
  y=x/3;
}

signed main(){
  cout<<fixed<<setprecision(12);
  auto start1=clock(),stop1=clock();
  for(int i=0;i<1000000;i++) stop1=clock();

  double d=0;
  auto start2=clock();
  for(int i=0;i<1000000;i++) d+=timer.get();
  auto stop2=clock();

  cout<<(double)(stop1-start1)/CLOCKS_PER_SEC<<endl;
  cout<<(double)(stop2-start2)/CLOCKS_PER_SEC<<endl;
  return 0;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

