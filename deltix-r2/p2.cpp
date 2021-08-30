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

const ll inf = 1e18;
ll solve()
{
    int n;
    ll res = inf;
    cin >> n;
    vector<int> arr(n), cnt(2);
    vector<vector<int>> ids(2);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        cnt[arr[i] % 2]++;
        ids[arr[i] % 2].pb(i);
    }
    int pos = (n - 1) / 2 + 1;
    for (int p = 0; p < 2; p++)
    {
        if (cnt[p] == pos)
        {
            int cur = 0;
            ll dis = 0;
            for (int id : ids[p])
            {
                dis += 1ll * abs(cur - id);
                cur += 2;
            }
            res = min(res, dis);
        }
    }
    return res >= inf ? -1 : res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        cout << solve() << "\n";
    return 0;
}