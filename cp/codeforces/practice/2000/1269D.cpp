// https://codeforces.com/contest/1269/problem/D
// Domino for Young

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

ll solve()
{
    int n;
    cin >> n;
    vector<ll> arr(n), cnt(2);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    for (int i = 0, p = 0; i < n; i++, p ^= 1)
    {
        cnt[p] += (arr[i] + 1) / 2;
        cnt[p ^ 1] += arr[i] / 2;
    }
    return min(cnt[0], cnt[1]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}