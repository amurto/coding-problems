#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int solve()
{
    int n;
    cin >> n;
    vector<int> arr(n), pre(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    if (n > 60)
        return 1;
    pre[0] = arr[0];
    for (int i = 1; i < n; i++)
        pre[i] = pre[i - 1] ^ arr[i];
    int res = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = i; k < j; k++)
            {
                int L = pre[k], R = pre[j] ^ pre[k];
                if (i - 1 >= 0)
                    L ^= pre[i - 1];
                if (L > R)
                    res = min(res, j - i - 1);
            }
        }
    }
    if (res == INT_MAX)
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