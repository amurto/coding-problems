#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back

void solve()
{
    int n, c, l, r, mx = 1;
    cin >> n >> c;
    vector<int> res(n + 1);
    for (int i = 0; i < c; i++)
    {
        cin >> l >> r;
        mx = max(mx, r - l + 1);
    }
    for (int i = 2; i <= n; i++)
        res[i] = (res[i - 1] + 1) % mx;
    for (int i = 1; i <= n; i++)
        cout << res[i] + 1 << " ";
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