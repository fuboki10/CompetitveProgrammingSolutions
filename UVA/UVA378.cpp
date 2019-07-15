// Fub0ki
// (づ°ω°)づﾐ★゜・。。・゜゜・。。・゜☆゜・。。・゜゜・。。・゜
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
typedef long long             ll;
typedef vector<int>           vi;
typedef vector<ll>            vll;
typedef pair<int, int>        ii;
typedef pair<int, ii>         iii;
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
#define EPS 1e-10
#define MAX 1000005
#define INF 1e18
const double PI = acos(-1.0);
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
struct point_i
{
    int x,y;
    point_i(int _x=0, int _y=0) {x = _x, y = _y;}
};
struct point
{
    double x,y;
    point() {x = y = 0;}
    point(double _x, double _y) {x = _x, y = _y;}
};
struct line
{
    double a,b,c;
};
void to_line(point_i p1, point_i p2, line& l)
{
    if (p1.x == p2.x)
    {
        l.b = 0.0;
        l.a = 1.0;
        l.c = -(double)p1.x;
    }
    else
    {
        l.b = 1.0;
        l.a = -(double)(p1.y - p2.y) / (double)(p1.x - p2.x);
        l.c = -(double)(p1.y + l.a * p1.x);
    }
}
bool are_parallel(line& l1, line& l2)
{
    return ((fabs(l1.a - l2.a) < EPS) && (fabs(l1.b - l2.b) < EPS));
}
bool are_same(line& l1, line& l2)
{
    return ((are_parallel(l1,l2)) && (fabs(l1.c - l2.c) < EPS));
}
bool are_intersect(line l1, line l2, point &p)
{
    if (are_parallel(l1,l2)) return 0;
    p.x = (l1.b * l2.c - l2.b * l1.c) / (l1.a * l2.b - l1.b * l2.a);
    if (fabs(l2.b) > EPS) p.y = -(l2.a * p.x + l2.c);
    else p.y = -(l1.a * p.x + l1.c);
    return 1;
}
void solve(line& l1, line& l2)
{
    point p;
    if (are_parallel(l1,l2))
    {
        if (are_same(l1,l2))
        {
            puts("LINE");
        }else puts("NONE");
    }
    else if (are_intersect(l1, l2, p))
    {
        cout << "POINT "
             << fixed << setprecision(2) << (p.x) << " " << (p.y)<< '\n';
    }
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("write.txt", "w", stdout);
    //IO;
    int n;
    cin >> n;
    puts("INTERSECTING LINES OUTPUT");
    lp(i,0,n)
    {
        int x1,y1,x2,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        line l1;
        to_line(point_i(x1,y1), point_i(x2,y2), l1);
        cin >> x1 >> y1 >> x2 >> y2;
        line l2;
        to_line(point_i(x1,y1), point_i(x2,y2), l2);
        solve(l1,l2);
    }
    puts("END OF OUTPUT");
    return 0;
}
