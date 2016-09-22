#include<bits/stdc++.h>
using namespace std;
template <class T>
struct avl_tree {
  struct node {
    T key;
    int size, height;
    node *child[2];
    node(const T &key) : key(key), size(1), height(1) {
      child[0] = child[1] = 0; }
  } *root;
  typedef node *pointer;
  avl_tree() { root = NULL; }

  pointer find(const T &key) { return find(root, key); }
  node *find(node *t, const T &key) {
    if (t == NULL) return NULL;
    if (key == t->key) return t;
    else if (key < t->key) return find(t->child[0], key);
    else                   return find(t->child[1], key);
  }
  void insert(const T &key) { root = insert(root, new node(key)); }
  node *insert(node *t, node *x) {
    if (t == NULL) return x;
    if (x->key <= t->key) t->child[0] = insert(t->child[0], x);
    else                  t->child[1] = insert(t->child[1], x);
    t->size += 1;
    return balance(t);
  }
  void erase(const T &key) { root = erase(root, key); }
  node *erase(node *t, const T &x) {
    if (t == NULL) return NULL;
    if (x == t->key) {
      return move_down(t->child[0], t->child[1]);
    } else {
      if (x < t->key) t->child[0] = erase(t->child[0], x);
      else            t->child[1] = erase(t->child[1], x);
      t->size -= 1;
      return balance(t);
    }
  }
  node *move_down(node *t, node *rhs) {
    if (t == NULL) return rhs;
    t->child[1] = move_down(t->child[1], rhs);
    return balance(t);
  }
#define sz(t) (t ? t->size : 0)
#define ht(t) (t ? t->height : 0)
  node *rotate(node *t, int l, int r) {
    node *s = t->child[r];
    t->child[r] = s->child[l];
    s->child[l] = balance(t);
    if (t) t->size = sz(t->child[0]) + sz(t->child[1]) + 1;
    if (s) s->size = sz(s->child[0]) + sz(s->child[1]) + 1;
    return balance(s);
  }
  node *balance(node *t) {
    for (int i = 0; i < 2; ++i) {
      if (ht(t->child[!i]) - ht(t->child[i]) < -1) {
        if (ht(t->child[i]->child[!i]) - ht(t->child[i]->child[i]) > 0)
          t->child[i] = rotate(t->child[i], i, !i);
        return rotate(t, !i, i);
      }
    }
    if (t) t->height = max(ht(t->child[0]), ht(t->child[1])) + 1;
    if (t) t->size = sz(t->child[0]) + sz(t->child[1]) + 1;
    return t;
  }
  pointer rank(int k) const { return rank(root, k); }
  pointer rank(node *t, int k) const {
    if (!t) return NULL;
    int m = sz(t->child[0]);
    if (k  < m) return rank(t->child[0], k);
    if (k == m) return t;
    if (k  > m) return rank(t->child[1], k - m - 1);
  }
};
typedef long long ll;
int main(){
  avl_tree<ll> avl=avl_tree<ll>();
  ll d[100005]={};
  ll n,c,s=0;
  cin >> n >> c;
  ll i,j,k,t,p,m;
  for(i=0;i<c;i++){
    cin >> k;
    if(k){
      cin>>m;
      if(s<m) cout<<0<<endl;
      else cout << avl.rank(s-m)->key << endl;
    }else{
      cin>>t>>p;
      if(d[t]){
	avl.erase(d[t]);
	d[t]+=p;
	avl.insert(d[t]);
      }else{
	s++;
	d[t]+=p;
	avl.insert(d[t]);
      }
    }
  }
  return 0;
}
