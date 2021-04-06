#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back

const int MOD = 998244353, N = 1e5 + 5;
const ll b = 1e9;
int two[N];
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

int solve()
{
    int n, res = 0;
    cin >> n;
    vector<pii> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i].first >> arr[i].second;
    sort(arr.begin(), arr.end());
    vector<int> suf(n);
    suf[n - 1] = arr[n - 1].first;
    for (int i = n - 2; i >= 0; i--)
        suf[i] = __gcd(arr[i].first, suf[i + 1]);
    ll l = 1;
    for (int i = 0; l <= b && i < n; i++)
    {
        if (i > 0 && suf[i] % l == 0)
            res = add(res, 1);
        l = l * 1ll * arr[i].first / __gcd(l, arr[i].first * 1ll);
        if (l < b && l == suf[i])
            res = add(res, add(two[arr[i].second], -2));
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    two[0] = 1;
    for (int i = 1; i < N; i++)
        two[i] = mul(two[i - 1], 2);
    int t;
    cin >> t;
    while (t-- > 0)
        cout << solve() << "\n";
    return 0;
}