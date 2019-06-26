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
#define clr(x,v) memset(x,v,sizeof(x))
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
#define UNIQUE(c) (c).resize(unique(ALL(c)) - (c).begin())
#define NumofDigits(n) ((int)log10(n)+1)
#define sc1(x)  scanf("%d",&x)
#define sc2(x,y)  scanf("%d%d",&x,&y)
#define sc3(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define sz(v) (int)(v.size())
#define rep(i,v) for (int i = 0; i < sz(v); i++)
#define lp(i, a, b) for (int i = int(a); i < int(b); i++)
#define lpi(i, b, a) for (int i = int(b); i >= a; i--)
#define watch(x) cout << (#x) << " is " << (x) << endl
#define EPS 1e-9
#define MAX 1000005
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
int par[MAX], size[MAX];
int getPar(int x)
{
    if (x == par[x]) return x; else return par[x] = getPar(par[x]);
}
int getSize(int x)
{
    return size[getPar(x)];
}
void build(int n)
{
    lp(i,0,n)
    {
        par[i] = i;
        size[i] = 1;
    }
}
void Union(int x, int y)
{
    int px = getPar(x), py = getPar(y);
    if (px == py) return;
    par[px] = py;
    size[py] += size[px];
}
msi id;
int main()
{
    //freopen("read.txt", "r", stdin);
    //freopen("write.txt", "w", stdout);
    //IO;
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        int cnt = 0;
        build(min(2*n, 100000));
        id.clear();
        while (n--)
        {
            string s1,s2;
            cin >> s1 >> s2;
            if (!id.count(s1))
            {
                id[s1] = cnt++;
            }
            if (!id.count(s2))
            {
                id[s2] = cnt++;
            }
            int id1 = id[s1], id2 = id[s2];
            Union(id1, id2);
            std::cout << getSize(id1) << "\n";
        }
    }
    return 0;
}
