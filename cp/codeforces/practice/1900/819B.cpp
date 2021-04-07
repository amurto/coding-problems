// https://codeforces.com/contest/819/problem/B
// Mister B and PR Shifts

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

// Range Update Arithmetic Progression Offline
void update(vector<ll> &dev, vector<ll> &diff, int l, int r, ll a, ll d)
{
    dev[l] += a;
    dev[r + 1] -= (a + (r - l) * 1ll * d);
    diff[l] += d;
    diff[r] -= d;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<ll> arr(n), dev(n + 1), diff(n + 1), res(n + 1);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        arr[i]--;
    }
    for (int i = 0; i < n; i++)
    {
        if (arr[i] <= i)
        {
            update(dev, diff, 0, n - i - 1, i - arr[i], 1);
            int r = n - i;
            if (r < n)
            {
                update(dev, diff, r, r + arr[i] - 1, arr[i], -1);
                r += arr[i];
            }
            if (r < n)
                update(dev, diff, r, n - 1, 0, 1);
        }
        else
        {
            update(dev, diff, 0, arr[i] - i, arr[i] - i, -1);
            int r = arr[i] - i + 1;
            if (arr[i] < n - 1)
            {
                update(dev, diff, r, r + n - arr[i] - 2, 1, 1);
                r += n - arr[i] - 1;
            }
            if (r < n)
                update(dev, diff, r, n - 1, arr[i], -1);
        }
    }
    for (int i = 1; i < n; i++)
        diff[i] += diff[i - 1];
    for (int i = 1; i < n; i++)
        dev[i] += dev[i - 1] + diff[i - 1];
    int mn = 0;
    for (int i = 0; i < n; i++)
        if (dev[i] < dev[mn])
            mn = i;
    cout << dev[mn] << " " << mn << "\n";
    return 0;
}