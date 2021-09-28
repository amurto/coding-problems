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
    vector<int> arr(n), l, r, offset;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    vector<int> seq = arr;
    sort(seq.begin(), seq.end());
    for (int i = 0; i < n; i++)
    {
        int req = seq[i], id = i;
        for (int j = i; j < n; j++)
            if (req == arr[j])
                id = j;
        if (id != i)
        {
            l.pb(i);
            r.pb(id);
            offset.pb(id - i);
            for (int j = id; j > i; j--)
                arr[j] = arr[j - 1];
            arr[i] = req;
        }
    }
    int sz = (int)l.size();
    cout << sz << "\n";
    if (sz > 0)
        for (int i = 0; i < sz; i++)
            cout << l[i] + 1 << " " << r[i] + 1 << " " << offset[i] << "\n";
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