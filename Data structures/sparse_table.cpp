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
const int MAXLOG = 20;

struct SparseTable{
	int sparse[MAXN][MAXLOG];
	int prec_lg2[MAXN];
	int n;

	SparseTable() { 
		memset(sparse, 0, sizeof(sparse)); 
		memset(prec_lg2, 0, sizeof(prec_lg2));
		n = 0; 
	}

	static int operation(const int a , const int b){
		return min(a , b);
	}

	void init(vector<int> &a) {
		n = a.size();
		
		for(int i = 2 ; i < 2 * n ; ++i){
			prec_lg2[i] = prec_lg2[i >> 1] + 1;
		}
		
		for(int i = 0 ; i < n ; ++i){
			sparse[i][0] = a[i];
		}
		
		for(int j = 1 ; (1 << j) <= n ; ++j){    
			for(int i = 0; i < n ; ++i){
				sparse[i][j] = operation(sparse[i][j - 1], sparse[i + (1 << (j - 1))][j - 1]);
			}
		}
	}

	int query(int l, int r) { //[l,r]
		int k = prec_lg2[r - l + 1];
		return operation(sparse[l][k], sparse[r - (1 << k) + 1][k]);
	}
};
 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(0); 
	
	int n = 15;
	vi v(n , 0);
	rep(i , n){
		v[i] = rand() % 322;
		cout << v[i] << " ";
	}
	cout << endl;
	
	SparseTable table;
	table.init(v);
	

	return 0;
}