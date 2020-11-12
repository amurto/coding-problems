#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int solve()
{
    int n, k, m, v, sum = 0;
    cin >> n >> k >> m;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> v;
        sum += v;
    }
    int res = m * n - sum;
    if (res <= 0)
        return 0;
    else if (res > k)
        return -1;
    return res;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}