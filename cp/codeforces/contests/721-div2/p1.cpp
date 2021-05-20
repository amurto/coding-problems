#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int solve()
{
    int n, cnt = 0;
    cin >> n;
    while (n > 0)
    {
        n >>= 1;
        cnt++;
    }
    return (1 << (cnt - 1)) - 1;
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