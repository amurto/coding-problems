#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

ll solve()
{
    int n;
    cin >> n;
    ll res = 0;
    vector<ll> arr(n + 1), jump(n + 1);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    for (int i = 0; i < n; i++)
    {
        if (i + arr[i] >= n)
        {
            ll target = max(1ll, n - 1ll - i);
            ll w = arr[i] - target;
            if (jump[i] <= w)
            {
                jump[n] += jump[i];
                arr[i] -= jump[i];
                jump[i] = 0;
            }
            else
            {
                jump[n] += w;
                jump[i] -= w;
                arr[i] = target;
            }
        }
        while (arr[i] > 1 && i + arr[i] < n && jump[i] > 0)
        {
            jump[i]--;
            jump[i + arr[i]]++;
            arr[i] = max(arr[i] - 1, 1ll);
        }
        if (jump[i] > 0)
        {
            jump[i + 1] += jump[i];
            jump[i] = 0;
        }
        if (i + arr[i] >= n)
        {
            ll target = max(1ll, n - 1ll - i);
            jump[n] += arr[i] - target;
            arr[i] = target;
        }
        while (arr[i] > 1)
        {
            jump[i + arr[i]]++;
            arr[i] = max(arr[i] - 1, 1ll);
        }
    }

    for (ll j : jump)
        res += j;
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