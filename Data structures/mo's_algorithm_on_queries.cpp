#include<bits/stdc++.h>
 
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
#define MAXN 505050
#define LEN (int)(sqrt(MAXN) + 1)
using namespace std;
 
struct Query{
    int l , r , i;
    Query(int _l , int _r , int _i){
        l = _l;
        r = _r;
        i = _i;
    }
};
 
class Mo{
	vector<Query> q;
	public:
	Mo(int query_count , int maxn){
		int l , r;
		rep(kk , query_count){
			cin >> l >> r;
			q.pb(Query(l , r , kk));
		}
		struct{
        	bool operator()(Query & a , Query & b){   
            	return a.l / LEN < b.l / LEN || (a.l / LEN == b.l / LEN && a.r / LEN < b.r / LEN);
        	}   
    	}comp;
		sort(all(q) , comp);
	}
	Query & getQuery(int index){
		assert(index < sz(q));
		return q[index];
	}
};
 
 
vi a(MAXN , 0);
map<int , int> m;
vi cnt(MAXN , 0);
vi ans(MAXN , 0);
 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(0); 
	int num = 1;
    int n , k;
    cin >> n >> k;
    repi(i , n){
        cin >> a[i];
        if(!m[a[i]]){
            m[a[i]] = num;
            ++num;
        }
        a[i] = m[a[i]];
    }
	Mo mo = Mo(k , n);
	cnt[a[1]] = 1;
    int x = 1 , y = 1;
    int t = 0;
    rep(i , k){
    	Query q = mo.getQuery(i);
        int l = q.l;
        int r = q.r;
        while(x > l){
            --x;
            if(cnt[a[x]] == 2)--t;
            ++cnt[a[x]];
            if(cnt[a[x]] == 2)++t;
        }
        while(x < l){
            if(cnt[a[x]] == 2)--t;
            --cnt[a[x]];
            if(cnt[a[x]] == 2)++t;
            ++x;
        }
        while(y < r){
            ++y;
            if(cnt[a[y]] == 2)--t;
            ++cnt[a[y]];
            if(cnt[a[y]] == 2)++t;
        }
        while(y > r){
            if(cnt[a[y]] == 2)--t;
            --cnt[a[y]];
            if(cnt[a[y]] == 2)++t;
            --y;
        }
        ans[q.i] = t;
    }	
    rep(i , k){
        die(ans[i]);
    }
	return 0;
}

/*
task Poklon from COCI 2016/2017 Round #5, January 21st, 2017
Little Mirko is a very simple man. Mirko’s friend Darko has given him an array of N natural
integers and asked him Q queries about the array that Mirko must answer.
Each query consists of two integers, the positions of the left and right end of an interval in
the array. The answer to the query is the number of different values that appear exactly
twice in the given interval. 
INPUT
The first line of input contains the integers N and Q (1 ≤ N, Q ≤ 500 000).
The second line of input contains N natural integers less than 1 000 000 000, the elements
of the array.
Each of the following Q lines contains two integers, L and R (1 ≤ L ≤ R ≤ N), from the task.
OUTPUT
The output must consist of Q lines, each line containing the answer to a query, respectively.
SCORING
In test cases worth 56 points in total, the numbers N and Q will not be larger than 5000. 
Input:
5 2
1 1 2 2 3
1 1
1 5 
Output:
0
2
*/