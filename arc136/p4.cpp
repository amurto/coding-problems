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

const int N = 1e6;

bool is_valid(int x, int req)
{
    for (int j = 0, k = 1; j < 6; j++, k *= 10)
    {
        int dig1 = (x / k) % 10, dig2 = (req / k) % 10;
        if (dig1 > dig2)
            return false;
    }
    return true;
}

ll solve()
{
    int n;
    cin >> n;
    ll res = 0;
    vector<int> arr(n), dp(N);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        dp[arr[i]]++;
    }
    for (int j = 0, k = 1; j < 6; j++, k *= 10)
    {
        for (int i = 1; i < N; i++)
        {
            int dig = (i / k) % 10;
            if (dig > 0)
                dp[i] += dp[i - k];
        }
    }
    for (int i = 0; i < n; i++)
    {
        int req = N - 1 - arr[i];
        int c = dp[req];
        if (is_valid(arr[i], req))
            c--;
        res += 1ll * c;
    }
    return res / 2;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}