#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

void solve()
{
    int n, l, r, s;
    cin >> n >> l >> r >> s;
    int len = r - l + 1;
    int d = s / len, m = s % len;
    vector<int> seq(len, d), res(n + 1);
    vector<bool> vis(n + 1);
    for (int i = 0; i < m; i++)
        seq[i]++;
    for (int i = 0, j = len - 1; i < j; i++, j--)
    {
        int lv = seq[i], rv = seq[j];
        while (lv - 1 > 0 && !vis[lv - 1] && rv + 1 <= n && !vis[rv + 1])
        {
            lv--;
            rv++;
        }
        seq[i] = lv;
        seq[j] = rv;
        vis[lv] = true;
        vis[rv] = true;
    }
    sort(seq.begin(), seq.end());
    int sum = seq[0];
    for (int i = 1; i < len; i++)
    {
        if (seq[i - 1] == seq[i])
        {
            cout << "-1\n";
            return;
        }
        sum += seq[i];
    }
    if (seq[0] <= 0 || seq.back() > n)
    {
        cout << "-1\n";
        return;
    }
    if (sum != s)
    {
        cout << "-1\n";
        return;
    }
    for (int i = l, j = 0; i <= r; i++, j++)
    {
        vis[seq[j]] = true;
        res[i] = seq[j];
    }
    stack<int> st;
    for (int i = 1; i <= n; i++)
        if (!vis[i])
            st.push(i);
    for (int i = 1; i <= n; i++)
    {
        if (i >= l && i <= r)
            continue;
        res[i] = st.top();
        st.pop();
    }
    for (int i = 1; i <= n; i++)
        cout << res[i] << " ";
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        solve();
    return 0;
}