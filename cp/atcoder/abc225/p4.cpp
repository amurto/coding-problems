#ifdef use_debug
#define TERMINAL
#include "headers/debug.cpp"
#else
#define d(...) 0
#endif
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> prev(n + 1, -1), nxt(n + 1, -1);
    for (int i = 0; i < q; i++)
    {
        int t, x, y;
        cin >> t;
        if (t == 1)
        {
            cin >> x >> y;
            nxt[x] = y;
            prev[y] = x;
        }
        else if (t == 2)
        {
            cin >> x >> y;
            nxt[x] = prev[y] = -1;
        }
        else
        {
            cin >> x;
            vector<int> cars;
            int cur = x;
            while (cur != -1)
            {
                cars.pb(cur);
                cur = prev[cur];
            }
            reverse(cars.begin(), cars.end());
            cur = nxt[x];
            while (cur != -1)
            {
                cars.pb(cur);
                cur = nxt[cur];
            }
            cout << (int)cars.size() << " ";
            for (int c : cars)
                cout << c << " ";
            cout << "\n";
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