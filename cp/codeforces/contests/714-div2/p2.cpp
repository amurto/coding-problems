#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int N = 2e5 + 5, MOD = 1e9 + 7;

int mul(int x, int y)
{
    return (x * 1ll * y) % MOD;
}

// factorial
int fact[N], invfact[N];
void init()
{
    fact[0] = fact[1] = 1;
    int i;
    for (i = 2; i < N; i++)
        fact[i] = (fact[i - 1] * 1ll * i) % MOD;
}

int nc2(int n)
{
    return (n * 1ll * (n - 1)) % MOD;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int key = 0, cnt = 0;
    for (int i = 0; i <= 30; i++)
        key |= (1 << i);
    for (int i = 0; i <= 30; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (((arr[j] >> i) & 1) == 0)
                key &= ~(1 << i);
        }
    }
    for (int i = 0; i < n; i++)
        if (arr[i] == key)
            cnt++;
    if (cnt < 2)
    {
        cout << "0\n";
        return;
    }
    int res = mul(nc2(cnt), fact[n - 2]);
    cout << res << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    init();
    int t;
    cin >> t;
    while (t-- > 0)
        solve();
    return 0;
}