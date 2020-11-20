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
ll ncr(ll n, ll r)
{
    vll nom,dom;
    for (ll i = 2; i <= n; ++i)
    {
        nom.pb(i);
    }
    for (ll i = 2; i <= n - r; ++i)
    {
        dom.pb(i);
    }
    for (ll i = 2; i <= r; ++i)
    {
        dom.pb(i);
    }
    for (int i = 0; i < nom.size(); ++i)
    {
        for (int j = 0; j < dom.size(); ++j)
        {
            int gc = __gcd(nom[i],dom[j]);
            nom[i] /= gc;
            dom[j] /= gc;
        }
    }
    ll sum1,sum2;
    sum1 = sum2 = 1;
    for (auto var : nom)
    {
        sum1 *= var;
    }
    for (auto var : dom)
    {
        sum2 *= var;
    }
    return sum1 / sum2;
}

int main()
{
    //freopen("read.txt", "r", stdin);
    //freopen("write.txt", "w", stdout);
    ll n,r;
    while (scanf("%lld%lld",&n,&r ) == 2)
    {
        if(n == 0 && r == 0) break;
        ll ans = ncr(n,r);
        printf("%lld things taken %lld at a time is %lld exactly.\n",n,r,ans);
    }
    return 0;
}
