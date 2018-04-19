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

const int MAXN = (int)3e5 + 1;
const int MAXV = (int)1e9;

struct wavelet_tree
{
	int lo, hi;
	wavelet_tree *l, *r;
	int *b, psz;

	wavelet_tree() { lo = 1; hi = 0; psz = 0; l = NULL; r = NULL; }

	void init(int *from, int *to, int x, int y)
	{
		lo = x, hi = y;
		if(lo == hi || from >= to) return;
		int mid = (lo + hi) >> 1; auto f = [mid](int x) { return x <= mid; };
		b = (int*)malloc((to - from + 2) * sizeof(int)); psz = 0; b[psz++] = 0;
		for(auto it = from; it != to; it++)	b[psz] = (b[psz - 1] + f(*it)), psz++;
		auto pivot = stable_partition(from, to, f);
		l = new wavelet_tree();
		l->init(from, pivot, lo, mid);
		r = new wavelet_tree();
		r->init(pivot, to, mid+1, hi);
	}

	// The kth smallest element in subarray
	int kth(int l, int r, int k)
	{
		if(l > r) return 0;
		if(lo == hi) return lo;
		int inLeft = b[r] - b[l - 1], lb = b[l - 1], rb = b[r];
		if(k <= inLeft) return this->l->kth(lb + 1, rb, k);
		return this->r->kth(l - lb, r - rb, k - inLeft);
	}

	// Number of elements in subarray that are less than or equal to k
	int LTE(int l, int r, int k) 
	{
		if(l > r || k < lo) return 0;
		if(hi <= k) return r - l + 1;
		int lb = b[l - 1], rb = b[r];
		return this->l->LTE(lb + 1, rb, k) + this->r->LTE(l - lb, r - rb, k);
	}

	// Number of occurrences of element k in subarray
	int count(int l, int r, int k) 
	{
		if(l > r || k < lo || k > hi) return 0;
		if(lo == hi) return r - l + 1;
		int lb = b[l - 1], rb = b[r];
		int mid = (lo + hi) >> 1;
		if(k <= mid) return this->l->count(lb + 1, rb, k);
		return this->r->count(l - lb, r - rb, k);
	}

	~wavelet_tree()
	{
		delete l;
		delete r;
	}
};

int n;
int a[MAXN];

 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(0); 
	
	int i,n,k,j,q,l,r;
	cin >> n;
	rep(i, n) cin >> a[i];
	wavelet_tree T;
	T.init(a, a + n, 1, MAXV);
	cin >> q;
	while(q--){
		int x;
		cin >> x;
		cin >> l >> r >> k;
		if(x == 0){
			//kth smallest
			cout << "Kth smallest: ";
			cout << T.kth(l, r, k) << endl;
		}
		if(x == 1){
			//less than or equal to K
			cout << "LTE: ";
			cout << T.LTE(l, r, k) << endl;
		}
		if(x == 2){
			//count occurence of K in [l, r]
			cout << "Occurence of K: ";
			cout << T.count(l, r, k) << endl;
		}
	}
	return 0;
}

/*

7
1 2 3 3 5 4 2
4
0 5 7 1
0 5 7 2
1 2 6 4
2 2 5 3 

*/