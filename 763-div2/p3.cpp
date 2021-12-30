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

bool check(vector<ll> arr, vector<ll> op, int n, ll x)
{
    for (int i = n - 1; i > 1; i--)
    {
        if (arr[i] < x)
            return false;
        ll t = min((arr[i] - x) / 3, op[i]);
        arr[i] -= t * 3;
        arr[i - 1] += t;
        arr[i - 2] += t * 2;
    }
    for (int i = 0; i < n; i++)
        if (arr[i] < x)
            return false;
    return true;
}

ll solve()
{
    int n;
    cin >> n;
    vector<ll> arr(n), op(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        op[i] = arr[i] / 3;
    }
    ll low = 1, high = 1e9 + 5, res = 1;
    while (low <= high)
    {
        ll mid = low + (high - low) / 2;
        if (check(arr, op, n, mid))
        {
            res = max(res, mid);
            low = mid + 1;
        }
        else
            high = mid - 1;
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