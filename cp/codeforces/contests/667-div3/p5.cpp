#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int solve()
{
    int n, k, res = 1;
    cin >> n >> k;
    vector<int> x(n), y(n), pre(n), suf(n);
    for (int i = 0; i < n; i++)
        cin >> x[i];
    for (int i = 0; i < n; i++)
        cin >> y[i];
    sort(x.begin(), x.end());
    for (int i = 0; i < n; i++)
    {
        int req = x[i] - k;
        int idx = lower_bound(x.begin(), x.end(), req) - x.begin();
        pre[i] = i - idx + 1;
    }
    for (int i = n - 1; i >= 0; i--)
    {
        int req = x[i] + k;
        int idx = upper_bound(x.begin(), x.end(), req) - x.begin();
        suf[i] = idx - i;
    }
    for (int i = 1; i < n; i++)
        pre[i] = max(pre[i - 1], pre[i]);
    for (int i = n - 2; i >= 0; i--)
        suf[i] = max(suf[i + 1], suf[i]);
    for (int i = 0; i < n - 1; i++)
        res = max(res, pre[i] + suf[i + 1]);
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