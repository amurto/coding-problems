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
    int h, w, n;
    cin >> h >> w >> n;
    vector<int> a(n), b(n), rows, cols;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i] >> b[i];
        rows.pb(a[i]);
        cols.pb(b[i]);
    }
    sort(rows.begin(), rows.end());
    rows.resize(unique(rows.begin(), rows.end()) - rows.begin());
    sort(cols.begin(), cols.end());
    cols.resize(unique(cols.begin(), cols.end()) - cols.begin());
    for (int i = 0; i < n; i++)
    {
        int r = lower_bound(rows.begin(), rows.end(), a[i]) - rows.begin();
        int c = lower_bound(cols.begin(), cols.end(), b[i]) - cols.begin();
        cout << r + 1 << " " << c + 1 << "\n";
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