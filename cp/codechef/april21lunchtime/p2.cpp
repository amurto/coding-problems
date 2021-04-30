#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int MOD = 1e9 + 7, N = 3e5 + 1;

int add(int x, int y)
{
    x += y;
    while (x >= MOD)
        x -= MOD;
    while (x < 0)
        x += MOD;
    return x;
}

int mul(int x, int y)
{
    return (x * 1ll * y) % MOD;
}

void solve()
{
    int n, q, x, sum = 0;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        sum = add(sum, arr[i]);
    }
    cin >> q;
    while (q-- > 0)
    {
        cin >> x;
        sum = add(sum, sum);
        cout << sum << "\n";
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