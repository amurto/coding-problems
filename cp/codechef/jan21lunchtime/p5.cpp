#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

bool solve()
{
    int n, x;
    cin >> n >> x;
    int req = n * n - x;
    if (req == 0 || req == (n + n - 1))
        return true;
    for (int i = 1; i < n; i++)
    {
        if (req - i * n < 0)
            continue;
        if ((req - i * n) % (n - i) == 0)
            return true;
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        solve() ? cout << "Yes\n" : cout << "No\n";
    return 0;
}