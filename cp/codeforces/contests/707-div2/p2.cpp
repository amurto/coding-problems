#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n), d(n + 2);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    ll cur = 0;
    for (int i = 0; i < n; i++)
    {
        cur++;
        if (arr[i] == 0)
            continue;
        ll tmp = max(0ll, cur - arr[i]);
        d[min(n * 1ll + 1, tmp + 1)]++;
        d[min(n * 1ll + 1, cur + 1)]--;
    }
    for (int i = 1; i < n + 2; i++)
        d[i] += d[i - 1];
    for (int i = 1; i <= n; i++)
        (d[i] > 0) ? cout << "1 " : cout << "0 ";
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