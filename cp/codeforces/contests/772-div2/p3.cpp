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

struct triplet
{
    int i = 0, j = 0, k = 0;
    triplet(int idx1, int idx2, int idx3)
    {
        i = idx1;
        j = idx2;
        k = idx3;
    }
};

void solve()
{
    int n;
    cin >> n;
    vector<ll> arr(n);
    vector<triplet> ops;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    if (arr[n - 2] > arr[n - 1])
    {
        cout << "-1\n";
        return;
    }
    int y = n - 2, z = n - 1;
    for (int i = n - 3; i >= 0; i--)
    {
        if (arr[i] > arr[i + 1])
        {
            arr[i] = arr[y] - arr[z];
            if (arr[i] > arr[i + 1])
            {
                cout << "-1\n";
                return;
            }
            ops.pb(triplet(i + 1, y + 1, z + 1));
        }
        y = i;
    }
    cout << (int)ops.size() << "\n";
    for (triplet t : ops)
        cout << t.i << " " << t.j << " " << t.k << "\n";
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