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

bool is_win(string board)
{
    bool row = (board[0] != '.' && board[0] == board[1] && board[1] == board[2]) ||
               (board[3] != '.' && board[3] == board[4] && board[4] == board[5]) ||
               (board[6] != '.' && board[6] == board[7] && board[7] == board[8]) ;

    bool col = (board[0] != '.' && board[0] == board[3] && board[3] == board[6]) ||
               (board[1] != '.' && board[1] == board[4] && board[4] == board[7]) ||
               (board[2] != '.' && board[2] == board[5] && board[5] == board[8]) ;

    bool diag = (board[0] != '.' && board[0] == board[4] && board[4] == board[8]) ||
                (board[2] != '.' && board[2] == board[4] && board[4] == board[6]) ;

    return row || col || diag;
}

int main()
{
    //freopen("read.txt", "r", stdin);
    //freopen("write.txt", "w", stdout);
    IO;
    int t;
    cin >> t;
    while (t--)
    {
        string board = "";
        for (int i = 0; i < 3; ++i)
        {
            string row;
            cin >> row;
            board += row;
        }

        std::queue<pair<string,bool>> q;
        string start = ".........";
        q.push({start,1});
        string ans = "no";
        while (!q.empty())
        {
            string cur = q.front().X;
            bool player = q.front().Y;
            q.pop();
            if (cur == board)
            {
                ans = "yes";
                break;
            }
            if (is_win(cur))
            {
                continue;
            }
            for (int i = 0; i < 9; ++i)
            {
                if (cur[i] == '.')
                {
                    cur[i] = (player ? 'X' : 'O');
                    if(cur[i] == board[i]) {
                        q.push({cur, 1 ^ player});
                    }
                    cur[i] = '.';
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
