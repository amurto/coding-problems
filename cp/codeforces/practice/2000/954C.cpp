// https://codeforces.com/contest/954/problem/E
// Water Taps

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;
#define pb push_back

double solve()
{
    int n, k = 0;
    ll T, num = 0, den = 0;
    cin >> n >> T;
    vector<pii> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i].second;
    for (int i = 0; i < n; i++)
        cin >> arr[i].first;
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n; i++)
    {
        num += arr[i].first * arr[i].second;
        den += arr[i].second;
    }
    if (num < T * den)
    {
        T *= -1;
        for (int i = 0; i < n; i++)
            arr[i].first *= -1;
        reverse(arr.begin(), arr.end());
        num *= -1;
    }
    int last = n - 1;
    while (num > T * den)
    {
        num -= arr[last].first * arr[last].second;
        den -= arr[last].second;
        last--;
    }
    last++;
    double low = 0, high = 1.0 * arr[last].second;
    for (int j = 0; j <= 60; j++)
    {
        double mid = (low + high) / 2.0;
        double curSum = 1.0 * num + mid * arr[last].first, curW = 1.0 * den + mid;
        if (curSum <= 1.0 * T * curW)
            low = mid;
        else
            high = mid;
    }
    return 1.0 * den + low;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(12);
    cout << solve() << "\n";
    return 0;
}