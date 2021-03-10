#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

double dis(int p1, int p2)
{
    return sqrt(1.0 * p1 * p1 + 1.0 * p2 * p2);
}

double solve()
{
    int n, px, py;
    cin >> n;
    vector<int> m, d;
    for (int i = 0; i < 2*n; i++)
    {
        cin >> px >> py;
        if (px < 0)
            px *= -1;
        if (py < 0)
            py *= -1;
        if (px == 0)
            m.pb(py);
        else
            d.pb(px);
    }
    sort(m.begin(), m.end());
    sort(d.begin(), d.end());
    double res = 0;
    for (int i = 0; i < n; i++)
        res += dis(m[i], d[i]);
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(18);
    int t;
    cin >> t;
    while (t-- > 0)
        cout << solve() << "\n";
    return 0;
}