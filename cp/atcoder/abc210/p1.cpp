#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int solve()
{
    int n, a, x, y;
    cin >> n >> a >> x >> y;
    if (n <= a)
        return x * n;
    return x * a + y * (n - a);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}