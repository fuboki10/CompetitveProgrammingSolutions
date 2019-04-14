// Fub0ki
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
typedef long long             ll;
typedef vector<int>           vi;
typedef vector<ll>            vll;
typedef pair<int, int>        ii;
typedef vector<ii>            vii;
typedef set<int>              si;
typedef map<string, int>      msi;
typedef map<string, string>   mss;
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define mp make_pair
#define pb push_back
#define mt make_tuple
#define eb emplace_back
#define bn begin()
#define nd end()
#define X first
#define Y second
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()
#define NumofDigits(n) ((int)log10(n)+1)
#define scn(x)  scanf("%d",&x)
#define lop(i, a, b) for (int i = int(a); i < int(b); i++)
#define watch(x) cout << (#x) << " is " << (x) << endl
#define EPS 1e-9
#define MAX 100005
#define INF 1e18
#define print_prec(ans,num) cout << fixed << setprecision(num) << (ans) << endl
#define IO ios_base::sync_with_stdio(false);cin.tie(NULL)
const int dx[] = { 1,-1,0,0,0,0 };
const int dy[] = { 0,0,1,-1,0,0 };
const int dz[] = { 0,0,0,0,1,-1 };
/*#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistic*/
/*max_element(all(m),
    [](const ii& p1, const ii& p2) {
        return p1.second < p2.second; });*/
const int N = 1e5 + 10;
bool vis[N];
int p[N];
int n,m;
vector<ii> adj[N];
struct edge
{
    int start, cost, parent;
    edge(int st, int c, int par)
    {
        start = st;
        cost = c;
        parent = par;
    }
    bool operator<(const edge& e) const
    {
        return cost > e.cost;
    }
};

void dijkstra(int src)
{
    priority_queue<edge> q;
    MEMS(p);
    q.push(edge(src,0,-1));
    while (!q.empty())
    {
        edge cur = q.top();
        q.pop();
        if (vis[cur.start]) continue;
        vis[cur.start] = 1;
        p[cur.start] = cur.parent;
        if (cur.start == n)
        {
            break;
        }
        for (auto nxt : adj[cur.start])
        {
            if (!vis[nxt.X])
            {
                q.push(edge(nxt.X, cur.cost + nxt.Y, cur.start));
            }
        }
    }
}

int main()
{
    //freopen("read.txt", "r", stdin);
    //freopen("write.txt", "w", stdout);
    IO;
    cin >> n >> m;

    int x,y,c;
    for (int i = 0; i < m; ++i)
    {
        cin >> x >> y >> c;
        adj[x].pb({y,c});
        adj[y].pb({x,c});
    }
    dijkstra(1);
    if (p[n] == -1)
    {
        std::cout << -1 << "\n";
        return 0;
    }
    vi path;
    for (int i = n; i != -1; i = p[i])
    {
        path.pb(i);
    }
    reverse(all(path));
    for (auto var : path)
    {
        std::cout << var << " ";
    }
    std::cout <<"\n";
    return 0;
}
