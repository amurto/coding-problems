// https://codeforces.com/contest/349/problem/C
// Mafia

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    ll mx = 0, sum = 0;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        mx = max(mx, arr[i]);
        sum += arr[i];
    }
    cout << max(mx, (sum + n - 2) / (n - 1)) << "\n";
    return 0;
}