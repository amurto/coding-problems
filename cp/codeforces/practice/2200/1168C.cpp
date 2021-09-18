// https://codeforces.com/contest/1168/problem/C
// And Reachability

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

const int K = 20;
void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> arr(n + 1), last(K);
    vector<vector<int>> dp(n + 1, vector<int>(K));
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        vector<int> set_bits, unset_bits;
        for (int j = 0; j < K; j++)
            if ((arr[i] >> j) & 1)
                set_bits.pb(j);
            else
                unset_bits.pb(j);
        for (int x : set_bits)
        {
            if (last[x] > 0)
                for (int y : unset_bits)
                    dp[i][y] = max(dp[i][y], dp[last[x]][y]);
            dp[i][x] = i;
            last[x] = i;
        }
    }
    for (int i = 0; i < q; i++)
    {
        int x, y;
        bool sat = false;
        cin >> x >> y;
        for (int j = 0; !sat && j < K; j++)
            if (((arr[x] >> j) & 1) && dp[y][j] >= x)
                sat = true;
        sat ? cout << "Shi\n" : cout << "Fou\n";
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