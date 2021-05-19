// https://codeforces.com/contest/1223/problem/D
// Sequence Sorting

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int solve()
{
    int n;
    cin >> n;
    vector<int> arr(n), seq(n), id(n + 1);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        seq[i] = arr[i];
    }
    sort(seq.begin(), seq.end());
    seq.resize(unique(seq.begin(), seq.end()) - seq.begin());
    for (int i = 0; i < seq.size(); i++)
        id[seq[i]] = i + 1;
    int mx = id[seq.back()];
    for (int i = 0; i < n; i++)
        arr[i] = id[arr[i]];
    vector<int> lt(mx + 1, -1), rt(mx + 1);
    for (int i = 0; i < n; i++)
    {
        if (lt[arr[i]] == -1)
            lt[arr[i]] = i;
        rt[arr[i]] = i;
    }
    vector<int> dp(mx + 1, 1);
    for (int i = 2; i <= mx; i++)
        if (rt[i - 1] < lt[i])
            dp[i] = dp[i - 1] + 1;
    return mx - *max_element(dp.begin(), dp.end());
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