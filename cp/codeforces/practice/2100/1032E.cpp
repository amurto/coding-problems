// https://codeforces.com/contest/1032/problem/E
// The Unbearable Lightness of Weights

#ifdef amurto
#define TERMINAL
#include "headers/debug.cpp"
#else
#define d(...) 0
#endif
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int solve()
{
    int n, res = 1, sum = 0;
    cin >> n;
    vector<int> arr(n), cnt(105);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        cnt[arr[i]]++;
        sum += arr[i];
    }
    set<int> st(arr.begin(), arr.end());
    if (st.size() <= 2)
        return n;
    vector<vector<int>> dp(sum + 1, vector<int>(n + 1));
    dp[0][0] = 1;
    for (int e = 1; e <= 100; e++)
        if (cnt[e] > 0)
            for (int i = sum; i > 0; i--)
                for (int c = 1, j = e; c <= cnt[e]; c++, j += e)
                    for (int k = n; k >= c; k--)
                        if (i - j >= 0)
                            dp[i][k] = min(2, dp[i][k] + dp[i - j][k - c]);
    for (int e = 1; e <= 100; e++)
        if (cnt[e] > 0)
            for (int c = 1, j = e; c <= cnt[e]; c++, j += e)
                if (dp[j][c] == 1)
                    res = max(res, c);
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