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

const int N = 2e5 + 5;
int mob[N];
vector<int> lp(N + 1), pr;
void mobius()
{
    for (int i = 2; i <= N; i++)
    {
        if (lp[i] == 0)
        {
            lp[i] = i;
            pr.push_back(i);
        }
        for (int j = 0; j < (int)pr.size() && pr[j] <= lp[i] && i * pr[j] <= N; ++j)
            lp[i * pr[j]] = pr[j];
    }
    for (int i = 1; i < N; i++)
    {
        if (i == 1)
            mob[i] = 1;
        else
        {
            if (lp[i / lp[i]] == lp[i])
                mob[i] = 0;
            else
                mob[i] = -1 * mob[i / lp[i]];
        }
    }
}

void solve()
{
    int n, q;
    ll sum = 0;
    cin >> n;
    vector<ll> a(n + 1), b(n + 1), diff(n + 1), e(n + 1), seq;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    for (int i = 2; i <= n; i++)
        diff[i] = b[i] - a[i];
    for (int i = 2; i <= n; i++)
    {
        e[i] = diff[i];
        ll rem = -diff[i];
        for (int j = i; j <= n; j += i)
            diff[j] += rem;
        if (mob[i] < 0)
            e[i] *= -1;
        if (mob[i] != 0)
            seq.pb(e[i]);
        else
            sum += abs(e[i]);
    }
    int sz = (int)seq.size();
    sort(seq.begin(), seq.end());
    vector<ll> pre(sz + 1);
    if (!seq.empty())
        pre[0] = seq[0];
    for (int i = 1; i < sz; i++)
        pre[i] = pre[i - 1] + seq[i];
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        cin >> b[1];
        ll x = b[1] - a[1], res = sum;
        res += abs(x);
        if (n > 1)
        {
            int low = 0, high = sz - 1, mx = -1;
            while (low <= high)
            {
                int mid = low + (high - low) / 2;
                if (x + seq[mid] < 0)
                {
                    mx = max(mx, mid);
                    low = mid + 1;
                }
                else
                    high = mid - 1;
            }
            if (mx == -1 || mx == sz - 1)
                res += abs(x * sz + pre[sz - 1]);
            else
                res += abs(x * (mx + 1) + pre[mx]) + abs(x * (sz - mx - 1) + pre[sz - 1] - pre[mx]);
        }
        cout << res << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    mobius();
    solve();
    return 0;
}