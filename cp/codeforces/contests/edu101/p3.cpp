#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

bool solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> h(n);
    for (int i = 0; i < n; i++)
        cin >> h[i];
    vector<int> bot(n), tp(n);
    bot[0] = h[0];
    tp[0] = h[0] + k;
    for (int i = 1; i < n - 1; i++)
    {
        if (h[i] >= tp[i - 1])
            return false;
        bot[i] = max(h[i], bot[i - 1] + 1 - k);
        tp[i] = min(h[i] + 2 * k - 1, tp[i - 1] + k - 1);
        if (abs(bot[i] - tp[i]) < k)
            return false;
    }
    bot[n - 1] = h[n - 1];
    tp[n - 1] = h[n - 1] + k;
    if (bot[n - 1] >= tp[n - 2] || tp[n - 1] <= bot[n - 2])
        return false;
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        solve() ? cout << "YES\n" : cout << "NO\n";
    return 0;
}