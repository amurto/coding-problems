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

int solve()
{
    int n, res = 0;
    cin >> n;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    for (int i = 0; i < n;)
    {
        int r = i;
        while (r < n && arr[i] == arr[r])
            r++;
        int cnt = r - i;
        if (r < n)
        {
            int itr = r;
            while (itr < n)
            {
                ll diff = arr[itr] - arr[i];
                int id = lower_bound(arr.begin(), arr.end(), arr[itr] + diff) - arr.begin();
                itr = id;
                cnt++;
            }
        }
        res = max(res, cnt);
        i = r;
    }
    return n - res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        cout << solve() << "\n";
    return 0;
}