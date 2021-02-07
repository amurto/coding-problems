// https://codeforces.com/contest/567/problem/C
// Geometric Progression

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
    ll k, v, res = 0;
    cin >> n >> k;
    vector<ll> arr(n);
    unordered_map<ll, ll> l, r;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        r[arr[i]]++;
    }
    for (int i = 0; i < n; i++)
    {
        r[arr[i]]--;
        if (arr[i] % k == 0)
            res += l[arr[i] / k] * r[arr[i] * k];
        l[arr[i]]++;
    }
    cout << res << "\n";
    return 0;
}