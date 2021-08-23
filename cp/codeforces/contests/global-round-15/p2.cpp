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
    int n, res = -1;
    cin >> n;
    vector<vector<int>> arr(n, vector<int>(5));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 5; j++)
            cin >> arr[i][j];
    if (n == 1)
        return 1;
    vector<int> ids(n);
    iota(ids.begin(), ids.end(), 0);
    sort(ids.begin(), ids.end(), [&](int &i1, int &i2)
         {
             vector<int> cnt(2);
             for (int j = 0; j < 5; j++)
                 cnt[arr[i1][j] < arr[i2][j]]++;
             return cnt[1] > cnt[0];
         });
    int w = ids[0];
    for (int i = 0; i < n; i++)
    {
        if (i != w)
        {
            vector<int> cnt(2);
            for (int j = 0; j < 5; j++)
                cnt[arr[w][j] < arr[i][j]]++;
            if (cnt[1] < cnt[0])
                return -1;
        }
    }
    return w + 1;
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