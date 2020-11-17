#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for (int ti = 1; ti <= t; ti++)
    {
        int n;
        ll moves = 0;
        cin >> n;
        int mid = (n - 1) / 2;
        vector<ll> x(n), y(n);
        for (int i = 0; i < n; i++)
            cin >> x[i] >> y[i];
        sort(x.begin(), x.end());
        sort(y.begin(), y.end());
        for (ll yv : y)
            moves += abs(yv - y[mid]);
        for (int i = 0; i < n; i++)
            x[i] -= i;
        sort(x.begin(), x.end());
        for (ll xv : x)
            moves += abs(xv - x[mid]);
        cout << "Case #" << ti << ": " << moves << "\n";
    }
    return 0;
}