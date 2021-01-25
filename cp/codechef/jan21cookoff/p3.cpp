#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int MOD = 1e9 + 7;

int add(int x, int y)
{
    x += y;
    while (x >= MOD)
        x -= MOD;
    while (x < 0)
        x += MOD;
    return x;
}

int solve()
{
    int n, m = 0;
    cin >> n;
    vector<int> arr(n + 1), last(n + 1), dp(n + 1), pre(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    arr[0] = arr[n];
    unordered_set<int> st(arr.begin(), arr.end());
    while (st.count(m))
        m++;
    multiset<int> ms;
    for (int i = 0; i < m; i++)
        ms.insert(0);
    dp[0] = pre[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        if (arr[i] < m)
        {
            ms.erase(ms.find(last[arr[i]]));
            last[arr[i]] = i;
            ms.insert(i);
        }
        int f = *ms.begin();
        if (f > 0)
            dp[i] = pre[f - 1];
        if (m == 0)
            dp[i] = pre[i - 1];
        pre[i] = add(pre[i - 1], dp[i]);
    }
    return dp[n];
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