#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int N = 3e3 + 5;

ll dfs(vector<int> &freq, int cur, int e, int i)
{
    if (i == 12)
        return freq[e] * 1ll * freq[cur];
    int b = 1 << i;
    ll res = dfs(freq, cur, e, i + 1);
    if (b & cur)
        res += dfs(freq, cur, e | b, i + 1);
    return res;
}

ll solve()
{
    int n, x;
    ll res = 0;
    cin >> n;
    vector<int> freq(N);
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        freq[x]++;
    }
    for (int i = 0; i < N; i++)
    {
        if (freq[i] == 0)
            continue;
        res += dfs(freq, i, 0, 0);
    }
    return res;
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