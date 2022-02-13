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

ll solve()
{
    int n;
    cin >> n;
    ll sum = 0, ev = 0, cnt = 0;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    for (int i = 1; i < n - 1; i++)
    {
        sum += arr[i];
        if (arr[i] & 1)
        {
            ev += (arr[i] - 1);
            cnt++;
        }
        else
        {
            ev += arr[i];
        }
    }
    if (cnt == 0)
        return sum / 2;
    if (ev == 0)
        return -1;
    if (cnt == 1 && n == 3)
        return -1;
    ll res = cnt + (sum - cnt) / 2;
    return res;
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