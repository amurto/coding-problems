#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    if (n <= 3)
        return n;
    int res = 3;
    vector<int> left(n), right(n), dleft(n), dright(n);
    for (int i = 1; i < n; i++)
        dleft[i] = arr[i] - arr[i - 1];
    for (int i = n - 2; i >= 0; i--)
        dright[i] = arr[i + 1] - arr[i];
    left[0] = 1;
    left[1] = 2;
    for (int i = 2; i < n; i++)
        left[i] = (dleft[i - 1] == dleft[i]) ? left[i - 1] + 1 : 2;
    right[n - 1] = 1;
    right[n - 2] = 2;
    for (int i = n - 3; i >= 0; i--)
        right[i] = (dright[i] == dright[i + 1]) ? right[i + 1] + 1 : 2;
    for (int i = 0; i < n; i++)
    {
        res = max(res, max(left[i], right[i]));
        if (i > 0)
            res = max(res, left[i - 1] + 1);
        if (i < n - 1)
            res = max(res, right[i + 1] + 1);
        if (i > 0 && i < n - 1)
        {
            int d = arr[i + 1] - arr[i - 1];
            int p = d % 2, h = d / 2;
            if (p == 0)
            {
                if (i - 1 == 0)
                {
                    if (h == dright[i + 1])
                        res = max(res, 2 + right[i + 1]);
                }
                else if (i + 1 == n - 1)
                {
                    if (h == dleft[i - 1])
                        res = max(res, 2 + left[i - 1]);
                }
                else
                {
                    if (h == dright[i + 1])
                        res = max(res, 2 + right[i + 1]);
                    if (h == dleft[i - 1])
                        res = max(res, 2 + left[i - 1]);
                    if (dleft[i - 1] == dright[i + 1] && h == dleft[i - 1])
                        res = max(res, left[i - 1] + 1 + right[i + 1]);
                }
            }
        }
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
    for (int tc = 1; tc <= t; tc++)
        cout << "Case #" << tc << ": " << solve() << "\n";
    return 0;
}