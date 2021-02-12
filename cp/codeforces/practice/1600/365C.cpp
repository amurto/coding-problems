// https://codeforces.com/contest/365/problem/C
// Matrix

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

ll nc2(ll x)
{
    return x * (x - 1) / 2;
}
ll solve()
{
    map<int, ll> mp;
    int a;
    cin >> a;
    string str;
    cin >> str;
    int n = str.length();
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        arr[i] = str[i] - '0';
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += arr[j];
            mp[sum]++;
        }
    }
    if (a == 0)
        return 2 * mp[0] * (nc2(n) + n) - mp[0] * mp[0];
    ll res = 0;
    for (auto x : mp)
        if (x.first > 0 && a % x.first == 0)
            res += x.second * mp[a / x.first];
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