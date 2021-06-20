#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

void solve()
{
    int n, q, l, r;
    string str;
    cin >> n >> q >> str;
    vector<vector<int>> ids(26), freq(n, vector<int>(26));
    for (int i = 0; i < n; i++)
    {
        ids[str[i] - 'a'].pb(i);
        if (i > 0)
            freq[i] = freq[i - 1];
        freq[i][str[i] - 'a']++;
    }
    for (int i = 0; i < 26; i++)
        ids[i].pb(n);
    for (int i = 0; i < q; i++)
    {
        cin >> l >> r;
        l--;
        r--;
        vector<int> st;
        for (int j = 0; j < 26; j++)
        {
            int id = lower_bound(ids[j].begin(), ids[j].end(), l) - ids[j].begin();
            if (ids[j][id] < n)
                st.pb(j);
        }
        ll res = 0;
        for (int j : st)
        {
            int cnt = freq[r][j];
            if (l > 0)
                cnt -= freq[l - 1][j];
            res += 1ll * (j + 1) * cnt;
        }
        cout << res << "\n";
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