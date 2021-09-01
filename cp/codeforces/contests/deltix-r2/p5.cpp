#ifdef use_debug
#define TERMINAL
#include "headers/debug.cpp"
#else
#define d(...) 0
#endif
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int N = 1e5 + 5, LGN = 18;
ll mn_sp[N][LGN], mx_sp[N][LGN];
int hp[N];

void init()
{
    // highest power of 2 less than i
    hp[0] = hp[1] = 0;
    for (int i = 2; i < N; i++)
        hp[i] = hp[i / 2] + 1;
}

void build(vector<ll> &arr, int n)
{
    // sparse table initialization with input array
    for (int i = 0; i < n; i++)
    {
        mn_sp[i][0] = arr[i];
        mx_sp[i][0] = arr[i];
    }

    // works for min, max, gcd
    // updates not supported
    for (int k = 1; k < LGN; k++)
    {
        for (int i = 0; i < n; i++)
        {
            mn_sp[i][k] = min(mn_sp[i][k - 1], mn_sp[min(n - 1, i + (1 << (k - 1)))][k - 1]);
            mx_sp[i][k] = max(mx_sp[i][k - 1], mx_sp[min(n - 1, i + (1 << (k - 1)))][k - 1]);
        }
    }
}

ll mn_query(int l, int r)
{
    int dis = r - l + 1;
    return min(mn_sp[l][hp[dis]], mn_sp[r - (1 << hp[dis]) + 1][hp[dis]]);
}

ll mx_query(int l, int r)
{
    int dis = r - l + 1;
    return max(mx_sp[l][hp[dis]], mx_sp[r - (1 << hp[dis]) + 1][hp[dis]]);
}

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<ll> a(n + 1), b(n + 1), pre(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
        a[i] -= b[i];
        pre[i] = pre[i - 1] + a[i];
    }
    build(pre, n);
    for (int i = 0; i < q; i++)
    {
        int l, r;
        cin >> l >> r;
        ll ans = -1;
        if (pre[r] - pre[l - 1] == 0 && mx_query(l, r) - pre[l - 1] <= 0)
            ans *= (mn_query(l, r) - pre[l - 1]);
        cout << ans << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    init();
    solve();
    return 0;
}