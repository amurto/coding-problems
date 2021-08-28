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

int hp(int n)
{
    for (int i = 0; i < 30; i++)
        if ((1 << i) > n)
            return i;
    return 20;
}

int solve()
{
    int n, m;
    cin >> n >> m;
    int res = n;
    int b = hp(n + 1);
    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    int sum = 0;
    vector<int> st1(1 << b), st2(1 << b);
    for (int i = 1; i <= n; i++)
    {
        sum += arr[i];
        sum %= m;
        st1[i] = sum;
        st2[n - i] = sum;
    }
    for (int mask = 0; mask < (1 << b); mask++)
    {
        for (int j = mask; j >= 0; j = (j - 1) & mask)
        {
            // mask is original set
            // j is subset
            if (mask + j < n && st1[j] == st2[mask])
            {
                res = min(res, __builtin_popcount(mask));
            }
            if (j == 0)
                break;
        }
    }
    return res == n ? -1 : res;
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