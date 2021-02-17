#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int solve()
{
    int n, k;
    cin >> n >> k;
    int res = k % n;
    if (res == 0)
        res += n;
    if (n & 1)
    {
        res += (k-1) / (n / 2);
        res %= n;
        if (res == 0)
            res += n;
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        cout << solve() << "\n";
    return 0;
}