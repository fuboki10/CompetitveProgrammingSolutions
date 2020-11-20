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
vi connections[1000];
bool vis[1000];

enum status {PATH = 0, CYCLE = 1};

status dfs(int cur_node, int par_node, int &nodes_cnt)
{
	if(vis[cur_node])
		return CYCLE;

	vis[cur_node] = 1;

	for(auto child_node : connections[cur_node]) if(child_node != par_node)
	{
		++nodes_cnt;

		if(dfs(child_node, cur_node, nodes_cnt) == CYCLE)
			return CYCLE;
	}
	return PATH;
}


int main()
{
    //freopen("read.txt", "r", stdin);
    //freopen("write.txt", "w", stdout);
    IO;
    int n,m;
    cin >> n >> m;
    int x,y;
    for (int i = 0; i < m; ++i)
    {
        cin >> x >> y;
        connections[x].pb(y);
        connections[y].pb(x);
    }
    MEM(vis);
    int toRemove = 0;

    for (int i = 1; i <= n; i++) if(!vis[i])
    {
        int cnt = 0;

        status solve = dfs(i, -1, cnt);

        if(solve == CYCLE)
            toRemove += (cnt % 2 == 1);
    }

    if( (n - toRemove) % 2 == 1)
        toRemove++;

    cout<<toRemove<<endl;
    return 0;
}
