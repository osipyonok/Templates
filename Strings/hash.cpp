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
	
struct Hash{
	vector<ll> suf , pows;
	ll mod;
   
	Hash(string & s , int base = 153 , int _mod = 1000000007){
		int n = s.size();
		suf = vector<ll>(n + 1 , 0LL);
		pows = vector<ll>(n + 1 , 0LL);
		pows[1] = base;
		mod = _mod;
		repn(i , n){
			suf[i] = (s[i] + suf[i + 1] * pows[1]) % mod;
		}
		repf(i , 2 , n + 1){
			pows[i] = (base * pows[i - 1]) % mod;
		}
	}
	
	ll str(int l , int r){ // [l , r]
		ll res = (suf[l] - suf[r + 1] * pows[r - l + 1]) % mod;
		while(res < 0)res += mod;
		return res % mod;
	}
};


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(0); 



	return 0;
}