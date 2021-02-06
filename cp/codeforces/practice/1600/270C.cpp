// https://codeforces.com/contest/270/problem/C
// Magical Boxes

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int N = 16;
vector<ll> four(N);

void init()
{
    four[0] = 1;
    for (int i = 1; i < N; i++)
        four[i] = four[i - 1] * 4;
}
ll solve()
{
    int n;
    cin >> n;
    vector<ll> k(n), arr(n);
    for (int i = 0; i < n; i++)
        cin >> k[i] >> arr[i];

    ll res = 0;
    for (int i = 0; i < n; i++)
    {
        ll cur = lower_bound(four.begin(), four.end(), arr[i]) - four.begin() + k[i];
        res = max(res, max(k[i] + 1, cur));
    }
    return res;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    init();
    cout << solve() << "\n";
    return 0;
}