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

const int B = 500;
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> x(n), y(n), period(n), last(n), t(m), trains(m), res(m), pre(m + 1);
    vector<bool> heavy(n);
    vector<vector<int>> add(n), rem(n), st(B);
    for (int i = 0; i < n; i++)
    {
        cin >> x[i] >> y[i];
        period[i] = x[i] + y[i];
        if (period[i] >= B)
            heavy[i] = true;
    }
    for (int i = 0; i < m; i++)
    {
        cin >> t[i] >> trains[i];
        trains[i]--;
        if (t[i] == 1)
            add[trains[i]].pb(i);
        else
            rem[trains[i]].pb(i);
    }
    for (int i = 0; i < n; i++)
        rem[i].pb(m);
    for (int i = 0; i < m; i++)
    {
        int train = trains[i];
        if (t[i] == 1)
        {
            if (heavy[train])
            {
                int r = lower_bound(rem[train].begin(), rem[train].end(), i) - rem[train].begin();
                r = rem[train][r];
                for (int j = i; j < r; j += period[train])
                {
                    if (j + x[train] < r)
                    {
                        pre[j + x[train]]++;
                        pre[min(r, j + period[train])]--;
                    }
                }
            }
            else
            {
                if (st[period[train]].empty())
                    st[period[train]].resize(period[train]);
                last[train] = ((i % period[train]) + x[train]) % period[train];
                for (int j = last[train], itr = 0; itr < y[train]; j++, itr++)
                {
                    if (j >= period[train])
                        j -= period[train];
                    st[period[train]][j]++;
                }
            }
        }
        else
        {
            if (!heavy[train])
            {
                for (int j = last[train], itr = 0; itr < y[train]; j++, itr++)
                {
                    if (j >= period[train])
                        j -= period[train];
                    st[period[train]][j]--;
                }
            }
        }
        for (int j = 2; j < B; j++)
            if (!st[j].empty())
                res[i] += st[j][i % j];
        if (i > 0)
            pre[i] += pre[i - 1];
        res[i] += pre[i];
    }
    for (int i = 0; i < m; i++)
        cout << res[i] << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}