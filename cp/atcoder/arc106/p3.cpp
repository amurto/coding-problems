#ifdef use_debug
#define TERMINAL
#include "headers/debug.cpp"
#else
#define d(...) 0
#endif
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back

void solve()
{
    int n, m;
    cin >> n >> m;
    if (n == 1 && m == 0)
    {
        cout << 1 << " " << 2 << "\n";
        return;
    }
    if (m < 0 || m >= n - 1)
    {
        cout << "-1\n";
        return;
    }
    vector<pii> pts;
    if (m == 0)
    {
        for (int i = 1; i <= n; i++)
            pts.pb({2 * i - 1, 2 * i});
    }
    else
    {
        int last = 1;
        pts.pb({1, 2 * (m + 1) + 2});
        for (int i = 1; i <= m + 1; i++)
        {
            pts.pb({last + 1, last + 2});
            last += 2;
        }
        last = 2 * (m + 1) + 2;
        int rem = n - (m + 2);
        for (int i = 1; i <= rem; i++)
        {
            pts.pb({last + 1, last + 2});
            last += 2;
        }
    }
    for (pii p : pts)
        cout << p.first << " " << p.second << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}