#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

void solve()
{
    int n;
    string str;
    cin >> n >> str;
    vector<int> arr(n + 1), ids(n + 1);
    for (int i = 0; i < n + 1; i++)
        cin >> arr[i];
    int low = 1, high = 1e4 + 5, res = 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        vector<vector<int>> tmp(mid, vector<int>(n + 1));
        bool pos = true;
        for (int i = 0; pos && i < n + 1; i++)
        {
            int e = arr[i] / mid, rem = arr[i] % mid;
            for (int j = 0; pos && j < mid; j++)
            {
                tmp[j][i] = e;
                if (j < rem)
                    tmp[j][i]++;
                if (i > 0)
                {
                    if (str[i - 1] == '<')
                        pos = (tmp[j][i - 1] < tmp[j][i]);
                    else
                        pos = (tmp[j][i - 1] > tmp[j][i]);
                }
            }
        }
        if (pos)
        {
            res = max(res, mid);
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
    cout << res << "\n";
    vector<vector<int>> ans(res, vector<int>(n + 1));
    for (int i = 0; i < n + 1; i++)
    {
        int e = arr[i] / res, rem = arr[i] % res;
        for (int j = 0; j < res; j++)
        {
            ans[j][i] = e;
            if (j < rem)
                ans[j][i]++;
        }
    }
    for (int i = 0; i < res; i++)
    {
        for (int j = 0; j < n + 1; j++)
            cout << ans[i][j] << " ";
        cout << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}