#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

void solve()
{
    int n, m, l, r, x = 0;
    string str;
    cin >> n >> m >> str;
    vector<int> pre(n + 1), pmn(n + 1), pmx(n + 1), smn(n + 1), smx(n + 1);
    for (int i = 1; i <= n; i++)
    {
        pre[i] = pre[i - 1];
        if (str[i - 1] == '+')
            pre[i]++;
        else
            pre[i]--;
        pmn[i] = min(pmn[i - 1], pre[i]);
        pmx[i] = max(pmx[i - 1], pre[i]);
    }
    smn[n] = pre[n];
    smx[n] = pre[n];
    for (int i = n - 1; i >= 1; i--)
    {
        smn[i] = min(smn[i + 1], pre[i]);
        smx[i] = max(smx[i + 1], pre[i]);
    }
    while (m-- > 0)
    {
        int l, r, mx, mn, tmn = 0, tmx = 0;
        cin >> l >> r;
        mn = pmn[l - 1];
        mx = pmx[l - 1];
        if (r < n)
        {
            mn = min(mn, smn[r + 1] - pre[r] + pre[l - 1]);
            mx = max(mx, smx[r + 1] - pre[r] + pre[l - 1]);
        }
        cout << mx - mn + 1 << "\n";
    }
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