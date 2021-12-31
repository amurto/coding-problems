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

void solve()
{
    int n, m, res = 0;
    cin >> n >> m;
    vector<string> grid(n);
    vector<int> x(n), arr(m);
    for (int i = 0; i < n; i++)
        cin >> x[i];
    for (int i = 0; i < n; i++)
        cin >> grid[i];
    for (int mask = 0; mask < (1 << n); mask++)
    {
        vector<int> coeff(m);
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            int v = (mask >> i) & 1;
            if (v == 0)
                v--;
            for (int j = 0; j < m; j++)
                if (grid[i][j] == '1')
                    coeff[j] += v;
        }
        for (int i = 0; i < n; i++)
            if ((mask >> i) & 1)
                sum -= x[i];
            else
                sum += x[i];
        vector<int> ids(m);
        iota(ids.begin(), ids.end(), 0);
        sort(ids.begin(), ids.end(), [&](int &i1, int &i2)
             { return coeff[i1] < coeff[i2]; });
        vector<int> perm(m);
        for (int i = 0; i < m; i++)
        {
            perm[ids[i]] = i + 1;
            sum += (i + 1) * coeff[ids[i]];
        }
        if (sum >= res)
        {
            res = sum;
            swap(arr, perm);
        }
    }
    for (int v : arr)
        cout << v << " ";
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        solve();
    return 0;
}