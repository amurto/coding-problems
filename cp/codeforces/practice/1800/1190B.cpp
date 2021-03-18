// https://codeforces.com/contest/1190/problem/B
// Tokitsukaze, CSL and Stone Game

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

ll nc2(int n)
{
    return n * 1ll * (n - 1) / 2;
}

string solve()
{
    string p[2] = {"cslnb", "sjfnb"};
    int n, cnt = 0;
    cin >> n;
    ll sum = 0;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n; i++)
        if (arr[i] < i)
            return p[0];
    for (int i = 1; i < n; i++)
        cnt += (arr[i - 1] == arr[i]);
    for (int i = 1; i < n - 1; i++)
        if (arr[i] - arr[i - 1] == 1 && arr[i] == arr[i + 1])
            return p[0];
    if (cnt > 1)
        return p[0];
    return p[(sum - nc2(n)) % 2];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}