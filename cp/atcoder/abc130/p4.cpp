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
    ll k, res = 0;
    cin >> n >> k;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int l = 0, r = 0;
    ll sum = 0;
    while (r < n)
    {
        sum += arr[r];
        while (l < r && sum - arr[l] >= k)
        {
            sum -= arr[l];
            l++;
        }
        if (sum >= k)
            res += l + 1;
        r++;
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}