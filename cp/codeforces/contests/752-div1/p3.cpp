#ifdef use_debug
#define TERMINAL
#include "headers/debug.cpp"
#else
#define d(...) 0
#endif
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back

const int MOD = 998244353, N = 1e5 + 5;
int cnt[N];

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
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    vector<pii> dp;
    for (int i = n - 1; i >= 0; i--)
    {
        vector<pii> tdp, ndp;
        for (pii p : dp)
        {
            // arr[i] -> p.first
            int tmp = arr[i];
            if (arr[i] > p.first)
            {
                int parts = (arr[i] + p.first - 1) / p.first;
                tmp = arr[i] / parts;
                res = add(res, mul(i + 1, mul(parts - 1, p.second)));
            }
            tdp.pb({tmp, p.second});
        }
        tdp.pb({arr[i], 1});
        sort(tdp.begin(), tdp.end());
        int sz = (int)tdp.size();
        for (int j = 0; j < sz;)
        {
            int r = j;
            ndp.pb({tdp[j].first, 0});
            while (r < sz && tdp[j].first == tdp[r].first)
            {
                ndp.back().second += tdp[r].second;
                r++;
            }
            j = r;
        }
        swap(dp, ndp);
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        cout << solve() << "\n";
    return 0;
}