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

ll solve()
{
    int n;
    ll L, res = LLONG_MAX;
    cin >> n >> L;
    vector<ll> arr(n + 1), pre(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    sort(arr.begin(), arr.end());
    for (int i = 1; i <= n; i++)
        pre[i] = pre[i - 1] + arr[i];
    auto calc = [&](const auto &self, int l, int r) -> ll
    {
        if (l == r)
            return 0;
        ll sum = pre[r] - pre[l - 1];
        int low = l, high = r, id = l;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (pre[mid] - pre[l - 1] <= pre[r] - pre[mid])
            {
                id = max(id, mid);
                low = mid + 1;
            }
            else
                high = mid - 1;
        }
        return sum + self(self, l, id) + self(self, id + 1, r);
    };
    res = calc(calc, 1, n);
    if (L > pre[n])
        res += L;
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}