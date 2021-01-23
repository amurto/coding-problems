// https://codeforces.com/contest/816/problem/B
// Karen and Coffee

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int N = 2e5 + 1;
vector<int> f(N + 1), pre(N + 1);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, k, q, l, r, mn = N, mx = 0;
    cin >> n >> k >> q;
    vector<int> arr(n), dep(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i] >> dep[i];
        mn = min(mn, arr[i]);
        mx = max(mx, dep[i]);
        f[arr[i]]++;
        f[dep[i] + 1]--;
    }
    for (int i = 1; i <= N; i++)
        f[i] += f[i - 1];
    for (int i = 1; i <= N; i++)
        if (f[i] >= k)
            pre[i] = 1;
    for (int i = 1; i <= N; i++)
        pre[i] += pre[i - 1];
    while (q-- > 0)
    {
        cin >> l >> r;
        cout << pre[r] - pre[l - 1] << "\n";
    }
    return 0;
}