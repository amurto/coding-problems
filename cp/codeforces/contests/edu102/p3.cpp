#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1), p(k + 1);
    for (int i = 1; i <= k; i++)
        a[i] = i;
    for (int i = k + 1; i <= n; i++)
        a[i] = a[i - 1] - 1;
    for (int i = 1; i <= k; i++)
        p[i] = i;
    int rem = n - k;
    if (rem > 0)
        for (int i = n, cur = k; i >= k; i--, cur--)
            p[a[i]] = cur;
    for (int i = 1; i <= k; i++)
        cout << p[i] << " ";
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