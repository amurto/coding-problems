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
    int n;
    cin >> n;
    vector<int> arr(n), ids(n), x(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    iota(ids.begin(), ids.end(), 0);
    sort(ids.begin(), ids.end(), [&](int &i1, int &i2)
         { return arr[i1] > arr[i2]; });
    int l = -1, r = 1;
    for (int id : ids)
    {
        if (abs(l) > r)
        {
            x[id] = r;
            r++;
        }
        else
        {
            x[id] = l;
            l--;
        }
    }
    ll mn = 0;
    for (int i = 0; i < n; i++)
        mn += 2ll * abs(x[i]) * arr[i];
    cout << mn << "\n";
    cout << "0 ";
    for (int i = 0; i < n; i++)
        cout << x[i] << " ";
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