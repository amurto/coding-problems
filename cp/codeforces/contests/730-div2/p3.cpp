#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int M = 1e6;

double prob(int x, int y)
{
    return (1.0 * x) / (1.0 * y);
}

double dfs(int len, int c, int m, int p, int v)
{
    double res = prob(p, M) * len;
    if (c > 0)
    {
        int tmp = (m == 0) ? 0 : m + min(c, v) / 2;
        int d = (m == 0) ? 1 : 2;
        res += prob(c, M) * dfs(len + 1, max(0, c - v), tmp, p + min(c, v) / d, v);
    }
    if (m > 0)
    {
        int tmp = (c == 0) ? 0 : c + min(m, v) / 2;
        int d = (c == 0) ? 1 : 2;
        res += prob(m, M) * dfs(len + 1, tmp, max(0, m - v), p + min(m, v) / d, v);
    }
    return res;
}

double solve()
{
    double c, m, p, v;
    cin >> c >> m >> p >> v;
    c *= M;
    m *= M;
    p *= M;
    v *= M;
    return dfs(1, round(c), round(m), round(p), round(v));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(12);
    int t;
    cin >> t;
    while (t-- > 0)
        cout << solve() << "\n";
    return 0;
}