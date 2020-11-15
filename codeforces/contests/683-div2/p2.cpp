#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int solve()
{
    int n, m, v, neg = 0, sum = 0, MIN = INT_MAX;
    cin >> n >> m;
    bool zero = false;
    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> v;
            if (v == 0)
                zero = true;
            else if (v < 0)
                neg++;
            MIN = min(MIN, abs(v));
            arr.pb(abs(v));
        }
    }
    for (int val : arr)
        sum += val;
    if (zero || neg % 2 == 0)
        return sum;
    return sum - 2 * MIN;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
    {
        cout << solve() << "\n";
    }
    return 0;
}