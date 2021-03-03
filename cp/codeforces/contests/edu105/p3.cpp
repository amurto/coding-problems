#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int op(vector<int> &a, vector<int> &b)
{
    int n = a.size(), m = b.size(), imx = INT_MAX;
    if (n == 0 || m == 0)
        return 0;
    a.pb(imx);
    set<int> st(b.begin(), b.end());
    vector<int> suf(n + 1);
    for (int i = n - 1; i >= 0; i--)
        suf[i] = suf[i + 1] + (st.find(a[i]) != st.end());
    int res = suf[0];
    for (int i = 1; i <= n; i++)
    {
        int r = lower_bound(b.begin(), b.end(), a[i - 1]) - b.begin();
        if (r >= m)
            continue;
        while (r < m && b[r] < a[i])
        {
            int l = upper_bound(b.begin(), b.end(), b[r] - i) - b.begin();
            res = max(res, r - l + 1 + suf[i]);
            r++;
        }
    }
    return res;
}

int solve()
{
    int n, m, x;
    cin >> n >> m;
    vector<int> a1, a2, b1, b2;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        if (x < 0)
            a1.pb(x);
        else
            a2.pb(x);
    }
    for (int i = 0; i < m; i++)
    {
        cin >> x;
        if (x < 0)
            b1.pb(x);
        else
            b2.pb(x);
    }
    reverse(a1.begin(), a1.end());
    reverse(b1.begin(), b1.end());
    for (int i = 0; i < a1.size(); i++)
        a1[i] *= -1;
    for (int i = 0; i < b1.size(); i++)
        b1[i] *= -1;
    return op(a1, b1) + op(a2, b2);
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