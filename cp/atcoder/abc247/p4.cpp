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
    int q;
    cin >> q;
    deque<pii> dq;
    for (int i = 0; i < q; i++)
    {
        int t, x, c;
        cin >> t;
        if (t == 1)
        {
            cin >> x >> c;
            dq.push_back({x, c});
        }
        else
        {
            cin >> c;
            ll sum = 0;
            while (c > 0)
            {
                int mn = min(c, dq.front().second);
                c -= mn;
                sum += mn * 1ll * dq.front().first;
                if (mn < dq.front().second)
                {
                    pii v = dq.front();
                    dq.pop_front();
                    v.second -= mn;
                    dq.push_front(v);
                }
                else
                    dq.pop_front();
            }
            cout << sum << "\n";
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}