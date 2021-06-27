#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

mt19937 rng((unsigned int)chrono::steady_clock::now().time_since_epoch().count());

ll solve()
{
    int n;
    cin >> n;
    ll res = 0;
    vector<ll> arr(n + 1), ids(2 * n + 5);
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    for (int i = 1; i <= n; i++)
        ids[arr[i]] = i;
    for (int i = 1; i <= n; i++)
    {
        ll v = arr[i];
        for (ll k = v, m = 1; k <= 2 * n; k += v, m++)
            res += (ids[m] != 0 && ids[m] < i && ids[m] == k - i);
    }
    return res;
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