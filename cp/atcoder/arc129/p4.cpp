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
ll calc(vector<ll> arr, vector<int> prev, vector<int> nxt, int n)
{
    int id = 0, mx = 0, op = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] >= mx)
        {
            mx = arr[i];
            id = i;
        }
    }
    for (int i = id, j = nxt[id], k = nxt[nxt[id]]; k != id;)
    {
        if (arr[i] < 0)
            return inf;
        ll t = arr[i];
        arr[i] -= t;
        arr[j] += 2 * t;
        arr[k] -= t;
        op += t;
        int ti = nxt[i];
        int tj = nxt[j];
        int tk = nxt[k];
        i = ti;
        j = tj;
        k = tk;
    }
    for (int i = 0; i < n; i++)
        if (arr[i] != 0)
            return inf;
    return op;
}

ll solve()
{
    int n;
    cin >> n;
    ll sum = 0, res = inf;

    vector<ll> arr(n);
    vector<int> prev(n), nxt(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        sum += arr[i];
        prev[i] = (i - 1 + n) % n;
        nxt[i] = (i + 1) % n;
    }
    if (sum != 0)
        return -1;
    for (int t = 0; t < 2; t++)
    {
        ll v = calc(arr, nxt, prev, n);
        res = min(res, v);
        reverse(arr.begin(), arr.end());
    }
    return res >= inf ? -1 : res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}