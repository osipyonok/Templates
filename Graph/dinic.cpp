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
 
using namespace std;
 
struct Edge{
    int u , v;
    ll cap , flow;
    Edge() {}
    Edge(int _u , int _v , ll _c){
        u = _u;
        v = _v;
        cap = _c;
        flow = 0;
    }
};
 
 
struct DinicFlow{
    int n;
    vector<Edge> e;
    vector<vi> g;
    vi d , pt;
   
    DinicFlow(int _n){
        n = _n;
        g.resize(n);
        d.resize(n);
        pt.resize(n);
    }
   
    void addEdge(int u , int v , ll cap){
        if(u != v){
            e.pb(Edge(u , v , cap));
            e.pb(Edge(v , u , 0));
            g[u].pb(sz(e) - 2);
            g[v].pb(sz(e) - 1);
        }
    }
   
    bool bfs(int s , int t){
        queue<int> q;
        q.push(s);
       
        d = vi(n , INF);
        d[s] = 0;
       
        while(sz(q)){
            int u = q.front();
            q.pop();
           
            if(u == t)break;
           
            rep(i , sz(g[u])){
                int k = g[u][i];
                Edge &edge = e[k];
                if(edge.flow < edge.cap && d[edge.v] > d[edge.u] + 1){
                    q.push(edge.v);
                    d[edge.v] = d[edge.u] + 1;
                }
            }
        }
       
        return d[t] != INF;
    }
   
    ll dfs(int u , int t , ll flow = -1){
        if(u == t || flow == 0)return flow;
        for(int & i = pt[u] ; i < sz(g[u]) ; ++i){
            int k = g[u][i];
            Edge &edge = e[k];
            Edge &oedge = e[k ^ 1];
            if(d[edge.v] == d[edge.u] + 1){
                ll a = edge.cap - edge.flow;
                if(flow != -1){
                    a = min(a , flow);
                }
                if(ll pushed = dfs(edge.v , t , a)){
                    edge.flow += pushed;
                    oedge.flow -= pushed;
                    return pushed;
                }
               
            }
        }
        return 0;
    }
   
    ll MaxFlow(int s , int t){
        ll total = 0;
        while(bfs(s , t)){
            pt = vi(n , 0);
            while(ll flow = dfs(s , t)){
                total += flow;
            }
        }
        return total;
    }
};
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(0);
 
    int n , m;
    cin >> n >> m;
   
    DinicFlow dinic(n);
   
    rep(i , m){
        int u , v;
        ll c;
        cin >> u >> v >> c;
        --u;
        --v;
        dinic.addEdge(u , v , c);
   //     dinic.addEdge(v , u , c);
    }
    cout << dinic.MaxFlow(0 , n - 1);
 
    return 0;
}