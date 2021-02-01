// https://codeforces.com/contest/466/problem/C
// Number of Ways

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

ll solve()
{
    int n;
    cin >> n;
    ll sum = 0, c = 0, res = 0;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }
    if (sum % 3 != 0)
        return 0;
    ll req = sum / 3;
    sum = 0;
    for (int i = 0; i < n - 1; i++)
    {
        sum += arr[i];
        if (sum == 2 * req)
            res += c;
        if (sum == req)
            c++;
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