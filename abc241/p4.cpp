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

const ll inf = 1e18 + 5;
void solve()
{
    int q;
    cin >> q;
    multiset<ll> ms;
    ms.insert(-inf);
    ms.insert(inf);
    for (int i = 0; i < q; i++)
    {
        int t, k;
        ll x;
        cin >> t >> x;
        if (t == 1)
            ms.insert(x);
        else if (t == 2)
        {
            cin >> k;
            auto it = ms.lower_bound(x + 1);
            it--;
            ll ans = inf;
            int cnt = 0;
            while (*it != -inf && cnt < k)
            {
                ans = min(ans, *it);
                it--;
                cnt++;
            }
            if (cnt < k)
                cout << "-1\n";
            else
                cout << ans << "\n";
        }
        else
        {
            cin >> k;
            auto it = ms.lower_bound(x);
            ll ans = -inf;
            int cnt = 0;
            while (*it != inf && cnt < k)
            {
                ans = max(ans, *it);
                it++;
                cnt++;
            }
            if (cnt < k)
                cout << "-1\n";
            else
                cout << ans << "\n";
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