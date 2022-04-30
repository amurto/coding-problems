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

const int K = 26;
int solve()
{
    int n, k, res = 0;
    cin >> n >> k;
    vector<string> arr(n);
    vector<vector<int>> st(n, vector<int>(K));
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        for (char ch : arr[i])
            st[i][ch - 'a'] = 1;
    }
    for (int mask = 0; mask < (1 << n); mask++)
    {
        int ans = 0;
        vector<int> cnt(K);
        for (int j = 0; j < n; j++)
            if ((mask >> j) & 1)
                for (int i = 0; i < K; i++)
                    cnt[i] += st[j][i];
        for (int v : cnt)
            if (v == k)
                ans++;
        res = max(res, ans);
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