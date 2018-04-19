#pragma comment(linker, "/STACK:66777216")

#include <stdexcept>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <cassert>
#include <cstdarg>
#include <cstring>
#include <cstdio>
#include <memory>
#include <random>
#include <cmath>
#include <ctime>
#include <unordered_map>
#include <unordered_set>
#include <functional>
#include <algorithm>
#include <complex>
#include <numeric>
#include <limits>
#include <bitset>
#include <vector>
#include <string>
#include <queue>
#include <deque>
#include <array>
#include <list>
#include <map>
#include <set>
 
#define INF 1000010000
#define nl '\n'
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define fi first
#define se second
#define pii pair<int,int>
#define pdd pair<double,double>
#define all(c) (c).begin(), (c).end()
#define SORT(c) sort(all(c))
#define sz(c) (c).size()
#define rep(i,n) for( int i = 0; i < n; ++i )
#define repi(i,n) for( int i = 1 ; i <= n; ++i )
#define repn(i,n) for( int i = n - 1 ; i >= 0 ; --i )
#define repf(j,i,n) for( int j = i ; j < n ; ++j )
#define die(s) {std::cout << s << nl;}
#define dier(s) {std::cout << s; return 0;}
#define vi vector<int>
typedef long long ll;
#define MAXN 101010
using namespace std;

inline unsigned clz(unsigned x){
    unsigned n = 0;
    if (x <= 0x0000ffff) n += 16, x <<= 16;
    if (x <= 0x00ffffff) n +=  8, x <<= 8;
    if (x <= 0x0fffffff) n +=  4, x <<= 4;
    if (x <= 0x3fffffff) n +=  2, x <<= 2;
    if (x <= 0x7fffffff) n ++;
    return n;
}

vector<ll> t(2 * MAXN , 0);
vector<ll> lazy(MAXN , -1);
 
int n , h;
 
void calc(int p , int k){
	if(lazy[p] == -1){
		t[p] = t[2 * p] + t[2 * p + 1];	
	}else{
		t[p] = k * lazy[p];
	}
}
 
void apply(int p , ll val , int k){
	t[p] = k * val;
	if(p < n){
		lazy[p] = val;
	}
}
 
void build(int l , int r){
	int k = 2;
	for(l += n , r += n - 1 ; l > 1 ; k *= 2){
		l /= 2;
		r /= 2;
		for(int i = r ; i >= l ; --i){
			calc(i , k);
		}
	}
}
 
void push(int l , int r){
	int s = h , k = 1 << (h - 1);
	for(l += n , r += n - 1 ; s > 0 ; --s , k /= 2){
		for(int i = l >> s ; i <= r >> s ; ++i){
			if(lazy[i] != -1){
				apply(2 * i , lazy[i] , k);
				apply(2 * i + 1 , lazy[i] , k);
				lazy[i] = -1;
			}
		}
	}
}
 
void upd(int l , int r , ll val){
	if(val == -1){
		return;
	}
	push(l , l + 1);
	push(r - 1 , r);
	int l0 = l , r0 = r , k = 1;
	for(l +=n , r += n ; l < r ; l/= 2 , r /= 2 , k *= 2){
		if(l % 2){
			apply(l , val , k);
			++l;
		}
		if(r % 2){
			--r;
			apply(r , val , k);
		}
	}
	build(l0 , l0 + 1);
	build(r0 - 1 , r0);
}
 
ll query(int l , int r){
	push(l , l + 1);
	push(r - 1 , r);
	ll res = 0;
	for(l += n , r += n ; l < r ; l /= 2 , r /= 2){
		if(l % 2){
			res += 1LL * t[l];
			++l;
		}
		if(r % 2){
			--r;
			res += 1LL * t[r];
		}
	}
	return res;
}
 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(0); 
	int k;
	cin >> n >> k;
	h = sizeof(int) * 8 - clz(n);
	rep(i , k){
		char type;
		cin >> type;
		if(type == 'A'){
			int l , r , x;
			cin >> l >> r >> x;
			--l;
			upd(l , r , x);
		}else if(type == 'Q'){
			int l , r;
			cin >> l >> r;
			--l;
			cout << query(l , r) << nl;
		}
	}
	return 0;
}