#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

ll solve()
{
    int n;
    cin >> n;
    vector<ll> x(n), y(n);
    vector<int> idx(n), idy(n);
    for (int i = 0; i < n; i++)
        cin >> x[i] >> y[i];
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&](int &i1, int &i2)
         { return x[i1] < x[i2]; });
    iota(idy.begin(), idy.end(), 0);
    sort(idy.begin(), idy.end(), [&](int &i1, int &i2)
         { return y[i1] < y[i2]; });
    ll xmx = abs(x[idx[0]] - x[idx[n - 1]]);
    ll ymx = abs(y[idy[0]] - y[idy[n - 1]]);
    int id1 = 0, id2 = 0;
    if (xmx > ymx)
    {
        id1 = idx[0];
        id2 = idx[n - 1];
    }
    else
    {
        id1 = idy[0];
        id2 = idy[n - 1];
    }
    vector<ll> dis;
    for (int i = 0; i < n; i++)
    {
        if (i == id1 || i == id2)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == j)
                    continue;
                if ((i == id1 && j == id2) || (i == id2 && j == id1))
                    continue;
                dis.pb(max(abs(x[i] - x[j]), abs(y[i] - y[j])));
            }
        }
        else
            dis.pb(max({abs(x[i] - x[idx[0]]), abs(x[i] - x[idx[n - 1]]), abs(y[i] - y[idy[0]]), abs(y[i] - y[idy[n - 1]])}));
    }
    sort(dis.rbegin(), dis.rend());
    return dis[0];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}