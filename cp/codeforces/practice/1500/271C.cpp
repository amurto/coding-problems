// https://codeforces.com/contest/271/problem/C
// Secret

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

void solve()
{
    int n, k;
    cin >> n >> k;
    int each = n / k, rem = n % k;
    if (each <= 2)
    {
        cout << "-1\n";
        return;
    }
    vector<int> req(k + 1, each), mark(n + 1);
    for (int i = 1; i <= k && rem > 0; i++, rem--)
        req[i]++;
    int beg = 1, end = n;
    for (int i = 1; i <= k; i++)
        for (int j = 0; j < req[i] - 1; j++, beg++)
            mark[beg] = i;
    for (int i = k; i > 0 && end >= beg; i--, end--)
        mark[end] = i;
    for (int i = 1; i <= n; i++)
        cout << mark[i] << " ";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}