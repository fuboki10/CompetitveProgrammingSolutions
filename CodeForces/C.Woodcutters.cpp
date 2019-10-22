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

ll OO = 1e18;

const int MAXI = 2e5 + 5;
vector<pair<ll, ll>> trees;
ll dp[MAXI][4];
ll n, t, h;
 
ll maximum(ll idx = 0, ll type = 3, ll maxiX = -OO)
{
	if (idx == n) return 0;
	
	ll &ret = dp[idx][type];
	if (~ret) return ret;
	ret = 0;
 
	ret = maximum(idx + 1, 0, trees[idx].X);
 
	if (trees[idx].X - trees[idx].Y > maxiX) 
		ret = max(ret, maximum(idx + 1, 1, trees[idx].X) + 1);
 
	if (idx == n - 1 || trees[idx].X + trees[idx].Y < trees[idx + 1].X )
		ret = max(ret, maximum(idx + 1, 2, trees[idx].X + trees[idx].Y) + 1);
 
	return ret;
}
 
int main()
{
	IO;
	cin >> n;
	memset(dp, -1, sizeof dp);
	
	for (int i = 0; i < n; i++)
		cin >> t >> h, trees.push_back({ t, h });
 
	cout << maximum() << endl;
	return 0;
}
