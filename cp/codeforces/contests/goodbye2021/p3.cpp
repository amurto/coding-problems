#ifdef use_debug
#define TERMINAL
#include "headers/debug.cpp"
#else
#define d(...) 0
#endif
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int solve()
{
    int n;
    cin >> n;
    int res = n - 1;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    if (n <= 2)
        return 0;
    for (int i = 0; i < n; i++)
    {
        for (int k = i + 1; k < n; k++)
        {
            int diff = arr[k] - arr[i], len = k - i;
            vector<int> tmp = arr;
            for (int j = 0; j < n; j++)
                tmp[j] *= len;
            for (int j = i + 1; j < n; j++)
                tmp[j] = tmp[j - 1] + diff;
            for (int j = i - 1; j >= 0; j--)
                tmp[j] = tmp[j + 1] - diff;
            int cnt = 0;
            for (int j = 0; j < n; j++)
                cnt += (len * arr[j] != tmp[j]);
            res = min(res, cnt);
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
    while (t-- > 0)
        cout << solve() << "\n";
    return 0;
}