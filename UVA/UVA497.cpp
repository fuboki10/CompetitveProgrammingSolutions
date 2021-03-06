#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vll;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<string, int> msi;
typedef map<string, string> mss;
#define re return
#define clr(x, v) memset(x, v, sizeof(x))
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
#define NumofDigits(n) ((int)log10(n) + 1)
#define sc1(x) scanf("%d", &x)
#define sc2(x, y) scanf("%d%d", &x, &y)
#define sc3(x, y, z) scanf("%d%d%d", &x, &y, &z)
#define sz size()
#define rep(i, v) for (int i = 0; i < (int)v.sz; i++)
#define lp(i, a, b) for (int i = int(a); i < int(b); i++)
#define lpi(i, b, a) for (int i = int(b); i >= a; i--)
#define watch(x) cout << (#x) << " is " << (x) << endl
#define print(ans) cout << ans << endl
#define print2(a, b) cout << a << ' ' << b << endl
#define EPS 1e-10
#define MAX 1000005
#define INF 1e18
ll MOD = 1e9 + 7;
const double PI = acos(-1.0);
#define print_prec(ans, num) cout << fixed << setprecision(num) << (ans) << endl
#define IO                          \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL)
const int dx[] = {1, -1, 0, 0, 0, 0};
const int dy[] = {0, 0, 1, -1, 0, 0};
const int dz[] = {0, 0, 0, 0, 1, -1};
const int N = 1000 + 5;

int main()
{
	//freopen("read.txt", "r", stdin);
	//freopen("write.txt", "w", stdout);
	//IO;
	int t;
	cin >> t;
	cin.ignore();
	cin.ignore();
	while (t--)
	{
		vi a;
		string s;
		while (getline(cin, s) && s != "")
		{
			stringstream ss(s);
			int missle;

			ss >> missle;
			a.push_back(missle);
		}

		int n = (int)a.sz;

		vi lis(n, 1);
		vi path(n, -1);
		int mx = 0;
		lp(i, 1, n) lp(j, 0, i)
		{
			int l = a[j] < a[i] ? lis[j] + 1 : 0;
			if (l > lis[i])
			{
				lis[i] = l;
				path[i] = j;
				if (lis[i] > lis[mx])
					mx = i;
			}
		}

		cout << "Max hits: " << lis[mx] << endl;
		vi ans;
		while (~mx)
			ans.pb(a[mx]), mx = path[mx];
		reverse(all(ans));
		for (auto u : ans)
			cout << u << endl;
		if (t)
			cout << endl;
	}
}