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

struct trie
{
	int psz, cnt[MAXN], len[MAXN];
	map<char, int> to[MAXN];	

	trie() { psz = 1; }

	void clear() { for(int i = 0; i < psz; i++) cnt[i] = 0, len[i] = 0, to[i].clear(); psz = 1; }

	void add(string s)
	{
		int u = 0;
		for(char c: s)	
		{
			if(!to[u].count(c)) len[psz] = len[u] + 1, to[u][c] = psz++;
			u = to[u][c]; cnt[u]++;
		}
	}	
	
	void del(string s)
	{
		int u = 0;
		for(char c: s)	
		{
			if(!to[u].count(c)) return;
			u = to[u][c]; cnt[u]--;
		}
	}

	int count(string s)
	{
		int u = 0;
		for(char c: s)
		{
			if(!to[u].count(c)) return 0;
			u = to[u][c]; 
		}

		return cnt[u];
	}
};

trie t;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(0); 



	return 0;
}