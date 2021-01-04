#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int bs(vector<int> &h, vector<int> &w, vector<int> &b, vector<int> &pre, int H, int W, int n)
{
    int l, r;
    l = 0, r = n - 1;
    while (l < r)
    {
        int mid = l + (r - l) / 2;
        int idx = b[mid];
        if (H > h[idx])
            l = mid + 1;
        else
            r = mid;
    }
    l--;
    if (l < 0 || W <= w[pre[l]])
        return -1;
    return pre[l];
}

void solve()
{
    int n;
    cin >> n;
    vector<int> b(n), pre(n), h(n), w(n);
    for (int i = 0; i < n; i++)
    {
        cin >> h[i] >> w[i];
        if (h[i] > w[i])
            swap(h[i], w[i]);
    }
    for (int i = 0; i < n; i++)
        b[i] = i;
    auto cmp = [&](int i1, int i2) {
        if (h[i1] == h[i2])
            return w[i1] < w[i2];
        return h[i1] < h[i2];
    };
    sort(b.begin(), b.end(), cmp);
    pre[0] = b[0];
    for (int i = 1; i < n; i++)
    {
        if (w[b[i]] < w[pre[i - 1]])
            pre[i] = b[i];
        else
            pre[i] = pre[i - 1];
    }
    vector<int> res(n, -1);
    for (int i = 0; i < n; i++)
    {
        int c1 = bs(h, w, b, pre, h[i], w[i], n);
        if (c1 >= 0)
            res[i] = c1 + 1;
    }
    for (int rs : res)
        cout << rs << " ";
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