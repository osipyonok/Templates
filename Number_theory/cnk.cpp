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
	
struct CNK{
	const int mod = 1000000007;
	int mx;
   
private:
	vi fac , ifac;
	   
public:
	CNK(int max){
		mx = max;
	   
		fac.resize(max + 1);
		ifac.resize(max + 1);
	   
		fac[0] = ifac[0] = 1;
	   
		for(int i = 1 ; i <= max ; ++i){
			fac[i] = 1LL * fac[i - 1] * i % mod;
			ifac[i] = fpow(fac[i], mod - 2);
		}
	}
   
	int fpow(int a , int b){
		ll ans = 1;
		while(b > 0){
			if(b & 1){
				ans = (1LL * ans * a) % mod;
			}
			a = (1LL * a * a) % mod;
			b /= 2;
		}
		return ans;
	}
   
	int cnk(int n , int k){
		assert(mx >= n);
		if (n < 0 || k < 0 || k > n) return 0;
		return 1LL * fac[n] * ifac[n - k] % mod * ifac[k] % mod;
	}
};
 


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(0); 

	/*
	int C[maxn+1][maxn+1];
	for (int n=0; n<=maxn; ++n) {
	    C[n][0] = C[n][n] = 1;
	    for (int k=1; k<n; ++k)
	        C[n][k] = C[n-1][k-1] + C[n-1][k];
	}
	*/

	return 0;
}