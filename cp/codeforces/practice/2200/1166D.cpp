// https://codeforces.com/contest/1166/problem/D
// Cute Sequences

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

ll contribution(ll diff)
{
    if (diff <= 1)
        return 1ll;
    return 1ll << (diff - 1);
}

bool calc(ll a, ll b, ll m, int k)
{
    vector<ll> arr(k + 1);
    arr[1] = a;
    ll pre = 0;
    for (int i = 2; i <= k; i++)
    {
        if (pre + arr[i - 1] > b)
            return false;
        pre += arr[i - 1];
        arr[i] = pre + 1;
    }
    if (arr[k] > b)
        return false;
    ll req = b - arr[k];
    for (int i = 2; i <= k; i++)
    {
        if (req > 0)
        {
            ll c = contribution(k - i);
            ll v = min(m - 1, req / c);
            req -= v * c;
            arr[i] += v;
            for (int j = i + 1; j <= k; j++, v *= 2)
                arr[j] += v;
        }
    }
    if (arr[k] != b)
        return false;
    cout << k << " ";
    for (int i = 1; i <= k; i++)
        cout << arr[i] << " ";
    cout << "\n";
    return true;
}

void solve()
{
    int q;
    ll a, b, m;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        cin >> a >> b >> m;
        if (a == b)
            cout << "1 " << a << "\n";
        else
        {
            bool pos = false;
            for (int k = 2; !pos && k <= 50; k++)
                if (calc(a, b, m, k))
                    pos = true;
            if (!pos)
                cout << "-1\n";
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