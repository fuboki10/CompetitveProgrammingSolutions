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
std::vector<pair<int,char>> in(3);

int main()
{
    //freopen("read.txt", "r", stdin);
    //freopen("write.txt", "w", stdout);
    IO;
    in[0] = {0,'A'};
    in[1] = {0,'B'};
    in[2] = {0,'C'};
    string s;
    for (int i = 0; i < 3; ++i)
    {
        cin >> s;
        if (s[1] == '>')
        {
            in[s[0] - 'A'].X++;
        }
        else if (s[1] == '<')
        {
            in[s[2] - 'A'].X++;
        }
    }
    sort(all(in));
    if (in[0].X == in[1].X || in[1].X == in[2].X)
    {
        std::cout << "Impossible\n" << "\n";
    }
    else
    {
        for (auto& var : in)
        {
            std::cout << var.Y;
        }
        std::cout <<"\n";
    }
    return 0;
}
