// https://codeforces.com/problemset/problem/1102/E
// Monotonic Renumeration

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int N = 2e5 + 5, MOD = 998244353;
int two[N];
void init()
{
    two[0] = 1;
    for (int i = 1; i < N; i++)
        two[i] = (two[i - 1] * 1ll * 2) % MOD;
}

int solve()
{
    int n, cur = -1, res = 0;
    cin >> n;
    map<int, int> lt;
    vector<int> arr(n), pos(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    for (int i = n - 1; i >= 0; i--)
    {
        if (lt[arr[i]] == 0)
            lt[arr[i]] = i;
        pos[i] = lt[arr[i]];
    }
    for (int i = 0; i < n; i++)
    {
        cur = max(cur, pos[i]);
        if (cur == i)
            res++;
    }
    return two[res - 1];
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