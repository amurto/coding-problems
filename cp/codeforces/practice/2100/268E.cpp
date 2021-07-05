// https://codeforces.com/contest/268/problem/E
// Playlist

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

double solve()
{
    int n;
    cin >> n;
    double res = 0;
    vector<int> arr(n), p(n), ids(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i] >> p[i];
    iota(ids.begin(), ids.end(), 0);
    sort(ids.begin(), ids.end(), [&](int &i1, int &i2)
         { return p[i1] * (100 - p[i2]) * arr[i1] > p[i2] * (100 - p[i1]) * arr[i2]; });
    int suf = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        int id = ids[i];
        res += ((1.0 * p[id] * suf) / 10000.0 + 1.0) * arr[id];
        suf += 100 - p[id];
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(12);
    cout << solve() << "\n";
    return 0;
}