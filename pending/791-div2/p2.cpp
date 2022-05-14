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
    ll sum = 0, last_val;
    cin >> n >> q;
    vector<ll> arr(n);
    vector<int> last(n, -1);
    int c = -1;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }
    for (int i = 0; i < q; i++)
    {
        int t;
        ll x;
        cin >> t;
        if (t == 1)
        {
            int id;
            cin >> id >> x;
            id--;
            if (c > last[id])
                sum -= last_val;
            else
                sum -= arr[id];
            last[id] = i;
            arr[id] = x;
            sum += arr[id];
        }
        else
        {
            cin >> last_val;
            c = i;
            sum = last_val * n;
        }
        cout << sum << "\n";
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