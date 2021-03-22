#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int solve()
{
    int n, m, k, res = 0;
    cin >> n >> m >> k;
    vector<int> arr(n + m + 2);
    for (int i = 1; i <= n; i++)
    {
        arr[i + 1]++;
        arr[i + m + 1]--;
    }
    for (int i = 1; i <= n + m; i++)
    {
        arr[i] += arr[i - 1];
        if (arr[i] & 1)
            res ^= (i + k);
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