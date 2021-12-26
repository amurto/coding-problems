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
    int n, q;
    cin >> n;
    vector<int> R(n), C(n), id_r(n), id_c(n), pos_r(n), pos_c(n);
    for (int i = 0; i < n; i++)
        cin >> R[i];
    for (int i = 0; i < n; i++)
        cin >> C[i];
    iota(id_r.begin(), id_r.end(), 0);
    sort(id_r.begin(), id_r.end(), [&](int &i1, int &i2)
         { return R[i1] > R[i2]; });
    iota(id_c.begin(), id_c.end(), 0);
    sort(id_c.begin(), id_c.end(), [&](int &i1, int &i2)
         { return C[i1] < C[i2]; });
    for (int i = 0; i < n; i++)
        pos_r[id_r[i]] = i;
    for (int i = 0; i < n; i++)
        pos_c[id_c[i]] = i;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int r, c;
        cin >> r >> c;
        r--;
        c--;
        if (pos_r[r] <= pos_c[c])
            cout << '#';
        else
            cout << '.';
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}