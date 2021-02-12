#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

void solve()
{
    int n, q, k, l, r;
    cin >> n >> q >> k;
    vector<int> arr(n + 1);
    vector<ll> pre(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    pre[1] = arr[2] - 2;
    for (int i = 2; i < n; i++)
        pre[i] = pre[i - 1] + arr[i + 1] - arr[i - 1] - 2;
    pre[n] = k - arr[n - 1] - 1;
    for (int i = 0; i < q; i++)
    {
        cin >> l >> r;
        ll cur = k;
        if (l == r)
            cur--;
        else if (r - l == 1)
            cur -= arr[r] - arr[l] - 3;
        else
            cur -= pre[r - 1] - pre[l] + arr[l + 1] - arr[r - 1] - 3;
        cout << cur << "\n";
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