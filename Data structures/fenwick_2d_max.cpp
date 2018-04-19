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
const int bound = (int)(1e6) + 42;

template<typename T>
struct fenwick_2d
{
	int sz; 
	unordered_map<int, T> t[MAXN];

	void init(int _sz) {sz = _sz;}

	void update_row(int row, int idx, T val)
	{
		if(idx == 0) return;
		for(; idx <= sz; idx += (idx & -idx))
			t[row][idx] = max(t[row][idx], val);
	}

	T query_row(int row, int idx)
	{
		T ans = 0;
		for(; idx >= 1; idx -= (idx & -idx))
			ans = max(t[row][idx], ans);
		
		return ans;
	}

	void update(int row, int col, T val)
	{
		if(col == 0) return;
		for(; row <= sz; row += (row & -row))	
			update_row(row, col, val);
	}
	
	T query(int row, int col)
	{
		T ans = 0;
		for(; row >= 1; row -= (row & -row))
			ans = max(query_row(row, col), ans);
		
		return ans;
	}
};
 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(0); 


	return 0;
}