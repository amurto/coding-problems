#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back

bool solve()
{
    int n, m, k;
    cin >> m >> n;
    vector<int> p(m);
    for (int i = 0; i < m; i++)
        cin >> p[i];
    vector<pii> car(n);
    for (int i = 0; i < n; i++)
        cin >> car[i].first;
    for (int i = 0; i < n; i++)
        cin >> car[i].second;
    sort(car.begin(), car.end());
    int j = 0;
    while (j < n && car[j].first == p[0])
        j++;
    for (int i = 1; i < m; i++)
    {
        vector<double> lp, rp;
        vector<pii> lt, rt;
        while (j < n && car[j].first < p[i])
        {
            if (car[j].second < 0)
            {
                if (!rt.empty())
                    return false;
                lt.pb(car[j]);
            }
            else
                rt.pb(car[j]);
            j++;
        }
        for (pii v : lt)
            lp.pb(1.0 * abs(p[i - 1] - v.first) / (1.0 * abs(v.second)));
        for (pii v : rt)
            rp.pb(1.0 * abs(p[i] - v.first) / (1.0 * abs(v.second)));
        reverse(rp.begin(), rp.end());
        if (!is_sorted(lp.begin(), lp.end()))
            return false;
        if (!is_sorted(rp.begin(), rp.end()))
            return false;
        while (j < n && car[j].first == p[i])
            j++;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        solve() ? cout << "YES\n" : cout << "NO\n";
    return 0;
}