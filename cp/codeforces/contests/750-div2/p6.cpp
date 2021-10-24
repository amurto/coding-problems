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

const int M = 512, inf = 1e9 + 7;
void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n), dp(M, inf), seq;
    dp[0] = 0;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    for (int i = 0; i < n; i++)
    {
        vector<int> tdp = dp;
        for (int j = 0; j < M; j++)
            if (dp[j] < inf && dp[j] < arr[i])
                tdp[j ^ arr[i]] = min(tdp[j ^ arr[i]], arr[i]);
        swap(dp, tdp);
    }
    for (int i = 0; i < M; i++)
        if (dp[i] < inf)
            seq.pb(i);
    cout << (int)seq.size() << "\n";
    for (int x : seq)
        cout << x << " ";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}