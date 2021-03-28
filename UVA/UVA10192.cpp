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
int MOD = 1e9 + 7;
const double PI = acos(-1.0);
#define print_prec(ans, num) cout << fixed << setprecision(num) << (ans) << endl
#define IO                          \
  ios_base::sync_with_stdio(false); \
  cin.tie(NULL)
const int dx[] = {1, -1, 0, 0, 0, 0};
const int dy[] = {0, 0, 1, -1, 0, 0};
const int dz[] = {0, 0, 0, 0, 1, -1};
const int N = 1e6 + 5;

string a, b;
int n, m;
int dp[100][100];

int lcs(int i, int j)
{
  if (i == n || j == m)
    return 0;
  int &ret = dp[i][j];
  if (~ret)
    return ret;
  if (a[i] == b[j])
    ret = lcs(i + 1, j + 1) + 1;
  else
    ret = max(lcs(i + 1, j), lcs(i, j + 1));
  return ret;
}

int main()
{
  //freopen("read.txt", "r", stdin);
  //freopen("write.txt", "w", stdout);
  //IO;
  int t = 1;
  while (getline(cin, a), a[0] != '#')
  {
    getline(cin, b);
    n = (int)a.sz;
    m = (int)b.sz;
    lp(i, 0, n) lp(j, 0, m) dp[i][j] = -1;
    cout << "Case #" << t++ << ": you can visit at most " << lcs(0, 0) << " cities.\n";
  }
}