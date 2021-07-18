#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int solve()
{
    int n;
    cin >> n;
    vector<ll> a(n + 1), b(n + 1), preA(n + 1), preB(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    a[0] = b[0] = 1e9 + 5;
    sort(a.rbegin(), a.rend());
    sort(b.rbegin(), b.rend());
    a[0] = 0;
    b[0] = 0;
    for (int i = 1; i <= n; i++)
        preA[i] = preA[i - 1] + a[i];
    for (int i = 1; i <= n; i++)
        preB[i] = preB[i - 1] + b[i];
    int low = 0, high = 1e9 + 5, res = 1e9 + 5;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int e = n + mid;
        int h = e - n;
        int k = e - (e / 4);
        int req = max(0, k - h);
        ll a_sum = 1ll * 100 * min(k, h) + preA[req];
        ll b_sum = preB[min(n, k)];
        if (a_sum >= b_sum)
        {
            res = min(res, mid);
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
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