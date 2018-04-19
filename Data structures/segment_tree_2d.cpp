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
#define rep(i,n) for( int i = 0; i < n; ++i )
#define repi(i,n) for( int i = 1 ; i <= n; ++i )
#define repn(i,n) for( int i = n - 1 ; i >= 0 ; --i )
#define repf(j,i,n) for( int j = i ; j < n ; ++j )
#define die(s) {std::cout << s << nl;}
#define dier(s) {std::cout << s; return 0;}
#define vi vector<int>
typedef long long ll;

using namespace std;

const int MAXN = (1 << 20);

struct rmq1d  {
	vector<int> rmq;
	int n;
	void init(int N) {
		n = N;
		rmq.resize(4 * n);
	}
	void add(int v, int tl, int tr, int x) {
		++rmq[v];
		if (tl + 1 == tr)
			return;
		int m = (tl + tr) >> 1;
		if (x < m)
			add(v * 2 + 1, tl, m, x);
		else
			add(v * 2 + 2, m, tr, x);
	}
	void add(int x) {
		add(0, 0, n, x);
	}
	int get(int v, int tl, int tr, int l, int r) {
		if (r <= tl || tr <= l)
			return 0;
		if (l <= tl && tr <= r)
			return rmq[v];
		int m = (tl + tr) >> 1;
		return get(v * 2 + 1, tl, m, l, r) + get(v * 2 + 2, m, tr, l, r);
	}
	int get(int l, int r) {
		return get(0, 0, n, l, r);
	}
};

struct rmq2d {
	vector<rmq1d> rmq;
	vector<vector<int> > sv;
	int n;
	void init(int N) {
		n = N;
		sv.resize(4 * n);
		rmq.resize(4 * n);
	}
	void prep(int v, int tl, int tr, int x, int y) {
		sv[v].push_back(y);
		if (tl + 1 == tr)
			return;
		int m = (tl + tr) >> 1;
		if (x < m)
			prep(v * 2 + 1, tl, m, x, y);
		else
			prep(v * 2 + 2, m, tr, x, y);
	}
	void prep(int x, int y) {
		prep(0, 0, n, x, y);
	}
	void add(int v, int tl, int tr, int x, int y) {
		int k = lower_bound(sv[v].begin(), sv[v].end(), y) - sv[v].begin();
		rmq[v].add(k);
		if (tl + 1 == tr)
			return;
		int m = (tl + tr) >> 1;
		if (x < m)
			add(v * 2 + 1, tl, m, x, y);
		else
			add(v * 2 + 2, m, tr, x, y);
	}
	void add(int x, int y) {
		add(0, 0, n, x, y);
	}
	void build(int v, int tl, int tr) {
		sort(sv[v].begin(), sv[v].end());
		rmq[v].init(sv[v].size());
		if (tl + 1 == tr)
			return;
		int m = (tl + tr) >> 1;
		build(v * 2 + 1, tl, m);
		build(v * 2 + 2, m, tr);
	}
	void init2() {
		build(0, 0, n);
	}
	int get(int v, int tl, int tr, int l1, int r1, int l2, int r2) {
		if (r1 <= tl || tr <= l1)
			return 0;
		if (l1 <= tl && tr <= r1) {
			l2 = lower_bound(sv[v].begin(), sv[v].end(), l2) - sv[v].begin();
			r2 = lower_bound(sv[v].begin(), sv[v].end(), r2) - sv[v].begin();
			return rmq[v].get(l2, r2);
		}
		int m = (tl + tr) >> 1;
		return get(v * 2 + 1, tl, m, l1, r1, l2, r2) + get(v * 2 + 2, m, tr, l1, r1, l2, r2);
	}
	int get(int l1, int r1, int l2, int r2) {
		return get(0, 0, n, l1, r1, l2, r2);
	}
};
 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(0); 

	return 0;
}