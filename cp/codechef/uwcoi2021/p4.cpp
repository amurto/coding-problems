#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int N = 2e5;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> x1(k), y1(k), x2(k), y2(k);
    vector<ll> d(N), C(N);
    for (int i = 0; i < k; i++)
    {
        cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
        d[min(y1[i], y2[i])] += abs(x1[i] - x2[i]);
        d[max(y1[i], y2[i]) + 1] -= abs(x1[i] - x2[i]);
    }
    for (int i = 1; i <= n; i++)
        d[i] += d[i - 1];
    int h = 1;
    for (int i = 1; i <= n; i++)
        if (d[i] >= d[h])
            h = i;
    ll res = 0;
    for (int i = 0; i < k; i++)
    {
        ll ub = min(y1[i], y2[i]), lb = max(y1[i], y2[i]), cur = 0;
        cur += (lb - ub) * 2;
        if (h >= ub && h <= lb)
            cur += abs(x1[i] - x2[i]);
        else
        {
            // get to selected h
            ll gth = 4 * min(abs(lb - h), abs(ub - h)) + abs(x1[i] - x2[i]);
            cur += min(gth, abs(x1[i] - x2[i]) * 2ll);  
        }
        res += cur;
    }
    cout << res << "\n";
    return 0;
}