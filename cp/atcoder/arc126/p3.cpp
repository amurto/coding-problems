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

const int N = 3e5 + 5;
ll solve()
{
    int n;
    ll k, res = 1;
    cin >> n >> k;
    vector<int> arr(n), freq(2 * N);
    vector<ll> pre(2 * N);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        freq[arr[i]]++;
        pre[arr[i]] += arr[i];
    }
    for (int i = 1; i < freq.size(); i++)
    {
        freq[i] += freq[i - 1];
        pre[i] += pre[i - 1];
    }
    for (int g = 2; g < N; g++)
    {
        ll inc = 0, req = 0;
        for (int i = 1, j = g; j < 2 * N; i++, j += g)
        {
            int cnt = freq[j] - freq[j - g];
            inc += (1ll * i * cnt);
            ll sum = pre[j] - pre[j - g];
            req += ((1ll * cnt * j) - sum);
        }
        if (req <= k)
            res = max(res, 1ll * g + (k - req) / inc);
    }
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